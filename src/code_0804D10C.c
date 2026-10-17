#include "global.h"

void sub_0804D10C(void)
{
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] == gUnk_030057E0.unkC5B)
    {
        gUnk_030057E0.unkC5B = gUnk_030057E0.unkC94[0] ^ 1;
        sub_08052BA0(gUnk_030057E0.unkC5B);
        if (gUnk_030057E0.unkC94[1] == 0)
        {
            if (gUnk_030057E0.unkC5B)
            {
                memcpy_u8(gUnk_030057E0.unkC18, gUnk_030057E0.unkC10, 8);
            }
            else
            {
                memcpy_u8(gUnk_030057E0.unkC10, gUnk_030057E0.unkC18, 8);
                gUnk_030057E0.unkC10[0] = 0;
                gUnk_030057E0.unkC10[1] = 0;
                gUnk_030057E0.unkC10[2] = 0;
                gUnk_030057E0.unkC10[3] = 0;
                gUnk_030057E0.unkC10[4] = 0;
                gUnk_030057E0.unkC10[5] = 0;
                gUnk_030057E0.unkC10[6] = 0;
                gUnk_030057E0.unkC10[7] = 0;
            }
        }
    }
}

void nullsub_0804D1B8(void)
{
}

void sub_0804D1BC(void)
{
    gUnk_030057E0.unk7FF = read_map_script_byte();
}

