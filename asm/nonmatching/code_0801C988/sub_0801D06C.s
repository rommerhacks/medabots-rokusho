	.syntax unified

	thumb_func_start sub_0801D06C
sub_0801D06C: @ 0x0801D06C
	push {r4, r5, r6, lr}
	ldr r2, _0801D0D8 @ =0x03002C30
	ldr r3, _0801D0DC @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r0, #2
	lsls r4, r0, #0xa
	ldr r1, _0801D0E0 @ =0xFFFFC204
	adds r0, r1, #0
	movs r1, #0x84
	lsls r1, r1, #4
	adds r6, r2, r1
	movs r5, #0
	orrs r4, r0
	strh r4, [r6]
	adds r1, #0x1c
	adds r0, r2, r1
	strb r5, [r0]
	ldr r0, _0801D0E4 @ =0x0000084A
	adds r1, r2, r0
	movs r0, #6
	strb r0, [r1]
	ldr r0, _0801D0E8 @ =0x00000849
	adds r1, r2, r0
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _0801D0EC @ =0x00000848
	adds r1, r2, r0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _0801D0F0 @ =0x0000084B
	adds r1, r2, r0
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _0801D0F4 @ =0x00000844
	adds r1, r2, r0
	movs r0, #0x3c
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801D0FC
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r4, r0
	strh r4, [r6]
	ldr r0, _0801D0F8 @ =0x00000842
	adds r1, r2, r0
	movs r0, #0x68
	b _0801D102
	.align 2, 0
_0801D0D8: .4byte 0x03002C30
_0801D0DC: .4byte 0x03001800
_0801D0E0: .4byte 0xFFFFC204
_0801D0E4: .4byte 0x0000084A
_0801D0E8: .4byte 0x00000849
_0801D0EC: .4byte 0x00000848
_0801D0F0: .4byte 0x0000084B
_0801D0F4: .4byte 0x00000844
_0801D0F8: .4byte 0x00000842
_0801D0FC:
	ldr r0, _0801D118 @ =0x00000842
	adds r1, r2, r0
	movs r0, #0x88
_0801D102:
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801D134
	cmp r0, #1
	bgt _0801D11C
	cmp r0, #0
	beq _0801D126
	b _0801D15E
	.align 2, 0
_0801D118: .4byte 0x00000842
_0801D11C:
	cmp r0, #2
	beq _0801D144
	cmp r0, #3
	beq _0801D154
	b _0801D15E
_0801D126:
	ldr r0, _0801D130 @ =0x00000846
	adds r1, r2, r0
	movs r0, #0xb0
	lsls r0, r0, #4
	b _0801D15C
	.align 2, 0
_0801D130: .4byte 0x00000846
_0801D134:
	ldr r0, _0801D140 @ =0x00000846
	adds r1, r2, r0
	movs r0, #0xc0
	lsls r0, r0, #4
	b _0801D15C
	.align 2, 0
_0801D140: .4byte 0x00000846
_0801D144:
	ldr r0, _0801D150 @ =0x00000846
	adds r1, r2, r0
	movs r0, #0xd0
	lsls r0, r0, #4
	b _0801D15C
	.align 2, 0
_0801D150: .4byte 0x00000846
_0801D154:
	ldr r0, _0801D170 @ =0x00000846
	adds r1, r2, r0
	movs r0, #0xe0
	lsls r0, r0, #4
_0801D15C:
	strh r0, [r1]
_0801D15E:
	adds r1, r3, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D170: .4byte 0x00000846
	.syntax divided
