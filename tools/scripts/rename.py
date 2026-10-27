#!/usr/bin/env python3
"""Rename symbols across the repo (whole-word, every tracked text file).

usage: rename.py OLD NEW [OLD NEW ...]
       rename.py -f pairs.txt      (one "OLD NEW" pair per line, '#' comments)

Touches sources, headers, asm/data stubs, symbols.ld and config/ (functions.tsv, the Ghidra cfg and the
data_ptrs tables), so a renamed function or global stays consistent everywhere. Refuses a NEW name that
already exists. Run `make compare` afterwards.
"""
import re
import subprocess
import sys


def load_pairs(argv):
    if argv[:1] == ["-f"]:
        pairs = []
        for line in open(argv[1]):
            line = line.split("#", 1)[0].split()
            if line:
                pairs.append((line[0], line[1]))
        return pairs
    if len(argv) % 2 or not argv:
        sys.exit(__doc__)
    return list(zip(argv[::2], argv[1::2]))


def main():
    pairs = load_pairs(sys.argv[1:])
    files = subprocess.run(["git", "ls-files"], capture_output=True, text=True, check=True).stdout.split()
    texts = {}
    for path in files:
        try:
            texts[path] = open(path, encoding="utf-8").read()
        except (UnicodeDecodeError, IsADirectoryError, FileNotFoundError):
            continue
    for old, new in pairs:
        if any(re.search(r"\b%s\b" % re.escape(new), t) for t in texts.values()):
            sys.exit("%s already exists" % new)
    for path, text in texts.items():
        orig = text
        for old, new in pairs:
            text = re.sub(r"\b%s\b" % re.escape(old), new, text)
        if text != orig:
            open(path, "w", encoding="utf-8").write(text)
            print("updated", path)


if __name__ == "__main__":
    main()
