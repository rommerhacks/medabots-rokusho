// Vehicle menu (guess from the code: no scenario reaches it), mode-1 handler 2: sub_08057024 runs the
// gUnk_083D5E08 sub-states (load graphics, slide the window in, cursor input, slide out, leave through
// switch_game_mode, restore the field). check_vehicle_usability says which of the four entries can be used;
// the menu state lives in gUnk_030064A0 after the choice menu. Uses engine/ tilemap and sprite helpers.
#include "global.h"

static u32 check_vehicle_usability(s32 idx);
static void handle_cursor_up_down_input(s32 count);
static void sub_08057EBC(void);
static void update_cursor_sprite_position(void);
static void init_vehicle_menu_sprite(s32 slide);
static void render_npc_tilemap_row(s32 row);

void sub_08057024(void) {
    gUnk_083D5E08[gGameSubState]();
}

void sub_08057044(void) {
    memzero_bytes((u8 *)&gUnk_030064A0, 0x874);
    LZ77UnCompVram(gUnk_085FA144, (void *)0x06000F80);
    LZ77UnCompVram(gUnk_085FA5D8, (void *)0x06002100);
    memzero_bytes((u8 *)gUnk_03006D14, 0x2000);
    DmaSet(3, gUnk_085FA4D8, gUnk_03006D14, DMA_ENABLE | (0xE0 / 2));
    DmaSet(3, gUnk_085FA620, gUnk_03006D14 + 0x200, DMA_ENABLE | (0x20 / 2));
    copy_tilemap_region((u16 *)gUnk_083D5F30, gUnk_03006D14 + 0x400, 0, 0, 0x10, 10, 0, 0xF, 0);
    fill_tilemap_rect_0804916C(gUnk_03006D14 + 0x800, 2, 0xE, 0x10, 10, 0, 0xF, 0);
    copy_tilemap_region(gUnk_03006D14, gUnk_03006D14 + 0x400, 1, 1, 0xE, 8, 0x7C, 0xE, 0);

    switch (check_vehicle_usability(0)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA660, (void *)0x06016F80);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06016F80);
        render_npc_tilemap_row(0);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA87C, (void *)0x06016F80);
        break;
    }
    switch (check_vehicle_usability(1)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA6E8, (void *)0x06017000);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017000);
        render_npc_tilemap_row(1);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA904, (void *)0x06017000);
        break;
    }
    switch (check_vehicle_usability(2)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA774, (void *)0x06017080);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017080);
        render_npc_tilemap_row(2);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA990, (void *)0x06017080);
        break;
    }
    switch (check_vehicle_usability(3)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA7FC, (void *)0x06017100);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017100);
        render_npc_tilemap_row(3);
        break;
    default:
        LZ77UnCompVram(gUnk_085FAA18, (void *)0x06017100);
        break;
    }

    DmaCopy32(3, gUnk_085FA640, OBJ_PLTT + 0x180, 32) DmaCopy32(3, gUnk_085FA85C, OBJ_PLTT + 0x1A0, 32)
        decompress_bg_tiles_to_vram_bg();
    DmaCopy32(3, gUnk_084C6998, PLTT + 0x1C0, 32) lz_decompress_dispatch(gUnk_084878EC, (void *)0x06002600);
    lz_decompress_dispatch(gUnk_0848796C, (void *)0x060026E0);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    DmaCopy32(3, gUnk_084E2E58, OBJ_PLTT + 0x1C0, 32) gUnk_030064A0.unk66 = 0;
    gUnk_030064A0.unk67 = 0;
    gUnk_030064A0.unk6F = 0;
    gUnk_030064A0.unk6E = gUnk_030064A0.unk6D = gUnk_030064A0.unk6C = 0;
    gUnk_030064A0.unk6C = 0x10;
    gUnk_030064A0.unk6D = 3;
    sub_0804A1C4();
}

