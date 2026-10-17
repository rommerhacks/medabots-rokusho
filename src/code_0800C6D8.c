#include "global.h"

void debug_tinpet_update(void)
{
    gDebugTinpetHandlers[gUnk_03000440.unk33]();
}

void debug_tinpet_input(void)
{
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else
    {
        memcpy_bytes_0803F63C(gDebugTinpetLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
        gUnk_03000440.unk35[gUnk_03000440.unk34] ^= 1;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2)
    {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        if (!sub_08042218())
            add_position_entry(gUnk_03000440.unk35[0]);
    }
}

void debug_item_update(void)
{
    gDebugItemHandlers[gUnk_03000440.unk33]();
}

void debug_item_input(void)
{
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x40)
    {
        if (gUnk_03000440.unk34 == 0)
            gUnk_03000440.unk34 = 2;
        else
            gUnk_03000440.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80)
    {
        if (gUnk_03000440.unk34 == 2)
            gUnk_03000440.unk34 = 0;
        else
            gUnk_03000440.unk34++;
    }
    switch (gUnk_03000440.unk34)
    {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugItemLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugItemLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugItemLabels[2], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
    {
        if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x3E)
            gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
        else
            gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20)
    {
        if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
            gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x3E;
        else
            gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[2]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2))
    {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        switch (gUnk_03000440.unk34)
        {
        case 0:
            if (gUnk_03000440.unk35[0] < 0x40)
                sub_080422B8(gUnk_03000440.unk35[0], 1);
            break;
        case 1:
            if (gUnk_03000440.unk35[1] < 0x40)
                sub_08042318(gUnk_03000440.unk35[1], 1);
            break;
        default:
            for (gUnk_03000440.unk35[2] = b; gUnk_03000440.unk35[2] < 0x3F; gUnk_03000440.unk35[2]++)
                sub_080422B8(gUnk_03000440.unk35[2], 1);
            break;
        }
    }
}

void debug_face_update(void)
{
    gDebugFaceHandlers[gUnk_03000440.unk33]();
}

void debug_face_input(void)
{
    u8 b;

    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gUnk_03000440.unk34 ^= 1;
    switch (gUnk_03000440.unk34)
    {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugFaceLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugFaceLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
    {
        if (gUnk_03000440.unk34 == 0)
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0xAF)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
        else
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 8)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20)
    {
        if (gUnk_03000440.unk34 == 0)
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0xAF;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
        else
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 8;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2))
    {
        vram_fill_tilemap_rect(0x11, 8, 0, 7, REG_BG0CNT, 0);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        load_bg0_tilemap(gUnk_03000440.unk35[0], gUnk_03000440.unk35[1], 0, 7, 1);
        load_bg0_tilemap(gUnk_03000440.unk35[0], gUnk_03000440.unk35[1], 9, 7, b);
    }
}

void debug_mdlpic_update(void)
{
    gDebugMdlpicHandlers[gUnk_03000440.unk33]();
}

void debug_mdlpic_input(void)
{
    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gUnk_03000440.unk34 ^= 1;
    switch (gUnk_03000440.unk34)
    {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugFaceLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugFaceLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
    {
        if (gUnk_03000440.unk34 == 0)
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x1D)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
        else
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 4)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20)
    {
        if (gUnk_03000440.unk34 == 0)
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x1D;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
        else
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 4;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2)
    {
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        DmaSet(3, gUnk_084E2E98, 0x050003E0, 0x84000008);
        lz_decompress_dispatch(gUnk_083AC494[gUnk_03000440.unk35[0]][gUnk_03000440.unk35[1]], (void *)0x06010000);
        gUnk_03002C30[0].unk0 = 0xC004;
        gUnk_03002C30[0].unk2 = 0x40;
        gUnk_03002C30[0].unk4 = 0x50;
        gUnk_03002C30[0].unk6 = 0x200;
        gUnk_03002C30[0].unkA = 15;
        gUnk_03002C30[0].unk1C = 0;
        gUnk_03002C30[0].unkB = 0xC0;
    }
}

void debug_rndtk_update(void)
{
    gDebugRndTkHandlers[gUnk_03000440.unk33]();
}

