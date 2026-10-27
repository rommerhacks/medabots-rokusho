// Battle action step handlers. gBattleMessageSteps is one long table of step lists; each runner (battle_message_show
// for messages, target_panels_show, miss_popup_run ...) calls entry [step] of its own sub-table and the handlers
// advance the step counter. Then come the runners of script opcodes 0x04-0x09 and 0x19-0x1A (trap_hit_run ...
// closeup_enter_run; their order in an attack was seen at runtime) and of opcodes 0x1E-0x24 (gUnk_083AF000):
// attack_hit_run (0x1E: the hit itself, with its miss / nullified / absorbed branches), status_attack_run (0x1F:
// Bug, Thunder, Wave, Fire... status skills), closeup_exit_run (0x20), bot_defeat_run (0x21: "A's function ceased"),
// reaction_run (0x22), sacrifice_run (0x23: Sacrifice breaks the attacker's part) and destroy_check_run (0x24:
// Destroy needs a target facing away). The list continues in defend_heal_skills.c.
// Called from the battle action state code (state 8) and the action script commands (state 9).

#include "global.h"

// Hidden function (no callers): remaps the record's unkE0 through gUnk_083AD3F9.
void sub_0801C0A0(u32 rec) {
    gUnk_03000590[rec].unkE0 = gUnk_083AD3F9[gUnk_03000590[rec].unkE0];
}

// The battle message runner: open the window, print message msg, finish; 1 when done.
u32 battle_message_show(u32 msg) {
    gUnk_03001800.unkA1[1] = msg;
    gBattleMessageSteps[gUnk_03001800.unkA1[0]]();
    if (gUnk_03001800.unkA1[0] == 3) {
        gUnk_03001800.unkA1[0] = 0;
        return 1;
    }
    return 0;
}

void battle_message_step_open(void) {
    battle_message_open();
    gUnk_03001800.unkA1[0]++;
}

void battle_message_step_print(void) {
    if (battle_message_print(gUnk_03001800.unkA1[1]))
        gUnk_03001800.unkA1[0]++;
}

void battle_message_step_finish(void) {
    if (battle_message_finish())
        gUnk_03001800.unkA1[0]++;
}

// The "MISS!!" popup (seen at runtime in the battle scenario): load its graphics, spawn it above the acting
// Medabot, let it drop 4 px, hold it 60 frames (A skips); 1 when done.
u32 miss_popup_run(void) {
    gMissPopupSteps[gUnk_03001800.unk9C[0]]();
    if (gUnk_03001800.unk9C[0] == 4) {
        gUnk_03001800.unk9C[0] = 0;
        return 1;
    }
    return 0;
}

void miss_popup_load(void) {
    lz_decompress_dispatch(gUnk_084C8AC4, (void *)0x06014E00);
    CpuFastSet(gUnk_084E3078, (void *)0x050002C0, 8);
    gUnk_03001800.unk9C[0]++;
}

void miss_popup_spawn(void) {
    gSpriteEntries[3].unk0 = 0xC004;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[3].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 12;
    gSpriteEntries[3].unkA = 6;
    gSpriteEntries[3].unk6 = 0xA11;
    gSpriteEntries[3].unkB = 0x81;
    play_sound_effect(0x2F);
    gUnk_03001800.unk9C[0]++;
}

void miss_popup_drop(void) {
    if (gFrameCounter & 1) {
        gSpriteEntries[3].unk4++;
        if (gSpriteEntries[3].unk4 == gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 4) {
            gUnk_03001800.unk9C[1] = 0;
            gUnk_03001800.unk9C[0]++;
        }
    }
}

void miss_popup_wait(void) {
    gUnk_03001800.unk9C[1]++;
    if (gUnk_03000440.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1))
        gUnk_03001800.unk9C[1] = 60;
    if (gUnk_03001800.unk9C[1] == 60) {
        clear_battle_sprite_slot(3, 1);
        gUnk_03001800.unk9C[0]++;
    }
}

// Shows who acts on whom: a pointer line from the acting Medabot (unk87) and its panel; with show_target != 0
// the arrows then run to the target's (unk88) panel. 1 once the panels are up (the last step idles).
u32 target_panels_show(u32 show_target) {
    gUnk_03001800.unk9C[1] = show_target;
    gTargetPanelSteps[gUnk_03001800.unk9C[0]]();
    if (gUnk_03001800.unk9C[2] != 0)
        return 1;
    return 0;
}

void target_panels_line_init(void) {
    CpuFastSet(gUnk_084E2EF8, (void *)0x05000300, 8);
    bot_pointer_line_init(gUnk_03001800.unk87);
    gUnk_03001800.unk9C[0]++;
}

void target_panels_line_extend(void) {
    if (bot_pointer_line_extend(gUnk_03001800.unk87))
        gUnk_03001800.unk9C[0]++;
}

void target_panels_actor_frame(void) {
    bot_pointer_line_animate(gUnk_03001800.unk87);
    draw_bot_panel_frame(gUnk_03001800.unk87);
    gUnk_03001800.unk9C[0]++;
}

void target_panels_actor_panel(void) {
    bot_pointer_line_animate(gUnk_03001800.unk87);
    render_bot_name_sprites(gUnk_03001800.unk87);
    draw_bot_status_panel(gUnk_03001800.unk87);
    if (gUnk_03001800.unk9C[1] == 0) {
        gUnk_03001800.unk9C[2] = 1;
        gUnk_03001800.unk9C[0]++;
    } else
        gUnk_03001800.unk9C[0] = 5;
}

void target_panels_idle(void) {
    bot_pointer_line_animate(gUnk_03001800.unk87);
}

void target_panels_arrows_init(void) {
    CpuFastSet(gUnk_084E2F18, (void *)0x05000320, 8);
    bot_pointer_line_animate(gUnk_03001800.unk87);
    target_arrows_init(gUnk_03001800.unk87);
    gUnk_03001800.unk9C[0]++;
}

void target_panels_arrows_slide(void) {
    bot_pointer_line_animate(gUnk_03001800.unk87);
    if (target_arrows_slide(gUnk_03001800.unk87))
        gUnk_03001800.unk9C[0]++;
}

void target_panels_target_frame(void) {
    bot_pointer_line_animate(gUnk_03001800.unk87);
    target_arrows_animate(gUnk_03001800.unk87);
    draw_bot_panel_frame(gUnk_03001800.unk88);
    gUnk_03001800.unk9C[0]++;
}

void target_panels_target_panel(void) {
    bot_pointer_line_animate(gUnk_03001800.unk87);
    target_arrows_animate(gUnk_03001800.unk87);
    render_bot_name_sprites(gUnk_03001800.unk88);
    draw_bot_status_panel(gUnk_03001800.unk88);
    gUnk_03001800.unk9C[2] = 1;
    gUnk_03001800.unk9C[0]++;
}

void target_panels_arrows_idle(void) {
    bot_pointer_line_animate(gUnk_03001800.unk87);
    target_arrows_animate(gUnk_03001800.unk87);
}

// Script opcode 0x04: a trap (Grap Trap / Shot Trap / Attack Clr) laid on the acting Medabot's side by the other side
// (trap_apply, unk28[side]) springs on it. unkAB = 0 the action goes on, 1 it was stopped (Attack Clr), 2 the
// actor's head broke.
void trap_hit_run(void) {
    gUnk_03001800.unkB5 = 0;
    gTrapHitSteps[gUnk_03001800.unkAA]();
}

