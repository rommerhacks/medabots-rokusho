#ifndef GUARD_SHOP_SHOP_MENU_H
#define GUARD_SHOP_SHOP_MENU_H

// Mode-2 state 11: Medaparts shop menu (Buy / Sell / Exit)

void shop_copy_text_with_portrait(); // (u8 *dst, u8 *src, u32 unused, u32 i): copies src[i..] up to 0xFF plus 2 bytes,
                                     // dst[2]
void shop_menu_close_message(void);  // state 6: closes the message window
void shop_menu_part_type_prompt(void); // state 9: "Please select the Medapart type you want."
void shop_highlight_part_type_icon(
    u32 sel, u32 frame);               // BG2 tiles of 4 icons: palette 6 for icon sel when frame & 8, else palette 5
void shop_menu_greeting(void);         // state 4: "What can I help you with today?"
void shop_menu_part_type_chosen(void); // state 12: icon blinks 45 frames, message closes
void shop_menu_start(void);            // state 0: cursor on Buy, not returning from the list; -> 14
void shop_menu_goto_init(void);        // state 15: -> 1
void shop_menu_dispatch(void);         // gShopMenuStates[gGameSubState](), BG3 scrolls diagonally
void shop_menu_fade_out_exit(void);    // state 7: fade to white, back to the field
void shop_menu_close_part_types(void); // state 11 (B): cursor grows back, BG2 fades out; -> 4
void shop_menu_fade_out_to_list(void); // state 13: fade out, game state 12 (shop list)
void shop_menu_show_layers(void);      // state 2: BG1-3 + OBJ on, palettes to the blend buffer
void shop_menu_open_part_types(void);  // state 8: cursor shrinks, part type panel (BG2) fades in

#endif // GUARD_SHOP_SHOP_MENU_H