void sub_0804D1D8(void)
{
    read_map_script_bytes(5);
    sub_0804DB84(gUnk_030057E0.unkC94[0], find_next_available_battle_sprite_slot());
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D224(void)
{
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D25C(void)
{
    read_map_script_bytes(5);
    sub_0804DB84(gUnk_030057E0.unkC94[0], find_next_available_battle_sprite_slot());
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D2A8(void)
{
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D2E0(void)
{
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D2F4(void)
{
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D308(void)
{
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D31C(void)
{
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void nullsub_0804D330(void)
{
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void nullsub_0804D334(void)
{
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D338(void)
{
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void nullsub_0804D34C(void)
{
}

void sub_0804D350(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    gUnk_03006D38.unk0 = gUnk_030057E0.unkC94[0];
    if (sub_08047F50() > 2)
        gUnk_030057E0.unkC89 = 1;
    else
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

void sub_0804D3B4(void)
{
    gUnk_03006D38.unk1 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D3B4).
void sub_0804D3D8(void)
{
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D3EC(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    if ((u8)((u16)sub_08047D9C(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1]) >> 8) == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void nullsub_0804D440(void)
{
}

void sub_0804D444(void)
{
    gUnk_030057E0.unkC32 = read_map_script_byte();
}

void sub_0804D460(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D488(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D4B0(void)
{
    gUnk_030064A0.unk52 = 0;
    sub_080496C8(gUnk_030064A0.unk2, 8);
    sub_080496C8(gUnk_030064A0.unkA, 8);
    sub_080496C8(gUnk_030064A0.unk12[0], 64);
    sub_080496C8(&gUnk_030064A0.unk52, 1);
    sub_080496C8(&gUnk_030064A0.unk53, 1);
    sub_080496C8(gUnk_030064A0.unk54, 8);
    gUnk_030057E0.unkC92 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gMapScriptCommands[gUnk_030057E0.unkC92]();
}

void sub_0804D534(void)
{
    read_map_script_bytes(8);
    memcpy_u8(gUnk_030057E0.unkC94, gUnk_030064A0.unk12[gUnk_030064A0.unk52++], 8);
    gUnk_030057E0.unkC92 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gMapScriptCommands[gUnk_030057E0.unkC92]();
}

// Not called directly (hidden in the tail of sub_0804D534).
void sub_0804D590(void)
{
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D5A4(void)
{
    u8 slot;

    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] & 0x10)
    {
        if (gUnk_030057E0.unkC94[0] & 0x40)
        {
            if (gUnk_030057E0.unkC94[1] == 0)
                sub_0804877C(47);
            else
                sub_08050770(47, gUnk_030057E0.unkC94[1]);
        }
        else if (gUnk_030057E0.unkC94[0] & 0x20)
        {
            if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
            {
                slot = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
                if (gUnk_030057E0.unkC94[1] == 0)
                    sub_0804877C(slot);
                else
                    sub_08050770(slot, gUnk_030057E0.unkC94[1]);
            }
        }
        else
        {
            if (gUnk_030057E0.unkC94[1] == 0)
                sub_0804877C(sub_0804DBA4(gUnk_030057E0.unkC94[0] & 0xF) + 79);
            else
                sub_08050780(gUnk_030057E0.unkC94[0] & 0xF, gUnk_030057E0.unkC94[1]);
        }
    }
    else
    {
        if (gUnk_030057E0.unkC94[0] & 0x40)
        {
            sub_080507A0(47, gUnk_030057E0.unkC94[1]);
        }
        else if (gUnk_030057E0.unkC94[0] & 0x20)
        {
            if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
            {
                slot = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
                sub_080507A0(slot, gUnk_030057E0.unkC94[1]);
            }
        }
        else
        {
            sub_080507C0(gUnk_030057E0.unkC94[0] & 0xF, gUnk_030057E0.unkC94[1]);
        }
    }
}

void sub_0804D70C(void)
{
    read_map_script_bytes(1);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D72C(void)
{
    struct Unk_030064A0 *v = &gUnk_030064A0;
    v->unk52 = 0;
    sub_080496C8(v->unk2, 8);
    sub_080496C8(v->unkA, 8);
    sub_080496C8(v->unk12[0], 64);
}

void sub_0804D760(void)
{
    read_map_script_bytes(8);
    memcpy_u8(gUnk_030057E0.unkC94, gUnk_030064A0.unk12[gUnk_030064A0.unk52++], 8);
}

// Not called directly (hidden in the tail of sub_0804D760).
void sub_0804D798(void)
{
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D7AC(void)
{
    u16 start = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC76 == 0)
        gUnk_030057E0.unkC8A = start + ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

u8 read_map_script_byte(void)
{
    u8 *data = gMapScriptData;
    u32 offsets = (u16)((data[0] | (data[1] << 8)) - 0x4000);
    u16 banks = (data[2] | (data[3] << 8)) - 0x4000;
    u16 script = gUnk_030057E0.unkC8E;
    u8 *header;
    u16 start;
    u8 bank;
    u32 pos;
    u8 ret;

    offsets += script * 2;
    header = data + 0x4000;
    start = header[offsets];
    offsets++;
    start = (start | (header[offsets] << 8)) - 0x4000;
    bank = header[banks + script];
    pos = start + gUnk_030057E0.unkC8A;
    ret = data[pos + (bank << 14)];
    gUnk_030057E0.unkC8A++;
    return ret;
}

void read_map_script_bytes(u8 n)
{
    s32 i;
    for (i = 0; i < n; i++)
        gUnk_030057E0.unkC94[i] = read_map_script_byte();
}

s32 sub_0804D8A8(u16 id)
{
    s32 i;
    for (i = 0; i < 64; i++)
        if ((gUnk_030057E0.unk5DC[i].unk2 & 0xFFF) == id)
            return i;
    if (i == 64)
        return -1;
}

struct MapObject *battle_find_entity_by_id(u16 id)
{
    s32 i;
    for (i = 0; i < 64; i++)
        if ((gUnk_030057E0.unk5DC[i].unk2 & 0xFFF) == id)
            return &gUnk_030057E0.unk5DC[i];
    if (i == 64)
        return NULL;
}

void sub_0804D934(struct MapObject *obj)
{
    u8 *raw = (u8 *)obj;
    const u8 *tiles = gUnk_084045A8[gUnk_030057E0.unk7FE];
    set_tile_data(obj->x, obj->y, tiles[obj->y * (gUnk_030057E0.unk800 >> 1) + obj->x]);
    if (obj->unk4_6)
    {
        clear_battle_sprite_entry(obj->unk4_0 + 49);
        clear_battle_sprite_entry(obj->unk4_0 + 91);
    }
    sub_080496C8(raw, 8);
}

void sub_0804D9AC(u8 i)
{
    clear_battle_sprite_entry(48);
    clear_battle_sprite_entry(90);
    memcpy_u8(&gUnk_03002C30[i], &gUnk_03002C30[48], 0x40);
    memcpy_u8(&gUnk_030055A0[i], &gUnk_030055A0[48], 4);
    gUnk_030057E0.unkC76 = 1;
    gUnk_030057E0.unkC6E = gUnk_03002C30[48].unk2 + gBg1Scroll.x;
    gUnk_030057E0.unkC70 = gUnk_03002C30[48].unk4 + gBg1Scroll.y;
    gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
    gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
    gUnk_030057E0.unkC84 = gUnk_03002C30[48].unk2B;
    sub_08051E8C();
    sub_080493D4(48, sub_080502B4(48, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk21));
    init_battle_sprite_entry_08048818(90, 0xCC0C, 0x90, 0xE, 1);
    gUnk_03002C30[90].unk2 = gUnk_03002C30[48].unk2;
    gUnk_03002C30[90].unk4 = gUnk_03002C30[48].unk4 - 5;
    gUnk_03002C30[90].unkC_8 = gUnk_03002C30[48].unkC_8;
    gUnk_03002C30[90].unk10_8 = gUnk_03002C30[48].unk10_8 - 5;
    update_battle_direction_indicator(1);
    gUnk_030057E0.unkC5E = gUnk_030057E0.unkC5D;
    gUnk_030057E0.unkC5D = 0xDF;
}

void sub_0804DB34(void)
{
    clear_battle_sprite_entry(48);
    clear_battle_sprite_entry(90);
    gUnk_030057E0.unkC76 = 0;
    gUnk_030057E0.unkC5D = gUnk_030057E0.unkC5E;
}

void sub_0804DB68(u8 i)
{
    gUnk_030057E0.unkCA4[i] = 0;
}

void sub_0804DB84(u8 i, u8 v)
{
    gUnk_030057E0.unkCA4[i] = v + 1;
}

u32 sub_0804DBA4(u8 i)
{
    return gUnk_030057E0.unkCA4[i] - 1;
}

void map_script_update_command(void)
{
    gMapScriptUpdates[gUnk_030057E0.unkC92]();
}

void nullsub_0804DBE8(void)
{
}

// Opcode 1 update: shows message (C94[1] << 8 | C94[2]) of text bank C94[0] (runtime: bank 2, id 1
// is the lab intro "Good afternoon!"), finishes once the text window closes.
void map_script_update_message(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    const u32 *const *tbl;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        gUnk_030057A0.unk2E = s->unkC94[0] - 2;
        gUnk_030057A0.unk30 = (s->unkC94[1] << 8) | s->unkC94[2];
        if (sub_0804B6EC())
            map_script_command_done();
        s->unkC93++;
        break;
    case 1:
        if (s->unkC94[0] < 2)
            tbl = (const u32 *const *)gTextTable;
        else
            tbl = gTextBankTables[s->unkC94[0] - 2];
        if (scene_transition_step_08047C24(0, 0, 0, tbl[(s->unkC94[1] << 8) | s->unkC94[2]]))
            map_script_command_done();
        break;
    }
}

void sub_0804DCAC(void)
{
    map_script_command_done();
}

void sub_0804DCB8(void)
{
    if (game_state_execute_handler_a())
        map_script_command_done();
}

void sub_0804DCCC(void)
{
    if (gUnk_030057E0.unkC94[0] != 0)
        gUnk_030057E0.unkC94[0]--;
    else
        map_script_command_done();
}

void sub_0804DCF0(void)
{
    if (KEY_BITS(gNewKeys).a | KEY_BITS(gNewKeys).start)
        map_script_command_done();
}

void sub_0804DD10(void)
{
    if (run_blend_fade_transition(0))
        map_script_command_done();
}

void sub_0804DD24(void)
{
    if (run_blend_fade_transition(0))
        map_script_command_done();
}

void sub_0804DD38(void)
{
    if (run_blend_fade_transition(0x7FFF))
        map_script_command_done();
}

void sub_0804DD50(void)
{
    if (run_blend_fade_transition(0x7FFF))
        map_script_command_done();
}

void sub_0804DD68(void)
{
    sub_0804DD80();
}

void sub_0804DD74(void)
{
    sub_0804DD80();
}

void sub_0804DD80(void)
{
    sub_080482C0();
    dma_load_battle_palettes();
    load_room_graphics();
    load_battlefield_data_to_buffer();
    gUnk_030057E0.unkC35 = 0;
    gUnk_030057E0.unkC36 = 0;
    animate_area_bg_tiles();
    load_battle_terrain_data();
    gUnk_030057E0.unkC52 = gUnk_030057E0.unkC56 * 16 + gUnk_030057E0.unkC48;
    gUnk_030057E0.unkC54 = gUnk_030057E0.unkC57 * 16 + gUnk_030057E0.unkC4A;
    init_battle_field_setup();
    update_bg_scroll_offsets_a();
    gUnk_03002C30[47].unk25 = 1;
    field_set_player_facing(gUnk_030057E0.unkC67);
    update_cursor_tile_position();
    decompress_battle_tile_graphics();
    map_script_command_done();
}

void sub_0804DE28(void)
{
    switch (gUnk_03002C30[47].unk26)
    {
    case 0:
        if (gUnk_03002C30[47].unk28 < 16)
        {
            gUnk_03002C30[47].unk4 = gUnk_030057E0.unkC94[0] - gUnk_083D69A0[gUnk_03002C30[47].unk28][0] / 16;
            gUnk_03002C30[47].unk28++;
            if (gUnk_03002C30[47].unk4 / 4 <= (gUnk_030057E0.unkC94[0] - 16) / 4)
                gUnk_03002C30[47].unkB = 0xFF;
            else
                sub_0804877C(47);
        }
        else
        {
            gUnk_03002C30[47].unk26 = 1;
            gUnk_03002C30[47].unk28 = 0;
        }
        break;
    case 1:
        sub_0804877C(47);
        gUnk_03002C30[47].unk4 = gUnk_030057E0.unkC94[0];
        map_script_command_done();
        break;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804DEF4);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E0E8);

void sub_0804E324(void)
{
    u8 obj;
    u32 i;

    gUnk_030057E0.unkC69 = gUnk_030057E0.unkC5C = gUnk_083D2998[gUnk_030057E0.unkC94[0]];
    gUnk_030057E0.unkC28 = gUnk_083D2998[gUnk_030057E0.unkC94[0]];
    load_battle_terrain_data();
    decompress_battle_tile_graphics();
    switch (gUnk_03006F40.unk1)
    {
    case 1:
    case 3:
    case 5:
    case 6:
        obj = 1;
        break;
    default:
        obj = 0;
        break;
    }
    i = resolve_tile_from_battle_state(0);
    if (gUnk_083F8634[i] == NULL)
        i = 1;
    if (obj)
        DmaCopy32(3, gUnk_083F8634[i], OBJ_PLTT, 32)
    else
        DmaCopy32(3, gUnk_083F8634[i], 0x0202F800, 32)
    map_script_command_done();
}

void sub_0804E3F0(void)
{
    if (sub_08050868())
        map_script_command_done();
}

void sub_0804E404(void)
{
    if (sub_080508CC())
        map_script_command_done();
}

void sub_0804E418(void)
{
    if (sub_080507E0(gUnk_03006D20.unkA))
        map_script_command_done();
}

void sub_0804E434(void)
{
    sub_0804E44C();
}

void sub_0804E440(void)
{
    sub_0804E44C();
}

void sub_0804E44C(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        spawn_battle_medapart_sprite(s->unkC94[0], s->unkC94[1], s->unkC94[2], s->unkC94[3]);
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[4], 0);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void sub_0804E4D0(void)
{
    sub_0804E4E8();
}

void sub_0804E4DC(void)
{
    sub_0804E4E8();
}

void sub_0804E4E8(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[1], 0);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void sub_0804E540(void)
{
    if (sub_080507E0(gUnk_03006D20.unkA))
        map_script_command_done();
}

void sub_0804E55C(void)
{
    if (sub_08050868())
        map_script_command_done();
}

void sub_0804E570(void)
{
    if (sub_080508CC())
        map_script_command_done();
}

void sub_0804E584(void)
{
    sub_0804E5A4(0, 1);
}

void sub_0804E594(void)
{
    sub_0804E5A4(1, 1);
}

void sub_0804E5A4(u8 b, u8 mode)
{
    s32 empty = 0;
    s32 done = 0;
    s32 i;
    s32 slot;

    switch (gUnk_030057E0.unkC93)
    {
    case 0:
        for (i = 0; i <= 3; i++)
        {
            if (sub_0804DBA4(i) != -1 && gUnk_030055A0[sub_0804DBA4(i) + 79].unk0 != 0)
            {
                if (mode == 1)
                    setup_battle_sprite_terrain(sub_0804DBA4(i) + 79, gUnk_030057E0.unkC94[0], b);
                else
                    sub_080500D8(sub_0804DBA4(i) + 79, gUnk_030057E0.unkC94[0], b);
            }
        }
        gUnk_030057E0.unkC93++;
        break;
    case 1:
        for (i = 0; i <= 3; i++)
        {
            slot = sub_0804DBA4(i);
            if (slot != -1)
            {
                if (gUnk_030055A0[slot + 79].unk0 != 0)
                    done += update_battle_sprite_movement(slot + 79, mode);
                else
                    done++;
            }
            else
                empty++;
        }
        if (empty == 4)
            map_script_command_done();
        if (done)
            map_script_command_done();
        break;
    }
}

void sub_0804E6B4(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        spawn_battle_medapart_sprite(s->unkC94[0], s->unkC94[1], s->unkC94[2], s->unkC94[3]);
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[4], 0);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804E738(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[1], 0);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void nullsub_0804E790(void)
{
}

void nullsub_0804E794(void)
{
}

void nullsub_0804E798(void)
{
}

void sub_0804E79C(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    u32 r;

    switch (s->unkC93)
    {
    case 0:
        init_bg0_for_cursor(0);
        s->unkC93++;
        break;
    case 1:
        r = sub_08047FEC();
        if (r)
        {
            if (r & 0xF0)
                s->unkC8A = s->unkC8C + s->unkC94[0];
            s->unkC93++;
        }
        break;
    case 2:
        if (game_state_execute_handler_a())
            map_script_command_done();
        break;
    }
}

void sub_0804E814(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    u32 r;

    switch (s->unkC93)
    {
    case 0:
        init_bg0_for_cursor(1);
        s->unkC93++;
        break;
    case 1:
        r = sub_08047FEC();
        if (r)
        {
            if (r & 0xF0)
                s->unkC8A = s->unkC8C + s->unkC94[0];
            map_script_command_done();
        }
        break;
    }
}

void sub_0804E878(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x20, 0))
        {
            u32 v = s->unkC4F;
            if (v == 1)
                gUnk_03005310.unk39 = v;
            else if (v == 2)
                gUnk_03005310.unk39 = v;
            map_script_command_done();
        }
        break;
    }
}

void nullsub_0804E8D4(void)
{
}

void nullsub_0804E8D8(void)
{
}

// guess: opcode 0x36, give arg1 of item arg0 (capped at 99) and show the text.
void sub_0804E8DC(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 have;
    s32 n;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        have = sub_08047D8C(s->unkC94[0]);
        if (have == 99)
        {
            sub_08047BA8(6);
            copy_string_to_text_buffer(0, sub_08048088(s->unkC94[0]));
            s->unkC93 = 1;
            break;
        }
        sub_08047BA8(14);
        if (s->unkC94[1] + have > 99)
            n = 99 - have;
        else
            n = s->unkC94[1];
        sub_08047DC0(gUnk_030057E0.unkC94[0], n);
        copy_string_to_text_buffer(0, sub_08048088(gUnk_030057E0.unkC94[0]));
        format_number_to_text_buffer(1, n);
        gUnk_030057E0.unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[0]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[1]))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x37, take arg1 of item arg0 and show the text.
void sub_0804E9CC(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 have;
    s32 n;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        have = sub_08047D8C(s->unkC94[0]);
        if (have == 0)
        {
            sub_08047BA8(6);
            copy_string_to_text_buffer(0, sub_08048088(s->unkC94[0]));
            s->unkC93 = 1;
            break;
        }
        sub_08047BA8(5);
        if (have - s->unkC94[1] < 0)
            n = have;
        else
            n = s->unkC94[1];
        sub_08047DD8(s->unkC94[0], n);
        copy_string_to_text_buffer(0, sub_08048088(s->unkC94[0]));
        format_number_to_text_buffer(1, n);
        have = sub_08047D8C(s->unkC94[0]);
        if (have == 0)
            s->unkC93 = 3;
        else
            s->unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[2]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[3]))
            map_script_command_done();
        break;
    case 3:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[4]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x38: give arg2 of Medapart (arg0, arg1), capped at 99 (medapart_add_quantity), then show the text.
void map_script_update_give_medapart(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 have;
    s32 n;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        have = (s32)(sub_08047D9C(s->unkC94[0], s->unkC94[1]) & 0xFF00) >> 8;
        if (have == 99)
        {
            sub_08047BA8(6);
            copy_string_to_text_buffer(0, sub_08047BEC(s->unkC94[1], s->unkC94[0]));
            s->unkC93 = 1;
            break;
        }
        sub_08047BA8(14);
        if (s->unkC94[2] + have > 99)
            n = 99 - have;
        else
            n = s->unkC94[2];
        sub_08047DF0(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1], n);
        copy_string_to_text_buffer(0, sub_08047BEC(gUnk_030057E0.unkC94[1], gUnk_030057E0.unkC94[0]));
        format_number_to_text_buffer(1, n);
        gUnk_030057E0.unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[5]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[1] + 6]))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x39, take arg2 of Medapart (arg0, arg1) and show the text.
void sub_0804EBEC(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 have;
    s32 n;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        have = (s32)(sub_08047D9C(s->unkC94[0], s->unkC94[1]) & 0xFF00) >> 8;
        if (have == 0)
        {
            sub_08047BA8(6);
            copy_string_to_text_buffer(0, sub_08047BEC(s->unkC94[1], s->unkC94[0]));
            s->unkC93 = 1;
            break;
        }
        sub_08047BA8(5);
        if (have - s->unkC94[2] < 0)
            n = have;
        else
            n = s->unkC94[2];
        sub_08047E08(s->unkC94[0], s->unkC94[1], n);
        copy_string_to_text_buffer(0, sub_08047BEC(s->unkC94[1], s->unkC94[0]));
        format_number_to_text_buffer(1, n);
        have = sub_08047D9C(s->unkC94[0], s->unkC94[1]) & 0xFF00;
        if (have == 0)
            s->unkC93 = 3;
        else
            s->unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[1] + 14]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[1] + 18]))
            map_script_command_done();
        break;
    case 3:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[1] + 18]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3A: add the 16-bit argument * 10 to gMoney and show the "got money" text (runtime: +5000 in the intro).
void map_script_update_give_money(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    u32 n;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        n = ((s->unkC94[0] << 8) | s->unkC94[1]) * 10;
        sub_08047BA8(7);
        add_money(n);
        sub_08047D24(0, n);
        s->unkC93 = 1;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[26]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3B: subtract the 16-bit argument * 10 from gMoney, at most what is left (runtime: -4980 buying Rokusho).
void map_script_update_take_money(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 n;
    s32 money;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        n = ((s->unkC94[0] << 8) | s->unkC94[1]) * 10;
        sub_08047BA8(5);
        money = get_money();
        if (money - n <= 0)
            n = money;
        sub_08047BA8(5);
        sub_money(n);
        sub_08047D24(0, n);
        s->unkC93 = 1;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[27]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3C: give medal arg0 unless already owned (find_medal_slot_by_id), then run scene 1.
void map_script_update_give_medal(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        sub_08047BA8(14);
        copy_string_to_text_buffer(0, sub_08047BCC(s->unkC94[0]));
        if (sub_08047DB0(s->unkC94[0]))
        {
            s->unkC93 = 1;
            break;
        }
        gUnk_030017EC = sub_08047E20(s->unkC94[0]);
        s->unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[28]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[29]))
        {
            sub_08050C74();
            s->unkC93++;
        }
        break;
    case 3:
        if (scene_state_dispatch(1, s->unkC94[0]))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x3D, add position entry arg0 unless all slots are occupied (runs in walkthrough 01).
void sub_0804EF10(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        init_cursor_state();
        sub_08047BA8(14);
        if (sub_08047E30())
        {
            s->unkC93 = 1;
            break;
        }
        sub_08047E3C(s->unkC94[0]);
        s->unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[30]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[0] + 31]))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x40, flash the screen white arg0 times.
void sub_0804EFB0(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
        s->unkC93++;
        break;
    case 1:
        if (run_blend_fade_transition(0x7FFF))
        {
            setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
            s->unkC93++;
        }
        break;
    case 2:
        if (run_blend_fade_transition(0x7FFF))
        {
            if (--s->unkC94[0] != 0)
                s->unkC93 = 0;
            else
                map_script_command_done();
        }
        break;
    }
}

void sub_0804F058(void)
{
    s32 empty = 0;
    s32 done = 0;
    s32 i;

    for (i = 0; i <= 3; i++)
    {
        if (sub_0804DBA4(i) != -1)
        {
            if (gUnk_030055A0[sub_0804DBA4(i) + 79].unk0 != 0)
                done += sub_080507E0(sub_0804DBA4(i) + 79);
            else
                empty++;
        }
    }
    if (empty == 4)
        done = 1;
    if (done)
        map_script_command_done();
}

void sub_0804F0C4(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        s->unkC8A = 16 / sub_080518F4(47);
        sub_080500D8(47, (s->unkC94[0] << 4) | s->unkC94[1], 0);
        s->unkC93++;
        break;
    case 1:
        if (sub_0804F13C(s->unkC94[0]))
            map_script_command_done();
        break;
    }
}

// guess: scripted player step in dir (field_player_step without the input checks); returns 1 when the step ends.
u32 sub_0804F13C(u8 dir)
{
    u32 ret;

    switch (dir)
    {
    case 0:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A != 0)
        {
            gUnk_030057E0.unkC54 -= sub_080518F4(47);
            if (!sub_08052A18()
             && gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A < gUnk_030057E0.unk802 * 8 - 0x60
             && gBg1Scroll.y != 0)
            {
                sub_08052AF8(-sub_080518F4(47));
                gUnk_03002C30[0].unk4 += sub_080518F4(47);
            }
        }
        break;
    case 1:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 < gUnk_030057E0.unk802 * 8)
        {
            gUnk_030057E0.unkC54 += sub_080518F4(47);
            if (!sub_08052A18()
             && gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 > 0x50
             && gBg1Scroll.y + 0xA0 < gUnk_030057E0.unk802 * 8)
            {
                sub_08052AF8(sub_080518F4(47));
                gUnk_03002C30[0].unk4 -= sub_080518F4(47);
            }
        }
        break;
    case 2:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 != 0)
        {
            gUnk_030057E0.unkC52 -= sub_080518F4(47);
            if (!sub_08052A04()
             && gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 < gUnk_030057E0.unk800 * 8 - 0x80
             && gBg1Scroll.x != 0)
            {
                sub_08052A2C(-sub_080518F4(47));
                gUnk_03002C30[0].unk2 += sub_080518F4(47);
            }
        }
        break;
    case 3:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 < gUnk_030057E0.unk800 * 8)
        {
            gUnk_030057E0.unkC52 += sub_080518F4(47);
            if (!sub_08052A04()
             && gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 > 0x80
             && gBg1Scroll.x + 0xF0 < gUnk_030057E0.unk800 * 8)
            {
                sub_08052A2C(sub_080518F4(47));
                gUnk_03002C30[0].unk2 -= sub_080518F4(47);
            }
        }
        break;
    }
    gUnk_03006D20.unk0--;
    ret = 0;
    if (gUnk_03006D20.unk0 == 0)
    {
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F3AC);

