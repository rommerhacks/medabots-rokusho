	.syntax unified

	thumb_func_start sub_0800A1E4
	.global sub_0800A1E4
sub_0800A1E4: @ 0x0800A1E4
	push {r4, r5, r6, lr}
	ldr r5, _0800A21C @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #1
	bls _0800A2AC
	ldr r2, _0800A220 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _0800A25A
	movs r0, #2
	bl play_sound_effect
	movs r3, #0
	adds r2, r5, #0
	adds r2, #0x3d
	mov ip, r5
	ldr r6, _0800A224 @ =0x03000BE0
	adds r5, r4, #0
_0800A212:
	ldrb r0, [r2]
	cmp r0, #0
	bne _0800A228
	movs r0, #0x1d
	b _0800A22A
	.align 2, 0
_0800A21C: .4byte 0x03000440
_0800A220: .4byte 0x03001798
_0800A224: .4byte 0x03000BE0
_0800A228:
	subs r0, #1
_0800A22A:
	strb r0, [r2]
	ldrb r0, [r2]
	lsls r0, r0, #6
	adds r0, r0, r6
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800A254
	mov r0, ip
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800A24A
	adds r4, r5, #0
	b _0800A25A
_0800A24A:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0800A254
	movs r3, #1
_0800A254:
	adds r4, r5, #0
	cmp r3, #0
	beq _0800A212
_0800A25A:
	ldrb r1, [r4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800A2AC
	movs r0, #2
	bl play_sound_effect
	movs r3, #0
	ldr r2, _0800A27C @ =0x0300047D
	ldr r5, _0800A280 @ =0x03000BE0
	subs r4, r2, #1
_0800A272:
	ldrb r0, [r2]
	cmp r0, #0x1d
	bne _0800A284
	movs r0, #0
	b _0800A286
	.align 2, 0
_0800A27C: .4byte 0x0300047D
_0800A280: .4byte 0x03000BE0
_0800A284:
	adds r0, #1
_0800A286:
	strb r0, [r2]
	ldrb r0, [r2]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800A2A8
	ldrb r0, [r4]
	cmp r0, #1
	bne _0800A2AC
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0800A2A8
	movs r3, #1
_0800A2A8:
	cmp r3, #0
	beq _0800A272
_0800A2AC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
