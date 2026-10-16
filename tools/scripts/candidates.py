#!/usr/bin/env python3
"""List functions still in asm/nonmatching/, easiest first, to pick the next batch.

Usage: candidates.py [--module M] [--leaf] [--max-size N] [--coverage FILE] [--scene S] [-n N]

For each function: size, number of calls (bl), jump tables / loops, and (with --coverage, a JSON file
mapping function names to the scenes that ran them: {"functions": {name: [scene, ...]}}) the scenes
it runs in. Sorted by: leaf functions first, then size. --scene keeps functions that run in scene S.
"""
import argparse
import json
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module")
    ap.add_argument("--leaf", action="store_true", help="only functions without calls")
    ap.add_argument("--max-size", type=lambda s: int(s, 0), default=None)
    ap.add_argument("--coverage")
    ap.add_argument("--scene")
    ap.add_argument("-n", type=int, default=40)
    a = ap.parse_args()

    scenes = {}
    if a.coverage:
        scenes = json.load(open(a.coverage)).get("functions", {})

    rows = []
    for line in open(os.path.join(ROOT, "config", "functions.tsv")):
        p = line.rstrip("\n").split("\t")
        if line.startswith("#") or len(p) < 4 or p[3] == "-":
            continue
        addr, size, name, module = int(p[0], 16), int(p[1], 16), p[2], p[3]
        if a.module and module != a.module:
            continue
        path = os.path.join(ROOT, "asm", "nonmatching", module, name + ".s")
        if not os.path.exists(path):
            continue
        text = open(path).read()
        calls = len(re.findall(r"\bbl\s", text))
        loops = len(re.findall(r"\b(?:b|b\w\w)\s+_0", text))
        if a.leaf and calls:
            continue
        if a.max_size and size > a.max_size:
            continue
        tags = scenes.get(name, [])
        if a.scene and a.scene not in tags:
            continue
        rows.append((calls > 0, size, addr, name, module, calls, loops, tags))

    rows.sort()
    for _, size, addr, name, module, calls, branches, tags in rows[:a.n]:
        print(f"{addr:08X}  {size:#6x}  {name:40} {module:16} calls={calls:<3} branches={branches:<3} {','.join(tags)}")
    print(f"# {len(rows)} functions")


if __name__ == "__main__":
    main()
