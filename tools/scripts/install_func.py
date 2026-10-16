#!/usr/bin/env python3
"""Move a matched function from a scratch C file into its module and delete its asm.

Usage: install_func.py FUNC FILE.c [--no-compare]

Run tools/scripts/match.py first. FILE.c must define FUNC; the definition (from the line that
starts its signature to the closing brace in column 0) replaces the module's INCLUDE_ASM line.
Declarations it needs must already be in include/ (functions.h, variables.h, ...).
Afterwards `make compare` runs; if the ROM no longer matches, everything is put back.
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def extract(src, func):
    lines = src.splitlines()
    for i, l in enumerate(lines):
        if re.match(rf"^[A-Za-z_].*\b{re.escape(func)}\s*\(", l) and not l.rstrip().endswith(";"):
            j = i
            while j < len(lines) and lines[j] != "}":
                j += 1
            if j == len(lines):
                break
            return "\n".join(lines[i:j + 1])
    raise SystemExit(f"no definition of {func} in the file")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("func")
    ap.add_argument("cfile")
    ap.add_argument("--no-compare", action="store_true")
    args = ap.parse_args()

    body = extract(open(args.cfile).read(), args.func)
    module = None
    for line in open(os.path.join(ROOT, "config", "functions.tsv")):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 4 and p[2] == args.func:
            module = p[3]
    if not module or module == "-":
        raise SystemExit(f"{args.func}: no C module in config/functions.tsv")
    mod_path = os.path.join(ROOT, "src", module + ".c")
    asm_path = os.path.join(ROOT, "asm", "nonmatching", module, args.func + ".s")
    old_mod = open(mod_path).read()
    inc = f'INCLUDE_ASM("asm/nonmatching/{module}", {args.func});\n'
    if inc not in old_mod:
        raise SystemExit(f"{args.func}: not INCLUDE_ASM'd in {mod_path}")
    new_mod = old_mod.replace(inc, "\n" + body + "\n\n", 1)
    new_mod = re.sub(r"\n{3,}", "\n\n", new_mod)
    old_asm = open(asm_path).read()

    open(mod_path, "w").write(new_mod)
    os.remove(asm_path)
    if args.no_compare:
        return 0
    r = subprocess.run(["make", "-j2", "compare"], cwd=ROOT, capture_output=True, text=True)
    if r.returncode == 0:
        print(f"{args.func}: installed in src/{module}.c, ROM still matches")
        return 0
    open(mod_path, "w").write(old_mod)
    open(asm_path, "w").write(old_asm)
    sys.stderr.write((r.stdout + r.stderr)[-3000:])
    print(f"{args.func}: make compare failed, reverted", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