// Does the trap catch this action? Grap Trap (0xA) catches part kinds 0-1, Shot Trap (0xB) kinds 2-3, Attack Clr
// (0xC) any attack; type 0x5A (unk51 3) is the trap a Medaforce lays
// (medaforce_effects). unkA6 = the "Caught in a ..."
// message. Bit 1 of the actor's unkC0, or a part with skill 0x15 (combat_helpers), keeps it out.
void trap_hit_check(void) {
    struct Unk_03001800 *b;
    u32 r;
    u32 type;
    u32 k;

    if (gUnk_03000590[(b = &gUnk_03001800)->unk87].unkC0 & 2)
        goto fail;
    r = sub_08034F44(b->unk87);
    if (r != 0)
        goto fail;
    type = b->unk28[b->unk89].skill;
    if (type == 0xA) {
        k = gUnk_03000590[b->unk87].parts[gUnk_03000590[b->unk87].unkDD - 1].data[2];
        if (k == 0)
            goto okA;
        if (k != 1)
            goto fail;
    okA:
        b->unkA6 = 0xE;
        b->unk51 = r;
        b->unkAA++;
    } else if (type == 0xB) {
        k = gUnk_03000590[b->unk87].parts[gUnk_03000590[b->unk87].unkDD - 1].data[2];
        if (k == 2)
            goto okB;
        if (k != 3)
            goto fail;
    okB:
        b->unkA6 = 0xF;
        b->unk51 = 1;
        b->unkAA++;
    } else if (type == 0xC) {
        if (gUnk_03000590[b->unk87].parts[gUnk_03000590[b->unk87].unkDD - 1].data[2] > 3)
            goto fail;
        b->unkA6 = 0x10;
        b->unk51 = 2;
        b->unkAA++;
    } else if (type == 0x5A) {
        if (gUnk_03000590[b->unk87].parts[gUnk_03000590[b->unk87].unkDD - 1].data[2] > 3)
            goto fail;
        b->unkA6 = 0x11;
        b->unk51 = 3;
        b->unkAA++;
    } else {
    fail:
        b->unkAA = 0x2D;
    }
}

// The trap hits the actor's last part with armor left (legs first) for the trap's stored power.
void trap_hit_calc_damage(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (gUnk_03000590[gUnk_03001800.unk87].parts[i].unk11) {
            gUnk_03001800.unkD0 = i;
            break;
        }
    }
    battle_set_damage_vs_armor(gUnk_03001800.unk87, gUnk_03001800.unkD0,
                               gUnk_03001800.unk28[gUnk_03001800.unk89].power);
    gUnk_03001800.unkAA++;
}

void trap_hit_load_graphics(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084C907C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E058, (void *)0x050002C0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9288, (void *)0x06014800);
        CpuFastSet(gUnk_0850E078, (void *)0x050002C0, 8);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084C9624, (void *)0x06014800);
        CpuFastSet(gUnk_0850E098, (void *)0x050002C0, 8);
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084C978C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E0B8, (void *)0x050002C0, 8);
        break;
    }
    gUnk_03001800.unkAA++;
}

void trap_hit_sprite_spawn(void) {
    gSpriteEntries[0x21].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | -0x3DFC;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk9 = 0x40;
    if (gUnk_03001800.unk89 == 0) {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2 = 0x68;
    } else
        gSpriteEntries[0x21].unk2 = 0x88;
    switch (gUnk_03001800.unk51) {
    case 0:
        gSpriteEntries[0x21].unkB = 5;
        gSpriteEntries[0x21].unk8 = 8;
        gSpriteEntries[0x21].unk4 = 0x3C;
        gUnk_03001800.unk52 = 0x19;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x19], 0x21);
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA++;
        break;
    case 1:
        gSpriteEntries[0x21].unkB = 5;
        gSpriteEntries[0x21].unk8 = 8;
        gSpriteEntries[0x21].unk4 = 0x3C;
        gUnk_03001800.unk52 = 0x1A;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1A], 0x21);
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA++;
        break;
    case 2:
        gSpriteEntries[0x21].unkB = 0xF0;
        gSpriteEntries[0x21].unk8 = 0x40;
        gSpriteEntries[0x21].unk4 = -0x2C;
        gSpriteEntries[0x21].unk6 = 0xD00;
        gSpriteEntries[0x21].unk24 = 8;
        gSpriteEntries[0x21].unk25 = 0;
        gSpriteEntries[0x21].unk30 = 0;
        play_sound_effect(0x61);
        gUnk_03001800.unkAA = 0x10;
        break;
    case 3:
        gSpriteEntries[0x21].unkB = 0xF0;
        gSpriteEntries[0x21].unk8 = 0x40;
        gSpriteEntries[0x21].unk4 = -0x2C;
        gSpriteEntries[0x21].unk6 = 0xE00;
        gSpriteEntries[0x21].unk20 = 0;
        gSpriteEntries[0x21].unk24 = 8;
        gSpriteEntries[0x21].unk25 = 0;
        gSpriteEntries[0x21].unk30 = 0;
        play_sound_effect(0x61);
        gUnk_03001800.unkAA = 0x10;
        break;
    }
}

void trap_hit_sprite_grow(void) {
    if ((gSpriteEntries[0x21].unk8 += 8) == 0x40) {
        if (gUnk_03001800.unkAA < 0x20)
            play_sound_effect(0x3F);
        gUnk_03001800.unkAA++;
    }
}

void trap_hit_sprite_animate(void) {
    set_target_sprite_position(gUnk_03001800.unk87, gFrameCounter, gUnk_03001800.unk51);
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03001800.unk52], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        update_target_cursor_position(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    }
}

void trap_hit_sprite_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
    }
}

void trap_hit_damage_popup_init(void) {
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 1);
    battle_number_popup_init_slot(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x21);
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void trap_hit_damage_popup_wait(void) {
    battle_popup_update_slot(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x21);
    if (++gUnk_03000440.unk84, gUnk_03000440.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk87 * 4 + 0x21, 4);
        gUnk_03001800.unkAA++;
    }
}

// Message 0x12: "Medapart <kind> received <n> damage".
void trap_hit_damage_message(void) {
    memcpy_bytes_0803F63C(gPartKindNames[gUnk_03001800.unkD0], gUnk_03000440.unk9E, 0xE);
    divide_by_100000_b(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkC8, 0x35);
    gUnk_03001800.unkA6 = 0x12;
    gUnk_03001800.unkAA++;
}

void trap_hit_apply_damage(void) {
    reduce_bot_part_stat(gUnk_03001800.unk87, gUnk_03001800.unkD0, gUnk_03001800.unkC8);
    gUnk_03001800.unkAA++;
}

// Message 0x13 "<kind> Medapart broke" and the break effect if the part broke.
void trap_hit_check_part_broken(void) {
    if (gUnk_03001800.unkD1) {
        play_sound_effect(0x3B);
        bot_halve_broken_leg_stats(gUnk_03001800.unk87);
        gUnk_03001800.unkA6 = 0x13;
        gUnk_03001800.unkAA = 0x1A;
    } else {
        gUnk_03001800.unkAA = 0x20;
    }
}

void trap_hit_check_head_broken(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[0].unk11 == 0) {
        add_bot_to_defeated_list(gUnk_03001800.unk87);
        gUnk_03001800.unkAA = 0x2F;
    } else {
        gUnk_03001800.unkAA = 0x20;
    }
}

// Attack Clr (and type 0x5A): the trap drops on the actor and shakes the screen.
void trap_hit_erase_drop(void) {
    if (sprite_move_toward_target(0x21, 0x3C, 0x84)) {
        play_sound_effect(0x41);
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void trap_hit_erase_shake_bg(void) {
    bg3_shake_step(gUnk_03000440.unk84);
    if (++gUnk_03000440.unk84 > 0x1D) {
        play_sound_effect(0x3F);
        gBg3Scroll.y = 0;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk86 = gSpriteEntries[0x21].unk2;
        gUnk_03001800.unkAA++;
    }
}

void trap_hit_erase_shake_sprite(void) {
    sprite_shake_x_step(0x21, gUnk_03000440.unk84, gUnk_03000440.unk86);
    if (++gUnk_03000440.unk84 == 0x5A) {
        gSpriteEntries[0x21].unk2 = gUnk_03000440.unk86;
        gUnk_03001800.unkAA++;
    }
}

void trap_hit_erase_branch(void) {
    if (gUnk_03001800.unk51 == 2)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 8;
}

// Message 0x15: "Your attack has been stopped by the Erase Attack Trap".
void trap_hit_erase_message(void) {
    gUnk_03001800.unkA6 = 0x15;
    gUnk_03001800.unkAA++;
}

void trap_hit_goto_wear(void) {
    gUnk_03001800.unkAA = 0x20;
}

void trap_hit_break_cursor_init(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk2,
                            gSpriteEntries[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk4, 4);
    gUnk_03001800.unkAA++;
}

void trap_hit_break_cursor_wait(void) {
    if (staggered_sprites_update(0x21, 4))
        gUnk_03001800.unkAA++;
}

void trap_hit_break_burst_init(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC004;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void trap_hit_break_burst_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        switch (gUnk_03001800.unk51) {
        case 0:
            lz_decompress_dispatch(gUnk_084C907C, (void *)0x06014800);
            CpuFastSet(gUnk_0850E058, (void *)0x050002C0, 8);
            break;
        case 1:
            lz_decompress_dispatch(gUnk_084C9288, (void *)0x06014800);
            CpuFastSet(gUnk_0850E078, (void *)0x050002C0, 8);
            break;
        case 2:
            lz_decompress_dispatch(gUnk_084C9624, (void *)0x06014800);
            CpuFastSet(gUnk_0850E098, (void *)0x050002C0, 8);
            break;
        case 3:
            lz_decompress_dispatch(gUnk_084C978C, (void *)0x06014800);
            CpuFastSet(gUnk_0850E0B8, (void *)0x050002C0, 8);
            break;
        }
        gUnk_03001800.unkAA = 0xE;
    }
}

// Wear the trap down: Grap / Shot Trap lose half the actor's leg stat (unk12) of durability, Attack Clr one use;
// used up -> the disarm animation.
void trap_hit_wear(void) {
    u8 v;

    if (gUnk_03001800.unk51 != 2) {
        v = gUnk_03000590[gUnk_03001800.unk87].parts[3].unk12 >> 1;
        if (v >= gUnk_03001800.unk28[gUnk_03001800.unk89].durability) {
            gUnk_03001800.unkAA++;
        } else {
            gUnk_03001800.unk28[gUnk_03001800.unk89].durability -= v;
            gUnk_03001800.unkAA = 0x2D;
        }
    } else {
        gUnk_03001800.unk28[gUnk_03001800.unk89].durability--;
        if (gUnk_03001800.unk28[gUnk_03001800.unk89].durability == 0)
            gUnk_03001800.unkAA++;
        else
            gUnk_03001800.unkAA = 0x2E;
    }
}

void trap_disarm_load_graphics(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084C907C, (void *)0x06015400);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9288, (void *)0x06015400);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084C9624, (void *)0x06015400);
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084C978C, (void *)0x06015400);
        break;
    }
    gUnk_03001800.unkAA++;
}

