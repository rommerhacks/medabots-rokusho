#!/usr/bin/env python3
"""Try C variants of a function inside its own module (agbcc output depends on the file context).

    tryin.py FUNC VARIANTS.c [N]

VARIANTS.c holds one or more definitions of FUNC separated by lines "----". Each one in turn
replaces FUNC's INCLUDE_ASM line in src/<module>.c, the module is compiled and compared with
match.py, and the module is restored afterwards. With N, the full diff of variant N is printed.
Run `make` once first (match.py links against the last full build).
"""
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    func, vfile = sys.argv[1:3]
    show = int(sys.argv[3]) if len(sys.argv) > 3 else None
    module = None
    for line in open(os.path.join(ROOT, "config", "functions.tsv")):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 4 and p[2] == func:
            module = p[3]
    path = os.path.join(ROOT, "src", module + ".c")
    base = open(path).read()
    inc = f'INCLUDE_ASM("asm/nonmatching/{module}", {func});\n'
    if inc not in base:
        raise SystemExit(f"{func}: not INCLUDE_ASM'd in {path}")
    try:
        for i, v in enumerate(open(vfile).read().split("----\n")):
            open(path, "w").write(base.replace(inc, v + "\n"))
            r = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "scripts", "match.py"), func, path],
                               cwd=ROOT, capture_output=True, text=True)
            out = r.stdout + r.stderr
            ok = "MATCH (" in out and "MISMATCH" not in out
            print(i, "MATCH" if ok else f"{out.count('!!')} diff lines" + ("" if "!!" in out else ": " + out.strip().splitlines()[-1]))
            if show == i:
                print(out)
    finally:
        open(path, "w").write(base)


if __name__ == "__main__":
    main()