void nullsub_0804F57C(void)
{
}

void nullsub_0804F580(void)
{
}

void nullsub_0804F584(void)
{
}

void nullsub_0804F588(void)
{
}

void nullsub_0804F58C(void)
{
}

// guess: opcode 0x56, reload the map (clears tile buffers, recopies the collision map, reloads NPC sprites).
void sub_0804F590(void)
{
    populate_battle_entity_tile_positions();
    sub_080496C8(gUnk_03003870, 0x900);
    sub_080496C8(gUnk_03003870 + 0xA80, 0x900);
    sub_080496C8(gUnk_03005664, 0x90);
    sub_080496C8(gUnk_03005664 + 0xA8, 0x90);
    init_battle_medapart_sprites_all();
    sub_080496C8(gUnk_030057E0.unk810, 0x400);
    memcpy_u8(gUnk_084045A8[gUnk_030057E0.unk7FE], gUnk_030057E0.unk810,
              (gUnk_030057E0.unk802 >> 1) * (gUnk_030057E0.unk800 >> 1));
    gUnk_030057E0.unkCBA = 1;
    load_map_npc_sprites();
    update_entity_sprites_on_screen();
    map_script_command_done();
}

void nullsub_0804F628(void)
{
}

void nullsub_0804F62C(void)
{
}