void sub_080572F8(void) {
    gUnk_030064A0.unk66 = 0;
    if (gUnk_030064A0.unk6F < 0x10) {
        gUnk_030064A0.unk6F++;
        copy_tilemap_rect_with_offset(gUnk_03006D14 + 0x400, (u16 *)0x06002800, 2, 0x1E - gUnk_030064A0.unk6F,
                                      gUnk_030064A0.unk6F, 10, 0x20, 0x20, 0, 0);
        init_vehicle_menu_sprite(0);
    } else {
        sprite_entry_init(0x7F, 0xC004, 0x307, 0xC, 0);
        update_cursor_sprite_position();
        gUnk_030064A0.unk65 = 0;
        init_cursor_state();
        sub_0804A1C4();
    }
}

static void sub_08057380(void) {
    sub_0804A1C4();
}

void sub_0805738C(void) {
    u32 r;

    gUnk_030064A0.unk67++;
    update_cursor_sprite_position();
    handle_cursor_up_down_input(4);
    if (KEYS_LO(gNewKeys) & 1) {
        r = check_vehicle_usability(gUnk_030064A0.unk65);
        if (r != 0) {
            gUnk_030064A0.unk67 = 0;
            update_cursor_sprite_position();
            sub_08047BA8(6);
            switch (r) {
            case 1:
                break;
            case 2:
                gUnk_030064A0.unk70 = 0;
                gGameSubState = 0xB;
                break;
            case 3:
                gGameSubState = 0xD;
                break;
            case 4:
            case 5:
            case 6:
                gGameSubState = 0xF;
                break;
            }
        } else {
            copy_tilemap_rect_with_offset((u16 *)0x06002800, gUnk_030064A0.unk72, 0, 0, 0x1E, 0x14, 0x20, 0x20, r, r);
            sub_08047BA8(4);
            gGameSubState = 0xA;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        sub_08047BA8(5);
        sprite_entry_clear(0x7F);
        gUnk_030064A0.unk6F = 0x10;
        sub_0804A1C4();
    }
}

void sub_08057494(void) {
    if (gUnk_030064A0.unk6F != 0) {
        copy_tilemap_rect_with_offset(gUnk_03006D14 + 0x800, (u16 *)0x06002800, 2, 0x1E - gUnk_030064A0.unk6F, 1, 10,
                                      0x20, 0x20, 0, 0);
        copy_tilemap_rect_with_offset(gUnk_03006D14 + 0x400, (u16 *)0x06002800, 2, 0x1F - gUnk_030064A0.unk6F,
                                      gUnk_030064A0.unk6F, 10, 0x20, 0x20, 0, 0);
        init_vehicle_menu_sprite(1);
        gUnk_030064A0.unk6F--;
    } else {
        lz_decompress_dispatch(gUnk_084C1ACC, (void *)0x06002100);
        sub_0804A1C4();
    }
}

void sub_08057540(void) {
    switch_game_mode(0x40, 0);
}

void sub_08057550(void) {
    setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, 8.0f);
    sub_0804A1C4();
}

void sub_08057574(void) {
    if (run_blend_fade_transition(0))
        sub_0804A1C4();
}

void sub_08057588(void) {
    switch_game_mode(6, 0);
}

