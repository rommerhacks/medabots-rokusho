	.syntax unified

	thumb_func_start sub_0803FC20
sub_0803FC20: @ 0x0803FC20
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _0803FC3C @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x26
	ldrb r4, [r5]
	adds r1, r0, #0
	cmp r4, #1
	beq _0803FC60
	cmp r4, #1
	bgt _0803FC40
	cmp r4, #0
	beq _0803FC46
	b _0803FCB8
	.align 2, 0
_0803FC3C: .4byte 0x03000440
_0803FC40:
	cmp r4, #2
	beq _0803FC84
	b _0803FCB8
_0803FC46:
	ldr r0, _0803FC54 @ =0x08487630
	ldr r1, _0803FC58 @ =0x06000020
	bl lz_decompress_dispatch
	ldr r2, _0803FC5C @ =0x08488600
	b _0803FC8E
	.align 2, 0
_0803FC54: .4byte 0x08487630
_0803FC58: .4byte 0x06000020
_0803FC5C: .4byte 0x08488600
_0803FC60:
	ldr r0, _0803FC74 @ =0x08487524
	ldr r1, _0803FC78 @ =0x06000020
	bl lz_decompress_dispatch
	ldr r2, _0803FC7C @ =0x084885A8
	ldr r0, _0803FC80 @ =0x04000008
	ldrh r3, [r0]
	str r4, [sp]
	b _0803FC96
	.align 2, 0
_0803FC74: .4byte 0x08487524
_0803FC78: .4byte 0x06000020
_0803FC7C: .4byte 0x084885A8
_0803FC80: .4byte 0x04000008
_0803FC84:
	ldr r0, _0803FCA8 @ =0x084873D0
	ldr r1, _0803FCAC @ =0x06000020
	bl lz_decompress_dispatch
	ldr r2, _0803FCB0 @ =0x08488540
_0803FC8E:
	ldr r0, _0803FCB4 @ =0x04000008
	ldrh r3, [r0]
	movs r0, #1
	str r0, [sp]
_0803FC96:
	movs r0, #0
	movs r1, #0xd
	bl set_tilemap_and_decompress_bg
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0803FCBE
	.align 2, 0
_0803FCA8: .4byte 0x084873D0
_0803FCAC: .4byte 0x06000020
_0803FCB0: .4byte 0x08488540
_0803FCB4: .4byte 0x04000008
_0803FCB8:
	ldrb r0, [r1, #4]
	adds r0, #1
	strb r0, [r1, #4]
_0803FCBE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