void debug_rndtk_input(void)
{
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else
    {
        memcpy_bytes_0803F63C(gDebugRndTkLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
        gUnk_030057E0.unkC2C ^= 1;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_030057E0.unkC2C);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2)
    {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
}

void debug_battle_update(void)
{
    gDebugBattleHandlers[gUnk_03000440.unk33]();
}

void debug_battle_input(void)
{
    u8 b;

    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else
    {
        memcpy_bytes_0803F63C(gDebugBattleLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[gUnk_03000440.unk34]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2))
    {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        clear_battle_sprite_slot(8, 0x21);
        gUnk_030057E0.unkC2E = b;
        gUnk_030057E0.unkC2F = b;
        gUnk_030057E0.unkC2D = 1;
        gUnk_030057E0.unkC2A = gUnk_03000440.unk35[gUnk_03000440.unk34];
        gGameState = 6;
        gGameSubState = b;
    }
}

void debug_sound_update(void)
{
    gDebugSoundHandlers[gUnk_03000440.unk33]();
}

void debug_sound_input(void)
{
    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gUnk_03000440.unk34 ^= 1;
    switch (gUnk_03000440.unk34)
    {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugSoundLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugSoundLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else
        {
            memcpy_bytes_0803F63C(gDebugSoundLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugSoundLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
    {
        if (gUnk_03000440.unk34 == 0)
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x7F)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
        else
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x35)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20)
    {
        if (gUnk_03000440.unk34 == 0)
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x7F;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
        else
        {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x35;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2)
    {
        play_song(0);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        if (gUnk_03000440.unk34 == 0)
            play_sound_effect(gUnk_03000440.unk35[gUnk_03000440.unk34]);
        else
            play_song(gUnk_03000440.unk35[gUnk_03000440.unk34]);
    }
}

void debug_motion_update(void)
{
    gDebugMotionHandlers[gUnk_03000440.unk33]();
}

void debug_motion_init(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk39 = 0;
    gUnk_03000440.unk33++;
}

void debug_motion_load(void)
{
    init_scene_buffers_080445F4();
    setup_scene_with_bg_and_sprites(0, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, 0x38, 0x68, 0, 4, 0, 0, 0);
    setup_scene_with_bg_and_sprites(1, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, 0xB8, 0x30, 0, 8, 1, 0, 1);
    gUnk_03000440.unk33++;
}

void debug_motion_input(void)
{
    vu32 fill;
    u8 b;

    fill = 0x200;
    DmaSet(3, &fill, gUnk_03002414->unkB84, 0x85000100);
    init_scene_with_bg_and_palette(0, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, 0x38, 0x68, 0, 4, 0, 1, 0, 0);
    init_scene_with_bg_and_palette(1, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, 0xB8, 0x30, 0, 8, 1, 1, 1, 0x28);
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else
    {
        memcpy_bytes_0803F63C(gDebugMotionLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[gUnk_03000440.unk34]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gRepeatKeys) & 8)
    {
        if (gUnk_03000440.unk39 == 0x79)
            gUnk_03000440.unk39 = 0;
        else
            gUnk_03000440.unk39++;
        gUnk_03000440.unk33--;
    }
    else if ((b = KEYS_LO(gRepeatKeys) & 4))
    {
        if (gUnk_03000440.unk39 == 0)
            gUnk_03000440.unk39 = 0x79;
        else
            gUnk_03000440.unk39--;
        gUnk_03000440.unk33--;
    }
    else if (KEYS_LO(gNewKeys) & 2)
    {
        clear_battle_sprite_slot(8, 0x21);
        gUnk_03000430 = b;
        gGameSubState = 1;
    }
    else if (KEYS_LO(gNewKeys) & 1)
        gUnk_03000440.unk33++;
}

void debug_motion_play(void)
{
    vu32 fill;

    fill = 0x200;
    DmaSet(3, &fill, gUnk_03002414->unkB84, 0x85000100);
    init_scene_with_bg_and_palette(0, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, 0x38, 0x68, 0, 4, 0, 1, 0, 0);
    init_scene_with_bg_and_palette(1, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39, 0xB8, 0x30, 0, 8, 1, 1, 1, 0x28);
    advance_text_display(0, gUnk_03000440.unk35[gUnk_03000440.unk34], gUnk_03000440.unk39);
    advance_text_display(1, gUnk_03000440.unk35[gUnk_03000440.unk34], gUnk_03000440.unk39);
    if (KEYS_LO(gNewKeys) & 2)
        gUnk_03000440.unk33 -= 2;
}

void medaparts_screen_update(void)
{
    u32 fill;

    if (sub_0803EED8() == 0)
    {
        if (gUnk_03000430 == 2)
        {
            fill = 0x200;
            CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
        }
        gMedapartsScreenHandlers[gGameSubState]();
    }
}

void medaparts_list_load_gfx(void)
{
    u32 zero;

    if (gUnk_03000440.unk42 == 1)
        load_medapart_sprite_by_slot();
    else if (gUnk_03000440.unk3C == 4)
        play_song(7);
    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084EBF50, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C4014, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C4330, (void *)0x06006A00);
    lz_decompress_dispatch(gUnk_084C36F0, (void *)0x06006C00);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    lz_decompress_dispatch(gUnk_0848833C, (void *)0x06007000);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF550, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFF74, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0BF0, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F1D34, REG_BG3CNT, 0x200);
    if (gUnk_03000440.unk42 == 1)
    {
        CpuFastSet(gUnk_084F3460, (void *)0x0202FA00, 0x70);
        CpuFastSet((void *)0x05000200, (void *)0x0202F800, 0x80);
        CpuFastSet(gUnk_0850DD58 + 0x10, (void *)0x0202F9A0, 8);
        CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
        CpuFastSet(gUnk_08488B44, (void *)0x0202FB60, 8);
        gUnk_03000440.unk84 = 0;
    }
    else
    {
        CpuFastSet(gUnk_084F3460, (void *)0x05000000, 0x70);
        CpuFastSet(gUnk_0850DD58 + 0x10, (void *)0x050003A0, 8);
        CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
        CpuFastSet(gUnk_08488B44, (void *)0x05000160, 8);
        set_blend_effect_mode(5, 0x3F, 0x20);
    }
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    write_tilemap_rect(10, 2, 0x10, 0, gUnk_083B4AE0[gUnk_03000440.unk3E + 0x59], REG_BG0CNT, 0x200);
    medaparts_list_set_cursor_from_part();
    sub_08042950(gUnk_03000440.unk3F + 1, 0xB, 2, 2, REG_BG1CNT, 0x7360);
    medaparts_list_draw_names();
    medaparts_list_draw_counts();
    sub_0800EDA0();
    medaparts_list_draw_part_icons();
    medaparts_list_init_page_arrows();
    medaparts_list_init_cursor();
    gUnk_03000440.unk44 = 0;
    if (gUnk_03000440.unk42 != 1)
        medaparts_list_load_part_sprite();
    gGameSubState++;
}

void medaparts_list_fade_in(void)
{
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sub_08041C14(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (gUnk_03000440.unk42 == 1)
    {
        if (gUnk_03000440.unk84 <= 8)
        {
            blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xF0FF);
            gUnk_03000440.unk84++;
        }
        else
        {
            gUnk_03000440.unk42 = 0;
            gGameSubState++;
        }
    }
    else if (update_blend_effect())
    {
        gUnk_03000440.unk42 = 0;
        gGameSubState++;
    }
}

void medaparts_list_open_text_window(void)
{
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sub_08041C14(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medaparts_list_show_hint(void)
{
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sub_08041C14(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (run_message(gUnk_083B53F8[16]))
        gGameSubState++;
}

void medaparts_list_handle_input(void)
{
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sub_08041C14(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (medaparts_list_row_input())
        return;
    if (medaparts_list_page_input())
        return;
    if (medaparts_list_kind_input())
        return;
    if (KEYS_LO(gNewKeys) & 2)
    {
        if (gUnk_03000440.unk3C == 4)
        {
            play_sound_effect(6);
        }
        else
        {
            play_sound_effect(5);
            gGameSubState++;
        }
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        if ((u16)sub_08042114(gUnk_03000440.unk3D, gUnk_03000440.unk3E))
        {
            play_sound_effect(4);
            if (gUnk_03000440.unk3C == 4)
                gGameSubState = 0x40;
            else
                gGameSubState = 10;
        }
        else
        {
            play_sound_effect(6);
        }
    }
}

void medaparts_list_start_fade_out(void)
{
    set_blend_effect_mode(6, 0x3F, 0x20);
    CpuFastSet(gUnk_084E2E38, (void *)0x050003E0, 8);
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sub_08041C14(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    gGameSubState++;
}

void medaparts_list_wait_fade(void)
{
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sub_08041C14(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (update_blend_effect())
        gGameSubState++;
}

void medaparts_list_exit(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000430 = 0;
    gGameState = 2;
    gGameSubState = 0x10;
}

void medaparts_list_open_detail(void)
{
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sub_08041C14(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medaparts_list_detail_fade_out(void)
{
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sub_08041C14(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xF0FF);
        gUnk_03000440.unk84++;
    }
    else
    {
        gGameSubState = 0x10;
    }
}

void medapart_detail_load_gfx(void)
{
    u32 zero;

    sub_08043CA8();
    if (gUnk_03000440.unk3C == 0 || gUnk_03000440.unk3C == 4)
        load_medapart_sprite_by_slot();
    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084ECB3C, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C43C0, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C47A0, (void *)0x06007080);
    lz_decompress_dispatch(gUnk_084C4330, (void *)0x06007100);
    lz_decompress_dispatch(gUnk_084C47E0, (void *)0x06007200);
    lz_decompress_dispatch(gUnk_084C4BAC, (void *)0x06007300);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06007880);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF5A4, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0068, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0CA4, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F1EC8, REG_BG3CNT, 0x200);
    if (gUnk_03000440.unk3C == 0 || gUnk_03000440.unk3C == 4)
    {
        CpuFastSet(gUnk_084F3620, (void *)0x0202FA00, 0x70);
        CpuFastSet((void *)0x05000200, (void *)0x0202F800, 0x80);
        CpuFastSet(gUnk_0850DD58 + 0x40, (void *)0x0202F980, 8);
        CpuFastSet(gUnk_0850DD58 + 0x10, (void *)0x0202F9A0, 8);
        CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
        gUnk_03000440.unk84 = 0;
    }
    else
    {
        CpuFastSet(gUnk_084F3620, (void *)0x05000000, 0x70);
        CpuFastSet(gUnk_0850DD58 + 0x40, (void *)0x05000380, 8);
        CpuFastSet(gUnk_0850DD58 + 0x10, (void *)0x050003A0, 8);
        CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
        init_scene_buffers_0800F60C();
        load_overworld_sprite_by_direction();
        set_blend_effect_mode(5, 0x3F, 0x20);
    }
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    load_part_data(gUnk_03000440.unk3D, gUnk_03000440.unk3E, &gUnk_03000440.unkEE);
    load_npc_sprite_data();
    load_scene_sprite_data();
    render_menu_tilemap_section();
    load_script_data_to_buffer();
    fill_bg1_tilemap_from_state();
    setup_menu_tilemap_by_state();
    render_shop_price_display();
    count_compatible_medaparts();
    setup_battle_bot_count_sprites();
    gUnk_03000440.unk42 = 1;
    gGameSubState++;
}

void medapart_detail_fade_in(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    toggle_sprite_hflip_by_frame();
    if (gUnk_03000440.unk3C == 0 || gUnk_03000440.unk3C == 4)
    {
        if (gUnk_03000440.unk84 <= 8)
        {
            blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xF0FF);
            gUnk_03000440.unk84++;
        }
        else
        {
            gGameSubState++;
        }
    }
    else if (update_blend_effect())
    {
        gGameSubState++;
    }
}

void medapart_detail_open_text_window(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    toggle_sprite_hflip_by_frame();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medapart_detail_show_hint(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    toggle_sprite_hflip_by_frame();
    if (gUnk_03000440.unk3E <= 2)
    {
        if (run_message(gUnk_083BE3E4[sub_0800F6CC()]))
            gGameSubState++;
    }
    else
    {
        if (run_message(gUnk_083BE92C[sub_0800F6CC()]))
            gGameSubState++;
    }
}

void medapart_detail_handle_input(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    toggle_sprite_hflip_by_frame();
    if (handle_medapart_selection_scroll())
    {
        sub_0803FB0C();
        gGameSubState--;
    }
    else if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 8)
    {
        play_sound_effect(4);
        switch (gUnk_03000440.unk3E)
        {
        case 0:
            gUnk_03000440.unk43 = 3;
            break;
        case 1:
        case 2:
            gUnk_03000440.unk43 = 4;
            break;
        case 3:
            gUnk_03000440.unk43 = 5;
            break;
        }
        gGameSubState = 0x20;
    }
}

void medapart_detail_start_fade_out(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    toggle_sprite_hflip_by_frame();
    if (gUnk_03000440.unk3C == 0 || gUnk_03000440.unk3C == 4)
    {
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk84 = 0;
    }
    else
    {
        set_blend_effect_mode(6, 0x3F, 0x20);
    }
    gGameSubState++;
}

void medapart_detail_wait_fade(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    toggle_sprite_hflip_by_frame();
    if (gUnk_03000440.unk3C == 0 || gUnk_03000440.unk3C == 4)
    {
        if (gUnk_03000440.unk84 <= 8)
        {
            blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xF0FF);
            gUnk_03000440.unk84++;
        }
        else
        {
            gGameSubState++;
        }
    }
    else if (update_blend_effect())
    {
        gGameSubState++;
    }
}

void medapart_detail_exit(void)
{
    u32 zero1, zero2, zero3, zero4;

    load_medapart_sprite_by_slot();
    clear_battle_sprite_slot(0, 0x80);
    switch (gUnk_03000440.unk3C)
    {
    case 0:
    case 4:
        gGameSubState = 0;
        break;
    case 1:
        gUnk_03000430 = 0;
        gGameState = 3;
        gGameSubState = 0x10;
        switch (gUnk_03000440.unk3E)
        {
        case 0:
            gUnk_03000440.unk98 = gUnk_03000440.unk3D;
            break;
        case 1:
            gUnk_03000440.unk99 = gUnk_03000440.unk3D;
            break;
        case 2:
            gUnk_03000440.unk9A = gUnk_03000440.unk3D;
            break;
        case 3:
            gUnk_03000440.unk9B = gUnk_03000440.unk3D;
            break;
        }
        break;
    case 2:
        zero1 = 0;
        CpuFastSet(&zero1, (void *)0x05000200, 0x01000080);
        zero2 = 0;
        CpuFastSet(&zero2, (void *)0x05000000, 0x01000080);
        gUnk_03000430 = 0;
        gGameState = 6;
        gGameSubState = 0x65;
        break;
    case 3:
        zero3 = 0;
        CpuFastSet(&zero3, (void *)0x05000200, 0x01000080);
        zero4 = 0;
        CpuFastSet(&zero4, (void *)0x05000000, 0x01000080);
        gUnk_03000430 = 0;
        gGameMode = 2;
        gGameState = 0x19;
        gGameSubState = 0;
        break;
    }
}

void medaparts_help_load(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    clear_sprite_table_mask(1, 5);
    CpuFastSet(gUnk_084E2E78, (void *)0x050003C0, 8);
    setup_battle_cursor_sprite_0800FF50();
    sub_0803FB0C();
    gGameSubState++;
}

void medaparts_help_show_intro(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    process_sprite_anim_commands(gUnk_083B5F80[3], 6);
    if (run_message(gUnk_083B53F8[5]))
        gGameSubState++;
}

void medaparts_help_cursor_input(void)
{
    u8 up;

    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    process_sprite_anim_commands(gUnk_083B5F80[3], 6);
    if ((up = KEYS_LO(gRepeatKeys) & 0x40))
    {
        if (gUnk_03000440.unk44 == 0)
            gUnk_03000440.unk44 = gUnk_03000440.unk45 - 1;
        else
            gUnk_03000440.unk44--;
        play_sound_effect(2);
        sub_0800FFF4();
    }
    else if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk44 == gUnk_03000440.unk45 - 1)
            gUnk_03000440.unk44 = up;
        else
            gUnk_03000440.unk44++;
        play_sound_effect(2);
        sub_0800FFF4();
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        setup_battle_cursor_sprite_0800FF50();
        sub_0803FB0C();
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 0xA)
    {
        play_sound_effect(5);
        gGameSubState = 0x24;
    }
}

void medaparts_help_show_text(void)
{
    u8 done;

    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    switch (gUnk_03000440.unk3E)
    {
    case 0:
        switch (gUnk_03000440.unk44)
        {
        case 0:
            done = run_message(gUnk_083B8170[gUnk_03000440.unkF0]);
            break;
        case 1:
            done = run_message(gUnk_083B6E24[gUnk_03000440.unkEE]);
            break;
        case 2:
            done = run_message(gUnk_083B53F8[sub_08042B80(gUnk_03000440.unkF0) + 17]);
            break;
        case 3:
            done = run_message(gUnk_083BD884[0]);
            break;
        case 4:
            done = run_message(gUnk_083BD884[1]);
            break;
        case 5:
            done = run_message(gUnk_083BD884[2]);
            break;
        case 6:
            done = run_message(gUnk_083BD884[3]);
            break;
        }
        break;
    case 1:
    case 2:
        switch (gUnk_03000440.unk44)
        {
        case 0:
            done = run_message(gUnk_083B8170[gUnk_03000440.unkF0]);
            break;
        case 1:
            done = run_message(gUnk_083B6E24[gUnk_03000440.unkEE]);
            break;
        case 2:
            done = run_message(gUnk_083B53F8[sub_08042B80(gUnk_03000440.unkF0) + 17]);
            break;
        case 3:
            done = run_message(gUnk_083BD884[0]);
            break;
        case 4:
            done = run_message(gUnk_083BD884[1]);
            break;
        case 5:
            done = run_message(gUnk_083BD884[2]);
            break;
        case 6:
            done = run_message(gUnk_083BD884[4]);
            break;
        case 7:
            done = run_message(gUnk_083BD884[5]);
            break;
        }
        break;
    case 3:
        switch (gUnk_03000440.unk44)
        {
        case 0:
            done = run_message(gUnk_083B6E24[gUnk_03000440.unkEE]);
            break;
        case 1:
            done = run_message(gUnk_083B53F8[19]);
            break;
        case 2:
            done = run_message(gUnk_083BD884[0]);
            break;
        case 3:
            done = run_message(gUnk_083BD884[6]);
            break;
        case 4:
            done = run_message(gUnk_083BD884[7]);
            break;
        case 5:
            done = run_message(gUnk_083BD884[8]);
            break;
        case 6:
            done = run_message(gUnk_083BD884[9]);
            break;
        case 7:
            done = run_message(gUnk_083BD884[10]);
            break;
        }
        break;
    }
    if (done)
    {
        sub_0803FB0C();
        gGameSubState = 0x21;
    }
}

void medaparts_help_exit(void)
{
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    clear_sprite_table_mask(6, 1);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    sub_0803FB0C();
    setup_battle_bot_count_sprites();
    gGameSubState = 0x13;
}

INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EA2C);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EA98);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EB34);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EB60);

