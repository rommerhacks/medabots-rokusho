	.syntax unified

	thumb_func_start sub_0802BF9C
sub_0802BF9C: @ 0x0802BF9C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0802C0C4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r3, #0
	mov ip, r4
	ldr r5, _0802C0C8 @ =0x03002C30
	movs r0, #0
	mov sb, r0
	ldr r7, _0802C0CC @ =0x0000C624
	mov r8, r7
	adds r6, r1, #0
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r1, #0x40
	ldr r7, _0802C0D0 @ =0x00004801
	mov sl, r7
_0802BFD4:
	mov r4, ip
	adds r4, #0xd2
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C018
	mov r0, r8
	strh r0, [r2]
	mov r7, sb
	strb r7, [r2, #0x1c]
	ldrb r0, [r6]
	adds r0, r0, r3
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrb r0, [r6]
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r0, [r0, #4]
	strh r0, [r2, #4]
	movs r0, #7
	strb r0, [r2, #0xa]
	movs r0, #0xf0
	strb r0, [r2, #0xb]
	strb r1, [r2, #8]
	strb r1, [r2, #9]
	mov r0, sl
	strh r0, [r2, #6]
_0802C018:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802BFD4
	adds r5, r4, #0
	subs r5, #0xd2
	adds r0, r4, #0
	subs r0, #0x4b
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	subs r1, #0x72
	strb r0, [r1]
	movs r3, #0
	mov ip, r5
	ldr r4, _0802C0C8 @ =0x03002C30
	movs r7, #0
	mov sb, r7
	ldr r0, _0802C0CC @ =0x0000C624
	mov r8, r0
	movs r7, #0x90
	lsls r7, r7, #4
	adds r2, r4, r7
	movs r5, #0x40
	ldr r0, _0802C0D4 @ =0x00004802
	mov sl, r0
_0802C04E:
	lsls r0, r3, #1
	mov r6, ip
	adds r6, #0xd6
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802C096
	mov r7, r8
	strh r7, [r2]
	mov r0, sb
	strb r0, [r2, #0x1c]
	ldrb r0, [r1]
	adds r0, r0, r3
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrb r0, [r1]
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #0x10
	strh r0, [r2, #4]
	movs r0, #7
	strb r0, [r2, #0xa]
	movs r0, #0xf0
	strb r0, [r2, #0xb]
	strb r5, [r2, #8]
	strb r5, [r2, #9]
	mov r0, sl
	strh r0, [r2, #6]
_0802C096:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802C04E
	movs r1, #0
	ldr r0, _0802C0D8 @ =0x03000440
	adds r0, #0x84
	strb r1, [r0]
	movs r0, #0x2e
	bl play_sound_effect
	adds r1, r6, #0
	subs r1, #0x2c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C0C4: .4byte 0x03001800
_0802C0C8: .4byte 0x03002C30
_0802C0CC: .4byte 0x0000C624
_0802C0D0: .4byte 0x00004801
_0802C0D4: .4byte 0x00004802
_0802C0D8: .4byte 0x03000440
	.syntax divided
