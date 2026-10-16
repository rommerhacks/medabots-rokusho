	.syntax unified

	thumb_func_start sub_08008CA0
sub_08008CA0: @ 0x08008CA0
	push {r4, r5, r6, lr}
	bl sub_080093F8
	ldr r0, _08008CBC @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x42
	ldrb r1, [r1]
	cmp r1, #1
	beq _08008D60
	cmp r1, #1
	bgt _08008CC0
	cmp r1, #0
	beq _08008CC8
	b _080090B4
	.align 2, 0
_08008CBC: .4byte 0x03000440
_08008CC0:
	cmp r1, #2
	bne _08008CC6
	b _08009090
_08008CC6:
	b _080090B4
_08008CC8:
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #4
	bls _08008CD2
	b _080090B4
_08008CD2:
	lsls r0, r0, #2
	ldr r1, _08008CDC @ =_08008CE0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08008CDC: .4byte _08008CE0
_08008CE0: @ jump table
	.4byte _08008CF4 @ case 0
	.4byte _08008D00 @ case 1
	.4byte _08008D0C @ case 2
	.4byte _08008D30 @ case 3
	.4byte _08008D54 @ case 4
_08008CF4:
	ldr r0, _08008CFC @ =0x083B53F8
	ldr r0, [r0, #0x18]
	b _080090AC
	.align 2, 0
_08008CFC: .4byte 0x083B53F8
_08008D00:
	ldr r0, _08008D08 @ =0x083B53F8
	ldr r0, [r0, #0x1c]
	b _080090AC
	.align 2, 0
_08008D08: .4byte 0x083B53F8
_08008D0C:
	ldr r2, _08008D24 @ =0x083B69C8
	ldr r1, _08008D28 @ =0x03000BE0
	ldr r0, _08008D2C @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #4]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	b _080090AC
	.align 2, 0
_08008D24: .4byte 0x083B69C8
_08008D28: .4byte 0x03000BE0
_08008D2C: .4byte 0x03000440
_08008D30:
	ldr r2, _08008D48 @ =0x083B70AC
	ldr r1, _08008D4C @ =0x03000BE0
	ldr r0, _08008D50 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #6]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	b _080090AC
	.align 2, 0
_08008D48: .4byte 0x083B70AC
_08008D4C: .4byte 0x03000BE0
_08008D50: .4byte 0x03000440
_08008D54:
	ldr r0, _08008D5C @ =0x083B53F8
	ldr r0, [r0, #0x20]
	b _080090AC
	.align 2, 0
_08008D5C: .4byte 0x083B53F8
_08008D60:
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #5
	bls _08008D6A
	b _080090B4
_08008D6A:
	lsls r0, r0, #2
	ldr r1, _08008D74 @ =_08008D78
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08008D74: .4byte _08008D78
_08008D78: @ jump table
	.4byte _08008D90 @ case 0
	.4byte _08008E08 @ case 1
	.4byte _08008E80 @ case 2
	.4byte _08008EF8 @ case 3
	.4byte _08008F04 @ case 4
	.4byte _08008F10 @ case 5
_08008D90:
	ldr r0, _08008DE4 @ =0x03000BE0
	ldr r5, _08008DE8 @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #9
	bls _08008DFC
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08008DEC @ =0x083B7E0C
	adds r0, r0, r1
	adds r4, r5, #0
	adds r4, #0xee
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08008DF0 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _08008DF4 @ =0x083B7F40
	ldr r2, _08008DF8 @ =0x00000113
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _080090AC
	.align 2, 0
_08008DE4: .4byte 0x03000BE0
_08008DE8: .4byte 0x03000440
_08008DEC: .4byte 0x083B7E0C
_08008DF0: .4byte 0x083B7CD4
_08008DF4: .4byte 0x083B7F40
_08008DF8: .4byte 0x00000113
_08008DFC:
	ldr r0, _08008E04 @ =0x083B7F40
	ldr r0, [r0, #0x10]
	b _080090AC
	.align 2, 0
_08008E04: .4byte 0x083B7F40
_08008E08:
	ldr r0, _08008E5C @ =0x03000BE0
	ldr r4, _08008E60 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x1d
	bls _08008E74
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08008E64 @ =0x083B7E0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xee
	movs r2, #3
	bl memcpy_bytes_08041D04
	adds r0, r4, #0
	adds r0, #0xef
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08008E68 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _08008E6C @ =0x083B7F40
	ldr r2, _08008E70 @ =0x00000113
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _080090AC
	.align 2, 0
_08008E5C: .4byte 0x03000BE0
_08008E60: .4byte 0x03000440
_08008E64: .4byte 0x083B7E0C
_08008E68: .4byte 0x083B7CD4
_08008E6C: .4byte 0x083B7F40
_08008E70: .4byte 0x00000113
_08008E74:
	ldr r0, _08008E7C @ =0x083B7F40
	ldr r0, [r0, #0x10]
	b _080090AC
	.align 2, 0
_08008E7C: .4byte 0x083B7F40
_08008E80:
	ldr r0, _08008ED4 @ =0x03000BE0
	ldr r4, _08008ED8 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x3b
	bls _08008EEC
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08008EDC @ =0x083B7E0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xee
	movs r2, #3
	bl memcpy_bytes_08041D04
	adds r0, r4, #0
	adds r0, #0xf0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08008EE0 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _08008EE4 @ =0x083B7F40
	ldr r2, _08008EE8 @ =0x00000113
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _080090AC
	.align 2, 0
_08008ED4: .4byte 0x03000BE0
_08008ED8: .4byte 0x03000440
_08008EDC: .4byte 0x083B7E0C
_08008EE0: .4byte 0x083B7CD4
_08008EE4: .4byte 0x083B7F40
_08008EE8: .4byte 0x00000113
_08008EEC:
	ldr r0, _08008EF4 @ =0x083B7F40
	ldr r0, [r0, #0x10]
	b _080090AC
	.align 2, 0
_08008EF4: .4byte 0x083B7F40
_08008EF8:
	ldr r0, _08008F00 @ =0x083B53F8
	ldr r0, [r0, #0x24]
	b _080090AC
	.align 2, 0
_08008F00: .4byte 0x083B53F8
_08008F04:
	ldr r0, _08008F0C @ =0x083B53F8
	ldr r0, [r0, #0x28]
	b _080090AC
	.align 2, 0
_08008F0C: .4byte 0x083B53F8
_08008F10:
	ldr r5, _08008F28 @ =0x03000440
	adds r6, r5, #0
	adds r6, #0x46
	ldrb r0, [r6]
	cmp r0, #1
	beq _08008FA8
	cmp r0, #1
	bgt _08008F2C
	cmp r0, #0
	beq _08008F32
	b _080090B4
	.align 2, 0
_08008F28: .4byte 0x03000440
_08008F2C:
	cmp r0, #2
	beq _0800901C
	b _080090B4
_08008F32:
	ldr r0, _08008F88 @ =0x03000BE0
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #9
	bls _08008F9C
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08008F8C @ =0x083B7E0C
	adds r0, r0, r1
	adds r4, r5, #0
	adds r4, #0xee
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r0, [r6]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08008F90 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _08008F94 @ =0x083B8170
	ldr r2, _08008F98 @ =0x0000010F
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _080090AC
	.align 2, 0
_08008F88: .4byte 0x03000BE0
_08008F8C: .4byte 0x083B7E0C
_08008F90: .4byte 0x083B7CD4
_08008F94: .4byte 0x083B8170
_08008F98: .4byte 0x0000010F
_08008F9C:
	ldr r0, _08008FA4 @ =0x083B53F8
	ldr r0, [r0, #0x2c]
	b _080090AC
	.align 2, 0
_08008FA4: .4byte 0x083B53F8
_08008FA8:
	ldr r0, _08008FFC @ =0x03000BE0
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x1d
	bls _08009010
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08009000 @ =0x083B7E0C
	adds r0, r0, r1
	adds r4, r5, #0
	adds r4, #0xee
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r0, [r6]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08009004 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _08009008 @ =0x083B8170
	ldr r2, _0800900C @ =0x0000010F
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _080090AC
	.align 2, 0
_08008FFC: .4byte 0x03000BE0
_08009000: .4byte 0x083B7E0C
_08009004: .4byte 0x083B7CD4
_08009008: .4byte 0x083B8170
_0800900C: .4byte 0x0000010F
_08009010:
	ldr r0, _08009018 @ =0x083B53F8
	ldr r0, [r0, #0x2c]
	b _080090AC
	.align 2, 0
_08009018: .4byte 0x083B53F8
_0800901C:
	ldr r0, _08009070 @ =0x03000BE0
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x3b
	bls _08009084
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08009074 @ =0x083B7E0C
	adds r0, r0, r1
	adds r4, r5, #0
	adds r4, #0xee
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r0, [r6]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08009078 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _0800907C @ =0x083B8170
	ldr r2, _08009080 @ =0x0000010F
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _080090AC
	.align 2, 0
_08009070: .4byte 0x03000BE0
_08009074: .4byte 0x083B7E0C
_08009078: .4byte 0x083B7CD4
_0800907C: .4byte 0x083B8170
_08009080: .4byte 0x0000010F
_08009084:
	ldr r0, _0800908C @ =0x083B53F8
	ldr r0, [r0, #0x2c]
	b _080090AC
	.align 2, 0
_0800908C: .4byte 0x083B53F8
_08009090:
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800909E
	cmp r0, #1
	beq _080090A8
	b _080090B4
_0800909E:
	ldr r0, _080090A4 @ =0x083B53F8
	ldr r0, [r0, #0x34]
	b _080090AC
	.align 2, 0
_080090A4: .4byte 0x083B53F8
_080090A8:
	ldr r0, _080090C8 @ =0x083B53F8
	ldr r0, [r0, #0x38]
_080090AC:
	bl run_message
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080090B4:
	cmp r4, #0
	beq _080090C2
	bl sub_0803FB0C
	ldr r1, _080090CC @ =0x0300137C
	movs r0, #0x49
	str r0, [r1]
_080090C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080090C8: .4byte 0x083B53F8
_080090CC: .4byte 0x0300137C
	.syntax divided
