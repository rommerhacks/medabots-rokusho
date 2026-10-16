	.syntax unified

	thumb_func_start sub_08047878
	.global sub_08047878
sub_08047878: @ 0x08047878
	adds r2, r1, #0
	cmp r0, #0x43
	bls _08047880
	b _08047B9A
_08047880:
	lsls r0, r0, #2
	ldr r1, _0804788C @ =_08047890
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804788C: .4byte _08047890
_08047890: @ jump table
	.4byte _08047A74 @ case 0
	.4byte _08047A94 @ case 1
	.4byte _08047AB4 @ case 2
	.4byte _08047AD4 @ case 3
	.4byte _08047AF0 @ case 4
	.4byte _08047B04 @ case 5
	.4byte _08047B24 @ case 6
	.4byte _08047B9A @ case 7
	.4byte _08047B38 @ case 8
	.4byte _08047B9A @ case 9
	.4byte _08047B9A @ case 10
	.4byte _08047B9A @ case 11
	.4byte _08047B9A @ case 12
	.4byte _08047B9A @ case 13
	.4byte _08047B9A @ case 14
	.4byte _08047B9A @ case 15
	.4byte _08047B4C @ case 16
	.4byte _08047B60 @ case 17
	.4byte _08047B74 @ case 18
	.4byte _08047B88 @ case 19
	.4byte _08047B9A @ case 20
	.4byte _08047B9A @ case 21
	.4byte _08047B9A @ case 22
	.4byte _08047B9A @ case 23
	.4byte _08047B9A @ case 24
	.4byte _08047B9A @ case 25
	.4byte _08047B9A @ case 26
	.4byte _08047B9A @ case 27
	.4byte _08047B9A @ case 28
	.4byte _08047B9A @ case 29
	.4byte _08047B9A @ case 30
	.4byte _08047B9A @ case 31
	.4byte _080479A0 @ case 32
	.4byte _080479D0 @ case 33
	.4byte _08047B9A @ case 34
	.4byte _08047B9A @ case 35
	.4byte _08047B9A @ case 36
	.4byte _08047B9A @ case 37
	.4byte _08047B9A @ case 38
	.4byte _08047B9A @ case 39
	.4byte _08047B9A @ case 40
	.4byte _08047B9A @ case 41
	.4byte _08047B9A @ case 42
	.4byte _08047B9A @ case 43
	.4byte _08047B9A @ case 44
	.4byte _08047B9A @ case 45
	.4byte _08047B9A @ case 46
	.4byte _08047B9A @ case 47
	.4byte _08047B9A @ case 48
	.4byte _08047B9A @ case 49
	.4byte _08047B9A @ case 50
	.4byte _08047B9A @ case 51
	.4byte _08047B9A @ case 52
	.4byte _08047B9A @ case 53
	.4byte _08047B9A @ case 54
	.4byte _08047B9A @ case 55
	.4byte _08047B9A @ case 56
	.4byte _08047B9A @ case 57
	.4byte _08047B9A @ case 58
	.4byte _08047B9A @ case 59
	.4byte _08047B9A @ case 60
	.4byte _08047B9A @ case 61
	.4byte _08047B9A @ case 62
	.4byte _08047B9A @ case 63
	.4byte _08047A00 @ case 64
	.4byte _08047A20 @ case 65
	.4byte _08047A3C @ case 66
	.4byte _08047A58 @ case 67
_080479A0:
	ldr r0, _080479BC @ =0x030057E0
	ldr r1, _080479C0 @ =0x00000C2D
	adds r0, r0, r1
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	ldr r0, _080479C4 @ =0x0300178C
	str r2, [r0]
	ldr r1, _080479C8 @ =0x03002B8C
	movs r0, #6
	str r0, [r1]
	ldr r0, _080479CC @ =0x0300137C
	str r2, [r0]
	b _08047B9A
	.align 2, 0
_080479BC: .4byte 0x030057E0
_080479C0: .4byte 0x00000C2D
_080479C4: .4byte 0x0300178C
_080479C8: .4byte 0x03002B8C
_080479CC: .4byte 0x0300137C
_080479D0:
	ldr r0, _080479EC @ =0x030057E0
	ldr r1, _080479F0 @ =0x00000C2D
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _080479F4 @ =0x0300178C
	str r1, [r0]
	ldr r2, _080479F8 @ =0x03002B8C
	movs r0, #6
	str r0, [r2]
	ldr r0, _080479FC @ =0x0300137C
	str r1, [r0]
	b _08047B9A
	.align 2, 0
_080479EC: .4byte 0x030057E0
_080479F0: .4byte 0x00000C2D
_080479F4: .4byte 0x0300178C
_080479F8: .4byte 0x03002B8C
_080479FC: .4byte 0x0300137C
_08047A00:
	ldr r1, _08047A14 @ =0x0300178C
	movs r0, #0
	str r0, [r1]
	ldr r1, _08047A18 @ =0x03002B8C
	movs r0, #1
	str r0, [r1]
	ldr r1, _08047A1C @ =0x0300137C
	movs r0, #0x10
	b _08047B98
	.align 2, 0
