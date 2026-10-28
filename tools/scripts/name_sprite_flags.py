#!/usr/bin/env python3
"""Replace numeric SpriteEntry.flags values with SPRITE_FLAG_* expressions.

usage: name_sprite_flags.py   (run from the repo root, then `make compare format`)

Finds the real SpriteEntry.flags accesses by renaming the member in include/structs.h for a moment and
collecting the compiler's "has no member named" errors, so the flags fields of other structs are untouched.
At each access, a plain number after `=`, `|=`, `&=`, `^=`, `&`, `|`, `==` or `!=` becomes named bits
(include/constants/sprites.h). The constant value is unchanged, so the code is too.
"""
import glob
import re
import subprocess

STRUCTS = "include/structs.h"
FLAGS = ["-fsyntax-only", "-I", "include", "-w"]

SINGLE = [
    (0x8000, "SPRITE_FLAG_ENABLED"),
    (0x4000, "SPRITE_FLAG_VISIBLE"),
    (0x2000, "SPRITE_FLAG_VFLIP"),
    (0x1000, "SPRITE_FLAG_HFLIP"),
]
LOW = [
    (0x0200, "SPRITE_FLAG_AFFINE"),
    (0x0100, "SPRITE_FLAG_ROTATE"),
    (0x0020, "SPRITE_FLAG_DOUBLE_SIZE"),
    (0x0004, "SPRITE_FLAG_PART_PALETTE"),
    (0x0002, "SPRITE_FLAG_OFFSCREEN"),
    (0x0001, "SPRITE_FLAG_MOSAIC"),
]
POS = {0x40: "SPRITE_POS_WORLD", 0x80: "SPRITE_POS_PERSPECTIVE", 0xC0: "SPRITE_POS_SHARED_AFFINE"}


def names(v, mask_ctx):
    out = [n for b, n in SINGLE if v & b]
    pri = v & 0xC00
    if pri:
        out.append("SPRITE_FLAG_PRIORITY_MASK" if mask_ctx and pri == 0xC00 else "SPRITE_PRIORITY(%d)" % (pri >> 10))
    out += [n for b, n in LOW if b >= 0x100 and v & b]
    pos = v & 0xC0
    if pos:
        out.append("SPRITE_POS_MASK" if mask_ctx and pos == 0xC0 else POS[pos])
    mode = v & 0x18
    if mode:
        out.append("SPRITE_FLAG_OBJ_MODE_MASK" if mask_ctx and mode == 0x18 else "SPRITE_OBJ_MODE(%d)" % (mode >> 3))
    out += [n for b, n in LOW if b < 0x100 and v & b]
    rest = v & ~0xFFFF
    if rest:
        return None
    return out


def expr(v, op):
    if v == 0 or v > 0xFFFF:
        return None
    mask_ctx = op in ("&", "&=")
    if mask_ctx and bin(v).count("1") > 8:
        inv = names(~v & 0xFFFF, True)
        if not inv:
            return None
        inner = inv[0] if len(inv) == 1 else "(%s)" % " | ".join(inv)
        return "(u16)~" + inner
    out = names(v, mask_ctx)
    if not out:
        return None
    s = " | ".join(out)
    if len(out) > 1 and op in ("&", "|", "==", "!="):
        s = "(%s)" % s
    return s


def find_accesses():
    text = open(STRUCTS).read()
    m = re.search(r"(struct SpriteEntry \{\n(?:.*\n)*?\s*u16 )flags;", text)
    hacked = text[: m.end(1)] + "flags__x;" + text[m.end() :]
    open(STRUCTS, "w").write(hacked)
    hits = {}
    try:
        pat = re.compile(r"^(.*?):(\d+):(\d+): error: .*has no member named 'flags'")
        for src in sorted(glob.glob("src/**/*.c", recursive=True)):
            p = subprocess.run(["arm-none-eabi-gcc"] + FLAGS + [src], capture_output=True, text=True)
            for line in p.stderr.splitlines():
                mm = pat.match(line)
                if mm:
                    hits.setdefault(mm.group(1), set()).add((int(mm.group(2)), int(mm.group(3))))
    finally:
        open(STRUCTS, "w").write(text)
    return hits


LIT = re.compile(r"flags(\s*)(\|=|&=|\^=|==|!=|=(?!=)|&(?![&=])|\|(?![|=]))(\s*)(0x[0-9A-Fa-f]+|\d+)\b(?!\s*[<>*/+-])")


def main():
    total = 0
    for path, locs in sorted(find_accesses().items()):
        lines = open(path).read().split("\n")
        n = 0
        for lineno, col in sorted(locs, reverse=True):
            line = lines[lineno - 1]
            start = line.find("flags", col - 1)
            if start < 0:
                continue
            mm = LIT.match(line, start)
            if not mm:
                continue
            e = expr(int(mm.group(4), 0), mm.group(2))
            if e is None:
                continue
            lines[lineno - 1] = line[: mm.start(4)] + e + line[mm.end(4) :]
            n += 1
        if n:
            text = "\n".join(lines)
            if '#include "constants/sprites.h"' not in text:
                incs = list(re.finditer(r'^#include "[^"]+"\n', text, re.M))
                pos = incs[-1].end() if incs else 0
                text = text[:pos] + '#include "constants/sprites.h"\n' + text[pos:]
            open(path, "w").write(text)
            print(path, n)
            total += n
    print("total", total)


main()
