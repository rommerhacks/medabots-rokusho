// Battle graphics: battle_load_graphics_step (staged decompression of the battle BG and sprite graphics),
// battle message window helpers, clear_battle_ui_tilemaps, Medaforce gauge fill / drain steps.
// Called from battle/robattle and battle/action_steps.

#include "global.h"

u32 battle_load_graphics_step(u32 direct) {
    switch (gGameWork.unk13A) {
    case 0:
        lz_decompress_dispatch(gUnk_084C4F00, (void *)0x06004000);
        lz_decompress_dispatch(gUnk_084C4F8C, (void *)0x06004140);
        lz_decompress_dispatch(gUnk_084879F0, (void *)0x06004200);
        gGameWork.unk13A++;
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C5080, (void *)0x06004300);
        lz_decompress_dispatch(gUnk_084C3648, (void *)0x06004400);
        lz_decompress_dispatch(gUnk_08487A24, (void *)0x0600C000);
        lz_decompress_dispatch(gUnk_084C5008, (void *)0x0600C600);
        gGameWork.unk13A++;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_08487E68, (void *)0x06004E00);
        lz_decompress_dispatch(gUnk_08487F64, (void *)0x06005100);
        lz_decompress_dispatch(gUnk_0848803C, (void *)0x06005400);
        lz_decompress_dispatch(gUnk_08488114, (void *)0x06005700);
        lz_decompress_dispatch(gUnk_084881EC, (void *)0x06005A00);
        gGameWork.unk13A++;
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084C4BAC, (void *)0x0600C280);
        lz_decompress_dispatch(gUnk_084C7634, (void *)0x06012000);
        lz_decompress_dispatch(gUnk_084C8AC4, (void *)0x06014E00);
        lz_decompress_dispatch(gUnk_084C984C, (void *)0x06017F80);
        lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
        gGameWork.unk13A++;
        break;
    case 4:
        lz_decompress_dispatch(gUnk_08487B80, (void *)0x06004600);
        lz_decompress_dispatch(gUnk_08487C94, (void *)0x06004800);
        lz_decompress_dispatch(gUnk_08487D6C, (void *)0x06004B00);
        gGameWork.unk13A++;
        break;
    case 5:
        gGameWork.unk13A++;
        break;
    case 6:
        lz_decompress_dispatch(gUnk_084C7FC0, (void *)0x06013000);
        lz_decompress_dispatch(gUnk_084E2950, (void *)0x06013C00);
        lz_decompress_dispatch(gUnk_084E2C18, (void *)0x06014200);
        gGameWork.unk13A++;
        break;
    case 7:
        vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
        gGameWork.unk13A++;
        break;
    case 8:
        if (direct == 0) {
            vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, direct);
            decompress_sprite_to_vram_08043C08(gBattleWork.unk38, 1);
            CpuFastSet(gUnk_084C6A18, (void *)0x0202FB00, 8);
            CpuFastSet(gUnk_08488AC4, (void *)0x0202FB40, 8);
            CpuFastSet(gUnk_08488B04, (void *)0x0202FB60, 8);
            CpuFastSet(gUnk_08488AE4, (void *)0x0202FB80, 8);
            CpuFastSet(gUnk_084C6A38, (void *)0x0202FBA0, 8);
            CpuFastSet(gUnk_084E2EF8, (void *)0x0202F900, 8);
            CpuFastSet(gUnk_084E2F18, (void *)0x0202F920, 8);
            CpuFastSet(gUnk_084E2F38, (void *)0x0202F940, 8);
            CpuFastSet(gUnk_0850DFF8, (void *)0x0202F960, 16);
            CpuFastSet(gUnk_0850DDB8, (void *)0x0202F9A0, 8);
            CpuFastSet(gUnk_0850DDB8 + 0x20, (void *)0x0202F9C0, 8);
            CpuFastSet(gUnk_0850DDB8 + 0x40, (void *)0x0202F9E0, 8);
            CpuFastSet(gUnk_0850E0D8, (void *)0x0202F8A0, 8);
        } else {
            decompress_sprite_to_vram_08043C08(gBattleWork.unk38, 0);
            CpuFastSet(gUnk_084C6A18, (void *)0x05000100, 8);
            CpuFastSet(gUnk_08488AC4, (void *)0x05000140, 8);
            CpuFastSet(gUnk_08488B04, (void *)0x05000160, 8);
            CpuFastSet(gUnk_08488AE4, (void *)0x05000180, 8);
            CpuFastSet(gUnk_084C6A38, (void *)0x050001A0, 8);
            CpuFastSet(gUnk_084E2EF8, (void *)0x05000300, 8);
            CpuFastSet(gUnk_084E2F18, (void *)0x05000320, 8);
            CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
            CpuFastSet(gUnk_0850DFF8, (void *)0x05000360, 16);
            CpuFastSet(gUnk_0850DDB8, (void *)0x050003A0, 8);
            CpuFastSet(gUnk_0850DDB8 + 0x20, (void *)0x050003C0, 8);
            CpuFastSet(gUnk_0850DDB8 + 0x40, (void *)0x050003E0, 8);
            CpuFastSet(gUnk_0850E0D8, (void *)0x050002A0, 8);
        }
        gGameWork.unk13A = 0;
        return 1;
    }
    return 0;
}

