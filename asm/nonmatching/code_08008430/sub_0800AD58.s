	.syntax unified

	thumb_func_start sub_0800AD58
sub_0800AD58: @ 0x0800AD58
	push {r4, lr}
	ldr r0, _0800AD90 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0800ADA0
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0800AD94 @ =0x03000BE0
	ldr r1, _0800AD98 @ =0x03000440
	adds r2, r1, #0
	adds r2, #0x46
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	ldrb r2, [r2]
	adds r1, r1, r2
	adds r0, #0x18
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800AD9C
	movs r0, #7
	b _0800ADDA
	.align 2, 0
_0800AD90: .4byte 0x03001798
_0800AD94: .4byte 0x03000BE0
_0800AD98: .4byte 0x03000440
_0800AD9C:
	subs r0, #1
	b _0800ADDA
_0800ADA0:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800ADE0
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0800ADD0 @ =0x03000BE0
	ldr r1, _0800ADD4 @ =0x03000440
	adds r2, r1, #0
	adds r2, #0x46
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	ldrb r2, [r2]
	adds r1, r1, r2
	adds r0, #0x18
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #7
	bne _0800ADD8
	strb r4, [r1]
	b _0800ADDC
	.align 2, 0
_0800ADD0: .4byte 0x03000BE0
_0800ADD4: .4byte 0x03000440
_0800ADD8:
	adds r0, #1
_0800ADDA:
	strb r0, [r1]
_0800ADDC:
	movs r0, #1
	b _0800ADE2
_0800ADE0:
	movs r0, #0
_0800ADE2:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
