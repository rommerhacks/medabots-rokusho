#!/usr/bin/env python3
# perm_setup.py FUNC CFILE [OUTDIR] : make OUTDIR/FUNC/ (default scratch/perm/FUNC/) for decomp-permuter
# (https://github.com/simonlindholm/decomp-permuter; run `permuter.py OUTDIR/FUNC -j2 --stop-on-zero`).
# CFILE is a match.py-style file (#include "global.h", DECLS, the function, static inline helpers ok).
# Both target and candidate are linked at FUNC's original address, so pools / bl targets compare as numbers.
import os, re, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
func, cfile = sys.argv[1], os.path.abspath(sys.argv[2])
d = os.path.abspath(os.path.join(sys.argv[3] if len(sys.argv) > 3 else f"{ROOT}/scratch/perm", func))
os.makedirs(d, exist_ok=True)
addr = size = None
for l in open(f"{ROOT}/config/functions.tsv"):
    p = l.rstrip("\n").split("\t")
    if len(p) >= 3 and p[2] == func:
        addr, size = int(p[0], 16), int(p[1], 16)
assert addr
pre = subprocess.check_output(["arm-none-eabi-cpp", "-P", "-nostdinc", "-I", "include", "-I", "tools/agbcc/include",
                               "-undef", cfile], cwd=ROOT, text=True)
pre = "\n".join(l for l in pre.splitlines() if not l.startswith("asm("))
open(f"{d}/base.c", "w").write(pre + "\n")
# target: original bytes as an ELF .text at addr
raw = open(f"{ROOT}/baserom.gba", "rb").read()[addr - 0x08000000: addr - 0x08000000 + size]
open(f"{d}/target.bin", "wb").write(raw)
open(f"{d}/target.s", "w").write(f'.text\n.thumb\n.global {func}\n{func}:\n.incbin "{d}/target.bin"\n')
subprocess.check_call(["arm-none-eabi-as", "-mcpu=arm7tdmi", "-o", f"{d}/t.o", f"{d}/target.s"])
subprocess.check_call(["arm-none-eabi-ld", "-Ttext", hex(addr), "-e", func, "-o", f"{d}/t.elf", f"{d}/t.o"])
subprocess.check_call(["arm-none-eabi-objcopy", "-N", "$d", "-N", "$t", f"{d}/t.elf", f"{d}/target.o"])
open(f"{d}/compile.sh", "w").write(f"""#!/bin/bash
# compile.sh in.c -o out
set -e
IN=$(realpath "$1"); OUT=$(realpath -m "$3")
T=$(mktemp -d)
trap 'rm -rf $T' EXIT
cd {ROOT}
tools/agbcc/bin/agbcc -mthumb-interwork -O2 -fhex-asm -fprologue-bugfix "$IN" -o $T/f.s 2>/dev/null
printf '\\t.text\\n\\t.align\\t2, 0\\n' >> $T/f.s
arm-none-eabi-as -mcpu=arm7tdmi -I include -I . -o $T/f.o $T/f.s
DEFS=""
for n in $(arm-none-eabi-nm -u $T/f.o | awk '{{print $2}}'); do
  if ! grep -qx "$n" {d}/known.txt; then
    a=$(echo $n | grep -oE '_[0-9A-F]{{8}}$' | tr -d _)
    [ -n "$a" ] && DEFS="$DEFS --defsym $n=0x$a"
  fi
done
arm-none-eabi-ld -Ttext {hex(addr)} -R {d}/syms.elf -e {func} -o $T/f.elf $T/f.o $DEFS
arm-none-eabi-objcopy -N '$d' -N '$t' $T/f.elf "$OUT"
""")
os.chmod(f"{d}/compile.sh", 0o755)
# symbols of the full build minus this function
subprocess.check_call(["arm-none-eabi-objcopy", f"{ROOT}/medabots_rokusho.elf", f"{d}/syms.elf", "--strip-symbol", func])
known = subprocess.check_output(["arm-none-eabi-nm", f"{d}/syms.elf"], text=True)
open(f"{d}/known.txt", "w").write("\n".join(l.split()[-1] for l in known.splitlines()) + "\n")
open(f"{d}/settings.toml", "w").write(f'func_name = "{func}"\ncompiler_type = "gcc"\n'
                                     f'objdump_command = "arm-none-eabi-objdump -drz -M force-thumb"\n')
print(d)
