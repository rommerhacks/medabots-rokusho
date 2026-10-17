#!/usr/bin/env python3
"""Split a scratch C file with several functions into one file per function.

Usage: split_scratch.py FILE.c OUTDIR

Everything before the first function definition is the shared header. Each function gets
OUTDIR/<name>.c with the header, prototypes of the other functions (taken from their
definition lines) and its own body, so match.py links calls to the others at their
original addresses.
"""
import os
import re
import sys

src = open(sys.argv[1]).read()
out = sys.argv[2]
os.makedirs(out, exist_ok=True)
# A definition starts at column 0 with "type name(args)" followed by a line "{".
pat = re.compile(r"^((?:static\s+)?[A-Za-z_][\w\s\*]*?\b(\w+)\s*\([^;{]*\))\s*\n\{", re.M)
ms = list(pat.finditer(src))
if not ms:
    raise SystemExit("no functions found")
header = src[:ms[0].start()]
funcs = []
for i, m in enumerate(ms):
    end = ms[i + 1].start() if i + 1 < len(ms) else len(src)
    funcs.append((m.group(2), m.group(1), src[m.start():end]))
for name, sig, body in funcs:
    protos = "".join(f"{s};\n" for n, s, _ in funcs if n != name and not s.startswith("static"))
    with open(os.path.join(out, name + ".c"), "w") as f:
        f.write(header + protos + "\n" + body)
    print(name)
