#!/usr/bin/env python3
"""Move absolute ROM symbols from symbols.ld into labels inside the data .incbin stubs.

A symbol `gFoo = 0x08xxxxxx;` in symbols.ld stays at that address whatever the link does; a label in
the .incbin stub that covers the address moves with the data. This script splits the stub's .incbin
lines at every such address, emits `.global gFoo` / `gFoo:` there and removes the line from symbols.ld.
It is idempotent: labels already in the stubs are kept, so it can be re-run after adding new symbols.

    python3 tools/scripts/label_data.py [--dry-run]
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


def parse_stub(path):
    """Return (header lines, [(offset, size)], {offset: [labels]}) for a stub that is labels + incbins."""
    header, chunks, labels = [], [], {}
    pending = []
    for line in path.read_text().splitlines():
        m = INCBIN_RE.match(line)
        if m:
            off, size = int(m[1], 16), int(m[2], 16)
            if chunks and chunks[-1][0] + chunks[-1][1] != off:
                raise SystemExit(f"{path}: .incbin chunks are not contiguous at {off:#x}")
            chunks.append((off, size))
            if pending:
                labels.setdefault(off, []).extend(pending)
                pending = []
            continue
        m = LABEL_RE.match(line)
        if m:
            pending.append(m[1])
            continue
        if line.strip().startswith(".global") or (not line.strip() and (chunks or pending)):
            continue
        if chunks or pending:
            raise SystemExit(f"{path}: unexpected line {line!r}")
        header.append(line)
    if pending:  # labels at the very end
        end = chunks[-1][0] + chunks[-1][1]
        labels.setdefault(end, []).extend(pending)
    return header, chunks, labels


def write_stub(path, header, start, end, labels):
    out = list(header)
    while out and not out[-1].strip():
        out.pop()
    out.append("")
    cuts = sorted(o for o in labels if start <= o <= end)
    pos = start
    for cut in cuts + [None]:
        stop = end if cut is None else cut
        if stop > pos:
            out.append(f'\t.incbin "baserom.gba", {pos:#X}, {stop - pos:#X}'.replace("0X", "0x"))
            pos = stop
        if cut is not None:
            for name in labels[cut]:
                if out[-1]:
                    out.append("")
                out.append(f"\t.global {name}")
                out.append(f"{name}:")
    path.write_text("\n".join(out) + "\n")


def main():
    dry = "--dry-run" in sys.argv
    stubs = {}
    for d in STUB_DIRS:
        for p in sorted((ROOT / d).glob("*.s")):
            header, chunks, labels = parse_stub(p)
            if chunks:
                stubs[p] = (header, chunks[0][0], chunks[-1][0] + chunks[-1][1], labels)

    sym_path = ROOT / "symbols.ld"
    kept, moved = [], 0
    for line in sym_path.read_text().splitlines():
        m = SYM_RE.match(line)
        if m and int(m[2], 16) >= ROM_BASE:
            off = int(m[2], 16) - ROM_BASE
            for p, (header, start, end, labels) in stubs.items():
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
    for p, (header, start, end, labels) in stubs.items():
        write_stub(p, header, start, end, labels)
    sym_path.write_text("\n".join(kept) + "\n")


if __name__ == "__main__":
    main()
