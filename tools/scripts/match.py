#!/usr/bin/env python3
"""Check whether a C function compiles to the original bytes, without rebuilding the ROM.

Usage: match.py FUNC FILE.c [--new]

FILE.c is a standalone C file (it may #include "global.h" and other headers) that defines FUNC.
It is compiled like the Makefile does: old_agbcc, or agbcc -fprologue-bugfix for the sound modules (--new: agbcc), linked at FUNC's original address
against the symbols of the last full build (medabots_rokusho.elf, so run `make` once first), and
compared byte for byte with baserom.gba over the original function's size (code and literal pool).

Exit status 0 = match. On mismatch, prints a side-by-side disassembly.
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ELF = os.path.join(ROOT, "medabots_rokusho.elf")
BASEROM = os.path.join(ROOT, "baserom.gba")


def run(cmd, **kw):
    r = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT, **kw)
    if r.returncode:
        sys.stderr.write(r.stdout + r.stderr)
        raise SystemExit(f"command failed: {' '.join(cmd[:3])} ...")
    return r.stdout


# Modules the Makefile builds with agbcc -fprologue-bugfix instead of old_agbcc (keep in sync with SOUND_OBJS)
BUGFIX_MODULES = {"sound_seq", "sound_driver"}


def func_info(name):
    """Original address and size (code + literal pool + padding) from config/functions.tsv."""
    for line in open(os.path.join(ROOT, "config", "functions.tsv")):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 3 and p[2] == name:
            return int(p[0], 16), int(p[1], 16), (p[3] if len(p) > 3 else "")
    raise SystemExit(f"{name}: not in config/functions.tsv")


def disasm(data, addr):
    with tempfile.NamedTemporaryFile(suffix=".bin") as f:
        f.write(data)
        f.flush()
        out = subprocess.run(["arm-none-eabi-objdump", "-D", "-b", "binary", "-m", "armv4t", "-M", "force-thumb",
                              f"--adjust-vma={addr:#x}", f.name], capture_output=True, text=True).stdout
    return [re.sub(r"\s+", " ", l.split(":", 1)[1]).strip() for l in out.splitlines()
            if re.match(r"\s+[0-9a-f]+:", l)]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("func")
    ap.add_argument("cfile")
    ap.add_argument("--new", action="store_true", help="use agbcc instead of old_agbcc")
    ap.add_argument("--old", action="store_true", help="use old_agbcc (default, except for BUGFIX_MODULES)")
    ap.add_argument("--bugfix", action="store_true", help="agbcc -fprologue-bugfix (implies --new)")
    args = ap.parse_args()

    addr, size, module = func_info(args.func)
    if module in BUGFIX_MODULES and not args.new and not args.old:
        args.bugfix = True
    base = open(BASEROM, "rb").read()[addr - 0x08000000: addr - 0x08000000 + size]

    with tempfile.TemporaryDirectory() as tmp:
        i, s, o, elf, binf, syms = (os.path.join(tmp, n) for n in ("f.i", "f.s", "f.o", "f.elf", "f.bin", "syms.elf"))
        run(["arm-none-eabi-cpp", "-nostdinc", "-I", "include", "-I", "tools/agbcc/include", "-undef",
             os.path.abspath(args.cfile), "-o", i])
        cc1 = "tools/agbcc/bin/agbcc" if args.new or args.bugfix else "tools/agbcc/bin/old_agbcc"
        extra = ["-fprologue-bugfix"] if args.bugfix else []
        run([cc1, "-mthumb-interwork", "-Wimplicit", "-Wparentheses", "-O2", "-fhex-asm"] + extra + [i, "-o", s])
        with open(s, "a") as f:
            f.write("\t.text\n\t.align\t2, 0\n")
        run(["arm-none-eabi-as", "-mcpu=arm7tdmi", "-I", "include", "-I", ".", "-o", o, s])
        # symbols of the full build, minus the ones this object defines
        defined = [l.split()[2] for l in run(["arm-none-eabi-nm", "--defined-only", o]).splitlines()
                   if len(l.split()) == 3 and l.split()[1] in "TtDdRrBb" and not l.split()[2].startswith(".")]
        cmd = ["arm-none-eabi-objcopy", ELF, syms]
        for d in defined:
            cmd += ["--strip-symbol", d]
        run(cmd)
        # place the object so that FUNC lands on its original address
        off = next((int(l.split()[0], 16) for l in run(["arm-none-eabi-nm", o]).splitlines()
                    if l.split()[-1] == args.func), None)
        if off is None:
            raise SystemExit(f"{args.func} is not defined in {args.cfile}")
        if addr - off < 0x08000000:
            raise SystemExit(f"{args.func} sits too far into {args.cfile}; put it first")
        run(["arm-none-eabi-ld", "-Ttext", hex(addr - off), "-R", syms, "-e", args.func, "-o", elf, o])
        run(["arm-none-eabi-objcopy", "-O", "binary", "-j", ".text", elf, binf])
        built = open(binf, "rb").read()[off:]
        # only the target function: the object may contain other functions after it
        out = run(["arm-none-eabi-nm", "-S", elf])
        fsize = next((int(l.split()[1], 16) for l in out.splitlines()
                      if l.split()[-1] == args.func and len(l.split()) == 4), len(built))

    built = built[:max(size, fsize)]
    if built[:size] == base and fsize <= size:
        print(f"{args.func}: MATCH ({size:#x} bytes)")
        return 0
    a, b = disasm(built[:max(size, fsize)], addr), disasm(base, addr)
    print(f"{args.func}: MISMATCH (built {fsize:#x} bytes, original {size:#x})")
    w = 44
    for k in range(max(len(a), len(b))):
        x = a[k] if k < len(a) else ""
        y = b[k] if k < len(b) else ""
        mark = "  " if x == y else "!!"
        print(f"{mark} {addr + 2 * k:08X}  {x[:w]:<{w}} | {y[:w]}")
    return 1


if __name__ == "__main__":
    sys.exit(main())
