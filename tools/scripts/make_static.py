#!/usr/bin/env python3
"""Make a module's file-local functions static.

Usage: make_static.py MODULE...

A function becomes static when nothing outside its C file and its own header (include/MODULE.h) names it
(other C files and headers, asm, data stubs, config/data_ptrs pointer tables). Its prototype moves from the
module header into the C file as a static forward declaration when it is used before its definition. Functions the linker still misses are put
back; if make compare then fails, every change is reverted.
"""
import glob
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def files(pattern):
    return [f for f in glob.glob(os.path.join(ROOT, pattern), recursive=True) if os.path.isfile(f)]


def defpat(name):
    return re.compile(r"^((?:[A-Za-z_]\w* )+\**)" + re.escape(name) + r"\(", re.M)


def build():
    r = subprocess.run(["make", "compare"], cwd=ROOT, capture_output=True, text=True)
    return r.returncode == 0, r.stdout + r.stderr


def main():
    others = files("include/**/*.h") + files("asm/**/*.s") + files("data/**/*.s") + files("sound/**/*.s")
    others += files("graphics/**/*.s") + files("config/data_ptrs/*.tsv") + files("src/**/*.c")
    texts = {f: open(f, errors="replace").read() for f in others}
    rows = [l.rstrip("\n").split("\t") for l in open(os.path.join(ROOT, "config", "functions.tsv"))
            if not l.startswith("#")]
    saved, changed = {}, {}
    for mod in sys.argv[1:]:
        cpath = os.path.join(ROOT, "src", mod + ".c")
        hpath = os.path.join(ROOT, "include", mod + ".h")
        src = saved[cpath] = open(cpath).read()
        hdr = open(hpath).read() if os.path.exists(hpath) else ""
        if hdr:
            saved[hpath] = hdr
        fwd = []
        names = []
        for r in rows:
            if r[3] != mod:
                continue
            word = re.compile(r"\b" + re.escape(r[2]) + r"\b")
            if any(word.search(t) for f, t in texts.items() if f not in (cpath, hpath)):
                continue
            m = defpat(r[2]).search(src)
            if not m or m.group(1).startswith("static"):
                continue
            proto = re.search(r"^[^\n;]*\b" + re.escape(r[2]) + r"\([^;]*\);[^\n]*\n", hdr, re.M)
            if proto:
                hdr = hdr[: proto.start()] + hdr[proto.end():]
                if word.search(src[: m.start()]):
                    fwd.append("static " + re.sub(r"\s*//.*", "", proto.group(0)).strip() + "\n")
            src = src[: m.start()] + "static " + src[m.start():]
            names.append(r[2])
        if fwd:
            src = src.replace('#include "global.h"\n', '#include "global.h"\n\n' + "".join(fwd), 1)
        open(cpath, "w").write(src)
        if hdr:
            open(hpath, "w").write(hdr)
        changed[cpath] = names
    ok, out = build()
    missing = set(re.findall(r"undefined reference to `(\w+)'", out))
    if missing:
        for cpath, names in changed.items():
            src = open(cpath).read()
            for n in names:
                if n in missing:
                    src = re.sub(r"^static ((?:[A-Za-z_]\w* )+\**)" + re.escape(n) + r"\(", r"\1" + n + "(", src,
                                 flags=re.M)
            open(cpath, "w").write(src)
            changed[cpath] = [n for n in names if n not in missing]
        ok, out = build()
    if not ok:
        for cpath, src in saved.items():
            open(cpath, "w").write(src)
        print(out[-2000:])
        raise SystemExit("make compare failed: reverted")
    for cpath, names in changed.items():
        print(f"{os.path.relpath(cpath, ROOT)}: {len(names)} static")


if __name__ == "__main__":
    main()
