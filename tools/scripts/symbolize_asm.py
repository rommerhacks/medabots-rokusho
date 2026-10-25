#!/usr/bin/env python3
"""Replace raw ROM addresses in asm literal pools (`.4byte 0x08xxxxxx`) with symbols.

A function start (or start + 1 for Thumb) becomes the function's name from config/functions.tsv; an
address inside a data stub becomes the label there, and a new `gUnk_XXXXXXXX` is added to symbols.ld
when there is none (run tools/scripts/label_data.py afterwards to move it into the stub). Addresses
inside code that are not a function start are reported and left alone.

    python3 tools/scripts/symbolize_asm.py [--dry-run] [files...]   (default: every asm/**/*.s)
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
WORD_RE = re.compile(r"\.4byte 0x(0[89][0-9A-Fa-f]{6})\b")
LABEL_RE = re.compile(r"^(\w+):", re.M)
INCBIN_RE = re.compile(r'\.incbin\s+"baserom\.gba",\s*(0x[0-9A-Fa-f]+),\s*(0x[0-9A-Fa-f]+)')


def data_labels():
    """{address: label} for every label in the data stubs, plus the stubs' address ranges."""
    labels, ranges = {}, []
    for d in ("data", "sound", "graphics"):
        for p in sorted((ROOT / d).glob("*.s")):
            pending = []
            for line in p.read_text().splitlines():
                m = LABEL_RE.match(line)
                if m:
                    pending.append(m[1])
                    continue
                m = INCBIN_RE.search(line)
                if m:
                    off, size = int(m[1], 16) + 0x08000000, int(m[2], 16)
                    for name in pending:
                        labels.setdefault(off, name)
                    pending = []
                    ranges.append((off, off + size))
    return labels, ranges


def functions():
    funcs = {}
    for line in (ROOT / "config/functions.tsv").read_text().splitlines():
        if line.startswith("#") or not line.strip():
            continue
        addr, size, name = line.split("\t")[:3]
        funcs[int(addr, 16)] = name
    return funcs


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    dry = "--dry-run" in sys.argv
    files = [Path(a) for a in args] or sorted((ROOT / "asm").rglob("*.s"))
    labels, ranges = data_labels()
    funcs = functions()
    new_syms = {}

    def resolve(value):
        if value in funcs:
            return funcs[value]
        if value & 1 and value - 1 in funcs:
            return funcs[value - 1]  # .thumb_func symbols get bit 0 from the linker
        if value in labels:
            return labels[value]
        if any(lo <= value < hi for lo, hi in ranges):
            name = f"gUnk_{value:08X}"
            new_syms[value] = name
            labels[value] = name
            return name
        return None

    changed = 0
    for p in files:
        text = p.read_text()

        def sub(m):
            nonlocal changed
            name = resolve(int(m[1], 16))
            if name is None:
                print(f"{p}: 0x{m[1]} is not a function start or data address, left alone")
                return m[0]
            changed += 1
            return f".4byte {name}"

        out = WORD_RE.sub(sub, text)
        if out != text and not dry:
            p.write_text(out)

    print(f"symbolized {changed} words, {len(new_syms)} new data symbols")
    if new_syms and not dry:
        with open(ROOT / "symbols.ld", "a") as f:
            for value, name in sorted(new_syms.items()):
                f.write(f"{name} = 0x{value:08X};\n")


if __name__ == "__main__":
    main()