void sub_0804F630(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(3, s->unkC94[0]))
            map_script_command_done();
        break;
    }
}

void nullsub_0804F678(void)
{
}

void nullsub_0804F67C(void)
{
}

void nullsub_0804F680(void)
{
}

void nullsub_0804F684(void)
{
}

void nullsub_0804F688(void)
{
}

void nullsub_0804F68C(void)
{
}

void nullsub_0804F690(void)
{
}

void sub_0804F694(void)
{
    u32 kind;

    switch (gUnk_030057E0.unkC93)
    {
    case 0:
        kind = gUnk_03005350.unk1D4 & 0x3F;
        if (kind == 0xD || kind == 0x16)
        {
            if (battle_scene_state_dispatch())
                gUnk_030057E0.unkC93++;
        }
        else if (battle_scene_state_dispatch())
            map_script_command_done();
        break;
    case 1:
        gUnk_03006D20.unk0 = 16 / sub_080518F4(47);
        sub_080500D8(47, (gUnk_030057E0.unkC94[0] << 4) | gUnk_030057E0.unkC94[1], 0);
        gUnk_030057E0.unkC93++;
        break;
    case 2:
        if ((gUnk_03005350.unk1D4 & 0x3F) == 0xD)
            gUnk_030057E0.unkC67 = 2;
        else
            gUnk_030057E0.unkC67 = 3;
        if (sub_0804F13C(gUnk_030057E0.unkC67))
        {
            gUnk_030057E0.unkC5B = 1;
            gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
            gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
            gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
            field_center_camera_on_player();
            sub_08052BA0(gUnk_030057E0.unkC5B);
            field_set_player_facing(gUnk_030057E0.unkC67);
            update_bg_scroll_offsets_a();
            init_battle_sprites();
            map_script_command_done();
        }
        break;
    }
}

