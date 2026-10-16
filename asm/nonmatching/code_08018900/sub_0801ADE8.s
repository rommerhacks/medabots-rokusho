	.syntax unified

	thumb_func_start sub_0801ADE8
sub_0801ADE8: @ 0x0801ADE8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #1
	movs r4, #0
	ldr r0, _0801AE30 @ =0x03002C30
	movs r7, #3
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r3, r0, r1
	adds r1, #0x21
	adds r2, r0, r1
_0801ADFE:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0801AE1A
	ldrb r0, [r2, #1]
	adds r0, #1
	ands r0, r7
	strb r0, [r2, #1]
	ldr r1, _0801AE34 @ =0x00000616
	adds r0, r0, r1
	strh r0, [r3, #6]
_0801AE1A:
	ldrb r0, [r2, #5]
	ldrb r1, [r2, #3]
	cmp r0, r1
	beq _0801AE5C
	movs r5, #0
	ldrb r0, [r2, #6]
	cmp r0, #0
	beq _0801AE38
	subs r0, #1
	strb r0, [r2, #6]
	b _0801AE5C
	.align 2, 0
_0801AE30: .4byte 0x03002C30
_0801AE34: .4byte 0x00000616
_0801AE38:
	cmp r6, #2
	bhi _0801AE42
	ldrh r0, [r3, #2]
	adds r0, #4
	b _0801AE46
_0801AE42:
	ldrh r0, [r3, #2]
	subs r0, #4
_0801AE46:
	strh r0, [r3, #2]
	ldrb r0, [r2, #7]
	adds r0, #1
	strb r0, [r2, #7]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0801AE5C
	ldrb r0, [r2, #3]
	adds r0, #1
	strb r0, [r2, #3]
_0801AE5C:
	adds r3, #0x40
	adds r2, #0x40
	adds r4, #1
	cmp r4, #7
	bls _0801ADFE
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
