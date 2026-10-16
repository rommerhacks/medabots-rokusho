	.syntax unified

	thumb_func_start init_battle_bg_tilemap
init_battle_bg_tilemap: @ 0x0806E558
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0806E630 @ =0xFFFFF650
	add sp, r4
	ldr r0, _0806E634 @ =0x087F1F58
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UnCompVram
	ldr r0, _0806E638 @ =0x087F2658
	mov r1, sp
	bl LZ77UnCompVram
	movs r1, #0
	ldr r0, _0806E63C @ =0x087F27D8
	mov sb, r0
	ldr r2, _0806E640 @ =0x03001800
	mov r8, r2
	ldr r3, _0806E644 @ =0x0300137C
	mov sl, r3
	movs r5, #0x96
	lsls r5, r5, #3
	add r5, sp
	movs r7, #0
	mov ip, r5
_0806E590:
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
_0806E5A6:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _0806E5A6
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
	ble _0806E590
	ldr r0, _0806E648 @ =0x040000D4
	movs r1, #0x96
	lsls r1, r1, #3
	add r1, sp
	str r1, [r0]
	ldr r1, _0806E64C @ =0x06007800
	str r1, [r0, #4]
	ldr r1, _0806E650 @ =0x84000140
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sb
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0806E654 @ =0x80000010
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r0, #0x34
	mov r2, r8
	str r0, [r2, #0x10]
	ldr r1, _0806E658 @ =0x04000008
	ldr r3, _0806E65C @ =0x00000F02
	adds r0, r3, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #7
	mov r1, r8
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
_0806E630: .4byte 0xFFFFF650
_0806E634: .4byte 0x087F1F58
_0806E638: .4byte 0x087F2658
_0806E63C: .4byte 0x087F27D8
_0806E640: .4byte 0x03001800
_0806E644: .4byte 0x0300137C
_0806E648: .4byte 0x040000D4
_0806E64C: .4byte 0x06007800
_0806E650: .4byte 0x84000140
_0806E654: .4byte 0x80000010
_0806E658: .4byte 0x04000008
_0806E65C: .4byte 0x00000F02
	.syntax divided
