	.syntax unified

	thumb_func_start sub_08011B5C
sub_08011B5C: @ 0x08011B5C
	push {r4, r5, r6, lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08011B98 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #8
	bhi _08011BA4
	ldr r5, _08011B9C @ =0x00007FFF
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _08011BA0 @ =0x0000FFFF
	adds r0, r5, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r6]
	lsls r1, r1, #2
	adds r0, r5, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _08011BAC
	.align 2, 0
_08011B98: .4byte 0x03000440
_08011B9C: .4byte 0x00007FFF
_08011BA0: .4byte 0x0000FFFF
_08011BA4:
	ldr r1, _08011BB4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08011BAC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011BB4: .4byte 0x0300137C
	.syntax divided
