	.syntax unified

	thumb_func_start sub_08044E64
	.global sub_08044E64
sub_08044E64: @ 0x08044E64
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r2, r0
	beq _08044EC8
	cmp r2, r0
	bgt _08044E7A
	cmp r2, #0
	beq _08044E84
	b _08044F4A
_08044E7A:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r2, r0
	beq _08044F0C
	b _08044F4A
_08044E84:
	movs r0, #0xc0
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08044EC0
	cmp r1, r0
	bgt _08044E9A
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08044EB8
	b _08044F4A
_08044E9A:
	cmp r1, #0
	beq _08044EA8
	movs r0, #0x80
	lsls r0, r0, #0x17
	cmp r1, r0
	beq _08044EB0
	b _08044F4A
_08044EA8:
	ldr r3, _08044EAC @ =0x00080008
	b _08044F4A
	.align 2, 0
_08044EAC: .4byte 0x00080008
_08044EB0:
	ldr r3, _08044EB4 @ =0x00100010
	b _08044F4A
	.align 2, 0
_08044EB4: .4byte 0x00100010
_08044EB8:
	ldr r3, _08044EBC @ =0x00200020
	b _08044F4A
	.align 2, 0
_08044EBC: .4byte 0x00200020
_08044EC0:
	ldr r3, _08044EC4 @ =0x00400040
	b _08044F4A
	.align 2, 0
_08044EC4: .4byte 0x00400040
_08044EC8:
	movs r0, #0xc0
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08044F04
	cmp r1, r0
	bgt _08044EDE
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08044EFC
	b _08044F4A
_08044EDE:
	cmp r1, #0
	beq _08044EEC
	movs r0, #0x80
	lsls r0, r0, #0x17
	cmp r1, r0
	beq _08044EF4
	b _08044F4A
_08044EEC:
	ldr r3, _08044EF0 @ =0x00080010
	b _08044F4A
	.align 2, 0
_08044EF0: .4byte 0x00080010
_08044EF4:
	ldr r3, _08044EF8 @ =0x00080020
	b _08044F4A
	.align 2, 0
_08044EF8: .4byte 0x00080020
_08044EFC:
	ldr r3, _08044F00 @ =0x00100020
	b _08044F4A
	.align 2, 0
_08044F00: .4byte 0x00100020
_08044F04:
	ldr r3, _08044F08 @ =0x00200040
	b _08044F4A
	.align 2, 0
_08044F08: .4byte 0x00200040
_08044F0C:
	movs r0, #0xc0
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08044F48
	cmp r1, r0
	bgt _08044F22
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08044F40
	b _08044F4A
_08044F22:
	cmp r1, #0
	beq _08044F30
	movs r0, #0x80
	lsls r0, r0, #0x17
	cmp r1, r0
	beq _08044F38
	b _08044F4A
_08044F30:
	ldr r3, _08044F34 @ =0x00100008
	b _08044F4A
	.align 2, 0
_08044F34: .4byte 0x00100008
_08044F38:
	ldr r3, _08044F3C @ =0x00200008
	b _08044F4A
	.align 2, 0
_08044F3C: .4byte 0x00200008
_08044F40:
	ldr r3, _08044F44 @ =0x00200010
	b _08044F4A
	.align 2, 0
_08044F44: .4byte 0x00200010
_08044F48:
	ldr r3, _08044F50 @ =0x00400020
_08044F4A:
	adds r0, r3, #0
	bx lr
	.align 2, 0
_08044F50: .4byte 0x00400020
	.syntax divided
