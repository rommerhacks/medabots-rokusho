	.syntax unified

	thumb_func_start sub_080230C8
sub_080230C8: @ 0x080230C8
	push {r4, r5, lr}
	ldr r4, _080230FC @ =0x00001084
	ldr r0, _08023100 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r1, [r5]
	ldr r2, _08023104 @ =0x0000FFFF
	adds r0, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	movs r2, #0xff
	lsls r2, r2, #8
	adds r0, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	cmp r0, #0x10
	bne _0802310C
	ldr r1, _08023108 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08023110
	.align 2, 0
_080230FC: .4byte 0x00001084
_08023100: .4byte 0x03000440
_08023104: .4byte 0x0000FFFF
_08023108: .4byte 0x03001800
_0802310C:
	adds r0, #1
	strb r0, [r5]
_08023110:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
