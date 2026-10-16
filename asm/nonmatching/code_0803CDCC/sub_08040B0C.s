	.syntax unified

	thumb_func_start sub_08040B0C
sub_08040B0C: @ 0x08040B0C
	push {r4, r5, r6, lr}
	movs r5, #0xd9
	lsls r5, r5, #1
	ldr r6, _08040B3C @ =0x03000440
	ldrb r1, [r6, #0x1c]
	lsls r1, r1, #1
	ldr r4, _08040B40 @ =0x00001FFF
	adds r0, r5, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r6, #0x1c]
	lsls r1, r1, #1
	adds r0, r5, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6, #0x1c]
	cmp r0, #0
	bne _08040B44
	ldrb r0, [r6, #0x1b]
	adds r0, #1
	strb r0, [r6, #0x1b]
	b _08040B48
	.align 2, 0
_08040B3C: .4byte 0x03000440
_08040B40: .4byte 0x00001FFF
_08040B44:
	subs r0, #1
	strb r0, [r6, #0x1c]
_08040B48:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08040B50:
	.byte 0x01, 0x49, 0x08, 0x20, 0x08, 0x71, 0x70, 0x47, 0x40, 0x04, 0x00, 0x03
	.syntax divided
