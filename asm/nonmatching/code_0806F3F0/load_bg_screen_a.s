	.syntax unified

	thumb_func_start load_bg_screen_a
load_bg_screen_a: @ 0x08070114
	push {r4, r5, r6, r7, lr}
	ldr r4, _080701D4 @ =0xFFFFF64C
	add sp, r4
	ldr r0, _080701D8 @ =0x087C8E00
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UnCompVram
	ldr r0, _080701DC @ =0x087CC7BC
	movs r4, #0xa0
	lsls r4, r4, #3
	add r4, sp
	adds r1, r4, #0
	bl LZ77UnCompVram
	movs r2, #0x9b
	lsls r2, r2, #4
	add r2, sp
	movs r0, #0
	str r0, [r2]
	ldr r1, _080701E0 @ =0x040000D4
	str r2, [r1]
	ldr r0, _080701E4 @ =0x06007800
	str r0, [r1, #4]
	ldr r0, _080701E8 @ =0x85000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r1, #0
	ldr r0, _080701EC @ =0x087CCAEC
	mov ip, r0
	adds r7, r4, #0
	movs r6, #0
_08070154:
	lsls r4, r1, #5
	lsls r0, r1, #4
	adds r5, r1, #1
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r2, r0, r7
	lsls r0, r1, #6
	mov r3, sp
	adds r1, r0, r3
	movs r3, #0x1d
_08070168:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08070168
	adds r0, r4, #0
	adds r0, #0x1e
	lsls r0, r0, #1
	mov r2, sp
	adds r1, r2, r0
	adds r0, r4, #0
	adds r0, #0x1f
	lsls r0, r0, #1
	add r0, sp
	strh r6, [r0]
	strh r6, [r1]
	adds r1, r5, #0
	cmp r1, #0x13
	ble _08070154
	ldr r0, _080701E0 @ =0x040000D4
	str r2, [r0]
	ldr r1, _080701E4 @ =0x06007800
	str r1, [r0, #4]
	ldr r1, _080701F0 @ =0x80000280
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	mov r3, ip
	str r3, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _080701F4 @ =0x80000100
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _080701F8 @ =0x04000008
	movs r2, #0xfc
	lsls r2, r2, #4
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
	ldr r3, _080701FC @ =0x000009B4
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080701D4: .4byte 0xFFFFF64C
_080701D8: .4byte 0x087C8E00
_080701DC: .4byte 0x087CC7BC
_080701E0: .4byte 0x040000D4
_080701E4: .4byte 0x06007800
_080701E8: .4byte 0x85000200
_080701EC: .4byte 0x087CCAEC
_080701F0: .4byte 0x80000280
_080701F4: .4byte 0x80000100
_080701F8: .4byte 0x04000008
_080701FC: .4byte 0x000009B4
	.syntax divided
