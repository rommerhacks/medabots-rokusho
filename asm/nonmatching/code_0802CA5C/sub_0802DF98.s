	.syntax unified

	thumb_func_start sub_0802DF98
sub_0802DF98: @ 0x0802DF98
	push {r4, r5, lr}
	ldr r4, _0802DFCC @ =0x00001084
	ldr r0, _0802DFD0 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r1, [r5]
	ldr r2, _0802DFD4 @ =0x0000FFFF
	adds r0, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	movs r2, #0xff
	lsls r2, r2, #8
	adds r0, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	cmp r0, #0x10
	bne _0802DFDC
	ldr r1, _0802DFD8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802DFE0
	.align 2, 0
_0802DFCC: .4byte 0x00001084
_0802DFD0: .4byte 0x03000440
_0802DFD4: .4byte 0x0000FFFF
_0802DFD8: .4byte 0x03001800
_0802DFDC:
	subs r0, #2
	strb r0, [r5]
_0802DFE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
