#!/usr/bin/env python3
"""Show where the built ROM differs from baserom.gba, with Thumb disassembly of both sides.

Usage: romdiff.py [built.gba] [baserom.gba] [-n BYTES]
"""
import argparse, os, subprocess, tempfile

ap = argparse.ArgumentParser()
ap.add_argument("built", nargs="?", default="medabots_rokusho.gba")
ap.add_argument("base", nargs="?", default="baserom.gba")
ap.add_argument("-n", type=lambda s: int(s, 0), default=0x40)
args = ap.parse_args()
a, b = open(args.built, "rb").read(), open(args.base, "rb").read()
if len(a) != len(b):
    print(f"size differs: built {len(a):#x} base {len(b):#x}")
n = min(len(a), len(b))
d = next((i for i in range(n) if a[i] != b[i]), None)
if d is None:
    print("identical" if len(a) == len(b) else "identical up to the shorter length")
    raise SystemExit(0 if len(a) == len(b) else 1)
ndiff = sum(1 for i in range(n) if a[i] != b[i])
start = max(0, (d & ~1) - 0x10)
print(f"first difference at 0x{0x08000000 + d:08X} ({ndiff} bytes differ in total)")
for label, data in (("built", a), ("base", b)):
    with tempfile.NamedTemporaryFile(suffix=".bin") as f:
        f.write(data[start:start + args.n]); f.flush()
        out = subprocess.run(["arm-none-eabi-objdump", "-D", "-b", "binary", "-m", "armv4t", "-M", "force-thumb",
                              f"--adjust-vma={0x08000000 + start:#x}", f.name], capture_output=True, text=True).stdout
    print(f"--- {label}")
    print("\n".join(l for l in out.splitlines() if l.startswith(" ") and ":" in l))
