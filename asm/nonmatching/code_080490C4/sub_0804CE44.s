	.syntax unified

	thumb_func_start sub_0804CE44
sub_0804CE44: @ 0x0804CE44
	push {lr}
	movs r0, #1
	bl read_map_script_bytes
	ldr r1, _0804CE78 @ =0x030057E0
	ldr r2, _0804CE7C @ =0x00000C94
	adds r0, r1, r2
	ldrb r3, [r0]
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _0804CE98
	movs r0, #0xf
	ands r0, r3
	cmp r0, #1
	bne _0804CE84
	ldr r0, _0804CE80 @ =0x00000C5D
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, #0xdf
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2]
	b _0804CEA2
	.align 2, 0
_0804CE78: .4byte 0x030057E0
_0804CE7C: .4byte 0x00000C94
_0804CE80: .4byte 0x00000C5D
_0804CE84:
	ldr r0, _0804CE94 @ =0x00000C5D
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r2]
	b _0804CEA2
	.align 2, 0
_0804CE94: .4byte 0x00000C5D
_0804CE98:
	movs r0, #0xf
	ands r0, r3
	ldr r2, _0804CEA8 @ =0x00000C33
	adds r1, r1, r2
	strb r0, [r1]
_0804CEA2:
	pop {r0}
	bx r0
	.align 2, 0
_0804CEA8: .4byte 0x00000C33
	.syntax divided
