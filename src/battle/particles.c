// Particle sprites (slots 0x21-0x3B): spawners (sub_080378F0, spawn_battle_particle_effect) and the
// per-sprite handlers run by sprite unk29 from gUnk_083AF530 (sub_08037B9C), gUnk_083AF690 (sub_080383E8),
// gUnk_083AF6E0 (sub_080385F8) and gUnk_083AF720 (sub_0803884C). Called from battle/medaforce_effects.

#include "global.h"

void sub_080378A8(void) {
    if (!(gUnk_03001800.unkF8 & 2))
        gSpriteEntries[0x21].unk2 = (gSpriteEntries[0x21].unk2 + 4) & 0x1FF;
    else
        gSpriteEntries[0x21].unk2 = (gSpriteEntries[0x21].unk2 - 4) & 0x1FF;
}

static void sub_080378F0(u32 src) {
    u32 mask;
    u32 n;
    struct SpriteEntry *p, *s;
    struct SpriteEntry *base;

    switch (gUnk_03001800.unk51) {
    case 0:
        mask = 0xF;
        break;
    case 1:
        mask = 7;
        break;
    case 2:
        mask = 7;
        break;
    case 3:
        mask = 7;
        break;
    case 4:
        mask = 7;
        break;
    case 5:
        mask = 7;
        break;
    }
    base = gSpriteEntries;
    p = &base[src];
    if (!(p->unk2D & mask)) {
        n = find_next_free_sprite_slot(src + 1, 0x14);
        clear_battle_sprite_slot(n, 1);
        s = &base[n];
        s->unk0 = 0xC604;
        s->unk1C = 0;
        s->unk2 = (p->unk2 + gUnk_083AF520[(rng_next_byte() & 3) * 2]) & 0x1FF;
        s->unk4 = (p->unk4 + gUnk_083AF520[(rng_next_byte() & 3) * 2 + 1]) & 0xFF;
        s->unk8 = 0x40;
        s->unk9 = 0x40;
        s->unkA = 6;
        s->unkB = 0xE0;
        switch (gUnk_03001800.unk51) {
        case 0:
            gSpriteEntries[n].unk6 = (rng_next_byte() & 3) + 0x6B01;
            gSpriteEntries[n].unk29 = 0x10;
            break;
        case 1:
            gSpriteEntries[n].unk6 = 0x6C01;
            gSpriteEntries[n].unk29 = 0x14;
            break;
        case 2:
            gSpriteEntries[n].unk6 = 0x6D01;
            gSpriteEntries[n].unk29 = 0x18;
            break;
        case 3:
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x5E], n);
            gSpriteEntries[n].unk29 = 0x1C;
            break;
        case 4:
            gSpriteEntries[n].unk6 = 0x7001;
            gSpriteEntries[n].unk29 = 0x20;
            break;
        case 5:
            break;
        }
    }
}

void spawn_battle_particle_effect(u32 src) {
    u32 mask;
    u32 n;
    struct SpriteEntry *p, *s;
    struct SpriteEntry *base;

    switch (gUnk_03001800.unk51) {
    case 0:
        mask = 7;
        break;
    case 1:
        mask = 7;
        break;
    case 2:
        mask = 7;
        break;
    }
    base = gSpriteEntries;
    p = &base[src];
    if (!(p->unk2D & mask)) {
        n = find_next_free_sprite_slot(src + 1, 0x14);
        clear_battle_sprite_slot(n, 1);
        s = &base[n];
        s->unk0 = 0xC604;
        s->unk1C = 0;
        s->unk2 = (p->unk2 + gUnk_083AF520[(rng_next_byte() & 3) * 2]) & 0x1FF;
        s->unk4 = (p->unk4 + gUnk_083AF520[(rng_next_byte() & 3) * 2 + 1]) & 0xFF;
        s->unk8 = 0x40;
        s->unk9 = 0x40;
        s->unkA = 6;
        s->unkB = 0xE0;
        switch (gUnk_03001800.unk51) {
        case 0:
            s->unk6 = 0x7201;
            s->unk29 = 0x30;
            break;
        case 1:
            s->unk6 = 0x7302;
            s->unk29 = 0x34;
            break;
        case 2:
            s->unk6 = 0x7402;
            s->unk29 = 0x34;
            break;
        }
    }
}

u32 sub_08037B9C(void) {
    u32 done = 1;
    u32 i;
    u32 k;

    for (i = 0; i <= 0x1A; i++) {
        gUnk_0300056F = i + 0x21;
        if (gSpriteEntries[i + 0x21].unk29)
            done = 0;
        k = gSpriteEntries[i + 0x21].unk29;
        gUnk_083AF530[k]();
    }
    return done;
}

