	.syntax unified

	thumb_func_start sub_080653B4
sub_080653B4: @ 0x080653B4
	push {r4, r5, lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0806540E
	ldr r0, _080653EC @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _080653F4
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _080653F0 @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0806540E
	.align 2, 0
_080653EC: .4byte 0x03000440
_080653F0: .4byte 0x0000FFFF
_080653F4:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _08065414 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	movs r0, #2
	bl dispatch_by_index_0476e8
_0806540E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065414: .4byte 0x0000FDFF
	.syntax divided
