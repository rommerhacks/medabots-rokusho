#!/usr/bin/env python3
"""Move a C module to its system folder and give it a header.

Usage: move_module.py OLD NEW ["one-line description"]
  e.g. move_module.py sound_seq audio/sound_seq "Sound sequencer: ..."

- git mv src/OLD.c src/NEW.c (OLD may equal NEW to only split out the header);
- the object in ld_script.ld and the module column of config/functions.tsv follow;
- the prototypes of the module's functions move from include/functions.h to include/NEW.h
  (include guard GUARD_<NEW>_H), which functions.h then includes.
Run make compare afterwards.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def path(*p):
    return os.path.join(ROOT, *p)


def split_decls(text):
    """Split header text into top-level chunks: comments/blank lines kept as-is, declarations up to ';'."""
    chunks, cur = [], []
    for line in text.splitlines(keepends=True):
        code = re.sub(r"//.*", "", line).strip()
        if not cur and (not code or code.startswith("#")):
            chunks.append(line)
            continue
        cur.append(line)
        if code.endswith(";"):
            chunks.append("".join(cur))
            cur = []
    if cur:
        chunks.append("".join(cur))
    return chunks


def decl_name(chunk):
    code = re.sub(r"//.*", "", chunk)
    m = re.match(r"[^(;{]*?\b(\w+)\s*\(", code.strip(), re.S)
    if m and code.strip().endswith(";") and not code.lstrip().startswith(("typedef", "#", "extern")):
        return m.group(1)
    return None


def main():
    old, new = sys.argv[1], sys.argv[2]
    desc = sys.argv[3] if len(sys.argv) > 3 else ""
    if old != new:
        os.makedirs(os.path.dirname(path("src", new + ".c")), exist_ok=True)
        subprocess.check_call(["git", "mv", f"src/{old}.c", f"src/{new}.c"], cwd=ROOT)
        ld = open(path("ld_script.ld")).read()
        ld = ld.replace(f"build/src/{old}.o(", f"build/src/{new}.o(")
        open(path("ld_script.ld"), "w").write(ld)

    names = set()
    rows = open(path("config", "functions.tsv")).read().splitlines(keepends=True)
    for i, r in enumerate(rows):
        p = r.rstrip("\n").split("\t")
        if len(p) >= 4 and p[3] == old:
            names.add(p[2])
            p[3] = new
            rows[i] = "\t".join(p) + "\n"
    open(path("config", "functions.tsv"), "w").write("".join(rows))

    fh = open(path("include", "functions.h")).read()
    keep, moved = [], []
    for c in split_decls(fh):
        (moved if decl_name(c) in names else keep).append(c)
    guard = "GUARD_" + re.sub(r"\W", "_", new).upper() + "_H"
    inc = f'#include "{new}.h"\n'
    fh = "".join(keep)
    if inc not in fh:
        fh = fh.replace("\n#endif // GUARD_FUNCTIONS_H", "\n" + inc + "\n#endif // GUARD_FUNCTIONS_H")
        fh = re.sub(r"\n\n(#include \"[^\"]+\.h\"\n)\n#include", r"\n\n\1#include", fh)
    open(path("include", "functions.h"), "w").write(fh)

    hdr = path("include", new + ".h")
    if os.path.exists(hdr):
        h = open(hdr).read().replace(f"\n#endif // {guard}", "".join(moved) + f"\n#endif // {guard}")
    else:
        os.makedirs(os.path.dirname(hdr), exist_ok=True)
        top = f"// {desc}\n\n" if desc else ""
        h = f"#ifndef {guard}\n#define {guard}\n\n{top}" + "".join(moved) + f"\n#endif // {guard}\n"
    open(hdr, "w").write(h)
    print(f"{old} -> {new}: {len(moved)} prototypes to include/{new}.h, {len(names) - len(moved)} without one")


if __name__ == "__main__":
    main()
