	.syntax unified

	thumb_func_start sub_0802D198
sub_0802D198: @ 0x0802D198
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r3, #0
	ldr r0, _0802D250 @ =0x00004D01
	mov sl, r0
_0802D1AA:
	ldr r1, _0802D254 @ =0x030018D2
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r7, r3, #1
	str r7, [sp]
	cmp r0, #0
	beq _0802D226
	movs r4, #0
	ldr r0, _0802D258 @ =0x083ADEE0
	mov sb, r0
	ldr r5, _0802D25C @ =0x03002C30
	lsls r1, r3, #8
	movs r7, #0
	mov r8, r7
	ldr r0, _0802D260 @ =0x0000C404
	mov ip, r0
	ldr r6, _0802D264 @ =0x03001860
	movs r7, #0xc0
	lsls r7, r7, #4
	adds r1, r1, r7
	adds r0, r5, #0
	adds r0, #0x24
	adds r2, r1, r0
	adds r1, r1, r5
_0802D1DA:
	mov r0, ip
	strh r0, [r1]
	mov r7, r8
	strb r7, [r1, #0x1c]
	ldrb r0, [r6]
	adds r0, r0, r3
	lsls r0, r0, #8
	movs r7, #0xb4
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	ldrb r0, [r6]
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r0, [r0, #4]
	adds r0, #4
	strh r0, [r1, #4]
	movs r0, #7
	strb r0, [r1, #0xa]
	movs r0, #0xf0
	strb r0, [r1, #0xb]
	movs r0, #6
	strb r0, [r2]
	mov r7, sb
	adds r0, r4, r7
	ldrb r0, [r0]
	strb r0, [r2, #1]
	mov r0, sl
	strh r0, [r1, #6]
	adds r2, #0x40
	adds r1, #0x40
	adds r4, #1
	cmp r4, #3
	bls _0802D1DA
_0802D226:
	ldr r3, [sp]
	cmp r3, #2
	bls _0802D1AA
	ldr r1, _0802D268 @ =0x03000440
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0802D26C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D250: .4byte 0x00004D01
_0802D254: .4byte 0x030018D2
_0802D258: .4byte 0x083ADEE0
_0802D25C: .4byte 0x03002C30
_0802D260: .4byte 0x0000C404
_0802D264: .4byte 0x03001860
_0802D268: .4byte 0x03000440
_0802D26C: .4byte 0x03001800
	.syntax divided