void sub_08037BF4(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2E], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk4 == 0x14)
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    else
        gSpriteEntries[gUnk_03000440.unk12F].unk4 = (gSpriteEntries[gUnk_03000440.unk12F].unk4 + 1) & 0xFF;
}

void sub_08037C50(void) {
    struct Coords16 v;

    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2E], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0xFF) {
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
        return;
    }
    if (!(gSpriteEntries[gUnk_03000440.unk12F].unk2D & 0x3F)) {
        switch (gUnk_03001800.unk51) {
        case 0:
            play_sound_effect(0x36);
            break;
        case 1:
            play_sound_effect(0x28);
            break;
        case 2:
            play_sound_effect(0x31);
            break;
        case 3:
            play_sound_effect(0x71);
            break;
        case 4:
            play_sound_effect(0x4F);
            break;
        case 5:
            break;
        }
    }
    gSpriteEntries[gUnk_03000440.unk12F].unk2B +=
        gUnk_083AF630[(gSpriteEntries[gUnk_03000440.unk12F].unk2D & 0x1F) * 2];
    if (!(gUnk_03001800.unkF8 & 1)) {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
        v = calc_polar_to_screen_coords(gSpriteEntries[gUnk_03000440.unk12F].unk2C,
                                        gSpriteEntries[gUnk_03000440.unk12F].unk2B, 0xB8, 0x34);
    } else {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gUnk_03000440.unk12F].unk2C++;
        v = calc_polar_to_screen_coords(gSpriteEntries[gUnk_03000440.unk12F].unk2C,
                                        gSpriteEntries[gUnk_03000440.unk12F].unk2B, 0x38, 0x34);
    }
    gSpriteEntries[gUnk_03000440.unk12F].unk2 = v.x;
    gSpriteEntries[gUnk_03000440.unk12F].unk4 = v.y;
    sub_080378F0(gUnk_03000440.unk12F);
    gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
}

void sub_08037E2C(void) {
    struct Coords16 v;

    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2E], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0xFF) {
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
        return;
    }
    if (!(gSpriteEntries[gUnk_03000440.unk12F].unk2D & 0x3F)) {
        switch (gUnk_03001800.unk51) {
        case 0:
            play_sound_effect(0x5D);
            break;
        case 1:
            play_sound_effect(0x2E);
            break;
        case 2:
            play_sound_effect(0x4B);
            break;
        }
    }
    gSpriteEntries[gUnk_03000440.unk12F].unk2B +=
        gUnk_083AF630[(gSpriteEntries[gUnk_03000440.unk12F].unk2D & 0x1F) * 2];
    if (gUnk_03001800.unkF8 & 1) {
        if (gUnk_03001800.unk51 == 0)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
        v = calc_polar_to_screen_coords(gSpriteEntries[gUnk_03000440.unk12F].unk2C,
                                        gSpriteEntries[gUnk_03000440.unk12F].unk2B, 0xB8, 0x34);
    } else {
        if (gUnk_03001800.unk51 == 0)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gUnk_03000440.unk12F].unk2C++;
        v = calc_polar_to_screen_coords(gSpriteEntries[gUnk_03000440.unk12F].unk2C,
                                        gSpriteEntries[gUnk_03000440.unk12F].unk2B, 0x38, 0x34);
    }
    gSpriteEntries[gUnk_03000440.unk12F].unk2 = v.x;
    gSpriteEntries[gUnk_03000440.unk12F].unk4 = v.y;
    spawn_battle_particle_effect(gUnk_03000440.unk12F);
    gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
}

void sub_08037FE4(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk8 == 4) {
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    } else {
        gSpriteEntries[gUnk_03000440.unk12F].unk8 -= 4;
        gSpriteEntries[gUnk_03000440.unk12F].unk9 -= 4;
    }
}

void sub_08038024(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0x5A)
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    else
        gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
}

void sub_0803805C(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk8 == 8) {
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    } else {
        gSpriteEntries[gUnk_03000440.unk12F].unk8 -= 8;
        gSpriteEntries[gUnk_03000440.unk12F].unk9 -= 8;
    }
}

void sub_0803809C(void) {
    clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_080380B8(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0x23)
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    else
        gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
}

