#!/usr/bin/env python3
"""One-time generator (already run; rerunning overwrites src/ and decompiled work).

Split gbadisasm output into per-region asm files and write data incbin files + linker script.

Usage: split_asm.py DISASM.s OUTDIR

The ROM is cut into regions (see REGIONS). Code regions are further split into chunks of
roughly CHUNK bytes at 4-byte aligned function starts. Labels referenced from another file
are made .global. Data regions become `.incbin "baserom.gba"` files.
"""
import os
import re
import sys
from collections import defaultdict

BASE = 0x08000000
ROM_END = 0x08800000
CHUNK = 0x4000

# (start, end, kind, path) -- kind: code (split into chunks), asm (single file), data (incbin)
REGIONS = [
    (0x08000000, 0x0800025C, "asm", "asm/crt0.s"),
    (0x0800025C, 0x080730FC, "code", "code"),
    (0x080730FC, 0x080750D8, "code", "sound_driver"),
    (0x080750D8, 0x0807C740, "data", "data/rodata_080750D8.s"),
    (0x0807C740, 0x0807CB50, "asm", "asm/lib/eeprom.s"),
    (0x0807CB50, 0x0807CB80, "asm", "asm/lib/syscall.s"),
    (0x0807CB80, 0x0807CBBC, "asm", "asm/lib/call_via.s"),
    (0x0807CBBC, 0x0807E6F0, "asm", "asm/lib/libgcc.s"),
    (0x0807E6F0, 0x08080000, "data", "data/data_0807E6F0.s"),
    (0x08080000, 0x080AB000, "data", "data/data_08080000.s"),
    (0x080AB000, 0x083AB9D0, "data", "sound/sound_data.s"),
    (0x083AB9D0, 0x08480000, "data", "data/data_083AB9D0.s"),
    (0x08480000, 0x08590000, "data", "data/data_08480000.s"),
    (0x08590000, 0x087F3270, "data", "graphics/graphics_08590000.s"),
    (0x087F3270, ROM_END, "data", "data/free_087F3270.s"),
]

HEADER = '\t.include "asm/macros.inc"\n\n\t.syntax unified\n\n\t.text\n\n'

ADDR_RE = re.compile(r"@ 0x([0-9A-F]{8})\s*$")
LABEL_DEF_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
SYM_RE = re.compile(r"\b(_[0-9A-F]{8}|[A-Za-z][A-Za-z0-9_]*_[0-9A-F]{8}|sub_[0-9A-F]{8})\b")


def parse_blocks(lines):
    """Group lines into blocks starting at each label definition; yield (addr, lines)."""
    blocks = []
    cur_addr, cur = 0x08000000, []
    pending = []  # lines before a label (func_start macro, blank lines) belong to that label
    for line in lines:
        m = LABEL_DEF_RE.match(line)
        if m:
            addr = label_addr(line, m.group(1))
            if addr is not None:
                if cur:
                    blocks.append((cur_addr, cur))
                cur_addr, cur = addr, pending + [line]
                pending = []
                continue
        if line.strip().startswith(("thumb_func_start", "arm_func_start", "non_word_aligned_thumb_func_start")) or (
                not line.strip() and pending):
            pending.append(line)
            continue
        if not line.strip():
            pending.append(line)
            continue
        cur += pending + [line]
        pending = []
    if cur:
        blocks.append((cur_addr, cur + pending))
    return blocks


def label_addr(line, name):
    m = ADDR_RE.search(line)
    if m:
        return int(m.group(1), 16)
    m = re.fullmatch(r"_([0-9A-F]{8})", name)
    if m:
        return int(m.group(1), 16)
    return None


