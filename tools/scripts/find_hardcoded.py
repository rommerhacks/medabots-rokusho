#!/usr/bin/env python3
"""List ROM pointers that did not move in the shifted build.

Compares baserom.gba with build/shifted.gba (SHIFT bytes of padding after crt0):
an aligned word that points past crt0 in the original should be SHIFT larger in
the shifted ROM. Words that kept their old value are hardcoded addresses (or data
that merely looks like a pointer).
"""
import bisect
import struct
import sys

shift = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0x1000
crt0_end = 0x25C
base = open('baserom.gba', 'rb').read()
shf = open('build/shifted.gba', 'rb').read()
rom_end = 0x08000000 + len(base)

# symbol lookup from the shifted map, to name where each hit sits
syms = []
for line in open('build/shifted.sym'):
    a, n = line.split()
    a = int(a, 16)
    if 0x08000000 <= a < 0x09000000:
        syms.append((a, n))
syms.sort()
addrs = [a for a, _ in syms]

def where(addr):
    i = bisect.bisect_right(addrs, addr) - 1
    if i < 0:
        return '?'
    return '%s+0x%X' % (syms[i][1], addr - syms[i][0])

for o in range(crt0_end, len(base) - 3, 4):
    v, = struct.unpack_from('<I', base, o)
    if not (0x08000000 + crt0_end <= (v & ~1) < rom_end):
        continue
    s, = struct.unpack_from('<I', shf, o + shift)
    if s == v + shift:
        continue
    tag = 'SAME' if s == v else 'DIFF'
    print('%s %08X %08X -> %08X  %s' % (tag, 0x08000000 + o, v, s, where(0x08000000 + o + shift)))
