	.syntax unified

	thumb_func_start sub_0802B258
sub_0802B258: @ 0x0802B258
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0802B320 @ =0x084DFBD4
	ldr r1, _0802B324 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802B328 @ =0x0850EDF8
	ldr r1, _0802B32C @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	movs r5, #0
	ldr r0, _0802B330 @ =0x03001800
	mov sb, r0
	ldr r1, _0802B334 @ =0x03002C30
	mov ip, r1
	movs r6, #0x60
	add r6, sb
	mov sl, r6
	movs r2, #0x84
	lsls r2, r2, #4
	add r2, ip
	ldr r0, _0802B338 @ =0x00000863
	add r0, ip
	mov r8, r0
	adds r4, r2, #0
_0802B294:
	mov r0, sb
	adds r0, #0xd2
	adds r0, r5, r0
	str r0, [sp]
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B350
	movs r7, #0
	ldr r1, _0802B33C @ =0xFFFFC404
	strh r1, [r2]
	strb r7, [r2, #0x1c]
	ldr r6, _0802B340 @ =0x03001887
	ldrb r0, [r6]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	add r0, ip
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrb r0, [r6]
	lsls r0, r0, #8
	adds r0, r0, r1
	add r0, ip
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r2, #4]
	mov r6, sl
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r1
	add r0, ip
	ldrh r0, [r0, #2]
	strh r0, [r2, #0x30]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r1
	add r0, ip
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r2, #0x32]
	movs r3, #6
	mov r0, r8
	strb r3, [r0, #1]
	strb r7, [r0]
	movs r0, #0xf0
	strb r0, [r2, #0xb]
	ldr r6, _0802B344 @ =0x030018F8
	ldrb r1, [r6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802B30E
	ldrh r0, [r2]
	movs r6, #0x80
	lsls r6, r6, #5
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
_0802B30E:
	ldr r1, [sp]
	ldrb r0, [r1]
	cmp r0, #1
	bne _0802B348
	strb r3, [r4, #0xa]
	movs r0, #0xf6
	lsls r0, r0, #7
	b _0802B34E
	.align 2, 0
_0802B320: .4byte 0x084DFBD4
_0802B324: .4byte 0x06014800
_0802B328: .4byte 0x0850EDF8
_0802B32C: .4byte 0x050002C0
_0802B330: .4byte 0x03001800
_0802B334: .4byte 0x03002C30
_0802B338: .4byte 0x00000863
_0802B33C: .4byte 0xFFFFC404
_0802B340: .4byte 0x03001887
_0802B344: .4byte 0x030018F8
_0802B348:
	movs r0, #7
	strb r0, [r4, #0xa]
	ldr r0, _0802B380 @ =0x00007B01
_0802B34E:
	strh r0, [r4, #6]
_0802B350:
	adds r2, #0x40
	movs r6, #0x40
	add r8, r6
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802B294
	movs r0, #0x24
	bl play_sound_effect
	ldr r1, _0802B384 @ =0x03001800
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
_0802B380: .4byte 0x00007B01
_0802B384: .4byte 0x03001800
	.syntax divided