void trap_disarm_sprite_spawn(void) {
    gSpriteEntries[0x21].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | -0x3DFC;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk8 = 8;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk4 = 0x3C;
    if (gUnk_03001800.unk89 == 0) {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2 = 0x68;
    } else
        gSpriteEntries[0x21].unk2 = 0x88;
    switch (gUnk_03001800.unk51) {
    case 0:
        gSpriteEntries[0x21].unk6 = 0xB00;
        break;
    case 1:
        gSpriteEntries[0x21].unk6 = 0xC00;
        break;
    case 2:
        gSpriteEntries[0x21].unk6 = 0xD00;
        break;
    case 3:
        gSpriteEntries[0x21].unk6 = 0xE00;
        break;
    }
    gUnk_03001800.unkAA++;
}

void trap_disarm_hop_init(void) {
    gSpriteEntries[0x21].unk23 = 0;
    gUnk_03000440.unk84 = 0;
    play_sound_effect(0x34);
    gUnk_03001800.unkAA++;
}

void trap_disarm_hop(void) {
    if (sprite_hop_step(0x21) == 0) {
        if (!(gUnk_03000440.unk84 & 1)) {
            if (gUnk_03001800.unk89 == 0)
                gSpriteEntries[0x21].unk2++;
            else
                gSpriteEntries[0x21].unk2--;
        }
        gUnk_03000440.unk84++;
    } else if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
    }
}

void trap_disarm_end(void) {
    if (gUnk_03001800.unk51 == 2)
        gUnk_03001800.unkAA = 0x2E;
    else
        gUnk_03001800.unkAA = 0x2D;
}

// Clear the side's trap record, message 0x25 "Trap was disarmed".
void trap_disarm_clear(void) {
    gUnk_03001800.unk28[gUnk_03001800.unk89].active = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].skill = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].durability = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].power = 0;
    gUnk_03001800.unkA6 = 0x25;
    gUnk_03001800.unkAA++;
}

void trap_hit_end_continue(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 0;
}

void trap_hit_end_stopped(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 1;
}

void trap_hit_end_defeated(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 2;
}

// Script opcode 0x05: is the acting Medabot's chosen part still intact? If not, message 5 "The Medapart for that
// action is broken" and unkAB = 1.
void action_part_check_run(void) {
    gUnk_03001800.unkB5 = 0;
    gActionPartCheckSteps[gUnk_03001800.unkAA]();
}

void action_part_check(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03000590[gUnk_03001800.unk87].unkDD - 1].unk11) {
        gUnk_03001800.unkB5 = 1;
        gUnk_03001800.unkAB = 0;
    } else {
        gUnk_03001800.unkA6 = 5;
        gUnk_03001800.unkAA++;
    }
}

void action_part_check_end_broken(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 1;
}

// Script opcode 0x07: is the targeted part still intact? If not, message 0xC "The target Medapart is broken" and
// unkAB = 1.
void target_part_check_run(void) {
    gUnk_03001800.unkB5 = 0;
    gTargetPartCheckSteps[gUnk_03001800.unkAA]();
}

void target_part_check(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03001800.unk8B].unk11) {
        gUnk_03001800.unkB5 = 1;
        gUnk_03001800.unkAB = 0;
    } else {
        gUnk_03001800.unkA6 = 0xC;
        gUnk_03001800.unkAA++;
    }
}

void target_part_check_end_broken(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 1;
}

// guess: script opcode 0x08, a small effect (animation 0x1B) that flies from the actor to the target.
void action_flash_run(void) {
    gUnk_03001800.unkB5 = 0;
    gActionFlashSteps[gUnk_03001800.unkAA]();
}

void action_flash_load_palette(void) {
    CpuFastSet(gUnk_084E3038, (void *)0x050002C0, 8);
    gUnk_03001800.unkAA++;
}

void action_flash_spawn(void) {
    clear_battle_sprite_slot(9, 1);
    gSpriteEntries[9].unk0 = 0xC404;
    gSpriteEntries[9].unk1C = 0;
    gSpriteEntries[9].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[9].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[9].unkA = 6;
    gSpriteEntries[9].unkB = 0xF0;
    gSpriteEntries[9].unk30 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[9].unk32 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[9].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1B], 9);
    gUnk_03001800.unkAA++;
}

void action_flash_move(void) {
    if (move_sprite_toward_target(9))
        gUnk_03001800.unkAA++;
}

void action_flash_finish(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x1B], 9);
    if (gSpriteEntries[9].unk22 == 0xFF) {
        clear_battle_sprite_slot(9, 1);
        gUnk_03001800.unkB5 = 1;
    }
}

// Script opcode 0x09: a teammate of the target with Defence / Full Block / Half Block ready (unkBD bit 3, skill in
// unkDF 0x1B-0x1D) jumps in front of it, shows its shield, message 0x16 "<name> protected!!" and becomes the new
// target. script_op_guard_restore (opcode 0x0A) puts its sprites back.
void guard_run(void) {
    gUnk_03001800.unkB5 = 0;
    gGuardSteps[gUnk_03001800.unkAA]();
}

void guard_find(void) {
    u32 base;
    u32 i;

    if (gUnk_03000590[gUnk_03001800.unk87].unkC0 & 4) {
        gUnk_03001800.unkB5 = 1;
        return;
    }
    base = battle_side_first_record(gUnk_03001800.unk88);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[base + i].unk40 == 0)
            continue;
        if (!(gUnk_03000590[base + i].unkBD & 8))
            continue;
        if (gUnk_03001800.unk88 == base + i)
            continue;
        if (gUnk_03000590[base + i].unkC9 == 0x2F)
            continue;
        if (gUnk_03000590[base + i].parts[gUnk_03000590[base + i].unkDE - 1].unk11 == 0)
            continue;
        gUnk_03001800.unkDE = base + i + 1;
        gUnk_03001800.unkDF = gUnk_03000590[base + i].unkDF;
    }
    if (gUnk_03001800.unkDE)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkB5 = 1;
}

void guard_load_graphics(void) {
    switch (gUnk_03001800.unkDF) {
    case 0x1B:
        lz_decompress_dispatch(gUnk_084C9880, (void *)0x06014800);
        CpuFastSet(gUnk_0850E0F8, (void *)0x050002C0, 8);
        break;
    case 0x1C:
        lz_decompress_dispatch(gUnk_084C9B88, (void *)0x06014800);
        CpuFastSet(gUnk_0850E118, (void *)0x050002C0, 8);
        break;
    case 0x1D:
        lz_decompress_dispatch(gUnk_084C9E9C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E138, (void *)0x050002C0, 8);
        break;
    }
    gUnk_03001800.unkAA++;
}

