	.syntax unified

	thumb_func_start sub_0800ADE8
sub_0800ADE8: @ 0x0800ADE8
	push {r4, lr}
	ldr r0, _0800AE10 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0800AE1C
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0800AE14 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x46
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800AE18
	movs r0, #7
	b _0800AE42
	.align 2, 0
_0800AE10: .4byte 0x03001798
_0800AE14: .4byte 0x03000440
_0800AE18:
	subs r0, #1
	b _0800AE42
_0800AE1C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800AE4C
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0800AE3C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x46
	ldrb r0, [r1]
	cmp r0, #7
	bne _0800AE40
	strb r4, [r1]
	b _0800AE44
	.align 2, 0
_0800AE3C: .4byte 0x03000440
_0800AE40:
	adds r0, #1
_0800AE42:
	strb r0, [r1]
_0800AE44:
	bl sub_0800AC2C
	movs r0, #1
	b _0800AE4E
_0800AE4C:
	movs r0, #0
_0800AE4E:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
