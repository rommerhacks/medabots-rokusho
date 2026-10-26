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
        build/src/engine/main.o(.text);
        build/src/engine/main.o(.rodata);
        build/src/engine/decompress.o(.text);
        build/src/engine/decompress.o(.rodata);
        build/src/engine/bg.o(.text);
        build/src/engine/bg.o(.rodata);
        build/src/engine/math.o(.text);
        build/src/engine/math.o(.rodata);
        build/src/engine/palette.o(.text);
        build/src/engine/palette.o(.rodata);
        build/src/engine/oam.o(.text);
        build/src/engine/oam.o(.rodata);
        build/src/link/serial.o(.text);
        build/src/link/serial.o(.rodata);
        build/src/engine/game_state.o(.text);
        build/src/engine/game_state.o(.rodata);
        build/src/menu/field_menu.o(.text);
        build/src/menu/field_menu.o(.rodata);
        build/src/menu/medawatch_menu.o(.text);
        build/src/menu/medawatch_menu.o(.rodata);
        build/src/menu/medabots_screen.o(.text);
        build/src/menu/medabots_screen.o(.rodata);
        build/src/menu/medals_screen.o(.text);
        build/src/menu/medals_screen.o(.rodata);
        build/src/debug/debug_menu.o(.text);
        build/src/debug/debug_menu.o(.rodata);
        build/src/menu/medaparts_screen.o(.text);
        build/src/menu/medaparts_screen.o(.rodata);
        build/src/battle/prebattle.o(.text);
        build/src/battle/prebattle.o(.rodata);
        build/src/battle/robattle.o(.text);
        build/src/battle/robattle.o(.rodata);
        build/src/battle/battle_bots.o(.text);
        build/src/battle/battle_bots.o(.rodata);
        build/src/battle/battle_hud.o(.text);
        build/src/battle/battle_hud.o(.rodata);
        build/src/battle/command_ring.o(.text);
        build/src/battle/command_ring.o(.rodata);
        build/src/battle/part_select.o(.text);
        build/src/battle/part_select.o(.rodata);
        build/src/battle/medaforce_select.o(.text);
        build/src/battle/medaforce_select.o(.rodata);
        build/src/battle/status_screen.o(.text);
        build/src/battle/status_screen.o(.rodata);
        build/src/battle/battle_setup.o(.text);
        build/src/battle/battle_setup.o(.rodata);
        build/src/battle/robattle_timer.o(.text);
        build/src/battle/robattle_timer.o(.rodata);
        build/src/battle/part_stats.o(.text);
        build/src/battle/part_stats.o(.rodata);
        build/src/battle/bot_movement.o(.text);
        build/src/battle/bot_movement.o(.rodata);
        build/src/battle/status_sprites.o(.text);
        build/src/battle/status_sprites.o(.rodata);
        build/src/battle/action_queue.o(.text);
        build/src/battle/action_queue.o(.rodata);
        build/src/battle/battle_graphics.o(.text);
        build/src/battle/battle_graphics.o(.rodata);
        build/src/battle/turn_order.o(.text);
        build/src/battle/turn_order.o(.rodata);
        build/src/battle/battle_sprites.o(.text);
        build/src/battle/battle_sprites.o(.rodata);
        build/src/battle/action_steps.o(.text);
        build/src/battle/action_steps.o(.rodata);
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
