#!/usr/bin/env python3
"""Report decompilation progress: functions and code bytes in C vs. still in asm.

Usage: progress.py [--json]
"""
import glob, json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

# Functions finished as equivalent C under #ifdef NONMATCHING (INCLUDE_ASM in the #else): still asm in the
# default build, reported separately.
nonmatching = set()
for c in glob.glob(os.path.join(ROOT, "src", "*.c")):
    for m in re.finditer(r"#ifdef NONMATCHING\b(.*?)#endif", open(c).read(), re.S):
        nonmatching.update(re.findall(r"INCLUDE_ASM\([^,]+,\s*(\w+)\)", m.group(1)))

done = total = done_b = total_b = nm = nm_b = 0
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
    elif p[2] in nonmatching:
        nm += 1
        nm_b += size
res = {"functions_total": total, "functions_matched": done, "bytes_total": total_b, "bytes_matched": done_b,
       "functions_nonmatching": nm, "bytes_nonmatching": nm_b,
       "percent_bytes": round(100 * done_b / total_b, 3), "percent_functions": round(100 * done / total, 3)}
if "--json" in sys.argv:
    print(json.dumps(res))
else:
    print(f"Functions: {done}/{total} ({res['percent_functions']}%)")
    print(f"Code bytes: {done_b:#x}/{total_b:#x} ({res['percent_bytes']}%)")
