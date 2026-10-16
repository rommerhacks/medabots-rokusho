	.syntax unified

	thumb_func_start sub_0800AE54
sub_0800AE54: @ 0x0800AE54
	push {r4, lr}
	ldr r0, _0800AE84 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0800AE94
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0800AE88 @ =0x03000BE0
	ldr r1, _0800AE8C @ =0x03000440
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #9]
	cmp r0, #0
	bne _0800AE90
	movs r0, #7
	b _0800AEC2
	.align 2, 0
_0800AE84: .4byte 0x03001798
_0800AE88: .4byte 0x03000BE0
_0800AE8C: .4byte 0x03000440
_0800AE90:
	subs r0, #1
	b _0800AEC2
_0800AE94:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800AEC8
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0800AEB8 @ =0x03000BE0
	ldr r1, _0800AEBC @ =0x03000440
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #9]
	cmp r0, #7
	bne _0800AEC0
	strb r4, [r1, #9]
	b _0800AEC4
	.align 2, 0
_0800AEB8: .4byte 0x03000BE0
_0800AEBC: .4byte 0x03000440
_0800AEC0:
	adds r0, #1
_0800AEC2:
	strb r0, [r1, #9]
_0800AEC4:
	movs r0, #1
	b _0800AECA
_0800AEC8:
	movs r0, #0
_0800AECA:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