void sub_08057598(void) {
    u32 zero;

    sub_0804B1FC();
    memzero_bytes((u8 *)gUnk_03002C30, 0x2000);
    memzero_bytes((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    REG_DISPCNT = 0x1F40;
    gUnk_030057E0.unkCBA = 1;
    area_load_graphics();
    lz_decompress_dispatch(gUnk_084C1C14, (void *)0x060017E0);
    lz_decompress_dispatch(gUnk_084C1608, (void *)0x06001800);
    lz_decompress_dispatch(gUnk_084C17F0, (void *)0x06001B00);
    lz_decompress_dispatch(gUnk_084C1934, (void *)0x06001E00);
    lz_decompress_dispatch(gUnk_084C1ACC, (void *)0x06002100);
    lz_decompress_dispatch(gUnk_08487708, (void *)0x06002400);
    DmaCopy32(3, gUnk_08488A84, 0x0202FBE0, 32) lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    DmaCopy32(3, gUnk_084E2E38, 0x0202F9E0, 32) LZ77UnCompVram(gUnk_085FA144, (void *)0x06000F80);
    LZ77UnCompVram(gUnk_085FA5D8, (void *)0x06002100);
    memzero_bytes((u8 *)gUnk_03006D14, 0x2000);
    DmaSet(3, gUnk_085FA4D8, gUnk_03006D14, DMA_ENABLE | (0xE0 / 2));
    DmaSet(3, gUnk_085FA620, gUnk_03006D14 + 0x200, DMA_ENABLE | (0x20 / 2));
    copy_tilemap_region((u16 *)gUnk_083D5F30, gUnk_03006D14 + 0x400, 0, 0, 0x10, 10, 0, 0xF, 0);
    fill_tilemap_rect_0804916C(gUnk_03006D14 + 0x800, 2, 0xE, 0x10, 10, 0, 0xF, 0);
    copy_tilemap_region(gUnk_03006D14, gUnk_03006D14 + 0x400, 1, 1, 0xE, 8, 0x7C, 0xE, 0);

    switch (check_vehicle_usability(0)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA660, (void *)0x06016F80);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06016F80);
        render_npc_tilemap_row(0);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA87C, (void *)0x06016F80);
        break;
    }
    switch (check_vehicle_usability(1)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA6E8, (void *)0x06017000);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017000);
        render_npc_tilemap_row(1);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA904, (void *)0x06017000);
        break;
    }
    switch (check_vehicle_usability(2)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA774, (void *)0x06017080);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017080);
        render_npc_tilemap_row(2);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA990, (void *)0x06017080);
        break;
    }
    switch (check_vehicle_usability(3)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA7FC, (void *)0x06017100);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017100);
        render_npc_tilemap_row(3);
        break;
    default:
        LZ77UnCompVram(gUnk_085FAA18, (void *)0x06017100);
        break;
    }

    lz_decompress_dispatch(gUnk_084873D0, (void *)0x06000020);
    lz_decompress_dispatch(gUnk_084C31BC, (void *)0x06001780);
    DmaCopy32(3, gUnk_08488A84, 0x0202FBE0, 32) DmaCopy32(3, gUnk_084C6998, 0x0202FBC0, 32)
        lz_decompress_dispatch(gUnk_084878EC, (void *)0x06002600);
    lz_decompress_dispatch(gUnk_0848796C, (void *)0x060026E0);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    DmaCopy32(3, gUnk_084E2E58, 0x0202F9C0, 32)
        copy_tilemap_rect_with_offset(gUnk_030064A0.unk72, (u16 *)0x06002800, 0, 0, 0x1E, 0x14, 0x20, 0x20, 0, 0);
    DmaCopy32(3, gUnk_085FA640, 0x0202F980, 32) DmaCopy32(3, gUnk_085FA85C, 0x0202F9A0, 32) init_vehicle_menu_sprite(0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_08057988(void) {
    if (run_blend_fade_transition(0)) {
        sprite_entry_init(0x7F, 0xC004, 0x307, 0xC, 0);
        update_cursor_sprite_position();
        gGameSubState = 2;
    }
}

void sub_080579C4(void) {
    struct Unk_030064A0 *s = &gUnk_030064A0;

    if (s->unk65 != 2) {
        sub_0804B1FC();
        sub_08057EBC();
    }
    sprite_entry_clear(0x7F);
    if (s->unk65 == 0)
        switch_game_mode(0x41, 0);
    else if (s->unk65 == 1)
        switch_game_mode(0x43, 0);
    else if (s->unk65 == 2)
        gGameSubState = 5;
    else if (s->unk65 == 3)
        switch_game_mode(0x42, 0);
}

void sub_08057A24(void) {
    u32 id;

    if (gUnk_030064A0.unk65 == 0) {
        id = 0x55;
        switch (gUnk_030064A0.unk70) {
        case 0:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        case 1:
            copy_string_to_text_buffer(0, sub_08047BEC(0, id));
            break;
        case 2:
            copy_string_to_text_buffer(1, sub_08047BEC(1, id));
            break;
        case 3:
            copy_string_to_text_buffer(2, sub_08047BEC(2, id));
            break;
        case 4:
            copy_string_to_text_buffer(3, sub_08047BEC(3, id));
            break;
        case 5:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        }
    } else if (gUnk_030064A0.unk65 == 2) {
        id = 0xB;
        switch (gUnk_030064A0.unk70) {
        case 0:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        case 1:
            copy_string_to_text_buffer(0, sub_08047BEC(0, id));
            break;
        case 2:
            copy_string_to_text_buffer(1, sub_08047BEC(1, id));
            break;
        case 3:
            copy_string_to_text_buffer(2, sub_08047BEC(2, id));
            break;
        case 4:
            copy_string_to_text_buffer(3, sub_08047BEC(3, id));
            break;
        case 5:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        }
    } else if (gUnk_030064A0.unk65 == 3) {
        id = 0x6B;
        switch (gUnk_030064A0.unk70) {
        case 0:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        case 1:
            copy_string_to_text_buffer(0, sub_08047BEC(0, id));
            break;
        case 2:
            copy_string_to_text_buffer(1, sub_08047BEC(1, id));
            break;
        case 3:
            copy_string_to_text_buffer(2, sub_08047BEC(2, id));
            break;
        case 4:
            copy_string_to_text_buffer(3, sub_08047BEC(3, id));
            break;
        case 5:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        }
    }
    if (gUnk_030064A0.unk70 == 0)
        init_cursor_state();
    sub_0804A1C4();
}

void sub_08057B68(void) {
    if (scene_transition_step_08047C24(1, 1, 0, gTextTable[gUnk_030064A0.unk70 + 0x82])) {
        if (++gUnk_030064A0.unk70 <= 5)
            gGameSubState--;
        else
            gGameSubState = 2;
    }
}

void sub_08057BBC(void) {
    init_cursor_state();
    sub_0804A1C4();
}

void sub_08057BCC(void) {
    if (scene_transition_step_08047C24(1, 1, 0, gTextTable[0x81]))
        gGameSubState = 2;
}

void sub_08057BF8(void) {
    init_cursor_state();
    sub_0804A1C4();
}

void sub_08057C08(void) {
    if (scene_transition_step_08047C24(1, 1, 0, gTextTable[0x80]))
        gGameSubState = 2;
}

static void nullsub_08057C34(void) {}

static u32 check_vehicle_usability(s32 idx) {
    u32 ret = 0;
    s32 n;
    u32 ok;
    u32 flag;

    switch (idx) {
    case 0:
        flag = sub_08047D8C(0x12);
        ret = 1;
        if (!flag)
            break;
        n = check_position_table_match(0x55, 0);
        n += check_position_table_match(0x55, 1);
        n += check_position_table_match(0x55, 2);
        n += check_position_table_match(0x55, 3);
        ret = 2;
        if (n != 4)
            break;
        ok = sub_0804803C(0);
        ret = 3;
        if (!ok)
            break;
        flag = gUnk_030057E0.unkC5D & 2;
        ret = 4;
        if (flag)
            break;
        ret = 0;
        if (gUnk_030057E0.unkC5C == 2)
            ret = 5;
        break;
    case 1:
        flag = sub_08047D8C(0x18);
        ret = 1;
        if (!flag)
            break;
        flag = gUnk_030057E0.unkC5D & 0x10;
        ret = 4;
        if (flag)
            break;
        ret = 0;
        if (gUnk_030057E0.unkC5C == 1 || gUnk_030057E0.unkC5C == 2)
            ret = 5;
        break;
    case 2:
        flag = sub_08047D8C(0x19);
        ret = 1;
        if (!flag)
            break;
        n = check_position_table_match(0xB, 0);
        n += check_position_table_match(0xB, 1);
        n += check_position_table_match(0xB, 2);
        n += check_position_table_match(0xB, 3);
        ret = 2;
        if (n != 4)
            break;
        ok = sub_0804803C(1);
        if (gUnk_083D29EB[gUnk_030057E0.unk7FE] == 0xA)
            ok = 0;
        ret = 3;
        if (!ok)
            break;
        flag = gUnk_030057E0.unkC5D & 4;
        ret = 4;
        if (flag)
            break;
        ret = 0;
        if (gUnk_030057E0.unkC5C == 1 || gUnk_030057E0.unkC5C == 2)
            ret = 5;
        break;
    case 3:
        flag = sub_08047D8C(0x26);
        ret = 1;
        if (!flag)
            break;
        n = check_position_table_match(0x6B, 0);
        n += check_position_table_match(0x6B, 1);
        n += check_position_table_match(0x6B, 2);
        n += check_position_table_match(0x6B, 3);
        ret = 2;
        if (n != 4)
            break;
        flag = gUnk_030057E0.unkC5D & 8;
        ret = 4;
        if (flag)
            break;
        flag = (u8)(gUnk_030057E0.unkC5C - 1);
        ret = 5;
        if (flag <= 1)
            break;
        ret = 0;
        if (get_adjacent_tile_value(gUnk_030057E0.unkC67) != 3)
            ret = 6;
        break;
    }
    return ret;
}

static void handle_cursor_up_down_input(s32 count) {
    struct Unk_030064A0 *s;

    gUnk_030057A0.unk15++;
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        sub_08047BA8(2);
        s = &gUnk_030064A0;
        if (--s->unk65 == 0xFF)
            s->unk65 = count - 1;
        s->unk6D = gUnk_083D5F2C[s->unk65];
        update_cursor_sprite_position();
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        sub_08047BA8(2);
        s = &gUnk_030064A0;
        s->unk65++;
        if (s->unk65 >= count)
            s->unk65 = 0;
        s->unk6D = gUnk_083D5F2C[s->unk65];
        update_cursor_sprite_position();
    }
}

