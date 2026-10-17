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

INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800D9DC);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DA34);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DD00);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DD88);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DDC0);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DE00);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DEC8);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DF14);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DF4C);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DF78);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800DFB8);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E020);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E2B0);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E328);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E350);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E3A0);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E43C);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E488);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E4F8);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E654);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E690);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E6C8);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E78C);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800E9F0);
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

INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EBFC);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EC20);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EC44);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800ED10);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EDA0);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EE34);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EEE4);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EF58);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EFB0);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800EFFC);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800F08C);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800F148);
INCLUDE_ASM("asm/nonmatching/code_0800C6D8", sub_0800F218);
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
