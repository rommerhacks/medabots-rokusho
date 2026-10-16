	.syntax unified

	thumb_func_start sub_08013A74
sub_08013A74: @ 0x08013A74
	push {r4, r5, r6, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08013AC8 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldr r0, _08013ACC @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #8
	bhi _08013AD4
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _08013AD0 @ =0x0000FFFF
	movs r0, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r6]
	lsls r0, r0, #2
	subs r4, r4, r0
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _08013ADA
	.align 2, 0
_08013AC8: .4byte 0x03001800
_08013ACC: .4byte 0x03000440
_08013AD0: .4byte 0x0000FFFF
_08013AD4:
	ldr r1, _08013AE0 @ =0x0300137C
	movs r0, #0xb
	str r0, [r1]
_08013ADA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013AE0: .4byte 0x0300137C
	.syntax divided
