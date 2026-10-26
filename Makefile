#### Medabots: Rokusho Version (USA) decompilation ####

TITLE     := MEDABOTSRKSV
GAME_CODE := A9BE
ROM       := medabots_rokusho.gba
ELF       := $(ROM:.gba=.elf)
MAP       := $(ROM:.gba=.map)
BUILD_DIR := build

PREFIX  ?= arm-none-eabi-
AS      := $(PREFIX)as
LD      := $(PREFIX)ld
OBJCOPY := $(PREFIX)objcopy
CPP     := $(PREFIX)cpp

AGBCC_DIR := tools/agbcc
# pret agbcc with -fprologue-bugfix (no push {lr} in leaf functions that branch). old_agbcc also
# builds most functions identically, but some (e.g. sub_080518F4) only match agbcc.
CC1       := $(AGBCC_DIR)/bin/agbcc

ASFLAGS  := -mcpu=arm7tdmi -I include -I .
CPPFLAGS := -nostdinc -I include -I $(AGBCC_DIR)/include -undef
CFLAGS   := -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm -fprologue-bugfix

SHA1 := $(shell { command -v sha1sum || command -v shasum; } 2>/dev/null) -c

ASM_SRCS := $(shell find asm data sound graphics -name '*.s' -not -path 'asm/macros*' -not -path 'asm/nonmatching/*')
C_SRCS   := $(shell find src -name '*.c' 2>/dev/null)
OBJS     := $(patsubst %.s,$(BUILD_DIR)/%.o,$(ASM_SRCS)) $(patsubst %.c,$(BUILD_DIR)/%.o,$(C_SRCS))

.PHONY: all compare clean progress shifted format format-check lint
.SECONDARY:
.SECONDEXPANSION:

all: $(ROM)

compare: $(ROM)
	@$(SHA1) rom.sha1

progress:
	@python3 tools/scripts/progress.py --json

clean:
	rm -rf $(BUILD_DIR) $(ROM) $(ELF) $(MAP)

baserom.gba:
	$(error baserom.gba is missing. Copy your own dump of the game (see INSTALL.md) to baserom.gba)

# Data files .incbin from baserom.gba
$(BUILD_DIR)/data/%.o $(BUILD_DIR)/sound/%.o $(BUILD_DIR)/graphics/%.o: | baserom.gba

$(BUILD_DIR)/%.o: %.s asm/macros.inc asm/macros/function.inc baserom.gba
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) -o $@ $<

# Data stubs: labels and .incbin from baserom.gba. The pointer words inside them are listed in
# config/data_ptrs/<dir>_<stub>.tsv and rendered as `.4byte symbol` so they move with the code and data.
STUB_SRCS := $(filter data/% sound/% graphics/%,$(ASM_SRCS))
STUB_OBJS := $(patsubst %.s,$(BUILD_DIR)/%.o,$(STUB_SRCS))

$(patsubst %.s,$(BUILD_DIR)/%.s,$(STUB_SRCS)): $(BUILD_DIR)/%.s: %.s $$(wildcard config/data_ptrs/$$(subst /,_,$$*).tsv) tools/scripts/label_data.py
	@mkdir -p $(@D)
	python3 tools/scripts/label_data.py --render $< $@

$(STUB_OBJS): $(BUILD_DIR)/%.o: $(BUILD_DIR)/%.s baserom.gba
	$(AS) $(ASFLAGS) -o $@ $<

# C: cpp -> agbcc -> as (the trailing .align keeps each object's size a multiple of 4, like the original link)
$(BUILD_DIR)/src/%.o: src/%.c $(shell find include -name '*.h') $$(wildcard asm/nonmatching/$$*/*.s)
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o $(BUILD_DIR)/src/$*.i
	$(CC1) $(CFLAGS) $(BUILD_DIR)/src/$*.i -o $(BUILD_DIR)/src/$*.s
	printf '\t.text\n\t.align\t2, 0\n' >> $(BUILD_DIR)/src/$*.s
	$(AS) $(ASFLAGS) -o $@ $(BUILD_DIR)/src/$*.s

$(ELF): ld_script.ld symbols.ld $(OBJS)
	$(LD) -T ld_script.ld -Map $(MAP) -o $@ --no-check-sections

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

# Shifted build: SHIFT bytes of padding after crt0 move all game code and data. A ROM address
# hardcoded anywhere breaks it; the walkthrough tests run on it. build/shifted.sym lists the symbols.
SHIFT ?= 0x1000

shifted: $(BUILD_DIR)/shifted.gba

$(BUILD_DIR)/ld_script_shifted.ld: ld_script.ld
	@mkdir -p $(@D)
	sed 's|^\([[:space:]]*\)build/asm/crt0.o(.text);|&\n\1. = . + $(SHIFT);|' $< > $@

$(BUILD_DIR)/shifted.elf: $(BUILD_DIR)/ld_script_shifted.ld symbols.ld $(OBJS)
	$(LD) -T $< -Map $(BUILD_DIR)/shifted.map -o $@ --no-check-sections

$(BUILD_DIR)/shifted.gba: $(BUILD_DIR)/shifted.elf
	$(OBJCOPY) -O binary $< $@
	$(PREFIX)nm -n $< | awk '$$1 ~ /^0[0-9a-f]+$$/ && $$3 !~ /^\$$/ {print toupper($$1), $$3}' > $(BUILD_DIR)/shifted.sym

# Code standard: clang-format (config/clang-format.yml) and a syntax check with a modern compiler, so every call
# goes through a real prototype.
FORMAT_SRCS := $(shell find src include -name '*.c' -o -name '*.h')
LINT_FLAGS  := -fsyntax-only -I include -Wall -Werror=implicit-function-declaration -Werror=implicit-int \
               -Werror=return-type -Werror=incompatible-pointer-types

format:
	clang-format --style=file:config/clang-format.yml -i $(FORMAT_SRCS)

format-check:
	clang-format --style=file:config/clang-format.yml --dry-run --Werror $(FORMAT_SRCS)

lint:
	@status=0; for f in $(C_SRCS); do $(PREFIX)gcc $(LINT_FLAGS) $$f || status=1; done; exit $$status
