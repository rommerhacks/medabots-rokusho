	.syntax unified

	thumb_func_start sub_080034A4
sub_080034A4: @ 0x080034A4
	push {r4, r5, lr}
	bl sub_080039BC
	ldr r0, _080034E0 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _080034EC
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _080034E4 @ =0x00001FFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #2
	subs r4, r4, r0
	ldr r2, _080034E8 @ =0x0000FFFF
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _080034F8
	.align 2, 0
_080034E0: .4byte 0x03000440
_080034E4: .4byte 0x00001FFF
_080034E8: .4byte 0x0000FFFF
_080034EC:
	bl sub_0800393C
	ldr r1, _08003500 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080034F8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003500: .4byte 0x0300137C
	.syntax divided