void sub_0800EBE4(void)
{
    clear_battle_sprite_slot(0, 0x80);
    sub_08043CA8();
    sub_08044CDC(2);
}

void medaparts_scroll_bg(void)
{
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void medaparts_list_set_cursor_from_part(void)
{
    gUnk_03000440.unk3F = gUnk_03000440.unk3D / 4;
    gUnk_03000440.unk40 = gUnk_03000440.unk3D % 4;
}

INCLUDE_ASM("asm/nonmatching/code_0800C6D8", medaparts_list_draw_names);

void medaparts_list_draw_counts(void)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        if (MEDAPART_INV(gUnk_03000440.unk3E, gUnk_03000440.unk3F, i, 0))
            sub_08042950(MEDAPART_INV(gUnk_03000440.unk3E, gUnk_03000440.unk3F, i, 0), 0x16, i * 2 + 5, 2, REG_BG1CNT, 0x7360);
        else
            sub_08042950(0, 0x16, i * 2 + 5, 2, REG_BG1CNT, 0x7360);
    }
}

void sub_0800EDA0(void)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        if (MEDAPART_INV(gUnk_03000440.unk3E, gUnk_03000440.unk3F, i, 1))
            sub_08042950(MEDAPART_INV(gUnk_03000440.unk3E, gUnk_03000440.unk3F, i, 1), 0x19, i * 2 + 5, 1, REG_BG1CNT, 0x6360);
        else
            sub_08042950(0, 0x19, i * 2 + 5, 1, REG_BG1CNT, 0x6360);
    }
}

