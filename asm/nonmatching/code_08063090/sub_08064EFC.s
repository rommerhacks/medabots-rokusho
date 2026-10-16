	.syntax unified

	thumb_func_start sub_08064EFC
sub_08064EFC: @ 0x08064EFC
	push {r4, r5, r6, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0
	ldr r3, _08064F84 @ =0x03006F74
	ldr r6, _08064F88 @ =0x03000584
	adds r5, r3, #0
	movs r4, #0xfe
_08064F3C:
	ldr r1, [r5]
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r1, #0x58
	adds r1, r1, r0
	strb r4, [r1]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	ble _08064F3C
	ldrb r0, [r6]
	cmp r0, #0
	bne _08064F8C
	movs r2, #0
	ldr r0, [r3]
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _08064F96
_08064F66:
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0xf
	bgt _08064F96
	ldr r0, [r3]
	adds r0, #0x58
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xfe
	bne _08064F66
	b _08064F96
	.align 2, 0
_08064F84: .4byte 0x03006F74
_08064F88: .4byte 0x03000584
_08064F8C:
	ldr r0, [r3]
	adds r0, #0x2f
	ldrb r0, [r0]
	bl render_battle_medal_names
_08064F96:
	ldr r0, _08064FE8 @ =0x08483AA0
	ldr r1, _08064FEC @ =0x0202FA20
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08064FF0 @ =0x084E2E58
	ldr r1, _08064FF4 @ =0x0202F800
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08064FF8 @ =0x084E2E38
	ldr r1, _08064FFC @ =0x0202F9E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08065000 @ =0x0850DD18
	ldr r1, _08065004 @ =0x0202F9A0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08065008 @ =0x08799B98
	ldr r1, _0806500C @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _08065010 @ =0x080AFAE8
	ldr r1, _08065014 @ =0x0202F940
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08065018 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0806501C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064FE8: .4byte 0x08483AA0
_08064FEC: .4byte 0x0202FA20
_08064FF0: .4byte 0x084E2E58
_08064FF4: .4byte 0x0202F800
_08064FF8: .4byte 0x084E2E38
_08064FFC: .4byte 0x0202F9E0
_08065000: .4byte 0x0850DD18
_08065004: .4byte 0x0202F9A0
_08065008: .4byte 0x08799B98
_0806500C: .4byte 0x0202FA00
_08065010: .4byte 0x080AFAE8
_08065014: .4byte 0x0202F940
_08065018: .4byte 0x03000440
_0806501C: .4byte 0x0300137C
	.syntax divided
