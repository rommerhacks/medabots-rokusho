#!/usr/bin/env python3
"""Find the Thumb function pointers inside the data stubs and list them in config/data_ptrs/ (rendered
as `.4byte function_name` by the build).

A word is taken as a function pointer when it is 4-byte aligned, equals the start of a Thumb function
from config/functions.tsv plus 1, and sits next to another pointer (a ROM or RAM address), as in the
handler tables. The sound and graphics stubs are left alone (their matches are noise in sample and
tile data). Re-running is safe: words already converted are skipped.

    python3 tools/scripts/data_func_ptrs.py [--dry-run]
"""
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from label_data import ROOT, load_stubs, save_stubs  # noqa: E402

STUBS = ["data/data_0807E6F0.s", "data/data_083AB9D0.s", "data/data_08480000.s"]


def is_pointer(v):
    return 0x08000000 <= v < 0x08800000 or 0x02000000 <= v < 0x02040000 or 0x03000000 <= v < 0x03008000


def main():
    dry = "--dry-run" in sys.argv
    rom = (ROOT / "baserom.gba").read_bytes()
    funcs = {}
    for line in (ROOT / "config/functions.tsv").read_text().splitlines():
        if line.startswith("#") or not line.strip():
            continue
        addr, size, name = line.split("\t")[:3]
        funcs[int(addr, 16)] = name
    arm = set()
    for p in (ROOT / "asm").rglob("*.s"):
        arm |= set(re.findall(r"arm_func_start (\w+)", p.read_text()))

    stubs = load_stubs()
    added = 0
    for rel in STUBS:
        header, start, end, labels, ptrs = stubs[ROOT / rel]
        inner = {o for o in labels if o & 3}
        for off in range((start + 3) & ~3, end - 3, 4):
            if off in ptrs or any(off < o < off + 4 for o in inner):
                continue
            v = struct.unpack_from("<I", rom, off)[0]
            name = funcs.get(v - 1)
            if not (v & 1) or name is None or name in arm:
                continue
            prev = struct.unpack_from("<I", rom, off - 4)[0]
            nxt = struct.unpack_from("<I", rom, off + 4)[0]
            if not (is_pointer(prev) or is_pointer(nxt)):
                continue
            ptrs[off] = name
            added += 1
    print(f"{added} function pointers")
    if not dry:
        save_stubs(stubs)


if __name__ == "__main__":
    main()
