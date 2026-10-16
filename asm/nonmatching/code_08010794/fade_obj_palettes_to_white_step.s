	.syntax unified

	thumb_func_start fade_obj_palettes_to_white_step
fade_obj_palettes_to_white_step: @ 0x08012B40
	push {r4, r5, r6, lr}
	ldr r0, _08012B78 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #8
	bhi _08012B80
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _08012B7C @ =0x0000FFFF
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
	b _08012B88
	.align 2, 0
_08012B78: .4byte 0x03000440
_08012B7C: .4byte 0x0000FFFF
_08012B80:
	ldr r1, _08012B90 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08012B88:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08012B90: .4byte 0x0300137C
	.syntax divided
