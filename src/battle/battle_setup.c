// Robattle start helpers: per-Medal skill use counters (count_bot_skill_use, called for each team Medabot by
// count_team_skill_uses), opponent defaults, the battle music choice (select_battle_music) and the action-select UI
// windows. Called from battle/robattle.

#include "global.h"
#include "keys.h"

static inline u32 sub1(u32 x) {
    return x - 1;
}

// Adds one to the bot's per-skill-type use counter (unkB0) for its chosen action: a part (unkDD 1-3) or
// one of the three Medal skills (4-6, available from Medal level 10 / 30 / 60).
void count_bot_skill_use(u32 rec) {
    u8 k;
    struct Unk_03000590 *base;
    struct Unk_03000590 *r;
    u32 off;

    if (rec > 2)
        return;
    base = gUnk_03000590;
    off = rec << 8;
    r = (struct Unk_03000590 *)((u8 *)base + off);
    if (r->unkDD == 0)
        return;
    if (r->unkDD <= 3) {
        k = *(u8 *)(sub1(r->unkDD) * 24 + off + (u32)base + 0x4A);
    } else {
        switch (r->unkDD - 4) {
        case 0:
            if (r->medal.unk5 <= 9)
                return;
            memcpy_bytes_08041D04(&gUnk_083B7E0C[r->medal.unk1 * 3], &gUnk_03000440.unkEE, 3);
            memcpy_bytes_08041D04(&gUnk_083B7CD4[(&gUnk_03000440.unkEE)[0] * 6], gUnk_03000440.unk10E, 6);
            k = gUnk_03000440.unk10E[1];
            break;
        case 1:
            if (r->medal.unk5 <= 29)
                return;
            memcpy_bytes_08041D04(&gUnk_083B7E0C[r->medal.unk1 * 3], &gUnk_03000440.unkEE, 3);
            memcpy_bytes_08041D04(&gUnk_083B7CD4[(&gUnk_03000440.unkEE)[1] * 6], gUnk_03000440.unk10E, 6);
            k = gUnk_03000440.unk10E[1];
            break;
        case 2:
            if (r->medal.unk5 <= 59)
                return;
            memcpy_bytes_08041D04(&gUnk_083B7E0C[r->medal.unk1 * 3], &gUnk_03000440.unkEE, 3);
            memcpy_bytes_08041D04(&gUnk_083B7CD4[(&gUnk_03000440.unkEE)[2] * 6], gUnk_03000440.unk10E, 6);
            k = gUnk_03000440.unk10E[1];
            break;
        default:
            return;
        }
    }
    {
        u32 t = k + off;
        register u32 q asm("r0") = (u32)base->unkB0;
        t += q;
        (*(u8 *)t)++;
    }
}

void count_team_skill_uses(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[i].unk40)
            count_bot_skill_use(i);
    }
}

// In battles of type 2 (gUnk_030057E0.unkC2E high nibble) the opponents start with a full Medaforce gauge.
void fill_opponent_medaforce_for_battle_type(void) {
    u32 i;

    if ((gUnk_030057E0.unkC2E & 0xF0) == 0x20) {
        for (i = 0; i <= 2; i++)
            gUnk_03000590[i + 3].unkC1 = 0x50;
    }
}

void select_battle_music(void) {
    if (gUnk_03000440.unk89 == 1)
        play_song(9);
    else if ((gUnk_030057E0.unkC2E & 0xF0) != 0) {
        if ((gUnk_030057E0.unkC2E & 0xF0) == 0x10)
            play_song(0xC);
        else
            play_song(0xD);
    } else
        play_song(gUnk_083AD3B0[gUnk_03000B94]);
}

void init_battle_action_select_ui(u32 a) {
    if (a != 0) {
        vram_fill_tilemap_rect(6, 5, 0xC, 0xF, REG_BG1CNT, 0);
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(1, 2);
    } else {
        set_tilemap_and_decompress_bg(0xC, 0xF, gUnk_084887A4, REG_BG1CNT, 0x230);
        gUnk_03002C30[0].unk0 = 0xC404;
        gUnk_03002C30[0].unk1C = 0;
        gUnk_03002C30[0].unkA = 0xA;
        gUnk_03002C30[0].unkB = 0x40;
        gUnk_03002C30[0].unk2 = 0x78;
        gUnk_03002C30[0].unk4 = 0x84;
        gUnk_03002C30[0].unk6 = 0x623;
        gUnk_03002C30[1].unk0 = 0xC404;
        gUnk_03002C30[1].unk1C = 0;
        gUnk_03002C30[1].unkA = 0xA;
        gUnk_03002C30[1].unkB = 0x40;
        gUnk_03002C30[1].unk2 = 0x70;
        gUnk_03002C30[1].unk4 = 0x90;
        gUnk_03002C30[1].unk6 = (u8)(gUnk_03001800.unk57 / 10) + 0x624;
        gUnk_03002C30[2].unk0 = 0xC404;
        gUnk_03002C30[2].unk1C = 0;
        gUnk_03002C30[2].unkA = 0xA;
        gUnk_03002C30[2].unkB = 0x40;
        gUnk_03002C30[2].unk2 = 0x80;
        gUnk_03002C30[2].unk4 = 0x90;
        gUnk_03002C30[2].unk6 = (u8)(gUnk_03001800.unk57 % 10) + 0x624;
    }
}
