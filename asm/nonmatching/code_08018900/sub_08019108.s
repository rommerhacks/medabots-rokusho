	.syntax unified

	thumb_func_start sub_08019108
sub_08019108: @ 0x08019108
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r6, _0801912C @ =0x03000590
	lsls r2, r3, #8
	adds r5, r2, r6
	adds r1, r5, #0
	adds r1, #0xdd
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801917E
	cmp r0, #3
	bls _08019130
	adds r0, r3, #0
	movs r1, #0xc
	bl sub_08019184
	b _0801917E
	.align 2, 0
_0801912C: .4byte 0x03000590
_08019130:
	ldrb r4, [r1]
	subs r0, r4, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	adds r2, r1, r6
	adds r0, r2, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801917E
	cmp r4, #1
	bne _08019156
	adds r0, r3, #0
	movs r1, #6
	bl sub_08019184
	b _0801917E
_08019156:
	adds r0, r5, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08019172
	adds r0, r2, #0
	adds r0, #0x50
	ldrb r1, [r0]
	adds r0, r3, #0
	bl sub_08019184
	b _0801917E
_08019172:
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r1, [r0]
	adds r0, r3, #0
	bl sub_08019184
_0801917E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