void guard_sprite_copy(void) {
    memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unkDE - 1) * 4 + 0x5A], &gSpriteEntries[0x21], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unkDE - 1) * 4 + 0x5B], &gSpriteEntries[0x22], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unkDE - 1) * 4 + 0x5C], &gSpriteEntries[0x23], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unkDE - 1) * 4 + 0x5D], &gSpriteEntries[0x24], 0x40);
    clear_sprite_table_mask(0x21, 4);
    get_bot_part_effective_values(gUnk_03001800.unkDE - 1, gUnk_03001800.unk64);
    setup_battle_sprite_group(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                              gUnk_03001800.unk64[3], gUnk_03001800.unkDE - 1, gUnk_03001800.unkDE * 4 + 0x56,
                              gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk2,
                              gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk4 - 4, (gUnk_03001800.unkF8 & 1) ^ 1,
                              gUnk_03001800.unk39[3] + 2, gUnk_03001800.unkDE * 4 + 0x56);
    battle_sprite_set_palette_index(gUnk_03001800.unkDE * 4 + 0x56, 8);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void guard_blink(void) {
    update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                            (gUnk_03001800.unkF8 & 1) ^ 1);
    if (gUnk_03000440.unk84 & 4)
        clear_sprite_table_mask(gUnk_03001800.unkDE * 4 + 0x56, 4);
    else
        set_sprite_hidden_flags(gUnk_03001800.unkDE * 4 + 0x56, 4);
    if (++gUnk_03000440.unk84 == 0x3C) {
        set_sprite_hidden_flags(gUnk_03001800.unkDE * 4 + 0x56, 4);
        play_sound_effect(0x40);
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk24 = 4;
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk25 = 0;
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk30 = 0;
        sub_08035694(gUnk_03001800.unkDE + 0x71);
        gUnk_03001800.unkAA++;
    }
}

void guard_jump(void) {
    if (update_sprite_deceleration(gUnk_03001800.unkDE * 4 + 0x59, -0x20, -0x10)) {
        check_sprite_overlap_and_adjust(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03001800.unkDE + 0x71);
        update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                                (gUnk_03001800.unkF8 & 1) ^ 1);
        gUnk_03001800.unkAA++;
    } else {
        update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                                (gUnk_03001800.unkF8 & 1) ^ 1);
        check_sprite_overlap_and_adjust(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03001800.unkDE + 0x71);
    }
}

void guard_slide_center(void) {
    u32 done = 0;

    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk2 -= 2;
        if (gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk2 <= 0x78)
            done = 1;
    } else {
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk2 += 2;
        if (gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk2 > 0x77)
            done = 1;
    }
    update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                            (gUnk_03001800.unkF8 & 1) ^ 1);
    if (done) {
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk24 = 8;
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk25 = 0;
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk30 = 0;
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk2 = 0x78;
        gSpriteEntries[gUnk_03001800.unkDE + 0x71].unk2 = 0x78;
        gSpriteEntries[gUnk_03001800.unkDE + 0x71].unk4 = gSpriteEntries[gUnk_03001800.unk87 + 0x72].unk4;
        gUnk_03001800.unkAA++;
    }
}

void guard_move_in(void) {
    if (sprite_move_toward_target(gUnk_03001800.unkDE * 4 + 0x59, gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4,
                                  gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 0x10)) {
        check_sprite_overlap_and_adjust(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03001800.unkDE + 0x71);
        update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                                (gUnk_03001800.unkF8 & 1) ^ 1);
        play_sound_effect(0x41);
        get_bot_part_effective_values(gUnk_03001800.unkDE - 1, gUnk_03001800.unk64);
        setup_battle_sprite_group(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                  gUnk_03001800.unk64[3], gUnk_03001800.unkDE - 1, gUnk_03001800.unkDE * 4 + 0x56,
                                  gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk2,
                                  gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk4 - 4,
                                  (gUnk_03001800.unkF8 & 1) ^ 1, gUnk_03001800.unk39[3] + 2,
                                  gUnk_03001800.unkDE * 4 + 0x56);
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x57].unk18 = 0;
        gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x58].unk18 = 0;
        sub_080356B4(gUnk_03001800.unkDE + 0x71);
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    } else {
        update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                                (gUnk_03001800.unkF8 & 1) ^ 1);
        check_sprite_overlap_and_adjust(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03001800.unkDE + 0x71);
    }
}

void guard_shield_spawn(void) {
    if (gUnk_03000440.unk84 != 0x1E) {
        gUnk_03000440.unk84++;
        return;
    }
    clear_battle_sprite_slot(0x21, 1);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unkDE * 4 + 0x59].unk4 - 4;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x21);
    gUnk_03001800.unkAA++;
}

void guard_shield_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        play_sound_effect(0x30);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void guard_shield_animate(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x1C], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        memcpy_bytes_0803F63C(gUnk_03000590[gUnk_03001800.unkDE - 1].medal.unkA, gUnk_03000440.unk9E, 0xE);
        gUnk_03001800.unkA6 = 0x16;
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void guard_retarget(void) {
    battle_set_action_target(gUnk_03001800.unk87, gUnk_03001800.unkDE);
    battle_set_action_target_part(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unkDE - 1].unkDE);
    gUnk_03001800.unkB5 = 1;
}

// Script opcode 0x19: message 0x17 "<part kind> action <skill>" for the acting Medabot's part.
void action_announce_run(void) {
    gUnk_03001800.unkB5 = 0;
    gActionAnnounceSteps[gUnk_03001800.unkAA]();
}

void action_announce_prepare(void) {
    memcpy_bytes_0803F63C((void *)gUnk_083B6EC8[gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2]],
                          gUnk_03000440.unk9E, 0xE);
    memcpy_bytes_0803F63C((void *)gUnk_083BE6E8[gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1]],
                          gUnk_03000440.unk9E + 0x14, 0xE);
    gUnk_03001800.unkA6 = 0x17;
    gUnk_03001800.unkAA++;
}

void action_announce_end(void) {
    gUnk_03001800.unkB5 = 1;
}

// Script opcode 0x1A: wipe out the battlefield, save its VRAM and sprites to EWRAM and set up the action close-up
// scene (closeup_scene.c).
void closeup_enter_run(void) {
    gUnk_03001800.unkB5 = 0;
    gCloseupEnterSteps[gUnk_03001800.unkAA]();
}

void closeup_enter_init(void) {
    u32 zero;
    u32 fill;

    gUnk_03000440.unk84 = 0;
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000120, 0x01000008);
    fill = 0x11111111;
    CpuFastSet(&fill, (void *)0x06004120, 0x01000008);
    gUnk_03001800.unkAA++;
}

void closeup_enter_wipe(void) {
    write_tilemap_rect(0x1E, 1, 0, gUnk_03000440.unk84, gUnk_083B4AE0_s.unk1A4, REG_BG0CNT, 0);
    write_tilemap_rect(0x1E, 1, 0, 0x13 - gUnk_03000440.unk84, gUnk_083B4AE0_s.unk1A4, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 9) {
        gUnk_03001800.unk1AE = 1;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03000440.unk84++;
    }
}

void closeup_enter_save_vram(void) {
    switch (gUnk_03000440.unk139) {
    case 0:
        CpuFastSet((void *)0x06002800, (void *)0x02020800, 0x200);
        CpuFastSet((void *)0x0600C800, (void *)0x02021000, 0x200);
        CpuFastSet((void *)0x0600D000, (void *)0x02021800, 0x200);
        CpuFastSet((void *)0x0600D800, (void *)0x02022000, 0x200);
        gUnk_03000440.unk139++;
        break;
    case 1:
        CpuFastSet(gSpriteEntries, (void *)0x02028000, 0x800);
        gUnk_03000440.unk139++;
        break;
    case 2:
        gVBlankCallback = nullsub_08000840;
        clear_battle_sprite_slot(0, 0x80);
        gUnk_03000440.unk139 = 0;
        gUnk_03001800.unkAA++;
        break;
    }
}

