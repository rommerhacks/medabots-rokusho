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
    gUnk_030057E0.unkC6E = gUnk_03002C30[48].unk2 + gUnk_03004C30.x;
    gUnk_030057E0.unkC70 = gUnk_03002C30[48].unk4 + gUnk_03004C30.y;
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
    update_sprite_animation_dma();
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
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E324);

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

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E418);

void sub_0804E434(void)
{
    sub_0804E44C();
}

void sub_0804E440(void)
{
    sub_0804E44C();
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E44C);

void sub_0804E4D0(void)
{
    sub_0804E4E8();
}

void sub_0804E4DC(void)
{
    sub_0804E4E8();
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E4E8);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E540);

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

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E5A4);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E6B4);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E738);

void nullsub_0804E790(void)
{
}

void nullsub_0804E794(void)
{
}

void nullsub_0804E798(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E79C);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E814);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E878);

void nullsub_0804E8D4(void)
{
}

void nullsub_0804E8D8(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E8DC);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804E9CC);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804EAC0);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804EBEC);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804ED3C);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804EDB4);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804EE40);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804EF10);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804EFB0);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F058);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F0C4);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F13C);
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

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F590);

void nullsub_0804F628(void)
{
}

void nullsub_0804F62C(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F630);

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

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F694);

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

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F818);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F89C);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F8F4);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F978);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804F9D0);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FA10);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FA50);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FA90);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FAD0);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FB40);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FB90);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FBD0);

void sub_0804FC20(void)
{
    sub_0804E5A4(0, 0);
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FC30);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FCC4);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FE20);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_0804FE50);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", setup_battle_sprite_terrain);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_080500D8);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", advance_sprite_by_terrain_modifier);
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

INCLUDE_ASM("asm/nonmatching/code_0804D10C", calc_medapart_table_index);

u8 sub_080502B4(u8 slot, u8 v)
{
    return v + gUnk_03002C30[slot].unk2B * 4;
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", compute_battle_sprite_anim_offset);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", spawn_battle_medapart_sprite);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", init_battle_medapart_sprite);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_08050508);
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
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_08050B50);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", battle_scene_state_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", init_battle_sprites);

void sub_08050C74(void)
{
    gUnk_03006D20.unkB = 0;
}

INCLUDE_ASM("asm/nonmatching/code_0804D10C", scene_state_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0804D10C", sub_08050F10);
