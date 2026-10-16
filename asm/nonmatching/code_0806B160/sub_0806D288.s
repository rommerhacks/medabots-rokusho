	.syntax unified

	thumb_func_start sub_0806D288
sub_0806D288: @ 0x0806D288
	ldr r0, _0806D2BC @ =0x03001800
	ldrh r0, [r0, #4]
	ldr r2, _0806D2C0 @ =0x03002B64
	cmp r0, #5
	bne _0806D2D4
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	ldr r1, _0806D2C4 @ =0x03007008
	cmp r0, #0
	bne _0806D2A4
	ldrb r0, [r1]
	cmp r0, #0
	beq _0806D2D4
_0806D2A4:
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0806D2C8 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _0806D2CC @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _0806D2D0 @ =0x0300137C
	movs r0, #0xa
	b _0806D2FA
	.align 2, 0
_0806D2BC: .4byte 0x03001800
_0806D2C0: .4byte 0x03002B64
_0806D2C4: .4byte 0x03007008
_0806D2C8: .4byte 0x0300178C
_0806D2CC: .4byte 0x03002B8C
_0806D2D0: .4byte 0x0300137C
_0806D2D4:
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0806D2FC
	ldr r0, _0806D300 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0806D2FC
	ldr r1, _0806D304 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _0806D308 @ =0x03002B8C
	movs r0, #7
	str r0, [r1]
	ldr r1, _0806D30C @ =0x0300137C
	movs r0, #0
_0806D2FA:
	str r0, [r1]
_0806D2FC:
	bx lr
	.align 2, 0
_0806D300: .4byte 0x0300058C
_0806D304: .4byte 0x0300178C
_0806D308: .4byte 0x03002B8C
_0806D30C: .4byte 0x0300137C
	.syntax divided
