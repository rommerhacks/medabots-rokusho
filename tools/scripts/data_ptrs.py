#!/usr/bin/env python3
"""Find the ROM data pointers inside the data stubs and list them in config/data_ptrs/ (rendered as
`.4byte label` / `.4byte label+0xN` by the build).

data_func_ptrs.py already handles pointers to functions; this one handles pointers to data, so the
tables move with the data in the shifted build. A raw .incbin word cannot be told apart from a pointer
for sure, so the rules are heuristic and per area:

- Table areas (rodata_080750D8, data_0807E6F0, data_08080000, the sound tables before the note table
  at 0x080B1788, and 0x083AB9D0-0x08488B44): an aligned word whose value points into data (or is a
  function start) is a pointer when
    * it targets an existing label, or a function with a pointer next to it, or
    * a neighbouring word is a pointer too and neither is made of small bytes (0x0808xxxx-like
      tile or map data), or
    * the same field repeats at a fixed stride (records) and the target is 4-aligned, or
    * it is isolated but targets a 4-aligned address in the same stub less than 0x8000 bytes away.
- Sound sequences (0x080B1788-0x080C5000): the note table, the song / sound effect headers (one
  pointer per set bit of the 12-bit track mask) and the operands of the 0xF4 jump / 0xF5 call
  opcodes (unaligned).
- Everything from 0x08488B44 on (compressed graphics, tilemaps, the graphics stub) only matches by
  accident and is left alone.

    python3 tools/scripts/data_ptrs.py [--dry-run] [--list]
"""
import bisect
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from label_data import ROOT, load_stubs, save_stubs  # noqa: E402

ROM = 0x08000000
CODE = [(0x0800025C, 0x080750D8), (0x0807C740, 0x0807E6F0)]
TABLE_AREAS = [(0x080750D8, 0x0807C740), (0x0807E6F0, 0x080B1788), (0x083AB9D0, 0x08488B44)]
SONG_TABLE_AREA = (0x080AFFB8, 0x080B1788)
NOTE_TABLE = 0x080B1788
SONG_TABLES = [0x080AFFB8, 0x080B06EC]  # set by AgbMain via sound_set_song_table / sound_set_se_table
SEQ_AREA = (0x080B1788, 0x080C5000)
SOUND_END = 0x083AB9D0
DATA_END = 0x08800000


def in_ranges(a, ranges):
    return any(lo <= a < hi for lo, hi in ranges)


def small(v):
    return all(((v >> s) & 0xFF) < 0x10 for s in (0, 8, 16))


