	.syntax unified

	thumb_func_start display_battle_cursor_on_bot
	.global display_battle_cursor_on_bot
display_battle_cursor_on_bot: @ 0x080185A8
	push {lr}
	ldr r3, _080185E0 @ =0x083AD3A4
	ldr r0, _080185E4 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x3d
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r2, #1
	adds r2, r2, r3
	ldrb r2, [r2]
	bl setup_bot_battle_sprites_08017A7C
	movs r0, #8
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #1
	bl draw_bg_window_rect
	pop {r0}
	bx r0
	.align 2, 0
_080185E0: .4byte 0x083AD3A4
_080185E4: .4byte 0x03000440
	.syntax divided
