# Clean-room policy

This repository contains original source reconstructions written by observing the game's behavior and machine
code, and from public community documentation. It does not contain, and must never contain:

- ROMs or any part of them as binaries, saves or savestates;
- game assets: graphics, audio, text, tilemaps, or data tables dumped as bytes. These are read from your own
  `baserom.gba` at build time;
- leaked or proprietary material: SDK source, official headers, leaked symbol maps or documents.

Names and types are our own. A name is used once its purpose has been confirmed from the code or at runtime;
until then the function keeps its `sub_XXXXXXXX` name, with a `// guess:` comment for a likely purpose. A byte
match verifies compiler output only. It doesn't prove the original source, names or structure.
