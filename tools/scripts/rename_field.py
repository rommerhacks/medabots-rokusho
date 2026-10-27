#!/usr/bin/env python3
"""Rename struct fields, only where the compiler says the access is to that struct.

usage: rename_field.py STRUCT OLD NEW [OLD NEW ...]
       rename_field.py -f pairs.txt   (lines "STRUCT OLD NEW", '#' comments)

Renames the member in the struct's definition (include/structs.h or any header), then runs
arm-none-eabi-gcc -fsyntax-only over src/*.c and fixes each "'struct S' has no member named 'OLD'"
error at the column it reports, until none are left. Accesses with the same field name on other
structs are untouched. Comments elsewhere are not updated. Run `make compare` afterwards.
"""
import collections
import glob
import re
import subprocess
import sys

FLAGS = ["-fsyntax-only", "-I", "include", "-w"]


def load(argv):
    if argv[:1] == ["-f"]:
        out = []
        for line in open(argv[1]):
            words = line.split("#", 1)[0].split()
            if words:
                out.append(tuple(words))
        return out
    if len(argv) < 3 or len(argv) % 2 == 0:
        sys.exit(__doc__)
    return [(argv[0], argv[i], argv[i + 1]) for i in range(1, len(argv), 2)]


def rename_in_definition(struct, old, new):
    for path in glob.glob("include/**/*.h", recursive=True):
        text = open(path).read()
        m = re.search(r"^struct %s \{\n(.*?)^\};" % re.escape(struct), text, re.S | re.M)
        if not m:
            continue
        body = m.group(1)
        lines = body.split("\n")
        hit = False
        for i, line in enumerate(lines):
            code, sep, comment = line.partition("//")
            new_code = re.sub(r"\b%s\b" % re.escape(old), new, code)
            if new_code != code:
                hit = True
                lines[i] = new_code + sep + comment
        if not hit:
            sys.exit("%s.%s not found in %s" % (struct, old, path))
        text = text[: m.start(1)] + "\n".join(lines) + text[m.end(1) :]
        open(path, "w").write(text)
        return
    sys.exit("struct %s not found" % struct)


def fix_errors(renames):
    srcs = sorted(glob.glob("src/**/*.c", recursive=True))
    pat = re.compile(r"^(.*?):(\d+):(\d+): error: '(?:struct|union) (\w+)'.*? has no member named '(\w+)'")
    for _ in range(50):
        fixes = collections.defaultdict(set)
        for src in srcs:
            r = subprocess.run(["arm-none-eabi-gcc"] + FLAGS + [src], capture_output=True, text=True)
            for line in r.stderr.splitlines():
                m = pat.match(line)
                if m and (m.group(4), m.group(5)) in renames:
                    fixes[m.group(1)].add((int(m.group(2)), int(m.group(3)), renames[(m.group(4), m.group(5))], m.group(5)))
        if not fixes:
            return
        for path, items in fixes.items():
            lines = open(path).read().split("\n")
            # right to left so earlier columns stay valid
            for ln, col, new, old in sorted(items, key=lambda t: (t[0], -t[1])):
                s = lines[ln - 1]
                idx = col - 1
                if s[idx : idx + len(old)] != old:
                    # gcc may point at the '.'/'->' or the start of the expression: find the next OLD
                    m = re.compile(r"\b%s\b" % re.escape(old)).search(s, idx)
                    if not m:
                        sys.exit("%s:%d: can't find %s" % (path, ln, old))
                    idx = m.start()
                lines[ln - 1] = s[:idx] + new + s[idx + len(old) :]
            open(path, "w").write("\n".join(lines))
            print("fixed %d in %s" % (len(items), path))
    sys.exit("gave up after 50 passes")


def main():
    triples = load(sys.argv[1:])
    renames = {}
    for struct, old, new in triples:
        rename_in_definition(struct, old, new)
        renames[(struct, old)] = new
    fix_errors(renames)


if __name__ == "__main__":
    main()
