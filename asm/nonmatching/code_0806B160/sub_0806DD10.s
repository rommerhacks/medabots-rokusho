	.syntax unified

	thumb_func_start sub_0806DD10
sub_0806DD10: @ 0x0806DD10
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _0806DD30 @ =0x03002C30
	lsls r0, r7, #6
	adds r0, r0, r1
	adds r5, r0, #0
	adds r5, #0x22
	ldrb r2, [r5]
	adds r0, r2, #0
	mov ip, r1
	cmp r0, #0x1e
	bls _0806DD34
	movs r0, #0
	b _0806DE20
	.align 2, 0
_0806DD30: .4byte 0x03002C30
_0806DD34:
	cmp r0, #0
	beq _0806DD3C
	cmp r0, #0x1e
	bne _0806DD5C
_0806DD3C:
	movs r0, #0
	str r0, [sp]
	ldr r1, _0806DD50 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _0806DD54 @ =0x050002C0
	str r0, [r1, #4]
	ldr r0, _0806DD58 @ =0x85000008
	b _0806DDB4
	.align 2, 0
_0806DD50: .4byte 0x040000D4
_0806DD54: .4byte 0x050002C0
_0806DD58: .4byte 0x85000008
_0806DD5C:
	cmp r0, #0xe
	bhi _0806DDA4
	lsls r4, r2, #0x19
	lsrs r3, r4, #0x18
	movs r0, #0
	str r0, [sp]
	ldr r2, _0806DD94 @ =0x040000D4
	mov r0, sp
	str r0, [r2]
	ldr r0, _0806DD98 @ =0x050002C0
	str r0, [r2, #4]
	movs r0, #0x20
	subs r0, r0, r3
	cmp r0, #0
	bge _0806DD7C
	adds r0, #3
_0806DD7C:
	asrs r0, r0, #2
	movs r1, #0x85
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _0806DD9C @ =0x0300180C
	str r0, [r2]
	ldr r0, _0806DDA0 @ =0x050002E0
	subs r0, r0, r3
	str r0, [r2, #4]
	b _0806DE06
	.align 2, 0
_0806DD94: .4byte 0x040000D4
_0806DD98: .4byte 0x050002C0
_0806DD9C: .4byte 0x0300180C
_0806DDA0: .4byte 0x050002E0
_0806DDA4:
	cmp r0, #0xf
	bne _0806DDCC
	ldr r1, _0806DDBC @ =0x040000D4
	ldr r0, _0806DDC0 @ =0x0300180C
	str r0, [r1]
	ldr r0, _0806DDC4 @ =0x050002C0
	str r0, [r1, #4]
	ldr r0, _0806DDC8 @ =0x8000000E
_0806DDB4:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0806DE12
	.align 2, 0
_0806DDBC: .4byte 0x040000D4
_0806DDC0: .4byte 0x0300180C
_0806DDC4: .4byte 0x050002C0
_0806DDC8: .4byte 0x8000000E
_0806DDCC:
	movs r0, #0x1e
	subs r0, r0, r2
	lsls r4, r0, #0x19
	lsrs r3, r4, #0x18
	movs r0, #0
	str r0, [sp]
	ldr r2, _0806DE28 @ =0x040000D4
	mov r0, sp
	str r0, [r2]
	ldr r6, _0806DE2C @ =0x050002C0
	adds r0, r3, r6
	str r0, [r2, #4]
	movs r0, #0x20
	subs r0, r0, r3
	cmp r0, #0
	bge _0806DDEE
	adds r0, #3
_0806DDEE:
	asrs r0, r0, #2
	movs r1, #0x85
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0806DE30 @ =0x030017EE
	adds r0, r0, r1
	str r0, [r2]
	str r6, [r2, #4]
_0806DE06:
	lsrs r0, r4, #0x19
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0806DE12:
	lsls r1, r7, #6
	add r1, ip
	adds r1, #0x22
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
_0806DE20:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806DE28: .4byte 0x040000D4
_0806DE2C: .4byte 0x050002C0
_0806DE30: .4byte 0x030017EE
	.syntax divided
