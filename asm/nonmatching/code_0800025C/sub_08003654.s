	.syntax unified

	thumb_func_start sub_08003654
sub_08003654: @ 0x08003654
	push {r4, lr}
	bl sub_080039BC
	ldr r0, _08003688 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #8
	bhi _08003694
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r2, _0800368C @ =0x00001FFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #2
	ldr r2, _08003690 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0800369C
	.align 2, 0
_08003688: .4byte 0x03000440
_0800368C: .4byte 0x00001FFF
_08003690: .4byte 0x0000FFFF
_08003694:
	ldr r1, _080036A4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800369C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080036A4: .4byte 0x0300137C
	.syntax divided
