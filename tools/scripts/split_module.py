#!/usr/bin/env python3
"""Split C modules at function boundaries, or join adjacent ones (ROM order is kept either way).

  split_module.py split SRC FUNC NEW   everything in src/SRC.c from FUNC's definition (and the comment above
                                       it) to the end moves to the new file src/NEW.c, linked right after SRC
  split_module.py join A B             src/B.c (linked right after A) is appended to src/A.c and removed

The module column of config/functions.tsv and ld_script.ld follow. Prototypes stay in include/functions.h
(move_module.py moves them to a module header). Run make compare afterwards.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
HEAD = '#include "global.h"\n'


def path(*p):
    return os.path.join(ROOT, *p)


def rows():
    return open(path("config", "functions.tsv")).read().splitlines(keepends=True)


def set_module(pred, new):
    out = []
    for r in rows():
        p = r.rstrip("\n").split("\t")
        if len(p) >= 4 and not r.startswith("#") and pred(p):
            p[3] = new
            r = "\t".join(p) + "\n"
        out.append(r)
    open(path("config", "functions.tsv"), "w").write("".join(out))


def ld_objs(text, mod):
    return f"        build/src/{mod}.o(.text);\n        build/src/{mod}.o(.rodata);\n"


def split(src, func, new):
    lines = open(path("src", src + ".c")).read().splitlines(keepends=True)
    pat = re.compile(r"^(?!static inline)[A-Za-z_].*\b" + re.escape(func) + r"\s*\(")
    idx = next(i for i, l in enumerate(lines) if pat.match(l) and not l.rstrip().endswith(";"))
    while idx > 0 and lines[idx - 1].startswith("//"):
        idx -= 1
    head, tail = lines[:idx], lines[idx:]
    while tail and not tail[0].strip():
        tail.pop(0)
    os.makedirs(os.path.dirname(path("src", new + ".c")), exist_ok=True)
    open(path("src", src + ".c"), "w").write("".join(head).rstrip("\n") + "\n")
    open(path("src", new + ".c"), "w").write(HEAD + "\n" + "".join(tail))
    subprocess.check_call(["git", "add", f"src/{new}.c"], cwd=ROOT)

    ld = open(path("ld_script.ld")).read()
    old = ld_objs(ld, src)
    ld = ld.replace(old, old + ld_objs(ld, new))
    open(path("ld_script.ld"), "w").write(ld)

    start = next(int(r.split("\t")[0], 16) for r in rows() if r.split("\t")[2:3] == [func])
    set_module(lambda p: p[3] == src and int(p[0], 16) >= start, new)


def join(a, b):
    ta = open(path("src", a + ".c")).read()
    tb = open(path("src", b + ".c")).read()
    if tb.startswith(HEAD):
        tb = tb[len(HEAD):]
    open(path("src", a + ".c"), "w").write(ta.rstrip("\n") + "\n\n" + tb.lstrip("\n"))
    subprocess.check_call(["git", "rm", "-qf", f"src/{b}.c"], cwd=ROOT)
    ld = open(path("ld_script.ld")).read()
    ld = ld.replace(ld_objs(ld, b), "")
    open(path("ld_script.ld"), "w").write(ld)
    set_module(lambda p: p[3] == b, a)


def main():
    if sys.argv[1] == "split":
        split(*sys.argv[2:5])
    elif sys.argv[1] == "join":
        join(*sys.argv[2:4])
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main()