void sub_080380F0(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0x46) {
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    } else {
        gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 +
                                                     gUnk_083AF670[gSpriteEntries[gUnk_03000440.unk12F].unk2D & 0xF]) &
                                                    0x1FF;
        if (gSpriteEntries[gUnk_03000440.unk12F].unk2D & 1)
            gSpriteEntries[gUnk_03000440.unk12F].unk4++;
        gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_08038178(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x5E], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0x5A)
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    else {
        if (!(gSpriteEntries[gUnk_03000440.unk12F].unk2D & 7))
            gSpriteEntries[gUnk_03000440.unk12F].unk4--;
        gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_080381E0(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0x23) {
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    } else {
        if (!(gUnk_03001800.unkF8 & 1))
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_08038258(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0x46) {
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    } else {
        if (gSpriteEntries[gUnk_03000440.unk12F].unk2D & 1)
            gSpriteEntries[gUnk_03000440.unk12F].unk4++;
        if (!(gUnk_03001800.unkF8 & 1))
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_080382F4(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0x5A) {
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
    } else {
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_0803836C(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        gUnk_03001800.unkD2[i] = 0;
        gUnk_03001800.unkD6[i] = 0;
    }
}

void sub_08038394(u32 rec, u32 flags) {
    if (flags & 1) {
        gUnk_03000590[rec].unkC9 = 0;
        gUnk_03000590[rec].unkCA = 0;
        gUnk_03000590[rec].unkCB = 0;
        gUnk_03000590[rec].unkCC = 0;
    }
    if (flags & 2) {
        gUnk_03000590[rec].unkC4 = 0;
        gUnk_03000590[rec].unkC5 = 0;
        gUnk_03000590[rec].unkC6 = 0;
        gUnk_03000590[rec].unkC7 = 0;
    }
}

void sub_080383E8(void) {
    u32 i;
    for (i = 10; i <= 0x1A; i++) {
        gUnk_0300056F = i + 0x21;
        gUnk_083AF690[gSpriteEntries[i + 0x21].unk29]();
    }
}

void sub_08038428(void) {
    u32 r, slot;
    struct SpriteEntry *s;
    struct SpriteEntry *base;

    if ((r = gUnk_03000440.unk86 & 7) == 0) {
        slot = find_next_free_sprite_slot(gUnk_03000440.unk12F + 1, 10);
        clear_battle_sprite_slot(slot, 1);
        base = gSpriteEntries;
        s = &base[slot];
        s->unk0 = 0xC604;
        s->unk1C = 0;
        s->unk2 = 0x78;
        s->unk4 = 0x78;
        s->unk8 = 0x40;
        s->unk9 = 0x40;
        s->unk18 = r;
        s->unkA = 6;
        s->unkB = 0xF0;
        s->unk6 = 0x7706;
        s->unk29 = 2;
        s->unk24 = 3;
        s->unk23 = 0;
        r = rng_next_byte() & 3;
        if (!(gUnk_03001800.unkF8 & 1)) {
            s->unk2 = (base[gUnk_03000440.unk12F].unk2 + gUnk_083AF6D0[r << 1]) & 0x1FF;
            s->unk4 = (base[gUnk_03000440.unk12F].unk4 + gUnk_083AF6D0[r * 2 + 1]) & 0xFF;
            s->unk30 = base[gUnk_03000440.unk12F].unk2 + 0x10;
            s->unk32 = base[gUnk_03000440.unk12F].unk4 + 4;
        } else {
            s->unk2 = (0xF0 - (base[gUnk_03000440.unk12F].unk2 + gUnk_083AF6D0[r << 1])) & 0x1FF;
            s->unk4 = (base[gUnk_03000440.unk12F].unk4 + gUnk_083AF6D0[r * 2 + 1]) & 0xFF;
            s->unk30 = base[gUnk_03000440.unk12F].unk2 - 0x10;
            s->unk32 = base[gUnk_03000440.unk12F].unk4 + 6;
        }
    }
}

void sub_0803858C(void) {
    gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
    if (move_sprite_toward_target(gUnk_03000440.unk12F))
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_080385D0(u32 rec) {
    u32 i;
    struct Unk_03001800 *b;
    for (i = 0, b = &gUnk_03001800; i <= 5; i++) {
        if (b->unk45[i][0] == rec + 1) {
            b->unk45[i][0] = 0;
            b->unk45[i][1] = 0;
        }
    }
}

u32 sub_080385F8(void) {
    u32 done = 1;
    u32 i;
    u32 k;

    for (i = 0; i <= 0x1A; i++) {
        gUnk_0300056F = i + 0x21;
        if (gSpriteEntries[i + 0x21].unk29)
            done = 0;
        k = gSpriteEntries[i + 0x21].unk29;
        gUnk_083AF6E0[k]();
    }
    return done;
}

void sub_08038650(void) {
    if (move_sprite_toward_target(gUnk_03000440.unk12F)) {
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6B], gUnk_03000440.unk12F);
        gSpriteEntries[gUnk_03000440.unk12F].unkA = 6;
        gSpriteEntries[gUnk_03000440.unk12F].unk28 = 0;
        gSpriteEntries[gUnk_03000440.unk12F].unk29++;
        memcpy_bytes_0803F63C(&gSpriteEntries[gUnk_03000440.unk12F], &gSpriteEntries[gUnk_03000440.unk12F + 3], 0x40);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6C], gUnk_03000440.unk12F + 3);
        gSpriteEntries[gUnk_03000440.unk12F + 3].unkB =
            (gUnk_03000440.unk12F + (gUnk_03001800.unk60 + 0xDF)) * 4 + 0x59;
        gSpriteEntries[gUnk_03000440.unk12F + 3].unk29 = 3;
    }
}