void sub_0804F7F0(void)
{
    if (sub_080509A0())
        map_script_command_done();
}

void sub_0804F804(void)
{
    map_script_command_done();
}

void nullsub_0804F810(void)
{
}

void nullsub_0804F814(void)
{
}

void sub_0804F818(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        spawn_battle_medapart_sprite(s->unkC94[0], s->unkC94[1], s->unkC94[2], s->unkC94[3]);
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[4], 1);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void sub_0804F89C(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[1], 1);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void sub_0804F8F4(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        spawn_battle_medapart_sprite(s->unkC94[0], s->unkC94[1], s->unkC94[2], s->unkC94[3]);
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[4], 1);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804F978(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[1], 1);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804F9D0(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x13, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FA10(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FA50(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(2, 0))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x73, run scene 8 until it ends (coverage: runs in the shop scenario).
void sub_0804FA90(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(8, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FAD0(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08047878(4, 0);
        s->unkC93++;
        break;
    case 1:
        if (gUnk_03006D20.unkC == 7)
            s->unkC93 = 2;
        else
            map_script_command_done();
        break;
    case 2:
        sub_08050C74();
        s->unkC93++;
        break;
    case 3:
        if (scene_state_dispatch(5, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FB40(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x10, 0))
        {
            if (sub_0804B6EC())
                gUnk_03005310.unk39 = 1;
            map_script_command_done();
        }
        break;
    }
}

void sub_0804FB90(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x12, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FBD0(void)
{
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93)
    {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x11, 0))
        {
            if (sub_0804B6EC())
                gUnk_03005310.unk39 = 1;
            map_script_command_done();
        }
        break;
    }
}

void sub_0804FC20(void)
{
    sub_0804E5A4(0, 0);
}

// guess: opcode 0x7F, end the follower: copy sprite 48 and its shadow back to map object arg0.
void sub_0804FC30(void)
{
    gUnk_03002C30[48].unkC_8 = gUnk_030057E0.unkC6E;
    gUnk_03002C30[48].unk10_8 = gUnk_030057E0.unkC70;
    memcpy_u8(&gUnk_03002C30[48], &gUnk_03002C30[gUnk_030057E0.unkC94[0] + 79], 0x40);
    gUnk_030055A0[gUnk_030057E0.unkC94[0] + 79].unk0 = 0xFFFF;
    memcpy_u8(&gUnk_03002C30[90], &gUnk_03002C30[gUnk_030057E0.unkC94[0] + 121], 0x40);
    map_script_command_done();
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FCC4);

void sub_0804FE20(void)
{
    if (gUnk_030057E0.unkC36 == 0)
    {
        gUnk_030057E0.unkC34 = gUnk_030057E0.unkC94[0];
        map_script_command_done();
    }
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FE50);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", setup_battle_sprite_terrain);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_080500D8);

void advance_sprite_by_terrain_modifier(u8 slot)
{
    s32 i;

    for (i = 0; i < sub_080518F4(slot); i++)
        advance_sprite_animation_frame(slot);
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", update_battle_sprite_movement);

// Ends the current command: the next frame runs the next one (map_script_run_command).
void map_script_command_done(void)
{
    gUnk_030057E0.unkC93 = 0;
    gUnk_030057E0.unkC89 = 0;
}

u8 sub_08050264(u8 a)
{
    return a >> 4;
}

u8 sub_0805026C(u8 a)
{
    return a & 3;
}

u8 calc_medapart_table_index(u8 a)
{
return sub_08050264(a) * 12 + sub_0805026C(a) * 3;
}

u8 sub_080502B4(u8 slot, u8 v)
{
    return v + gUnk_03002C30[slot].unk2B * 4;
}

u8 compute_battle_sprite_anim_offset(u8 id, u8 a)
{
    return gUnk_03002C30[sub_0804DBA4(id) + 79].unk2B * 12 + a * 3;
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", spawn_battle_medapart_sprite);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", init_battle_medapart_sprite);

// guess: remove the sprite of map object (arg & 0xF); if arg & 0xF0, play the exit sound when it stands on an exit.
void sub_08050508(u8 arg)
{
    u32 id = arg & 0xF;

    if (arg & 0xF0)
    {
        u8 x = sub_080526F0(gUnk_03002C30[sub_0804DBA4(id) + 79].unkC_8);
        u8 y = sub_08052714(gUnk_03002C30[sub_0804DBA4(id) + 79].unk10_8);

        if (find_map_event_by_coords(x, y) && gUnk_03006D38.unk3)
            sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
    }
    clear_battle_sprite_entry(sub_0804DBA4(id) + 79);
    clear_battle_sprite_entry(sub_0804DBA4(id) + 121);
    sub_0804DB68(id);
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", populate_battle_entity_tile_positions);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", init_battle_medapart_sprites_all);

u32 find_next_available_battle_sprite_slot(void)
{
    s32 i;
    for (i = 0; i < 6; i++)
    {
        if (!(gUnk_03002C30[i + 79].unk0 & 0x4000) && !gUnk_03002C30[i + 79].unk2E)
            break;
    }
    if (i == 6)
        return 5;
    return i;
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", set_battle_sprite_animation);

void sub_08050770(u32 idx, u8 val)
{
    gUnk_03002C30[idx].unkB = val;
}

void sub_08050780(u8 i, u32 val)
{
    gUnk_03002C30[sub_0804DBA4(i) + 79].unkB = val;
}

void sub_080507A0(u32 idx, u32 val)
{
    u32 v = (gUnk_03002C30[idx].unk32 & 0xF3FF) | (val << 10);
    gUnk_03002C30[idx].unk0 = v;
    gUnk_03002C30[idx].unk32 = v;
}

void sub_080507C0(u8 i, u8 val)
{
    sub_080507A0(sub_0804DBA4(i) + 79, val);
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_080507E0);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_08050868);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_080508CC);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_080509A0);

// Clears gNewKeys, gRepeatKeys and gHeldKeys (called every frame by sub_0804E0E8 during scripted scenes).
void sub_08050B50(void)
{
    sub_080496C8((u8 *)&gNewKeys, 4);
    sub_080496C8((u8 *)&gRepeatKeys, 4);
    sub_080496C8((u8 *)&gHeldKeys, 4);
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", battle_scene_state_dispatch);

void init_battle_sprites(void)
{
    s32 i;

    sub_080496C8((u8 *)gUnk_03002C30, 0xA00);
    sub_080492CC();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
}

void sub_08050C74(void)
{
    gUnk_03006D20.unkB = 0;
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", scene_state_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_08050F10);