void medaparts_list_draw_part_icons(void)
{
    u32 i;
    u32 page;

    for (i = 0; i < 4; i++)
    {
        if (gMedapartInventory[gUnk_03000440.unk3E * 240 + (page = gUnk_03000440.unk3F * 4) * 2 + i * 2])
        {
            load_part_data(page + i, gUnk_03000440.unk3E, &gUnk_03000440.unkEE);
            if (gUnk_03000440.unkF1)
                fill_tilemap_rect_08042698(2, 2, 0x1B, i * 2 + 5, REG_BG1CNT, 0xA354);
            else
                fill_tilemap_rect_08042698(2, 2, 0x1B, i * 2 + 5, REG_BG1CNT, 0xA350);
        }
        else
        {
            vram_fill_tilemap_rect(2, 2, 0x1B, i * 2 + 5, REG_BG1CNT, 0);
        }
    }
}

void medaparts_list_init_page_arrows(void)
{
    gUnk_03002C30[1].unk0 = 0xC804;
    gUnk_03002C30[1].unk2 = 0x4C;
    gUnk_03002C30[1].unk4 = 0x18;
    gUnk_03002C30[1].unk6 = 0x302;
    gUnk_03002C30[1].unkA = 14;
    gUnk_03002C30[1].unk1C = 0;
    gUnk_03002C30[1].unkB = 0x80;
    gUnk_03002C30[2].unk0 = 0xC804;
    gUnk_03002C30[2].unk2 = 0x8C;
    gUnk_03002C30[2].unk4 = 0x18;
    gUnk_03002C30[2].unk6 = 0x303;
    gUnk_03002C30[2].unkA = 14;
    gUnk_03002C30[2].unk1C = 0;
    gUnk_03002C30[2].unkB = 0x80;
}

