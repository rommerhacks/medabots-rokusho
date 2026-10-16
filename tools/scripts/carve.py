#!/usr/bin/env python3
"""Carve hidden functions out of the `.byte` tail of a nonmatching function.

    carve.py PARENT ADDR:NAME:SIZE [ADDR:NAME:SIZE ...]

The tail of PARENT's .s file from the first ADDR on is removed, PARENT's size in
config/functions.tsv shrinks to end there, and an entry is added for each new
function (ADDR and SIZE in hex). The carved functions must then be written in C
(or as INCLUDE_ASM with their own .s) right after PARENT in its module.
The new functions must cover the removed tail exactly.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TSV = ROOT / "config" / "functions.tsv"


def main():
    parent = sys.argv[1]
    new = []
    for arg in sys.argv[2:]:
        addr, name, size = arg.split(":")
        new.append((int(addr, 16), name, int(size, 16)))
    new.sort()

    lines = TSV.read_text().splitlines(keepends=True)
    idx = next(i for i, l in enumerate(lines) if l.split("\t")[2:3] == [parent])
    paddr, psize, _, module = lines[idx].rstrip("\n").split("\t")
    paddr, psize = int(paddr, 16), int(psize, 16)
    end = paddr + psize
    first = new[0][0]
    assert paddr < first < end, "carved functions must lie inside the parent"
    pos = first
    for addr, name, size in new:
        assert addr == pos, f"gap or overlap at {addr:08X}"
        pos += size
    assert pos == end, f"carved functions end at {pos:08X}, parent ends at {end:08X}"

    asm = ROOT / "asm" / "nonmatching" / module / f"{parent}.s"
    text = asm.read_text().splitlines(keepends=True)
    label = f"_{first:08X}:"
    cut = next(i for i, l in enumerate(text) if l.strip() == label)
    tail = [l for l in text[cut:] if l.strip() == ".syntax divided"]
    asm.write_text("".join(text[:cut] + tail))

    lines[idx] = f"{paddr:08X}\t{first - paddr:X}\t{parent}\t{module}\n"
    for k, (addr, name, size) in enumerate(new):
        lines.insert(idx + 1 + k, f"{addr:08X}\t{size:X}\t{name}\t{module}\n")
    TSV.write_text("".join(lines))


if __name__ == "__main__":
    main()
