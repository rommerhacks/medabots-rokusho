	.syntax unified

	thumb_func_start sub_080112F0
sub_080112F0: @ 0x080112F0
	push {r4, r5, lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08011328 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08011330
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _0801132C @ =0x0000FFFF
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
	b _08011338
	.align 2, 0
_08011328: .4byte 0x03000440
_0801132C: .4byte 0x0000FFFF
_08011330:
	ldr r1, _08011340 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08011338:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011340: .4byte 0x0300137C
	.syntax divided
