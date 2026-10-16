# Building

## 1. Dependencies

Linux, WSL, or macOS with:

* `make`, `git`, `python3`, a C compiler (to build agbcc)
* the ARM binutils: `binutils-arm-none-eabi` (Debian/Ubuntu) or devkitARM

```sh
sudo apt install build-essential git python3 binutils-arm-none-eabi gcc-arm-none-eabi
```

## 2. Clone this repository and agbcc

```sh
git clone https://github.com/rommerhacks/medabots-rokusho.git
git clone https://github.com/pret/agbcc.git
cd agbcc
./build.sh
./install.sh ../medabots-rokusho
cd ../medabots-rokusho
```

`install.sh` puts the compiler in `tools/agbcc/`.

## 3. Add your ROM

Copy your dump of the game into the repository as **`baserom.gba`**. It must have
SHA-1 `c4572428ea97b302f699a3b4eba2a1f0e87c1c9c`:

```sh
sha1sum baserom.gba
```

## 4. Build

```sh
make compare
```

This builds `medabots_rokusho.gba` and checks it against the original. A successful build ends with
`medabots_rokusho.gba: OK`. Use `make -j$(nproc) compare` to build faster.
