#!/usr/bin/env python3
"""List a module's functions in ROM order with the evidence for where the original translation units end.

Usage: module_cuts.py (MODULE | --from ADDR --to ADDR) [--coverage ../re/decomp/coverage.json] [--window N]

Per function: name, size, scene tags (coverage), and the "cut" score before it: the number of direct calls
(bl) crossing the boundary between it and the previous function, counting only callers/callees within
--window functions. Units call their own static helpers, so low scores mark candidate boundaries;
a change of scene tags or naming theme next to a low score is the strongest hint.
"""
import argparse
import json
import os
import struct

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module", nargs="?")
    ap.add_argument("--from", dest="lo", type=lambda x: int(x, 16))
    ap.add_argument("--to", dest="hi", type=lambda x: int(x, 16))
    ap.add_argument("--coverage", default=os.path.join(ROOT, "..", "re", "decomp", "coverage.json"))
    ap.add_argument("--window", type=int, default=40)
    a = ap.parse_args()
    rom = open(os.path.join(ROOT, "baserom.gba"), "rb").read()
    funcs = []
    for line in open(os.path.join(ROOT, "config", "functions.tsv")):
        if line.startswith("#"):
            continue
        p = line.rstrip("\n").split("\t")
        funcs.append((int(p[0], 16), int(p[1], 16), p[2], p[3]))
    starts = {f[0]: i for i, f in enumerate(funcs)}
    tags = {}
    if os.path.exists(a.coverage):
        tags = json.load(open(a.coverage)).get("functions", {})

    # direct calls: Thumb bl pairs (0xF000 high, 0xF800 low)
    edges = []
    for i, (addr, size, _, _) in enumerate(funcs):
        off = addr - 0x08000000
        for o in range(off, off + size - 2, 2):
            hi, lo = struct.unpack_from("<HH", rom, o)
            if hi & 0xF800 == 0xF000 and lo & 0xF800 == 0xF800:
                d = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
                if d & 0x400000:
                    d -= 0x800000
                t = 0x08000000 + o + 4 + d
                if t in starts:
                    edges.append((i, starts[t]))

    idx = [i for i, f in enumerate(funcs) if f[3] == a.module or a.module is None and a.lo <= f[0] < a.hi]
    for i in idx:
        cut = sum(1 for s, t in edges if min(s, t) < i <= max(s, t) and abs(s - t) <= a.window)
        out = sum(1 for s, t in edges if s == i and abs(s - t) > a.window)
        addr, size, name, _ = funcs[i]
        sc = ",".join(sorted(x.split("_", 1)[0] for x in tags.get(name, [])))
        print(f"{cut:3d} {addr:08X} {size:5X} {name:48} {funcs[i][3]:18} far={out:<2} {sc}")


if __name__ == "__main__":
    main()