void battle_message_open(void) {
    if (gOptionSkipMessages == 0 || gGameWork.unk89 == 1)
        text_window_init(1, 2, 0);
}

u32 battle_message_print(u32 msg) {
    u32 done;

    if (gOptionSkipMessages == 0 || gGameWork.unk89 == 1) {
        done = run_message(gUnk_083C65C4[msg]);
        if (done)
            gGameWork.unk1B = 0;
        return done;
    }
    return 1;
}

u32 battle_message_finish(void) {
    if (gOptionSkipMessages == 0 || gGameWork.unk89 == 1)
        return game_state_execute_handler_a();
    return 1;
}

void draw_bot_panel_frame(u32 bot) {
    if (bot <= 2) {
        set_tilemap_and_decompress_bg(0, 13, gUnk_08488830, REG_BG1CNT, 0x258);
        set_tilemap_and_decompress_bg(0, 17, gUnk_08488744, REG_BG1CNT, 0x210);
    } else {
        set_tilemap_and_decompress_bg(18, 13, gUnk_0848886C, REG_BG1CNT, 0x270);
        set_tilemap_and_decompress_bg(20, 17, gUnk_08488744, REG_BG1CNT, 0x210);
    }
}

void draw_bot_status_panel(u32 bot) {
    if (gBattleBots[bot].unkC1 == 0x50)
        draw_battle_panel_left_b(bot);
    else
        draw_battle_panel_left_a(bot);
    draw_medaforce_gauge_bar(bot);
    draw_medaforce_gauge_value(bot);
}

void target_arrows_init(u32 bot) {
    u32 i;

    clear_battle_sprite_slot(0x78, 8);
    for (i = 0; i <= 7; i++) {
        gSpriteEntries[0x78 + i].unk0 = 0xC404;
        gSpriteEntries[0x78 + i].unk1C = 0;
        gSpriteEntries[0x78 + i].unk4 = 0x78;
        gSpriteEntries[0x78 + i].unkA = 9;
        gSpriteEntries[0x78 + i].unkB = 0x80;
        gSpriteEntries[0x78 + i].unk6 = (i & 3) + 0x616;
        gSpriteEntries[0x78 + i].unk24 = 0;
        gSpriteEntries[0x78 + i].unk26 = 7 - i;
        gSpriteEntries[0x78 + i].unk28 = 0;
        gSpriteEntries[0x78 + i].unk27 = i * 2;
        gSpriteEntries[0x78 + i].unk21 = 0;
        gSpriteEntries[0x78 + i].unk22 = i & 3;
        if (bot <= 2) {
            gSpriteEntries[0x78 + i].unk0 |= 0x1000;
            gSpriteEntries[0x78 + i].unk2 = 0x5C;
        } else {
            gSpriteEntries[0x78 + i].unk0 &= ~0x1000;
            gSpriteEntries[0x78 + i].unk2 = 0x94;
        }
    }
}