void sub_08038700(void) {
    gSpriteEntries[gUnk_03000440.unk12F].unk28++;
    if (gSpriteEntries[gUnk_03000440.unk12F].unk28 & 2)
        gSpriteEntries[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))) * 4 + 0x5D].unk4 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))].y + 2;
    else
        gSpriteEntries[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))) * 4 + 0x5D].unk4 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))].y + 4;
    target_cursor_place_markers((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)));
    process_sprite_anim_commands(gUnk_083B5F80[0x6B], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk22 == 0xFF) {
        gSpriteEntries[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))) * 4 + 0x5D].unk4 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))].y + 4;
        target_cursor_place_markers((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)));
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    }
}

void sub_08038804(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x6C], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

u32 sub_0803884C(void) {
    u32 done = 1;
    u32 i;
    u32 k;

    for (i = 0; i <= 0x1A; i++) {
        gUnk_0300056F = i + 0x21;
        if (gSpriteEntries[i + 0x21].unk29)
            done = 0;
        k = gSpriteEntries[i + 0x21].unk29;
        gUnk_083AF720[k]();
    }
    return done;
}

void sub_080388A4(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x6D], gUnk_03000440.unk12F);
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 + 4) & 0x1FF;
        if (gSpriteEntries[gUnk_03000440.unk12F].unk2 >
                gSpriteEntries[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk2 &&
            gUnk_03001800.unkD6[gUnk_03000440.unk12F - 0x21] != 0 && gSpriteEntries[gUnk_03000440.unk12F].unk28 == 0) {
            play_sound_effect(0x54);
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk0 = 0xC404;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk1C = 0;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk2 =
                gSpriteEntries[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk2;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk4 =
                gSpriteEntries[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk4 - 4;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unkA = 6;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unkB = 0xF1;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk29 = 2;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk28 = 0;
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6E], gUnk_03000440.unk12F + 3);
            gSpriteEntries[gUnk_03000440.unk12F].unk28 = 1;
        }
    } else {
        gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 - 4) & 0x1FF;
        if (gSpriteEntries[gUnk_03000440.unk12F].unk2 <
                gSpriteEntries[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk2 &&
            gUnk_03001800.unkD6[gUnk_03000440.unk12F - 0x21] != 0 && gSpriteEntries[gUnk_03000440.unk12F].unk28 == 0) {
            play_sound_effect(0x54);
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk0 = 0xD404;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk1C = 0;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk2 =
                gSpriteEntries[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk2;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk4 =
                gSpriteEntries[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk4 - 4;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unkA = 6;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unkB = 0xF1;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk29 = 2;
            gSpriteEntries[gUnk_03000440.unk12F + 3].unk28 = 0;
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6E], gUnk_03000440.unk12F + 3);
            gSpriteEntries[gUnk_03000440.unk12F].unk28 = 1;
        }
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk27 > 0x28)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    else
        gSpriteEntries[gUnk_03000440.unk12F].unk27++;
}

void sub_08038AC0(void) {
    gSpriteEntries[gUnk_03000440.unk12F].unk28++;
    if (gSpriteEntries[gUnk_03000440.unk12F].unk28 & 2)
        gSpriteEntries[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))) * 4 + 0x5D].unk2 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))].x + 2;
    else
        gSpriteEntries[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))) * 4 + 0x5D].unk2 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))].x - 2;
    target_cursor_place_markers((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24)));
    process_sprite_anim_commands(gUnk_083B5F80[0x6E], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk22 == 0xFF) {
        gSpriteEntries[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))) * 4 + 0x5D].unk2 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))].x;
        target_cursor_place_markers((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24)));
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    }
}