void medaparts_list_blink_page_arrows(void)
{
    if (gFrameCounter & 8)
    {
        gUnk_03002C30[1].unk0 &= 0xBFFF;
        gUnk_03002C30[2].unk0 &= 0xBFFF;
    }
    else
    {
        gUnk_03002C30[1].unk0 |= 0x4000;
        gUnk_03002C30[2].unk0 |= 0x4000;
    }
}

void medaparts_list_init_cursor(void)
{
    gUnk_03002C30[3].unk0 = 0xC804;
    gUnk_03002C30[3].unk2 = 0x50;
    gUnk_03002C30[3].unk4 = gUnk_03000440.unk40 * 16 + 0x30;
    gUnk_03002C30[3].unk6 = 0x307;
    gUnk_03002C30[3].unkA = 14;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unkB = 0x81;
}

u32 medaparts_list_row_input(void)
{
    u32 ret;

    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        if (gUnk_03000440.unk40 == 0)
            gUnk_03000440.unk40 = 3;
        else
            gUnk_03000440.unk40--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk40 == 3)
            gUnk_03000440.unk40 = 0;
        else
            gUnk_03000440.unk40++;
    }
    if (!(KEYS_LO(gRepeatKeys) & 0xC0))
    {
        ret = 0;
    }
    else
    {
        play_sound_effect(2);
        gUnk_03000440.unk3D = gUnk_03000440.unk3F * 4 + gUnk_03000440.unk40;
        medaparts_list_init_cursor();
        load_overworld_sprite_by_direction();
        ret = 1;
    }
    return ret;
}

