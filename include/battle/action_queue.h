#ifndef GUARD_BATTLE_ACTION_QUEUE_H
#define GUARD_BATTLE_ACTION_QUEUE_H

// Turn queue (front/home line arrivals, sort, pop) and number/text popup sprites

u32 battle_queue_bots_at_lines(void);
void battle_queue_sort(void);
void battle_queue_take_head(
    void); // acting Medabot = queue head: gBattleWork.unk87 = record, unk89 = side, unk8A = other side
void battle_queue_pop(void); // drops the queue head, shifting the rest up
void iterate_bots_setup_battle_sprites(void);
u32 any_bot_extra_move_pending(void);
u32 team_bot_command_kept(u32 rec);        // tests gBattleWork.unk44 bit rec (rec 0-2)
void team_bot_clear_command_kept(u32 rec); // clears gBattleWork.unk44 bit rec (rec 0-2)
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
void battle_number_popup_init_slot(u8 *buf, u32 rec,
                                   u32 slot); // battle_number_popup_init for up to 5 digit sprites from slot + rec * 4
void battle_text_popup_init_slot(u8 *buf, u32 rec, u32 slot);             // same with tiles 0x5100 + digit, palette 0xC
void battle_text_popup_init_at(u8 *buf, u32 rec, u32 slot, u32 x, u32 y); // same at a given x, y
void battle_popup_update_slot(u8 *buf, u32 rec,
                              u32 slot); // battle_number_popup_update for up to 5 digit sprites
void battle_queue_add(u32 rec, u32 prio);

#endif // GUARD_BATTLE_ACTION_QUEUE_H
