OUTPUT_ARCH(arm)
ENTRY(crt0_start)

MEMORY
{
    EWRAM (rwx) : ORIGIN = 0x2000000, LENGTH = 256K
    IWRAM (rwx) : ORIGIN = 0x3000000, LENGTH = 32K
    ROM    (rx) : ORIGIN = 0x8000000, LENGTH = 32M
}

INCLUDE symbols.ld

SECTIONS {
    . = 0x8000000;

    .rom 0x8000000 :
    ALIGN(4)
    {
        build/asm/crt0.o(.text);
        build/src/code_0800025C.o(.text);
        build/src/code_0800025C.o(.rodata);
        build/src/code_080043A8.o(.text);
        build/src/code_080043A8.o(.rodata);
        build/src/code_08008430.o(.text);
        build/src/code_08008430.o(.rodata);
        build/src/code_0800C6D8.o(.text);
        build/src/code_0800C6D8.o(.rodata);
        build/src/code_08010794.o(.text);
        build/src/code_08010794.o(.rodata);
        build/src/code_080147FC.o(.text);
        build/src/code_080147FC.o(.rodata);
        build/src/code_08018900.o(.text);
        build/src/code_08018900.o(.rodata);
        build/src/code_0801C988.o(.text);
        build/src/code_0801C988.o(.rodata);
        build/src/code_080209B0.o(.text);
        build/src/code_080209B0.o(.rodata);
        build/src/code_080249C0.o(.text);
        build/src/code_080249C0.o(.rodata);
        build/src/code_08028A00.o(.text);
        build/src/code_08028A00.o(.rodata);
        build/src/code_0802CA5C.o(.text);
        build/src/code_0802CA5C.o(.rodata);
        build/src/code_08030CAC.o(.text);
        build/src/code_08030CAC.o(.rodata);
        build/src/code_08034CB8.o(.text);
        build/src/code_08034CB8.o(.rodata);
        build/src/code_08038D30.o(.text);
        build/src/code_08038D30.o(.rodata);
        build/src/code_0803CDCC.o(.text);
        build/src/code_0803CDCC.o(.rodata);
        build/src/code_08040EE4.o(.text);
        build/src/code_08040EE4.o(.rodata);
        build/src/code_08044F54.o(.text);
        build/src/code_08044F54.o(.rodata);
        build/src/code_080490C4.o(.text);
        build/src/code_080490C4.o(.rodata);
        build/src/code_0804D10C.o(.text);
        build/src/code_0804D10C.o(.rodata);
        build/src/code_0805137C.o(.text);
        build/src/code_0805137C.o(.rodata);
        build/src/code_080567AC.o(.text);
        build/src/code_080567AC.o(.rodata);
        build/src/code_0805AB40.o(.text);
        build/src/code_0805AB40.o(.rodata);
        build/src/code_0805EE6C.o(.text);
        build/src/code_0805EE6C.o(.rodata);
        build/src/code_08063090.o(.text);
        build/src/code_08063090.o(.rodata);
        build/src/code_08067160.o(.text);
        build/src/code_08067160.o(.rodata);
        build/src/code_0806B160.o(.text);
        build/src/code_0806B160.o(.rodata);
        build/src/code_0806F3F0.o(.text);
        build/src/code_0806F3F0.o(.rodata);
        build/src/audio/sound_seq.o(.text);
        build/src/audio/sound_seq.o(.rodata);
        build/src/audio/sound_driver.o(.text);
        build/src/audio/sound_driver.o(.rodata);
        build/data/rodata_080750D8.o(.rodata);
        build/asm/lib/eeprom.o(.text);
        build/asm/lib/syscall.o(.text);
        build/asm/lib/call_via.o(.text);
        build/asm/lib/libgcc.o(.text);
        build/data/data_0807E6F0.o(.rodata);
        build/data/data_08080000.o(.rodata);
        build/sound/sound_data.o(.rodata);
        build/data/data_083AB9D0.o(.rodata);
        build/data/data_08480000.o(.rodata);
        build/graphics/graphics_08590000.o(.rodata);
        build/data/free_087F3270.o(.rodata);
    } > ROM =0

    /DISCARD/ :
    {
        *(.comment .note .ARM.attributes)
    }
}