#define S gSpriteEntries[0x78 + i]
u32 target_arrows_slide(u32 bot) {
    u32 done = 1;
    u32 i;

    for (i = 0; i <= 7; i++) {
        S.unk21++;
        if ((S.unk21 & 3) == 0)
            S.unk6 = (S.unk22 = (S.unk22 + 1) & 3) + 0x616;
        if (S.unk26 != S.unk24) {
            done = 0;
            if (S.unk27 != 0)
                S.unk27--;
            else {
                if (bot <= 2)
                    S.unk2 += 4;
                else
                    S.unk2 -= 4;
                S.unk28++;
                if ((S.unk28 & 1) == 0)
                    S.unk24++;
            }
        }
    }
    return done;
}
#undef S

void target_arrows_animate(u32 bot) {
    u32 i;

    for (i = 0; i <= 7; i++) {
        gSpriteEntries[0x78 + i].unk21++;
        if ((gSpriteEntries[0x78 + i].unk21 & 3) == 0)
            gSpriteEntries[0x78 + i].unk6 =
                (gSpriteEntries[0x78 + i].unk22 = (gSpriteEntries[0x78 + i].unk22 + 1) & 3) + 0x616;
    }
}

void battle_substeps_reset(void) {
    gBattleWork.unk9C[0] = 0;
    gBattleWork.unk9C[1] = 0;
    gBattleWork.unk9C[2] = 0;
    gBattleWork.unk9C[3] = 0;
    gBattleWork.unk9C[4] = 0;
}

void battle_message_reset(void) {
    gBattleWork.unkA1[0] = 0;
    gBattleWork.unkA1[1] = 0;
    gBattleWork.unkA1[2] = 0;
    gBattleWork.unkA1[3] = 0;
    gBattleWork.unkA1[4] = 0;
}