def main():
    src, outdir = sys.argv[1], sys.argv[2]
    lines = open(src).read().splitlines()
    blocks = parse_blocks(lines)
    func_starts = set()
    for addr, blk in blocks:
        if any("func_start" in l for l in blk):
            func_starts.add(addr)

    files = []  # (path, start, end, kind)
    for start, end, kind, path in REGIONS:
        if kind == "code":
            cuts = [start]
            for a in sorted(func_starts):
                if start < a < end and a % 4 == 0 and a - cuts[-1] >= CHUNK:
                    cuts.append(a)
            cuts.append(end)
            for s, e in zip(cuts, cuts[1:]):
                name = path if len(cuts) == 2 else f"{path}_{s:08X}"
                files.append((f"src/{name}.c", s, e, "module"))
        else:
            files.append((path, start, end, kind))

    # assign blocks to files
    content = defaultdict(list)
    defs = {}
    for addr, blk in blocks:
        for path, s, e, kind in files:
            if s <= addr < e:
                if kind in ("asm", "module"):
                    content[path].append((addr, blk))
                    for l in blk:
                        m = LABEL_DEF_RE.match(l)
                        if m:
                            defs[m.group(1)] = path
                break

    # find cross-file references
    need_global = set()
    for path, ls in content.items():
        for l in (x for _, blk in ls for x in blk):
            if LABEL_DEF_RE.match(l) and ":" in l.split("@")[0] and not l.split(":", 1)[1].strip().split("@")[0].strip():
                continue
            code = l.split("@")[0]
            for sym in SYM_RE.findall(code):
                if sym in defs and defs[sym] != path:
                    need_global.add(sym)
            # also full names via .4byte / bl
            for tok in re.findall(r"\b[A-Za-z_][A-Za-z0-9_]*\b", code):
                if tok in defs and defs[tok] != path:
                    need_global.add(tok)

    ld_objs = []
    for path, s, e, kind in files:
        full = os.path.join(outdir, path)
        os.makedirs(os.path.dirname(full), exist_ok=True)
        with open(full, "w") as f:
            if kind == "data":
                f.write(f"\t.section .rodata\n\n")
                f.write(f"\t.global gData_{s:08X}\ngData_{s:08X}:\n")
                f.write(f'\t.incbin "baserom.gba", 0x{s - BASE:X}, 0x{e - s:X}\n')
            elif kind == "module":
                write_module(outdir, path, content[path], need_global, f)
            else:
                f.write(HEADER)
                body = [x for _, blk in content[path] for x in blk]
                if path == "asm/crt0.s":
                    # the cartridge header (logo, title, checksum) is copied from baserom.gba at build time
                    i = body.index("_08000004:")
                    j = i + 1
                    while body[j].lstrip().startswith(".byte"):
                        j += 1
                    body[i + 1:j] = ['\t.incbin "baserom.gba", 0x4, 0xBC  @ cartridge header']
                for l in body:
                    m = LABEL_DEF_RE.match(l)
                    if m and m.group(1) in need_global and not any("func_start" in x for x in []):
                        f.write(f"\t.global {m.group(1)}\n")
                    f.write(l + "\n")
                if path == "asm/lib/libgcc.s":
                    # 10 bytes of padding/data after the last libgcc routine
                    f.write('\n\t.incbin "baserom.gba", 0x7E6E6, 0xA\n')
        ld_objs.append((path, kind))

    with open(os.path.join(outdir, "ld_script.ld"), "w") as f:
        f.write(LD_HEAD)
        for path, kind in ld_objs:
            obj = "build/" + os.path.splitext(path)[0] + ".o"
            sect = ".rodata" if kind == "data" else ".text"
            f.write(f"        {obj}({sect});\n")
            if kind == "module":
                f.write(f"        {obj}(.rodata);\n")
        f.write(LD_TAIL)
    print(f"{len(files)} files, {len(need_global)} labels made global", file=sys.stderr)


def write_module(outdir, path, blocks, need_global, f):
    """Write src/<module>.c as INCLUDE_ASM lines, one asm/nonmatching/<module>/<func>.s per function."""
    module = os.path.splitext(os.path.basename(path))[0]
    funcs = []  # (name, lines)
    for addr, blk in blocks:
        start = next((l for l in blk if "func_start" in l), None)
        if start is not None or not funcs:
            name = start.split()[1] if start else f"sub_{addr:08X}"
            funcs.append((name, []))
        funcs[-1][1].extend(blk)
    asm_dir = os.path.join(outdir, "asm", "nonmatching", module)
    os.makedirs(asm_dir, exist_ok=True)
    f.write('#include "global.h"\n\n')
    for name, lines in funcs:
        with open(os.path.join(asm_dir, name + ".s"), "w") as af:
            af.write("\t.syntax unified\n")
            for l in lines:
                m = LABEL_DEF_RE.match(l)
                if m and m.group(1) in need_global:
                    af.write(f"\t.global {m.group(1)}\n")
                af.write(l + "\n")
            af.write("\t.syntax divided\n")
        f.write(f'INCLUDE_ASM("asm/nonmatching/{module}", {name});\n')


LD_HEAD = """OUTPUT_ARCH(arm)
ENTRY(crt0_start)

MEMORY
{
    EWRAM (rwx) : ORIGIN = 0x2000000, LENGTH = 256K
    IWRAM (rwx) : ORIGIN = 0x3000000, LENGTH = 32K
    ROM    (rx) : ORIGIN = 0x8000000, LENGTH = 32M
}

INCLUDE symbols.ld

SECTIONS {
    . = 0x8000000;

    .rom 0x8000000 :
    ALIGN(4)
    {
"""

LD_TAIL = """    } > ROM =0

    /DISCARD/ :
    {
        *(.comment .note .ARM.attributes)
    }
}
"""

if __name__ == "__main__":
    main()
