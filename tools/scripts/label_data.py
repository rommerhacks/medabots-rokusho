#!/usr/bin/env python3
"""Move absolute ROM symbols from symbols.ld into labels inside the data .incbin stubs.

A symbol `gFoo = 0x08xxxxxx;` in symbols.ld stays at that address whatever the link does; a label in
the .incbin stub that covers the address moves with the data. This script splits the stub's .incbin
lines at every such address, emits `.global gFoo` / `gFoo:` there and removes the line from symbols.ld.
It is idempotent: labels already in the stubs are kept, so it can be re-run after adding new symbols.

    python3 tools/scripts/label_data.py [--dry-run]

The pointers inside the stubs (`.4byte symbol` / `.4byte symbol+0xN`, from data_func_ptrs.py and
data_ptrs.py) are not written into the committed stubs: they live in config/data_ptrs/<dir>_<stub>.tsv
(`ROM address<TAB>symbol`), and the build renders each stub with them:

    python3 tools/scripts/label_data.py --render data/foo.s build/data/foo.s
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STUB_DIRS = ["data", "sound", "graphics"]
ROM_BASE = 0x08000000

INCBIN_RE = re.compile(r'^\s*\.incbin\s+"baserom\.gba",\s*(0x[0-9A-Fa-f]+),\s*(0x[0-9A-Fa-f]+)\s*$')
LABEL_RE = re.compile(r'^(\w+):\s*$')
SYM_RE = re.compile(r'^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;')


START_RE = re.compile(r'^@ data at (0x[0-9A-Fa-f]+)\s*$')
PTR_RE = re.compile(r'^\s*\.4byte\s+(\w+(?:\s*\+\s*0x[0-9A-Fa-f]+)?)\s*$')


def ptr_table(path):
    """config/data_ptrs/<dir>_<stub>.tsv for a stub path."""
    path = Path(path).resolve()
    return ROOT / "config" / "data_ptrs" / f"{path.parent.name}_{path.stem}.tsv"


def read_ptr_table(path):
    ptrs = {}
    table = ptr_table(path)
    if table.exists():
        for line in table.read_text().splitlines():
            if line and not line.startswith("#"):
                addr, sym = line.split("\t")
                ptrs[int(addr, 16) - ROM_BASE] = sym
    return ptrs


def parse_stub(path):
    """Return (header lines, start, end, {offset: [labels]}, {offset: symbol}) for a stub made of
    labels, .incbin chunks and `.4byte symbol` pointers."""
    header, labels, ptrs = [], {}, {}
    start = pos = None
    pending = []
    for line in path.read_text().splitlines():
        m = INCBIN_RE.match(line)
        p = None if m else PTR_RE.match(line)
        if m or p:
            if m:
                off, size = int(m[1], 16), int(m[2], 16)
                if pos is not None and pos != off:
                    raise SystemExit(f"{path}: .incbin chunks are not contiguous at {off:#x}")
            else:
                if pos is None:
                    raise SystemExit(f"{path}: .4byte before the first .incbin")
                off, size = pos, 4
                ptrs[off] = p[1]
            if start is None:
                start = off
            if pending:
                labels.setdefault(off, []).extend(pending)
                pending = []
            pos = off + size
            continue
        m = START_RE.match(line)
        if m and start is None:
            start = pos = int(m[1], 16)
            continue
        m = LABEL_RE.match(line)
        if m:
            pending.append(m[1])
            continue
        if line.strip().startswith(".global") or (not line.strip() and (start is not None or pending)):
            continue
        if start is not None or pending:
            raise SystemExit(f"{path}: unexpected line {line!r}")
        header.append(line)
    if pending:  # labels at the very end
        labels.setdefault(pos, []).extend(pending)
    ptrs.update(read_ptr_table(path))
    return header, start, pos, labels, ptrs


def write_stub(path, header, start, end, labels, ptrs):
    """Write the stub (labels and .incbin only) and its pointer table."""
    path.write_text(stub_text(header, start, end, labels, {}))
    table = ptr_table(path)
    if ptrs:
        table.parent.mkdir(parents=True, exist_ok=True)
        lines = [f"{ROM_BASE + o:08X}\t{ptrs[o]}" for o in sorted(ptrs)]
        table.write_text("# ROM address of a pointer word in the stub, and the symbol it points to\n"
                         + "\n".join(lines) + "\n")
    elif table.exists():
        table.unlink()


def stub_text(header, start, end, labels, ptrs):
    out = list(header)
    while out and not out[-1].strip():
        out.pop()
    out.append("")
    cuts = sorted(set(o for o in labels if start <= o <= end) | set(ptrs) | set(o + 4 for o in ptrs))
    pos = start
    if cuts and cuts[0] == start and start in ptrs:
        # a zero-length .incbin records the start offset when the stub begins with a pointer
        out.append(f"@ data at {start:#X}".replace("0X", "0x"))
    for cut in cuts + [None]:
        stop = end if cut is None else cut
        if stop > pos:
            out.append(f'\t.incbin "baserom.gba", {pos:#X}, {stop - pos:#X}'.replace("0X", "0x"))
            pos = stop
        if cut is None:
            break
        for name in labels.get(cut, []):
            if out[-1]:
                out.append("")
            out.append(f"\t.global {name}")
            out.append(f"{name}:")
        if cut in ptrs:
            out.append(f"\t.4byte {ptrs[cut]}")
            pos = cut + 4
    return "\n".join(out) + "\n"


def load_stubs():
    """{path: [header, start, end, labels, ptrs]} for every data stub."""
    stubs = {}
    for d in STUB_DIRS:
        for p in sorted((ROOT / d).glob("*.s")):
            stub = list(parse_stub(p))
            if stub[1] is not None:
                stubs[p] = stub
    return stubs


def save_stubs(stubs):
    for p, stub in stubs.items():
        write_stub(p, *stub)


def main():
    if sys.argv[1:2] == ["--render"]:
        stub = parse_stub(Path(sys.argv[2]))
        Path(sys.argv[3]).write_text(stub_text(*stub))
        return
    dry = "--dry-run" in sys.argv
    stubs = load_stubs()

    sym_path = ROOT / "symbols.ld"
    kept, moved = [], 0
    for line in sym_path.read_text().splitlines():
        m = SYM_RE.match(line)
        if m and int(m[2], 16) >= ROM_BASE:
            off = int(m[2], 16) - ROM_BASE
            for p, (header, start, end, labels, ptrs) in stubs.items():
                if start <= off < end:
                    names = labels.setdefault(off, [])
                    if m[1] not in names:
                        names.append(m[1])
                    moved += 1
                    break
            else:
                kept.append(line)
            continue
        kept.append(line)

    print(f"moved {moved} ROM symbols into data stubs")
    if dry:
        return
    save_stubs(stubs)
    sym_path.write_text("\n".join(kept) + "\n")


if __name__ == "__main__":
    main()