void clear_battle_ui_tilemaps(void) {
    vram_fill_tilemap_rect(12, 7, 0, 13, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(12, 7, 18, 13, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(12, 7, 0, 13, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 7, 18, 13, REG_BG0CNT, 0);
    clear_battle_sprite_slot(0x3C, 10);
    clear_battle_sprite_slot(0x78, 8);
    clear_battle_sprite_slot(10, 0x17);
}

u32 medaforce_gauge_fill_step(u32 bot) {
    if (gBattleWork.unk51 != 0 && gBattleBots[bot].unkC1 != 0x50) {
        gBattleBots[bot].unkC1++;
        gBattleWork.unk51--;
        draw_medaforce_gauge_bar(bot);
        draw_medaforce_gauge_value(bot);
        return 0;
    }
    return 1;
}

u32 medaforce_gauge_drain_step(u32 bot) {
    if (gBattleWork.unk51 != 0 && gBattleBots[bot].unkC1 != 0) {
        gBattleBots[bot].unkC1--;
        gBattleWork.unk51--;
        draw_medaforce_gauge_bar(bot);
        draw_medaforce_gauge_value(bot);
        return 0;
    }
    return 1;
}

void mf_charge_sparkles_init(u32 bot) {
    u32 i;
    struct Vec16 p;

    CpuFastSet(gUnk_084E3058, (void *)0x050002C0, 8);
    for (i = 0; i <= 7; i++) {
        clear_battle_sprite_slot(i + 0x21, 1);
        gSpriteEntries[0x21 + i].unk0 = ((gBattleWork.unk39[3] + 2) << 10) | 0x4204;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unkA = 6;
        gSpriteEntries[0x21 + i].unkB = 0x81;
        gSpriteEntries[0x21 + i].unk6 = 0xA10;
        gSpriteEntries[0x21 + i].unk20 = i << 5;
        gSpriteEntries[0x21 + i].unk21 = gSpriteEntries[bot * 4 + 0x5D].unk4;
        gSpriteEntries[0x21 + i].unk28 = 0;
        gSpriteEntries[0x21 + i].unk27 = i * 4;
        gSpriteEntries[0x21 + i].unk26 = 0;
        p = compute_polar_to_screen_position(gSpriteEntries[0x21 + i].unk20, 16, gSpriteEntries[bot * 4 + 0x5D].unk2,
                                             gSpriteEntries[0x21 + i].unk21, 8, 0);
        gSpriteEntries[0x21 + i].unk2 = p.x;
        gSpriteEntries[0x21 + i].unk4 = p.y;
        gSpriteEntries[0x21 + i].unk8 = 4;
        gSpriteEntries[0x21 + i].unk9 = 4;
    }
}

u32 mf_charge_sparkles_update(u32 bot) {
    u32 i;
    u32 done = 0;
    struct Vec16 p;

    for (i = 0; i <= 7; i++) {
        if (gSpriteEntries[0x21 + i].unk0 == 0) {
            done++;
            continue;
        }
        gSpriteEntries[0x21 + i].unk0 |= 0x8000;
        gSpriteEntries[0x21 + i].unk28++;
        gSpriteEntries[0x21 + i].unk20 -= 8;
        if ((gSpriteEntries[0x21 + i].unk28 & 7) == 0)
            gSpriteEntries[0x21 + i].unk21--;
        p = compute_polar_to_screen_position(gSpriteEntries[0x21 + i].unk20, gSpriteEntries[0x21 + i].unk26 + 16,
                                             gSpriteEntries[bot * 4 + 0x5D].unk2, gSpriteEntries[0x21 + i].unk21, 8, 0);
        gSpriteEntries[0x21 + i].unk2 = p.x;
        gSpriteEntries[0x21 + i].unk4 = p.y;
        if (gSpriteEntries[0x21 + i].unk20 > 0x80)
            gSpriteEntries[0x21 + i].unkB = bot * 4 + 0x59;
        else
            gSpriteEntries[0x21 + i].unkB = 0x81;
        if (gSpriteEntries[0x21 + i].unk21 > gSpriteEntries[bot * 4 + 0x5D].unk4 - 8 &&
            gSpriteEntries[0x21 + i].unk8 != 0x40) {
            gSpriteEntries[0x21 + i].unk8 += 4;
            gSpriteEntries[0x21 + i].unk9 += 4;
        }
        if (gSpriteEntries[0x21 + i].unk21 < gSpriteEntries[bot * 4 + 0x5D].unk4 - 12 &&
            gSpriteEntries[0x21 + i].unk8 != 4) {
            gSpriteEntries[0x21 + i].unk8 -= 4;
            gSpriteEntries[0x21 + i].unk9 -= 4;
        }
        if (gSpriteEntries[0x21 + i].unk20 == 0xC0 &&
            gSpriteEntries[0x21 + i].unk21 < gSpriteEntries[bot * 4 + 0x5D].unk4 - 16)
            clear_battle_sprite_slot(0x21 + i, 1);
    }
    if (done == 8)
        return 1;
    return 0;
}

void battle_action_cleanup(u32 bot) {
    u32 i;
    u32 zero;
    u32 zero2;

    gBattleBots[bot].unkBD &= ~1;
    gBattleBots[bot].unkDE = gBattleBots[bot].chosenAction;
    if (gBattleBots[bot].chosenAction == 0)
        gBattleBots[bot].unkDF = 0;
    else if (gBattleBots[bot].chosenAction > 3)
        gBattleBots[bot].unkDF = 0;
    else
        gBattleBots[bot].unkDF = gBattleBots[bot].parts[gBattleBots[bot].chosenAction - 1].data[1];
    for (i = 0; i <= 3; i++) {
        gBattleBots[bot].parts[i].unkE = 0;
        gBattleBots[bot].parts[i].unkF = 0;
    }
    zero = 0;
    CpuSet(&zero, gUnk_030018A8, 0x05000008);
    zero2 = 0;
    CpuSet(&zero2, gUnk_030018A8 + 8, 0x05000008);
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].unk40 && (gBattleBots[i].unkBD & 0x18) && (u8)(gBattleBots[i].unkDE - 1) <= 2 &&
            gBattleBots[i].parts[gBattleBots[i].unkDE - 1].unk11 == 0)
            gBattleBots[i].unkBD &= 0xE7;
    }
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].unkBA)
            gBattleBots[i].unkBC &= 0xF;
    }
    restore_changed_part(bot);
}

void restore_changed_part(u32 bot) {
    u32 zero;

    if (gBattleWork.unk118) {
        gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[0] = gBattleWork.unk11C.data[0];
        gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] = gBattleWork.unk11C.data[1];
        gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[5] = gBattleWork.unk11C.data[5];
        gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[6] = gBattleWork.unk11C.data[6];
        gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[7] = gBattleWork.unk11C.data[7];
        gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[0xC] = gBattleWork.unk11C.data[0xC];
        gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].unk17 = gBattleWork.unk11C.unk17;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
    }
    zero = 0;
    CpuSet(&zero, &gBattleWork.unk118, 0x05000009);
}