static void sub_08057EBC(void) {
    sprite_entry_clear(0x20);
    sprite_entry_clear(0x21);
    sprite_entry_clear(0x22);
    sprite_entry_clear(0x23);
}

static void update_cursor_sprite_position(void) {
    struct Unk_030064A0 *s = &gUnk_030064A0;
    s32 d = (u8)(s->unk67 & 4) >> 2;

    if (s->unk67 & 8)
        d = -d;
    gUnk_03002C30[0x7F].unk2 = s->unk6C * 8 + 8 + d;
    gUnk_03002C30[0x7F].unk4 = s->unk6D * 8 + 8;
    gUnk_03002C30[0x7F].unk6 = 0x307;
    gUnk_03002C30[0x7F].unkA = 0xE;
    gUnk_03002C30[0x7F].unk1C = 0;
    gUnk_03002C30[0x7F].unk8 = 1;
    gUnk_03002C30[0x7F].unk9 = 1;
    gUnk_03002C30[0x7F].unkB = 0xFF;
}

static void init_vehicle_menu_sprite(s32 x) {
    s32 ox;

    sprite_entry_init(0x20, 0xC004, 0x91, check_vehicle_usability(0) == 0 ? 0xC : 0xD, 1);
    gUnk_03002C30[0x20].unk2 = (0x10 - gUnk_030064A0.unk6F) * 8 + (ox = x * 8 + 0x90);
    gUnk_03002C30[0x20].unk4 = 0x18;
    gUnk_03002C30[0x20].unkB |= 0xFF;
    sprite_entry_init(0x21, 0xC004, 0x92, check_vehicle_usability(1) == 0 ? 0xC : 0xD, 1);
    gUnk_03002C30[0x21].unk2 = (0x10 - gUnk_030064A0.unk6F) * 8 + ox;
    gUnk_03002C30[0x21].unk4 = 0x28;
    gUnk_03002C30[0x21].unkB |= 0xFF;
    sprite_entry_init(0x22, 0xC004, 0x93, check_vehicle_usability(2) == 0 ? 0xC : 0xD, 1);
    gUnk_03002C30[0x22].unk2 = (0x10 - gUnk_030064A0.unk6F) * 8 + ox;
    gUnk_03002C30[0x22].unk4 = 0x38;
    gUnk_03002C30[0x22].unkB |= 0xFF;
    sprite_entry_init(0x23, 0xC004, 0x94, check_vehicle_usability(3) == 0 ? 0xC : 0xD, 1);
    gUnk_03002C30[0x23].unk2 = (0x10 - gUnk_030064A0.unk6F) * 8 + ox;
    gUnk_03002C30[0x23].unk4 = 0x48;
    gUnk_03002C30[0x23].unkB |= 0xFF;
}

static void render_npc_tilemap_row(s32 row) {
    copy_tilemap_region(gUnk_03006D14 + 0x200, gUnk_03006D14 + 0x400, row * 2 + 1, 6, 8, 2, 0x108, 0xE, 0);
}
