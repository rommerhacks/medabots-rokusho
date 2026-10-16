	.syntax unified

	thumb_func_start sub_0802BB24
sub_0802BB24: @ 0x0802BB24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r3, #0
	ldr r0, _0802BB94 @ =0x03001800
	mov ip, r0
	ldr r1, _0802BB98 @ =0x03000440
	mov r8, r1
	mov r6, ip
	adds r6, #0xd2
	ldr r0, _0802BB9C @ =0x03002C30
	ldr r5, _0802BBA0 @ =0x0000C404
	movs r7, #0x84
	lsls r7, r7, #4
	adds r2, r0, r7
	movs r4, #0xe0
_0802BB44:
	adds r0, r3, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BB68
	strh r5, [r2]
	strb r4, [r2, #0xb]
	ldrh r0, [r2, #4]
	adds r0, #8
	strh r0, [r2, #4]
	movs r0, #7
	strb r0, [r2, #0xa]
	mov r1, ip
	adds r1, #0x51
	ldr r7, _0802BBA4 @ =0x00007C04
	adds r0, r7, #0
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #6]
_0802BB68:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802BB44
	movs r1, #0
	mov r0, r8
	adds r0, #0x86
	strh r1, [r0]
	movs r0, #0x2e
	bl play_sound_effect
	ldr r1, _0802BB94 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BB94: .4byte 0x03001800
_0802BB98: .4byte 0x03000440
_0802BB9C: .4byte 0x03002C30
_0802BBA0: .4byte 0x0000C404
_0802BBA4: .4byte 0x00007C04
	.syntax divided
