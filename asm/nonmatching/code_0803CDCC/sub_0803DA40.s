	.syntax unified

	thumb_func_start sub_0803DA40
sub_0803DA40: @ 0x0803DA40
	push {r4, r5, lr}
	bl update_scroll_movement_a
	ldr r0, _0803DA74 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _0803DA7C
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _0803DA78 @ =0x0000FFFF
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
	b _0803DA84
	.align 2, 0
_0803DA74: .4byte 0x03000440
_0803DA78: .4byte 0x0000FFFF
_0803DA7C:
	ldr r1, _0803DA8C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DA84:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803DA8C: .4byte 0x0300137C
	.syntax divided
