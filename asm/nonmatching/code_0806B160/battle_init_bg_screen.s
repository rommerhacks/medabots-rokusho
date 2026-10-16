	.syntax unified

	thumb_func_start battle_init_bg_screen
battle_init_bg_screen: @ 0x0806E454
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0806E528 @ =0xFFFFF650
	add sp, r4
	ldr r0, _0806E52C @ =0x087F1B4C
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UnCompVram
	ldr r0, _0806E530 @ =0x087F1E4C
	mov r1, sp
	bl LZ77UnCompVram
	movs r1, #0
	ldr r0, _0806E534 @ =0x087F1F38
	mov r8, r0
	ldr r2, _0806E538 @ =0x03001800
	mov sb, r2
	ldr r3, _0806E53C @ =0x0300137C
	mov sl, r3
	movs r5, #0x96
	lsls r5, r5, #3
	add r5, sp
	movs r7, #0
	mov ip, r5
_0806E48C:
	lsls r4, r1, #5
	lsls r0, r1, #4
	adds r6, r1, #1
	subs r0, r0, r1
	lsls r0, r0, #2
	mov r3, sp
	adds r2, r0, r3
	lsls r0, r1, #6
	mov r3, ip
	adds r1, r0, r3
	movs r3, #0x1d
_0806E4A2:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _0806E4A2
	adds r0, r4, #0
	adds r0, #0x1e
	lsls r0, r0, #1
	adds r0, r5, r0
	strh r7, [r0]
	adds r0, r4, #0
	adds r0, #0x1f
	lsls r0, r0, #1
	adds r0, r5, r0
	strh r7, [r0]
	adds r1, r6, #0
	cmp r1, #0x13
	ble _0806E48C
	ldr r0, _0806E540 @ =0x040000D4
	movs r1, #0x96
	lsls r1, r1, #3
	add r1, sp
	str r1, [r0]
	ldr r1, _0806E544 @ =0x06007800
	str r1, [r0, #4]
	ldr r1, _0806E548 @ =0x84000140
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, r8
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0806E54C @ =0x80000010
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _0806E550 @ =0x04000008
	ldr r2, _0806E554 @ =0x00000F01
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	mov r1, sb
	strh r0, [r1, #4]
	movs r0, #1
	mov r2, sl
	str r0, [r2]
	movs r3, #0x9b
	lsls r3, r3, #4
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E528: .4byte 0xFFFFF650
_0806E52C: .4byte 0x087F1B4C
_0806E530: .4byte 0x087F1E4C
_0806E534: .4byte 0x087F1F38
_0806E538: .4byte 0x03001800
_0806E53C: .4byte 0x0300137C
_0806E540: .4byte 0x040000D4
_0806E544: .4byte 0x06007800
_0806E548: .4byte 0x84000140
_0806E54C: .4byte 0x80000010
_0806E550: .4byte 0x04000008
_0806E554: .4byte 0x00000F01
	.syntax divided