void closeup_enter_setup_bgs(void) {
    u32 zero;

    switch (gUnk_03000440.unk139) {
    case 0:
        clear_bg_scroll();
        REG_DISPCNT &= 0xE0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1801;
        REG_BG2CNT = 0x590A;
        REG_BG3CNT = 0x5B0B;
        lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
        vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
        decompress_tileset_to_vram(gUnk_03001800.unk38, 0);
        zero = 0;
        CpuFastSet(&zero, gSpriteEntries, 0x01000800);
        gUnk_03000440.unk139++;
        break;
    case 1:
        REG_DISPCNT |= 0x1F40;
        REG_DISPCNT &= 0xFFDF;
        apply_battle_blend_effect_a();
        if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
            decompress_indexed_graphics_to_ewram(gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1]);
        else
            decompress_indexed_graphics_to_ewram(gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50);
        decompress_fixed_graphics_to_ewram();
        sub_08035C3C();
        gVBlankCallback = battle_bg_scroll_vblank;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk139 = 0;
        gUnk_03001800.unkAA++;
        break;
    }
}

void closeup_enter_init_scene(void) {
    u32 zero = 0;

    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    init_battle_closeup_scene();
    init_battle_scene_backgrounds();
    closeup_reset_text_states();
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void closeup_enter_unwipe(void) {
    init_battle_scene_backgrounds();
    battle_advance_dialogue_text();
    battle_advance_action_text();
    vram_fill_tilemap_rect(0x1E, 1, 0, 9 - gUnk_03000440.unk84, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x1E, 1, 0, gUnk_03000440.unk84 + 10, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 9)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84++;
}

void closeup_enter_end(void) {
    init_battle_scene_backgrounds();
    battle_advance_dialogue_text();
    battle_advance_action_text();
    gUnk_03001800.unkB5 = 1;
}

// Opcode 0x1E, the hit (gAttackHitSteps). Runtime: runs after every attack, after reaction_run. Step 1 branches on
// the result flags: unkB7 bit 0 = missed (step 40), unkB8 2 = nullified (48), unkB8 4 = absorbed as healing (56).
// A hit shows the target's armor panel, sparks and the damage number, drains the armor, breaks the part (burst,
// defeat check) and carries leftover damage to the next part (Destroy repeats unkEC times).
void attack_hit_run(void) {
    gUnk_03001800.unkB5 = 0;
    gAttackHitSteps[gUnk_03001800.unkAA]();
}

void attack_hit_load_graphics(void) {
    u32 side;

    lz_decompress_dispatch(gUnk_084C4F00, (void *)0x06006400);
    lz_decompress_dispatch(gUnk_084882F4, (void *)0x06006520);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06006600);
    lz_decompress_dispatch(gUnk_084C65C8, (void *)0x06006800);
    CpuFastSet(gUnk_08488B24, (void *)0x05000140, 8);
    CpuFastSet(gUnk_084E3098, (void *)0x05000100, 8);
    CpuFastSet(gUnk_084C6A58, (void *)0x05000160, 8);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    armor_panel_draw_icons(side);
    armor_panel_draw_frame(side);
    armor_panel_draw_bars(side, gUnk_03001800.unk88);
    armor_panel_draw_numbers(side, gUnk_03001800.unk88);
    gUnk_03001800.unkAA++;
}

void attack_hit_branch(void) {
    gUnk_03001800.unkB9 = 0;
    if (gUnk_03001800.unkB7 & 1)
        gUnk_03001800.unkAA = 0x28;
    else if (gUnk_03001800.unkB7 & 3) {
        charge_target_medaforce();
        gUnk_03001800.unkAA = 10;
    } else if (gUnk_03001800.unkB8 & 2)
        gUnk_03001800.unkAA = 0x30;
    else if (gUnk_03001800.unkB8 & 4)
        gUnk_03001800.unkAA = 0x38;
    else {
        side_add_action_point();
        charge_target_medaforce();
        gUnk_03001800.unkAA++;
    }
}

// guess: unkBC bit 6 is set with bits 2-3 by battle_check_damage_threshold (a clean / critical hit).
void attack_hit_check_critical(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].unkBC & 0x40)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 6;
}

void attack_hit_critical_spawn(void) {
    lz_decompress_dispatch(gUnk_084CC430, (void *)0x06010000);
    CpuFastSet(gUnk_0850E2D8, (void *)0x050003C0, 8);
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    gSpriteEntries[10].unk6 = 0x1F00;
    gSpriteEntries[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[10].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk15A;
    } else {
        gSpriteEntries[10].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk156;
    }
    play_sound_effect(0x72);
    gUnk_03001800.unkAA++;
}

void attack_effect_hop(void) {
    if (sprite_hop_step(10)) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

// Destroy, or a hit moved to the strongest part by evasion (unkBC bit 5): show which part is hit first.
void attack_hit_check_part_marker(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30)
        gUnk_03001800.unkAA++;
    else if (gUnk_03000590[gUnk_03001800.unk88].unkBC & 0x20)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 10;
}

void attack_hit_part_marker_spawn(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30) {
        battle_set_damage_break_part(gUnk_03001800.unk88, gUnk_03001800.unk8B);
        lz_decompress_dispatch(gUnk_084CC7C8, (void *)0x06010000);
        CpuFastSet(gUnk_0850E318, (void *)0x050003C0, 8);
        gSpriteEntries[10].unk6 = 0x2100;
        play_sound_effect(0x54);
    } else {
        switch (gUnk_03001800.unk8B) {
        case 0:
            lz_decompress_dispatch(gUnk_084CB950, (void *)0x06010000);
            CpuFastSet(gUnk_0850E258, (void *)0x050003C0, 8);
            gSpriteEntries[10].unk6 = 0x1B00;
            break;
        case 1:
            lz_decompress_dispatch(gUnk_084CBC10, (void *)0x06010000);
            CpuFastSet(gUnk_0850E278, (void *)0x050003C0, 8);
            gSpriteEntries[10].unk6 = 0x1C00;
            break;
        case 2:
            lz_decompress_dispatch(gUnk_084CBF04, (void *)0x06010000);
            CpuFastSet(gUnk_0850E298, (void *)0x050003C0, 8);
            gSpriteEntries[10].unk6 = 0x1D00;
            break;
        case 3:
            lz_decompress_dispatch(gUnk_084CC19C, (void *)0x06010000);
            CpuFastSet(gUnk_0850E2B8, (void *)0x050003C0, 8);
            gSpriteEntries[10].unk6 = 0x1E00;
            break;
        }
        play_sound_effect(6);
    }
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    gSpriteEntries[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        if (gUnk_03001800.unk8B == 2)
            gSpriteEntries[10].unk2 = gUnk_03001800.unk158 - 0x10;
        else
            gSpriteEntries[10].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk15A;
    } else {
        if (gUnk_03001800.unk8B == 1)
            gSpriteEntries[10].unk2 = gUnk_03001800.unk154 + 0x10;
        else
            gSpriteEntries[10].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk156;
    }
    gUnk_03001800.unkAA++;
}

void attack_hit_part_marker_move(void) {
    if (effect_sprite_fly_to_part(10, gUnk_03001800.unk8B)) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void attack_hit_sparks_spawn(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06010800);
    CpuFastSet(gUnk_0850E338, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    hit_sparks_spawn(10, gUnk_03001800.unk8B, x, y);
    gUnk_03001800.unkAA++;
}

void attack_hit_sparks_wait(void) {
    CpuFastSet(gUnk_0850E338, (void *)0x050003C0, 8);
    if (hit_sparks_update(10)) {
        gUnk_03000440.unk86 = 10;
        gUnk_03001800.unkAA++;
    }
}

void attack_hit_damage_popup_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084D1824, (void *)0x06010000);
    CpuFastSet(gUnk_0850E018, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 1);
    damage_digits_spawn(&gUnk_03000440.unkEE, 10, gUnk_03001800.unk8B, x, y);
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void attack_damage_popup_wait(void) {
    if (advance_sprite_group_anims(&gUnk_03000440.unkEE, 10)) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void attack_hit_drain_sound(void) {
    play_sound_effect(0x2F);
    gUnk_03001800.unkAA++;
}

void attack_hit_drain_armor(void) {
    u32 done;
    u32 side;

    done = armor_drain_step(&gUnk_03001800.unkC8, gUnk_03001800.unk88, gUnk_03001800.unk8B);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    armor_panel_draw_bars(side, gUnk_03001800.unk88);
    armor_panel_draw_numbers(side, gUnk_03001800.unk88);
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void attack_hit_check_part_broken(void) {
    if (gUnk_03001800.unkD1) {
        bot_halve_broken_leg_stats(gUnk_03001800.unk88);
        gUnk_03001800.unkAA += 3;
    } else
        gUnk_03001800.unkAA++;
}

void attack_hide_armor_panel(void) {
    u32 side;

    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    armor_panel_clear(side);
    gUnk_03001800.unkAA++;
}

void attack_hit_end(void) {
    gUnk_03001800.unkB5 = 1;
}

void attack_hit_break_burst_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06010800);
    CpuFastSet(gUnk_0850E358, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gUnk_03000440.unk86 = 0;
    effect_sprite_spawn_at_part(10, gUnk_03001800.unk8B, x, y, 0x1E);
    gUnk_03001800.unkAA++;
}

void attack_hit_break_burst_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x1E], 10);
    if (gSpriteEntries[10].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 1);
        gUnk_03001800.unkAA++;
    }
    if (gUnk_03000440.unk86 == 0x12)
        setup_battle_medapart_scenes();
    gUnk_03000440.unk86++;
}

