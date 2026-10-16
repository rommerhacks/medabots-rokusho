#!/usr/bin/env python3
"""Report decompilation progress: functions and code bytes in C vs. still in asm.

Usage: progress.py [--json]
"""
import json, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
done = total = done_b = total_b = 0
for line in open(os.path.join(ROOT, "config", "functions.tsv")):
    p = line.rstrip("\n").split("\t")
    if line.startswith("#") or len(p) < 4 or p[3] == "-":
        continue  # crt0 and SDK libraries (libgcc, EEPROM, syscalls) stay in asm
    size = int(p[1], 16)
    total += 1
    total_b += size
    if not os.path.exists(os.path.join(ROOT, "asm", "nonmatching", p[3], p[2] + ".s")):
        done += 1
        done_b += size
res = {"functions_total": total, "functions_matched": done, "bytes_total": total_b, "bytes_matched": done_b,
       "percent_bytes": round(100 * done_b / total_b, 3), "percent_functions": round(100 * done / total, 3)}
if "--json" in sys.argv:
    print(json.dumps(res))
else:
    print(f"Functions: {done}/{total} ({res['percent_functions']}%)")
    print(f"Code bytes: {done_b:#x}/{total_b:#x} ({res['percent_bytes']}%)")
