	.syntax unified

	thumb_func_start sub_0802B810
sub_0802B810: @ 0x0802B810
	push {r4, r5, r6, r7, lr}
	bl sub_0803836C
	ldr r4, _0802B878 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r3, #0
	ldr r5, _0802B87C @ =0x03000590
	mov ip, r5
	adds r7, r4, #0
	adds r7, #0xd2
	adds r6, r1, #0
	movs r1, #1
_0802B836:
	ldrb r0, [r6]
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r2, r0, r5
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B856
	adds r0, r2, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B856
	adds r0, r3, r7
	strb r1, [r0]
_0802B856:
	adds r3, #1
	cmp r3, #2
	bls _0802B836
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	add r0, ip
	adds r0, #0xa8
	ldrb r0, [r0]
	cmp r0, #0x21
	beq _0802B892
	cmp r0, #0x21
	bgt _0802B880
	cmp r0, #0x1f
	beq _0802B88A
	b _0802B8AA
	.align 2, 0
_0802B878: .4byte 0x03001800
_0802B87C: .4byte 0x03000590
_0802B880:
	cmp r0, #0x23
	beq _0802B89A
	cmp r0, #0x25
	beq _0802B8A2
	b _0802B8AA
_0802B88A:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #0
	b _0802B8A8
_0802B892:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #1
	b _0802B8A8
_0802B89A:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #2
	b _0802B8A8
_0802B8A2:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #3
_0802B8A8:
	strb r0, [r1]
_0802B8AA:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