void attack_hit_break_pause(void) {
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

// Hidden function (no callers): attack_hit_break_pause plus the broken-part redraw.
void attack_hit_break_redraw(void) {
    setup_battle_medapart_scenes();
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void attack_hit_check_defeated(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11)
        gUnk_03001800.unkAA += 3;
    else {
        add_bot_to_defeated_list(gUnk_03001800.unk88);
        gUnk_03001800.unkAA++;
    }
}

// Leftover damage (unkCA) goes on to another part with actor unkD6 bit 1 or a piercing part (data[7]).
void attack_hit_check_carry_over(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30) {
        if (--gUnk_03001800.unkEC != 0) {
            gUnk_03001800.unkAA = 0x20;
            return;
        }
    } else if ((gUnk_03000590[gUnk_03001800.unk87].unkD6 & 2 ||
                gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[7]) &&
               gUnk_03001800.unkCA != 0) {
        gUnk_03001800.unkAA = 0x20;
        return;
    }
    gUnk_03001800.unkAA++;
}

void attack_hit_carry_over_retarget(void) {
    calc_bot_evasion_modifier(gUnk_03001800.unk87);
    sub_080355C4(gUnk_03001800.unk87);
    gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30)
        battle_set_damage_break_part(gUnk_03001800.unk88, gUnk_03001800.unk8B);
    else {
        if (gUnk_03000590[gUnk_03001800.unk87].unkD6 & 2)
            gUnk_03001800.unkCA += 10;
        battle_set_damage_vs_armor(gUnk_03001800.unk88, gUnk_03001800.unk8B, gUnk_03001800.unkCA);
    }
    gUnk_03001800.unkAA++;
}

void attack_carry_marker_spawn(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30) {
        lz_decompress_dispatch(gUnk_084CC7C8, (void *)0x06010000);
        CpuFastSet(gUnk_0850E318, (void *)0x050003C0, 8);
        gSpriteEntries[10].unk6 = 0x2100;
        play_sound_effect(0x54);
    } else {
        lz_decompress_dispatch(gUnk_084CA61C, (void *)0x06010000);
        CpuFastSet(gUnk_0850E198, (void *)0x050003C0, 8);
        gSpriteEntries[10].unk6 = 0x1500;
        play_sound_effect(0x2A);
    }
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    gSpriteEntries[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        if (gUnk_03001800.unk8B == 2)
            gSpriteEntries[10].unk2 = gUnk_03001800.unk158 - 0x10;
        else
            gSpriteEntries[10].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk15A;
    } else {
        if (gUnk_03001800.unk8B == 1)
            gSpriteEntries[10].unk2 = gUnk_03001800.unk154 + 0x10;
        else
            gSpriteEntries[10].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk156;
    }
    gUnk_03001800.unkAA++;
}

void attack_hit_goto_sparks(void) {
    gUnk_03001800.unkAA = 10;
}

// The miss branch (unkB7 bit 0: the target dodged, unkBC bit 4).
void attack_miss_sprite_spawn(void) {
    lz_decompress_dispatch(gUnk_084CA428, (void *)0x06010000);
    CpuFastSet(gUnk_0850E178, (void *)0x050003C0, 8);
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    gSpriteEntries[10].unk6 = 0x1400;
    gSpriteEntries[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[10].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk15A - 0x10;
        gSpriteEntries[10].unk30 = gUnk_03001800.unk15A;
    } else {
        gSpriteEntries[10].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk156 - 0x10;
        gSpriteEntries[10].unk30 = gUnk_03001800.unk156;
    }
    play_sound_effect(0x2F);
    gUnk_03001800.unkAA++;
}

void attack_miss_sprite_drop(void) {
    if (gFrameCounter & 1) {
        gSpriteEntries[10].unk4++;
        if (gSpriteEntries[10].unk4 == gSpriteEntries[10].unk30) {
            gUnk_03000440.unk86 = 0x3C;
            gUnk_03001800.unkAA++;
        }
    }
}

// The nullified branch (unkB8 == 2: Full / Half Block and the immunity checks of action_calc.c).
void attack_nullified_sprite_spawn(void) {
    lz_decompress_dispatch(gUnk_084CC5F8, (void *)0x06010000);
    CpuFastSet(gUnk_0850E2F8, (void *)0x050003C0, 8);
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    gSpriteEntries[10].unk6 = 0x2000;
    gSpriteEntries[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[10].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk15A;
    } else {
        gSpriteEntries[10].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk156;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

// The absorbed branch (unkB8 == 4): the damage heals the target's most damaged parts instead.
void attack_absorbed_sprite_spawn(void) {
    lz_decompress_dispatch(gUnk_084D18EC, (void *)0x06010000);
    CpuFastSet(gUnk_0850E498, (void *)0x050003C0, 8);
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    gSpriteEntries[10].unk6 = 0x2E00;
    gSpriteEntries[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[10].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk15A;
    } else {
        gSpriteEntries[10].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[10].unk4 = gUnk_03001800.unk156;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

void attack_absorbed_find_part(void) {
    u32 part = find_most_damaged_part(gUnk_03001800.unk88);

    if (part) {
        gUnk_03001800.unk8B = gUnk_03001800.unkD0 = part - 1;
        battle_calc_damage_split(gUnk_03001800.unk88, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
        gUnk_03001800.unkAA = 0x3E;
    } else
        gUnk_03001800.unkAA++;
}

void attack_absorbed_sparkle_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CDCD4, (void *)0x06010800);
    CpuFastSet(gUnk_0850E398, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    effect_sprite_spawn_at_part(10, gUnk_03001800.unk8B, x, y, 0x20);
    gUnk_03001800.unkAA++;
}

void attack_absorbed_sparkle_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x20], 10);
    if (gSpriteEntries[10].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 1);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void attack_absorbed_heal_popup_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084D1824, (void *)0x06010000);
    CpuFastSet(gUnk_0850DFF8, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 0);
    damage_digits_spawn(&gUnk_03000440.unkEE, 10, gUnk_03001800.unk8B, x, y);
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void attack_absorbed_heal_sound(void) {
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void attack_absorbed_heal_armor(void) {
    u32 done;
    u32 side;

    done = armor_heal_step(&gUnk_03001800.unkC8, gUnk_03001800.unk88, gUnk_03001800.unk8B);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    armor_panel_draw_bars(side, gUnk_03001800.unk88);
    armor_panel_draw_numbers(side, gUnk_03001800.unk88);
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void attack_absorbed_check_carry_over(void) {
    u32 part;
    struct Unk_03001800 *s;

    if ((gUnk_03000590[(s = &gUnk_03001800)->unk87].unkD6 & 2 || gUnk_03000590[s->unk87].parts[s->unkA7].data[7]) &&
        s->unkCA && (part = find_most_damaged_part(s->unk88))) {
        part--;
        s->unkD0 = part;
        s->unk8B = part;
        battle_calc_damage_split(s->unk88, s->unkD0, s->unkCA);
        s->unkAA = 0x4A;
    } else {
        s->unkAA++;
    }
}

void attack_absorbed_goto_sparkle(void) {
    gUnk_03001800.unkAA = 0x3E;
}

// Opcode 0x1F (gStatusAttackSteps): after a hit, skills 0xD-0x14 inflict their status unless the target missed /
// nullified / absorbed, is defeated, has Stability or a status guard. unk51 = kind: 0 Bug / Virus, 1 Thunder /
// Freeze, 2 Wave / Hold, 3 Fire / Melt (skill names from the ROM list).
void status_attack_run(void) {
    gUnk_03001800.unkB5 = 0;
    gStatusAttackSteps[gUnk_03001800.unkAA]();
}

void status_attack_check(void) {
    struct Unk_03001800 *s = &gUnk_03001800;
    u8 skill;

    if (s->unkB7 & 1)
        s->unkAA++;
    else if (s->unkB8 & 2)
        s->unkAA++;
    else if (s->unkB8 & 4)
        s->unkAA++;
    else if (!gUnk_03000590[s->unk88].parts[0].unk11)
        s->unkAA++;
    else if (!battle_bot_lacks_stability(s->unk88))
        s->unkAA++;
    else if (bot_has_status_guard(s->unk88, gUnk_03000590[s->unk87].parts[s->unkA7].data[1]))
        s->unkAA++;
    else {
        skill = gUnk_03000590[s->unk87].parts[s->unkA7].data[1];
        if (skill == 0xD)
            goto s0;
        if (skill != 0xE)
            goto c1;
    s0:
        s->unk51 = 0;
        s->unkAA = 2;
        return;
    c1:
        if (skill == 0xF)
            goto s1;
        if (skill != 0x10)
            goto c2;
    s1:
        s->unk51 = 1;
        s->unkAA = 2;
        return;
    c2:
        if (skill == 0x11)
            goto s2;
        if (skill != 0x12)
            goto c3;
    s2:
        s->unk51 = 2;
        s->unkAA = 2;
        return;
    c3:
        if (skill == 0x13)
            goto s3;
        if (skill != 0x14)
            goto nx;
    s3:
        s->unk51 = 3;
        s->unkAA = 2;
        return;
    nx:
        s->unkAA++;
    }
}

void status_attack_end(void) {
    gUnk_03001800.unkB5 = 1;
}

void status_attack_flash_spawn(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CA89C, (void *)0x06010000);
    CpuFastSet(gUnk_0850E1B8, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gSpriteEntries[10].unk0 = 0xC624;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unk2 = x;
    gSpriteEntries[10].unk4 = y;
    gSpriteEntries[10].unk8 = 0x40;
    gSpriteEntries[10].unk9 = 4;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0xF0;
    gSpriteEntries[10].unk6 = 0x1600;
    gSpriteEntries[10].unk20 = 0;
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084CE154, (void *)0x06010800);
        CpuFastSet(gUnk_0850E3B8, (void *)0x050003A0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084CE644, (void *)0x06010800);
        CpuFastSet(gUnk_0850E3D8, (void *)0x050003A0, 8);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084CEF14, (void *)0x06010800);
        CpuFastSet(gUnk_0850E3F8, (void *)0x050003A0, 8);
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084CF340, (void *)0x06010800);
        CpuFastSet(gUnk_0850E418, (void *)0x050003A0, 8);
        break;
    }
    gSpriteEntries[11].unk0 = 0xC404;
    gSpriteEntries[11].unk1C = 0;
    gSpriteEntries[11].unk2 = x;
    gSpriteEntries[11].unk4 = y;
    gSpriteEntries[11].unkA = 0xD;
    gSpriteEntries[11].unkB = 0x80;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x21], 11);
    play_sound_effect(0x2F);
    gUnk_03001800.unkAA++;
}

