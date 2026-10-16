	.syntax unified

	thumb_func_start sub_08023224
sub_08023224: @ 0x08023224
	push {r4, r5, lr}
	ldr r4, _08023258 @ =0x00001084
	ldr r0, _0802325C @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r1, [r5]
	ldr r2, _08023260 @ =0x0000FFFF
	adds r0, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	movs r2, #0xff
	lsls r2, r2, #8
	adds r0, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	cmp r0, #0
	bne _08023268
	ldr r1, _08023264 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802326C
	.align 2, 0
_08023258: .4byte 0x00001084
_0802325C: .4byte 0x03000440
_08023260: .4byte 0x0000FFFF
_08023264: .4byte 0x03001800
_08023268:
	subs r0, #1
	strb r0, [r5]
_0802326C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