_08047A14: .4byte 0x0300178C
_08047A18: .4byte 0x03002B8C
_08047A1C: .4byte 0x0300137C
_08047A20:
	ldr r0, _08047A30 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _08047A34 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _08047A38 @ =0x0300137C
	movs r0, #0x18
	b _08047B98
	.align 2, 0
_08047A30: .4byte 0x0300178C
_08047A34: .4byte 0x03002B8C
_08047A38: .4byte 0x0300137C
_08047A3C:
	ldr r0, _08047A4C @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _08047A50 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _08047A54 @ =0x0300137C
	movs r0, #0x1c
	b _08047B98
	.align 2, 0
_08047A4C: .4byte 0x0300178C
_08047A50: .4byte 0x03002B8C
_08047A54: .4byte 0x0300137C
_08047A58:
	ldr r0, _08047A68 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _08047A6C @ =0x03002B8C
	str r1, [r0]
	ldr r1, _08047A70 @ =0x0300137C
	movs r0, #0x28
	b _08047B98
	.align 2, 0
_08047A68: .4byte 0x0300178C
_08047A6C: .4byte 0x03002B8C
_08047A70: .4byte 0x0300137C
_08047A74:
	ldr r1, _08047A88 @ =0x03000584
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08047A8C @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047A90 @ =0x03002B8C
	movs r0, #0x12
	b _08047B92
	.align 2, 0
_08047A88: .4byte 0x03000584
_08047A8C: .4byte 0x0300178C
_08047A90: .4byte 0x03002B8C
_08047A94:
	ldr r1, _08047AA8 @ =0x03000584
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08047AAC @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047AB0 @ =0x03002B8C
	movs r0, #0x12
	b _08047B92
	.align 2, 0
_08047AA8: .4byte 0x03000584
_08047AAC: .4byte 0x0300178C
_08047AB0: .4byte 0x03002B8C
_08047AB4:
	ldr r1, _08047AC8 @ =0x03000584
	movs r0, #2
	strb r0, [r1]
	ldr r1, _08047ACC @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047AD0 @ =0x03002B8C
	movs r0, #0x12
	b _08047B92
	.align 2, 0
_08047AC8: .4byte 0x03000584
_08047ACC: .4byte 0x0300178C
_08047AD0: .4byte 0x03002B8C
_08047AD4:
	ldr r0, _08047AE4 @ =0x03002420
	strb r2, [r0]
	ldr r1, _08047AE8 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047AEC @ =0x03002B8C
	movs r0, #0xb
	b _08047B92
	.align 2, 0
_08047AE4: .4byte 0x03002420
_08047AE8: .4byte 0x0300178C
_08047AEC: .4byte 0x03002B8C
_08047AF0:
	ldr r1, _08047AFC @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047B00 @ =0x03002B8C
	movs r0, #0x15
	b _08047B92
	.align 2, 0
_08047AFC: .4byte 0x0300178C
_08047B00: .4byte 0x03002B8C
_08047B04:
	ldr r1, _08047B18 @ =0x03000588
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08047B1C @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047B20 @ =0x03002B8C
	movs r0, #0x14
	b _08047B92
	.align 2, 0
_08047B18: .4byte 0x03000588
_08047B1C: .4byte 0x0300178C
_08047B20: .4byte 0x03002B8C
_08047B24:
	ldr r1, _08047B30 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047B34 @ =0x03002B8C
	movs r0, #0x17
	b _08047B92
	.align 2, 0
_08047B30: .4byte 0x0300178C
_08047B34: .4byte 0x03002B8C
_08047B38:
	ldr r1, _08047B44 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047B48 @ =0x03002B8C
	movs r0, #0x16
	b _08047B92
	.align 2, 0
_08047B44: .4byte 0x0300178C
_08047B48: .4byte 0x03002B8C
_08047B4C:
	ldr r1, _08047B58 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _08047B5C @ =0x03002B8C
	movs r0, #4
	b _08047B92
	.align 2, 0
_08047B58: .4byte 0x0300178C
_08047B5C: .4byte 0x03002B8C
_08047B60:
	ldr r1, _08047B6C @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _08047B70 @ =0x03002B8C
	movs r0, #5
	b _08047B92
	.align 2, 0
_08047B6C: .4byte 0x0300178C
_08047B70: .4byte 0x03002B8C
_08047B74:
	ldr r0, _08047B80 @ =0x0300178C
	movs r1, #3
	str r1, [r0]
	ldr r0, _08047B84 @ =0x03002B8C
	str r1, [r0]
	b _08047B94
	.align 2, 0
_08047B80: .4byte 0x0300178C
_08047B84: .4byte 0x03002B8C
_08047B88:
	ldr r1, _08047B9C @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _08047BA0 @ =0x03002B8C
	movs r0, #6
_08047B92:
	str r0, [r1]
_08047B94:
	ldr r1, _08047BA4 @ =0x0300137C
	movs r0, #0
_08047B98:
	str r0, [r1]
_08047B9A:
	bx lr
	.align 2, 0
_08047B9C: .4byte 0x0300178C
_08047BA0: .4byte 0x03002B8C
_08047BA4: .4byte 0x0300137C
	.syntax divided