void status_attack_flash_animate(void) {
    if (gSpriteEntries[10].unk20 == 0) {
        if ((gSpriteEntries[10].unk9 += 4) == 0x80)
            gSpriteEntries[10].unk20 = 1;
    } else if (gSpriteEntries[10].unk9 != 0x40)
        gSpriteEntries[10].unk9 -= 4;
    process_sprite_anim_commands(gUnk_083B5F80[0x21], 11);
    if (gSpriteEntries[11].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 2);
        gUnk_03001800.unkAA++;
    }
}

void status_attack_icons_spawn(void) {
    u16 x, y;
    s16 sx, sy;

    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158 - 4;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154 + 4;
        y = gUnk_03001800.unk156;
    }
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084CAB58, (void *)0x06010000);
        CpuFastSet(gUnk_0850E1D8, (void *)0x050003C0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084CAFD8, (void *)0x06010000);
        CpuFastSet(gUnk_0850E1F8, (void *)0x050003C0, 8);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084CB36C, (void *)0x06010000);
        CpuFastSet(gUnk_0850E218, (void *)0x050003C0, 8);
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084CB684, (void *)0x06010000);
        CpuFastSet(gUnk_0850E238, (void *)0x050003C0, 8);
        break;
    }
    sx = x;
    sy = y;
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unk2 = sx - 0x10;
    gSpriteEntries[10].unk4 = sy - 8;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    gSpriteEntries[10].unk6 = 0x1700;
    gSpriteEntries[11].unk0 = 0xC404;
    gSpriteEntries[11].unk1C = 0;
    gSpriteEntries[11].unk2 = sx + 0x10;
    gSpriteEntries[11].unk4 = sy + 8;
    gSpriteEntries[11].unkA = 0xE;
    gSpriteEntries[11].unkB = 0x80;
    gSpriteEntries[11].unk6 = 0x1701;
    gUnk_03001800.unkAA++;
}

void status_attack_icons_slide(void) {
    sprite_slide_x_step(10, 0);
    if (sprite_slide_x_step(11, 1)) {
        play_sound_effect(0x2A);
        gUnk_03000440.unk86 = 0x5A;
        gUnk_03001800.unkAA++;
    }
}

void status_attack_apply(void) {
    battle_inflict_status(gUnk_03001800.unk88, gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1],
                          gUnk_03001800.unkE8, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

// Opcode 0x20 (gCloseupExitSteps), seen at runtime after each attack: wipe the close-up away and restore the battle
// field graphics that closeup_enter_save_vram put in EWRAM.
void closeup_exit_run(void) {
    gUnk_03001800.unkB5 = 0;
    gCloseupExitSteps[gUnk_03001800.unkAA]();
}

void closeup_exit_init(void) {
    u32 zero;
    u32 fill;

    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    gUnk_03000440.unk84 = 0;
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000120, 0x01000008);
    fill = 0x11111111;
    CpuFastSet(&fill, (void *)0x06004120, 0x01000008);
    gUnk_03001800.unkAA++;
}

void closeup_exit_wipe(void) {
    u32 v;

    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    write_tilemap_rect(0x1E, 1, 0, gUnk_03000440.unk84, gUnk_083B4AE0_s.unk1A4, REG_BG0CNT, 0);
    write_tilemap_rect(0x1E, 1, 0, 0x13 - gUnk_03000440.unk84, gUnk_083B4AE0_s.unk1A4, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 9) {
        v = 0x200;
        CpuFastSet(&v, gSpriteWork->oamBuf, 0x01000100);
        gSpriteWork->oamCount = 0;
        gSpriteWork->affineIdx = 0;
        gVBlankCallback = nullsub_08000840;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03000440.unk84++;
    }
}

void closeup_exit_reload(void) {
    switch (gUnk_03000440.unk139) {
    case 0:
        gUnk_03000440.unk96 = 0;
        gUnk_03000430 = 0;
        clear_bg_scroll();
        load_battle_script_entry_b();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1901;
        REG_BG2CNT = 0x1A0A;
        REG_BG3CNT = 0x1B0B;
        if (battle_load_graphics_step(1)) {
            gUnk_03000440.unk84 = 0;
            gUnk_03000440.unk139++;
        }
        break;
    case 1:
        REG_DISPCNT |= 0x1F40;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        apply_battle_blend_effect_b();
        decompress_to_ewram_27000(gUnk_083B24A8[gUnk_03001800.unk38 * 5 + 1]);
        gUnk_03000440.unk139++;
        break;
    case 2:
        CpuFastSet((void *)0x02021000, (void *)0x0600C800, 0x200);
        CpuFastSet((void *)0x02021800, (void *)0x0600D000, 0x200);
        CpuFastSet((void *)0x02022000, (void *)0x0600D800, 0x200);
        gUnk_03000440.unk139++;
        break;
    case 3:
        CpuFastSet((void *)0x02028000, gSpriteEntries, 0x800);
        gUnk_03000440.unk139++;
        break;
    case 4:
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        gVBlankCallback = battle_vblank_update_bg;
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unk1AE = 0;
        gUnk_03001800.unkAA++;
        gUnk_03000440.unk139 = 0;
        break;
    }
}

void closeup_exit_unwipe(void) {
    vram_fill_tilemap_rect(0x1E, 1, 0, 9 - gUnk_03000440.unk84, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x1E, 1, 0, gUnk_03000440.unk84 + 10, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 9)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84++;
}

