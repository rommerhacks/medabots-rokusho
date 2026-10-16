	.syntax unified

	thumb_func_start sub_08006F34
sub_08006F34: @ 0x08006F34
	ldr r1, _08006F58 @ =0x0300058C
	ldrb r2, [r1]
	movs r1, #1
	ands r1, r2
	cmp r1, #0
	beq _08006FAE
	ldr r1, _08006F5C @ =0x03000440
	adds r2, r1, #0
	adds r2, #0x5a
	ldrb r2, [r2]
	adds r3, r1, #0
	cmp r2, #4
	bhi _08006FAE
	lsls r0, r2, #2
	ldr r1, _08006F60 @ =_08006F64
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006F58: .4byte 0x0300058C
_08006F5C: .4byte 0x03000440
_08006F60: .4byte _08006F64
_08006F64: @ jump table
	.4byte _08006F78 @ case 0
	.4byte _08006F84 @ case 1
	.4byte _08006F8A @ case 2
	.4byte _08006F90 @ case 3
	.4byte _08006F9E @ case 4
_08006F78:
	adds r0, r3, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x1e
	beq _08006FA8
	b _08006F9A
_08006F84:
	adds r0, r3, #0
	adds r0, #0x98
	b _08006F94
_08006F8A:
	adds r0, r3, #0
	adds r0, #0x99
	b _08006F94
_08006F90:
	adds r0, r3, #0
	adds r0, #0x9a
_08006F94:
	ldrb r0, [r0]
	cmp r0, #0x77
	bhi _08006FA8
_08006F9A:
	movs r0, #1
	b _08006FAE
_08006F9E:
	adds r0, r3, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	cmp r0, #0x77
	bls _08006FAC
_08006FA8:
	movs r0, #2
	b _08006FAE
_08006FAC:
	movs r0, #1
_08006FAE:
	bx lr
	.syntax divided
