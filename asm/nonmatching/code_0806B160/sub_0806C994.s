	.syntax unified

	thumb_func_start sub_0806C994
sub_0806C994: @ 0x0806C994
	push {r4, lr}
	sub sp, #0x10
	ldr r1, _0806C9C8 @ =0x080AFF40
	mov r0, sp
	movs r2, #8
	bl memcpy_optimized
	add r4, sp, #8
	ldr r1, _0806C9CC @ =0x080AFF48
	adds r0, r4, #0
	movs r2, #8
	bl memcpy_optimized
	ldr r0, _0806C9D0 @ =0x03002C30
	adds r0, #0x20
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #6
	bls _0806C9BC
	b _0806CAE0
_0806C9BC:
	lsls r0, r0, #2
	ldr r1, _0806C9D4 @ =_0806C9D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806C9C8: .4byte 0x080AFF40
_0806C9CC: .4byte 0x080AFF48
_0806C9D0: .4byte 0x03002C30
_0806C9D4: .4byte _0806C9D8
_0806C9D8: @ jump table
	.4byte _0806C9F4 @ case 0
	.4byte _0806CA28 @ case 1
	.4byte _0806CA60 @ case 2
	.4byte _0806CA66 @ case 3
	.4byte _0806CA66 @ case 4
	.4byte _0806CA66 @ case 5
	.4byte _0806CA94 @ case 6
_0806C9F4:
	ldr r1, _0806CA14 @ =0x03002C30
	ldrh r0, [r1, #0x1a]
	cmp r0, #0x17
	bhi _0806CAE0
	cmp r0, #0xf
	bhi _0806CA18
	ldrb r0, [r1, #8]
	adds r0, #4
	strb r0, [r1, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _0806CAE0
	movs r0, #0x40
	strb r0, [r1, #8]
	b _0806CAE0
	.align 2, 0
_0806CA14: .4byte 0x03002C30
_0806CA18:
	ldrb r0, [r1, #9]
	adds r0, #8
	strb r0, [r1, #9]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _0806CAE0
	b _0806CABC
_0806CA28:
	ldr r1, _0806CA48 @ =0x03002C30
	ldrh r0, [r1, #0x1a]
	cmp r0, #0x17
	bhi _0806CAE0
	cmp r0, #7
	bhi _0806CA4C
	ldrb r0, [r1, #9]
	subs r0, #8
	strb r0, [r1, #9]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0806CAE0
	movs r0, #4
	strb r0, [r1, #9]
	b _0806CAE0
	.align 2, 0
_0806CA48: .4byte 0x03002C30
_0806CA4C:
	ldrb r0, [r1, #8]
	subs r0, #4
	strb r0, [r1, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0806CAE0
	movs r0, #4
	strb r0, [r1, #8]
	b _0806CAE0
_0806CA60:
	bl get_battle_state_value_div10
	b _0806CAE0
_0806CA66:
	ldr r1, _0806CA90 @ =0x03002C30
	ldrh r0, [r1, #0x1a]
	cmp r0, #8
	bls _0806CA9C
	cmp r0, #0x33
	bls _0806CAE0
	ldrb r0, [r1, #8]
	cmp r0, #8
	bls _0806CA7C
	subs r0, #8
	strb r0, [r1, #8]
_0806CA7C:
	ldrb r0, [r1, #9]
	adds r0, #4
	strb r0, [r1, #9]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x60
	bls _0806CAE0
	movs r0, #0x60
	strb r0, [r1, #9]
	b _0806CAE0
	.align 2, 0
_0806CA90: .4byte 0x03002C30
_0806CA94:
	ldr r1, _0806CAC4 @ =0x03002C30
	ldrh r0, [r1, #0x1a]
	cmp r0, #8
	bhi _0806CAC8
_0806CA9C:
	ldrb r0, [r1, #8]
	adds r0, #8
	strb r0, [r1, #8]
	movs r2, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _0806CAB0
	movs r0, #0x40
	strb r0, [r1, #8]
_0806CAB0:
	ldrb r0, [r1, #9]
	subs r0, #4
	strb r0, [r1, #9]
	ands r0, r2
	cmp r0, #0x3f
	bhi _0806CAE0
_0806CABC:
	movs r0, #0x40
	strb r0, [r1, #9]
	b _0806CAE0
	.align 2, 0
_0806CAC4: .4byte 0x03002C30
_0806CAC8:
	cmp r0, #0x15
	bls _0806CAE0
	ldr r2, _0806CAE8 @ =0x04000052
	ldrh r0, [r1, #0x1a]
	subs r0, #0x16
	adds r1, r4, r0
	ldrb r1, [r1]
	lsls r1, r1, #8
	add r0, sp
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r2]
_0806CAE0:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806CAE8: .4byte 0x04000052
	.syntax divided
