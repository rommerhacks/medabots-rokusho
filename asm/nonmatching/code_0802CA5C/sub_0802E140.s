	.syntax unified

	thumb_func_start sub_0802E140
sub_0802E140: @ 0x0802E140
	push {r4, r5, r6, lr}
	movs r3, #0
	movs r2, #0
	ldr r5, _0802E168 @ =0x03001800
	adds r4, r5, #0
	adds r4, #0xd2
	ldr r0, _0802E16C @ =0x03002C30
	movs r6, #0x84
	lsls r6, r6, #4
	adds r1, r0, r6
_0802E154:
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E17A
	ldrb r0, [r1, #8]
	cmp r0, #0x40
	bne _0802E170
	movs r3, #1
	b _0802E17A
	.align 2, 0
_0802E168: .4byte 0x03001800
_0802E16C: .4byte 0x03002C30
_0802E170:
	subs r0, #8
	strb r0, [r1, #8]
	ldrb r0, [r1, #9]
	subs r0, #8
	strb r0, [r1, #9]
_0802E17A:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #2
	bls _0802E154
	cmp r3, #0
	beq _0802E198
	ldr r0, _0802E1A0 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802E198:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E1A0: .4byte 0x03000440
	.syntax divided