// Opcode 0x21 (gBotDefeatSteps): for each Medabot waiting in unkE0 (add_bot_to_defeated_list), a ring and a burst
// over it, remove its sprites and show message 0x14 "<Medal>'s function ceased".
void bot_defeat_run(void) {
    gUnk_03001800.unkB5 = 0;
    gBotDefeatSteps[gUnk_03001800.unkAA]();
}

void bot_defeat_find(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkE0[i]) {
            gUnk_03001800.unk51 = gUnk_03001800.unkE0[i] - 1;
            gUnk_03001800.unkE0[i] = 0;
            load_all_bot_part_sprites();
            iterate_bots_setup_battle_sprites();
            reset_battle_bot_state(gUnk_03001800.unk51);
            gUnk_03001800.unkAA = 2;
            return;
        }
    }
    gUnk_03001800.unkAA++;
}

void bot_defeat_ring_init(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[gUnk_03001800.unk51 * 4 + 0x5D].unk2,
                            gSpriteEntries[gUnk_03001800.unk51 * 4 + 0x5D].unk4 - 4, 8);
    gUnk_03001800.unkAA++;
}

void bot_defeat_ring_wait(void) {
    if (staggered_sprites_update(0x21, 8))
        gUnk_03001800.unkAA++;
}

void bot_defeat_burst_init(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC004;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk51 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk51 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void bot_defeat_burst_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        clear_sprite_table_mask(0x5A + gUnk_03001800.unk51 * 4, 4);
        clear_sprite_table_mask(gUnk_03001800.unk51 + 0x72, 1);
        gUnk_03001800.unkAA++;
    }
}

void bot_defeat_message(void) {
    memcpy_bytes_0803F63C(gUnk_03000590[gUnk_03001800.unk51].medal.unkA, gUnk_03000440.unk9E, 0xE);
    gUnk_03001800.unkA6 = 0x14;
    gUnk_03001800.unkAA++;
}

void bot_defeat_next(void) {
    gUnk_03001800.unkAA = 0;
}

// Opcode 0x22 (gReactionSteps). guess: the target's prepared reaction (unkF6 bit 0, set by sub_08038D30 for a guard
// or a readied part): a sprite rises; with unkB7 == 3 it turns into a counter (reaction_counter_begin swaps the
// sides), else it drops back with a nullify or absorb effect. Runtime: runs first in each attack, skipped there.
void reaction_run(void) {
    gUnk_03001800.unkB5 = 0;
    gReactionSteps[gUnk_03001800.unkAA]();
}

void reaction_check(void) {
    if (gUnk_03001800.unkF6 & 1) {
        gUnk_03001800.unkAA = 2;
    } else {
        gUnk_03001800.unkAB = 0;
        gUnk_03001800.unkAA++;
    }
}

void reaction_rise_spawn(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CA1A4, (void *)0x06010000);
    CpuFastSet(gUnk_0850E158, (void *)0x050003C0, 8);
    lz_decompress_dispatch(gUnk_084D1074, (void *)0x06010800);
    CpuFastSet(gUnk_0850E478, (void *)0x050003A0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unk2 = x;
    gSpriteEntries[10].unk4 = y;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    gSpriteEntries[10].unk6 = 0x1300;
    gSpriteEntries[10].unk2B = 0;
    gSpriteEntries[10].unk2C = 0;
    gSpriteEntries[11].unk0 = 0xC404;
    gSpriteEntries[11].unk1C = 0;
    gSpriteEntries[11].unk2 = x;
    gSpriteEntries[11].unk4 = y;
    gSpriteEntries[11].unkA = 0xD;
    gSpriteEntries[11].unkB = 0x80;
    gSpriteEntries[11].unk6 = 0x2C00;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x37], 11);
    play_sound_effect(0x53);
    gUnk_03001800.unkAA++;
}

void reaction_rise(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x37], 11);
    if (gSpriteEntries[10].unk2B == 0x28) {
        clear_battle_sprite_slot(11, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[10].unk2C++;
        if (gSpriteEntries[10].unk2C & 1) {
            gSpriteEntries[10].unk4--;
            gSpriteEntries[10].unk2B++;
        }
    }
}

void reaction_check_counter(void) {
    if (gUnk_03001800.unkB7 == 3) {
        reaction_counter_begin();
        clear_battle_sprite_slot(10, 1);
        gUnk_03001800.unkAB = 1;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03001800.unkAA = 6;
    }
}

void reaction_drop_init(void) {
    lz_decompress_dispatch(gUnk_084CA428, (void *)0x06010000);
    CpuFastSet(gUnk_0850E178, (void *)0x050003C0, 8);
    gSpriteEntries[10].unk2B = 0;
    gSpriteEntries[10].unk2C = 0;
    play_sound_effect(0x2F);
    gUnk_03001800.unkAA++;
}

void reaction_drop(void) {
    if (gSpriteEntries[10].unk2B == 0x28) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAB = 0;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[10].unk2C++;
        gSpriteEntries[10].unk4++;
        gSpriteEntries[10].unk2B++;
    }
}

void reaction_branch(void) {
    if (gUnk_03001800.unkB8 == 2)
        gUnk_03001800.unkAA = 0xB;
    else if (gUnk_03001800.unkB8 == 4)
        gUnk_03001800.unkAA = 0xF;
    else
        gUnk_03001800.unkAA++;
}

void reaction_nullify_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084D01EC, (void *)0x06010800);
    CpuFastSet(gUnk_0850E438, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unk2 = x;
    gSpriteEntries[10].unk4 = y;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x25], 10);
    play_sound_effect(0x37);
    gUnk_03001800.unkAA++;
}

void reaction_nullify_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x25], 10);
    if (gSpriteEntries[10].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0x3C;
        clear_battle_sprite_slot(10, 1);
        gUnk_03001800.unkAA++;
    }
}

void reaction_absorb_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084D073C, (void *)0x06010800);
    CpuFastSet(gUnk_0850E458, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gSpriteEntries[10].unk0 = 0xC404;
    gSpriteEntries[10].unk1C = 0;
    gSpriteEntries[10].unk2 = x;
    gSpriteEntries[10].unk4 = y;
    gSpriteEntries[10].unkA = 0xE;
    gSpriteEntries[10].unkB = 0x80;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x26], 10);
    play_sound_effect(0x2B);
    gUnk_03001800.unkAA++;
}

void reaction_absorb_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x26], 10);
    if (gSpriteEntries[10].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0x3C;
        clear_battle_sprite_slot(10, 1);
        gUnk_03001800.unkAA++;
    }
}

// Opcode 0x23 (gSacrificeSteps): the attacker's own part breaks (message 0x18 "...due to the Sacrifice technique").
void sacrifice_run(void) {
    gUnk_03001800.unkB5 = 0;
    gSacrificeSteps[gUnk_03001800.unkAA]();
}

void sacrifice_ring_init(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkA7].unk2,
                            gSpriteEntries[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkA7].unk4, 4);
    gUnk_03001800.unkAA++;
}

void sacrifice_ring_wait(void) {
    if (staggered_sprites_update(0x21, 4))
        gUnk_03001800.unkAA++;
}

void sacrifice_burst_init(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC004;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkA7].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkA7].unk4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void sacrifice_burst_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sacrifice_break_part(void) {
    reduce_bot_part_stat(gUnk_03001800.unk87, gUnk_03001800.unkA7, 0xFF);
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    if (gUnk_03001800.unkA7 == 0)
        add_bot_to_defeated_list(gUnk_03001800.unk87);
    gUnk_03001800.unkAA++;
}

void sacrifice_message(void) {
    memcpy_bytes_0803F63C(gPartKindNames[gUnk_03001800.unkA7], gUnk_03000440.unk9E, 0xE);
    gUnk_03001800.unkA6 = 0x18;
    gUnk_03001800.unkAA++;
}

// Opcode 0x24 (gDestroyCheckSteps): Destroy fails with message 0x19 "Destroy only works against Medabots facing away"
// and the MISS!! popup unless the target has unkBD bit 2.
void destroy_check_run(void) {
    gUnk_03001800.unkB5 = 0;
    gDestroyCheckSteps[gUnk_03001800.unkAA]();
}

void destroy_check(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].unkBD & 4) {
        gUnk_03001800.unkAA++;
        gUnk_03001800.unkAB = 0;
    } else {
        gUnk_03001800.unkA6 = 0x19;
        gUnk_03001800.unkAA = 2;
        gUnk_03001800.unkAB = 1;
    }
}
