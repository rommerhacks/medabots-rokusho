	.syntax unified

	thumb_func_start sub_08027378
sub_08027378: @ 0x08027378
	push {r4, r5, r6, lr}
	ldr r4, _080273B8 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl sub_080378A8
	adds r6, r4, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #4
	bhi _080273C4
	ldr r5, _080273BC @ =0x00007FFF
	adds r1, r0, #0
	lsls r1, r1, #3
	ldr r4, _080273C0 @ =0x0000FFFF
	adds r0, r5, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r6]
	lsls r1, r1, #3
	adds r0, r5, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _080273D2
	.align 2, 0
_080273B8: .4byte 0x03000440
_080273BC: .4byte 0x00007FFF
_080273C0: .4byte 0x0000FFFF
_080273C4:
	movs r0, #0
	strb r0, [r6]
	ldr r1, _080273D8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080273D2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080273D8: .4byte 0x03001800
	.syntax divided