u32 medaparts_list_page_input(void)
{
    u32 ret;

    if (KEYS_LO(gRepeatKeys) & 0x20)
    {
        if (gUnk_03000440.unk3F == 0)
            gUnk_03000440.unk3F = 29;
        else
            gUnk_03000440.unk3F--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
    {
        if (gUnk_03000440.unk3F == 29)
            gUnk_03000440.unk3F = 0;
        else
            gUnk_03000440.unk3F++;
    }
    if (!(KEYS_LO(gRepeatKeys) & 0x30))
    {
        ret = 0;
    }
    else
    {
        play_sound_effect(2);
        gUnk_03000440.unk3D = gUnk_03000440.unk3F * 4 + gUnk_03000440.unk40;
        sub_08042950(gUnk_03000440.unk3F + 1, 0xB, 2, 2, REG_BG1CNT, 0x7360);
        medaparts_list_draw_names();
        medaparts_list_draw_counts();
        sub_0800EDA0();
        medaparts_list_draw_part_icons();
        load_overworld_sprite_by_direction();
        ret = 1;
    }
    return ret;
}

u32 medaparts_list_kind_input(void)
{
    u32 ret;

    if (KEYS_HI(gNewKeys) & 2)
    {
        if (gUnk_03000440.unk3E == 0)
            gUnk_03000440.unk3E = 3;
        else
            gUnk_03000440.unk3E--;
    }
    if (KEYS_HI(gNewKeys) & 1)
    {
        if (gUnk_03000440.unk3E == 3)
            gUnk_03000440.unk3E = 0;
        else
            gUnk_03000440.unk3E++;
    }
    if (!(KEYS_HI(gNewKeys) & 3))
    {
        ret = 0;
    }
    else
    {
        play_sound_effect(2);
        gUnk_03000440.unk3D = gUnk_03000440.unk3F * 4 + gUnk_03000440.unk40;
        write_tilemap_rect(10, 2, 0x10, 0, gUnk_083B4AE0[gUnk_03000440.unk3E + 0x59], REG_BG0CNT, 0x200);
        medaparts_list_draw_names();
        medaparts_list_draw_counts();
        sub_0800EDA0();
        medaparts_list_draw_part_icons();
        load_overworld_sprite_by_direction();
        ret = 1;
    }
    return ret;
}

void medaparts_list_load_part_sprite(void)
{
    struct Unk_08047414 *obj;
    u8 *b;
    u8 *c;
    u32 fill;

    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 4 + gUnk_03000440.unk40;
    obj = (struct Unk_08047414 *)0x02026000;
    sub_0803F624((u8 *)obj, 0xD0, 0);
    b = (u8 *)0x020260D0;
    sub_0803F624(b, 0x800, 0);
    c = (u8 *)0x020268D0;
    sub_0803F624(c, 0x60, 0);
    gUnk_03000430 = 2;
    gUnk_03002414 = (struct Unk_03002414 *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gUnk_03005308 = c;
    sub_08047414(obj, (u8 *)gUnk_03002414, (u32)gUnk_083D1BF8, (u32)b);
    obj->unk8 = (u32)b;
    load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, gUnk_03000440.unk3D, gUnk_03000440.unk3E, 0x3C, 0x28, 0x1C2, 8, 1);
}

INCLUDE_ASM("asm/nonmatching/code_0800C6D8", load_overworld_sprite_by_direction);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", load_medapart_sprite_by_slot);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", init_scene_buffers_0800F60C);

s32 sub_0800F6CC(void)
{
    s32 ret;
    if (gUnk_03000440.unkEF > 99)
        ret = gUnk_03000440.unkEF - 100;
    else
        ret = gUnk_03000440.unkEF;
    return ret;
}

INCLUDE_ASM("asm/nonmatching/code_0800C6D8", load_npc_sprite_data);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", load_scene_sprite_data);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", render_menu_tilemap_section);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", load_script_data_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", fill_bg1_tilemap_from_state);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", setup_menu_tilemap_by_state);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", render_shop_price_display);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", count_compatible_medaparts);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", setup_battle_bot_count_sprites);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", toggle_sprite_hflip_by_frame);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", handle_medapart_selection_scroll);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", setup_battle_cursor_sprite_0800FF50);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800FFF4);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_08010040);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_080100BC);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0801013C);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_08010170);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_080101E8);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0801022C);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", prebattle_intro_state_handler);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_080102C0);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_080103F4);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_08010478);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0801053C);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0801058C);
