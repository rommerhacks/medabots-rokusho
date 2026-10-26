#ifndef GUARD_BATTLE_ACTION_QUEUE_H
#define GUARD_BATTLE_ACTION_QUEUE_H

// Turn queue (front/home line arrivals, sort, pop) and number/text popup sprites

u32 sub_08019EF0(void);
void battle_queue_sort(void);
void battle_queue_take_head(
    void); // acting Medabot = queue head: gUnk_03001800.unk87 = record, unk89 = side, unk8A = other side
void battle_queue_pop(void); // drops the queue head, shifting the rest up
void iterate_bots_setup_battle_sprites(void);
u32 sub_0801A6B0(void);
u32 sub_0801A6EC(u32 rec);  // tests gUnk_03001800.unk44 bit rec (rec 0-2)
void sub_0801A744(u32 rec); // clears gUnk_03001800.unk44 bit rec (rec 0-2)
u32 battle_bot_at_front_line(
    u32 rec,
    u32 peek); // 1 when the Medabot has reached its front line (x 0x68 team, 0x88 opponents); queues it unless peek
u32 battle_bot_at_home_line(
    u32 rec, u32 peek); // 1 when the returning Medabot is back home (x 0x28 / 0xC8); queues it unless peek
void set_display_digit_type(
    u8 *buf, u32 value,
    u32 type); // buf = [sign 0xA (type 0) / 0xB (type 1)] digits without leading zeros, 0xFE; buf[6] = length
void battle_number_popup_init(
    u8 *buf,
    u32 rec); // digit sprites 10 + rec * 4 .. from set_display_digit_type's buffer, centred over the Medabot's sprite
void battle_number_popup_update(u32 rec); // bounces the 3 digit sprites up (gUnk_083AD3B3), one step per frame
void render_battle_text_sprites(u8 *buf, u32 rec,
                                u32 slot); // battle_number_popup_init for up to 5 digit sprites from slot + rec * 4
void battle_setup_text_sprites_0801A418(u8 *buf, u32 rec, u32 slot); // same with tiles 0x5100 + digit, palette 0xC
void battle_setup_text_sprites_0801A4F4(u8 *buf, u32 rec, u32 slot, u32 x, u32 y); // same at a given x, y
void update_battle_sprite_animations(u8 *buf, u32 rec,
                                     u32 slot); // battle_number_popup_update for up to 5 digit sprites
void battle_queue_add(u32 rec, u32 prio);

#endif // GUARD_BATTLE_ACTION_QUEUE_H
