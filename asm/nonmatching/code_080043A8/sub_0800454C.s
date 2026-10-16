	.syntax unified

	thumb_func_start sub_0800454C
sub_0800454C: @ 0x0800454C
	push {r4, lr}
	bl sub_08004E74
	bl sub_08006764
	bl toggle_sprite_pair_visibility
	bl dispatch_game_substate_handler_08006824
	bl battle_update_medabot_display
	bl sub_08006F14
	ldr r1, _0800459C @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #0
	bne _080045A8
	adds r4, r1, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #8
	bhi _080045B0
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r2, _080045A0 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #2
	ldr r2, _080045A4 @ =0x0000F0FF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _080045B8
	.align 2, 0
_0800459C: .4byte 0x03000440
_080045A0: .4byte 0x0000FFFF
_080045A4: .4byte 0x0000F0FF
_080045A8:
	bl update_blend_effect
	cmp r0, #0
	beq _080045B8
_080045B0:
	ldr r1, _080045C0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080045B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080045C0: .4byte 0x0300137C
	.syntax divided
