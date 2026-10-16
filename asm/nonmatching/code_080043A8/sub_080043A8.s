	.syntax unified

	thumb_func_start sub_080043A8
sub_080043A8: @ 0x080043A8
	push {r4, r5, lr}
	bl sub_08004E74
	bl sub_08006764
	bl toggle_sprite_pair_visibility
	bl dispatch_game_substate_handler_08006824
	bl battle_update_medabot_display
	bl sub_08006F14
	ldr r1, _08004400 @ =0x03000440
	adds r4, r1, #0
	adds r4, #0x56
	ldrb r0, [r4]
	cmp r0, #0
	bne _0800440C
	adds r5, r1, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08004414
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _08004404 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #2
	subs r4, r4, r0
	ldr r2, _08004408 @ =0x0000F0FF
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08004420
	.align 2, 0
_08004400: .4byte 0x03000440
_08004404: .4byte 0x0000FFFF
_08004408: .4byte 0x0000F0FF
_0800440C:
	bl update_blend_effect
	cmp r0, #0
	beq _08004420
_08004414:
	movs r0, #1
	strb r0, [r4]
	ldr r1, _08004428 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08004420:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08004428: .4byte 0x0300137C
	.syntax divided