def main():
    dry = "--dry-run" in sys.argv
    rom = (ROOT / "baserom.gba").read_bytes()
    word = lambda a: struct.unpack_from("<I", rom, a - ROM)[0]  # noqa: E731

    funcs = {}
    for line in (ROOT / "config/functions.tsv").read_text().splitlines():
        if line.startswith("#") or not line.strip():
            continue
        addr, _size, name = line.split("\t")[:3]
        funcs[int(addr, 16)] = name

    arm = set()
    for p in (ROOT / "asm").rglob("*.s"):
        arm |= set(re.findall(r"arm_func_start (\w+)", p.read_text()))

    stubs = load_stubs()
    # every label in the stubs, by ROM address, with the stub it belongs to
    stub_list = []
    labels = {}
    for path, (header, start, end, labs, ptrs) in stubs.items():
        stub_list.append((ROM + start, ROM + end, path))
        for off, names in labs.items():
            labels.setdefault(ROM + off, names[0])
    stub_list.sort()
    taken = set()  # offsets already holding a symbolic pointer
    for path, (header, start, end, labs, ptrs) in stubs.items():
        for off in ptrs:
            taken.update(range(off, off + 4))

    def stub_of(a):
        for lo, hi, path in stub_list:
            if lo <= a < hi:
                return path
        return None

    stub_labels = {}
    for path, (header, start, end, labs, ptrs) in stubs.items():
        stub_labels[path] = sorted((ROM + o, n[0]) for o, n in labs.items())

    def target_symbol(v):
        """Symbol expression for the ROM address v, or None when v is not a valid target."""
        if in_ranges(v & ~1, CODE):
            if v & 1 and (v - 1) in funcs:
                return funcs[v - 1]
            if not v & 1 and funcs.get(v) in arm:
                return funcs[v]
            return None
        if not (CODE[0][1] <= v < DATA_END):
            return None
        path = stub_of(v)
        if path is None:
            return None
        labs = stub_labels[path]
        i = bisect.bisect_right(labs, (v, "\x7f")) - 1
        if i < 0:
            return None
        base, name = labs[i]
        return name if base == v else f"{name}+0x{v - base:X}"

    def exact(v):
        return (v & 1 and (v - 1) in funcs) or (not v & 1 and funcs.get(v) in arm) or v in labels

    found = {}  # ROM address of the word -> symbol expression

    # table areas
    cand = {}
    for lo, hi in TABLE_AREAS:
        for a in range((lo + 3) & ~3, hi - 3, 4):
            if a - ROM in taken:
                continue
            v = word(a)
            if not (ROM <= v < DATA_END):
                continue
            sym = target_symbol(v)
            # sound sequences and samples are only reached from the sound tables
            if sym is not None and not (SEQ_AREA[0] <= v < SOUND_END and not a < SOUND_END):
                cand[a] = (v, sym)
    big = {a for a, (v, sym) in cand.items() if not small(v)}
    for a, (v, sym) in cand.items():
        run = (a - 4) in cand or (a + 4) in cand
        per = any(((a + s) in big and (a + 2 * s) in big) or ((a - s) in big and (a - 2 * s) in big)
                  or ((a - s) in big and (a + s) in big) for s in range(8, 0x400, 4))
        ok = v in labels or (exact(v) and run)
        song = SONG_TABLE_AREA[0] <= a < SONG_TABLE_AREA[1]
        ok = ok or (((a - 4) in big or (a + 4) in big) and a in big)
        # record fields at a fixed stride: aligned targets only (or sound headers), and not the
        # `08 xx 08` byte pairs of the script data
        ok = ok or (per and a in big and (v % 4 == 0 or song) and ((v & 0xFF) != 0x08 or abs(v - a) < 0x1000))
        ok = ok or (run and song)
        ok = ok or (not run and not per and v % 4 == 0 and abs(v - a) < 0x8000 and stub_of(v) == stub_of(a))
        if ok:
            found[a] = sym

    # sound: note table, song headers, sequence jumps
    def sound_ptr(a):
        v = word(a)
        sym = target_symbol(v)
        if sym is not None and a - ROM not in taken:
            found[a] = sym
            return v
        return None

    count = struct.unpack_from("<H", rom, NOTE_TABLE - ROM)[0]
    for i in range(count + 1):
        sound_ptr(NOTE_TABLE + 4 + 4 * i)
    for table in SONG_TABLES:
        a = table
        while True:
            v = word(a)
            if not (SONG_TABLE_AREA[0] <= v < SEQ_AREA[1]) or (a != table and a in labels):
                break
            sound_ptr(a)
            mask = struct.unpack_from("<H", rom, v - ROM)[0]
            for n in range(bin(mask & 0xFFF).count("1")):
                sound_ptr(v + 4 + 4 * n)
            a += 4
    for p in range(SEQ_AREA[0] - ROM, SEQ_AREA[1] - ROM):
        if rom[p] in (0xF4, 0xF5):
            v = struct.unpack_from("<I", rom, p + 1)[0]
            if SEQ_AREA[0] <= v < SEQ_AREA[1] and abs(v - (ROM + p)) < 0x10000:
                if not any(q in taken for q in range(p + 1, p + 5)):
                    found[ROM + p + 1] = target_symbol(v)

    # drop overlapping hits (keep the first) and words with a label inside them
    last = -8
    for a in sorted(found):
        if a < last + 4 or any((a + k) in labels for k in (1, 2, 3)):
            del found[a]
        else:
            last = a

    if "--list" in sys.argv:
        for a in sorted(found):
            print(f"{a:08X} {word(a):08X} {found[a]}")
    print(f"{len(found)} data pointers")
    if dry:
        return
    for a, sym in found.items():
        path = stub_of(a)
        stubs[path][4][a - ROM] = sym
    save_stubs(stubs)


if __name__ == "__main__":
    main()
