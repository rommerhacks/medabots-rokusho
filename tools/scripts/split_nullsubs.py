#!/usr/bin/env python3
"""Split trailing `bx lr` stubs (emitted by gbadisasm as .byte data) into their own nullsub functions."""
import os, re, glob

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
STUB = [0x70, 0x47, 0x00, 0x00]
tsv = [l.rstrip("\n").split("\t") for l in open("config/functions.tsv")]
rows = {r[2]: r for r in tsv if len(r) >= 4}
new_rows = []
count = 0
for path in sorted(glob.glob("asm/nonmatching/*/*.s")):
    module = path.split("/")[2]
    func = os.path.basename(path)[:-2]
    lines = open(path).read().splitlines()
    # trailing block: a "_ADDR:" label followed only by .byte lines (and the closing .syntax divided)
    k = len(lines) - 1
    while k >= 0 and (not lines[k].strip() or lines[k].strip() == ".syntax divided"):
        k -= 1
    j = k
    while j >= 0 and lines[j].lstrip().startswith(".byte"):
        j -= 1
    if j == k or not re.fullmatch(r"_([0-9A-F]{8}):", lines[j]):
        continue
    addr = int(lines[j][1:9], 16)
    data = [int(x, 16) for l in lines[j + 1:k + 1] for x in l.split(".byte")[1].split(",")]
    if addr % 4 or len(data) % 4 or any(data[i:i + 4] != STUB for i in range(0, len(data), 4)):
        continue
    stubs = [addr + i for i in range(0, len(data), 4)]
    open(path, "w").write("\n".join(lines[:j]).rstrip("\n") + "\n\n\t.syntax divided\n")
    mod_path = f"src/{module}.c"
    src = open(mod_path).read()
    inc = f'INCLUDE_ASM("asm/nonmatching/{module}", {func});\n'
    add = "".join(f'INCLUDE_ASM("asm/nonmatching/{module}", nullsub_{a:08X});\n' for a in stubs)
    assert inc in src, (func, mod_path)
    open(mod_path, "w").write(src.replace(inc, inc + add, 1))
    for a in stubs:
        open(f"asm/nonmatching/{module}/nullsub_{a:08X}.s", "w").write(
            f"\t.syntax unified\n\tthumb_func_start nullsub_{a:08X}\nnullsub_{a:08X}: @ 0x{a:08X}\n\tbx lr\n\t.align 2, 0\n\t.syntax divided\n")
        new_rows.append([f"{a:08X}", "4", f"nullsub_{a:08X}", module])
    r = rows[func]
    r[1] = f"{stubs[0] - int(r[0], 16):X}"
    count += len(stubs)
hdr = [l for l in tsv if l[0].startswith("#")]
body = sorted([r for r in tsv if not r[0].startswith("#")] + new_rows, key=lambda r: int(r[0], 16))
open("config/functions.tsv", "w").write("\n".join("\t".join(r) for r in hdr + body) + "\n")
print(f"{count} nullsubs split out")
