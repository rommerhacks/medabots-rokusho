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

.PHONY: all compare clean progress
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

$(BUILD_DIR)/data/%.o: data/%.s baserom.gba
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/sound/%.o: sound/%.s baserom.gba
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/graphics/%.o: graphics/%.s baserom.gba
	@mkdir -p $(@D)
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
