	.syntax unified

	thumb_func_start battle_init_tilemap_and_palette
battle_init_tilemap_and_palette: @ 0x0806E114
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _0806E208 @ =0xFFFFF650
	add sp, r4
	ldr r1, _0806E20C @ =0x08487328
	ldr r4, _0806E210 @ =0x03001800
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0806E214 @ =0x06008000
	bl LZ77UnCompVram
	ldr r1, _0806E218 @ =0x08487358
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, sp
	bl LZ77UnCompVram
	movs r1, #0
	mov sb, r4
	ldr r0, _0806E21C @ =0x08487388
	mov r8, r0
	movs r5, #0x96
	lsls r5, r5, #3
	add r5, sp
	movs r7, #0
	mov ip, r5
_0806E154:
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
_0806E16A:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _0806E16A
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
	ble _0806E154
	ldr r1, _0806E220 @ =0x040000D4
	movs r0, #0x96
	lsls r0, r0, #3
	add r0, sp
	str r0, [r1]
	ldr r0, _0806E224 @ =0x06007800
	str r0, [r1, #4]
	ldr r0, _0806E228 @ =0x84000140
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0806E22C @ =0x800000E0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xca
	ldr r3, _0806E230 @ =0x00000F8B
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #2
	movs r1, #1
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #4
	mov r1, sb
	strh r0, [r1, #4]
	ldr r1, _0806E234 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	movs r3, #0x9b
	lsls r3, r3, #4
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E208: .4byte 0xFFFFF650
_0806E20C: .4byte 0x08487328
_0806E210: .4byte 0x03001800
_0806E214: .4byte 0x06008000
_0806E218: .4byte 0x08487358
_0806E21C: .4byte 0x08487388
_0806E220: .4byte 0x040000D4
_0806E224: .4byte 0x06007800
_0806E228: .4byte 0x84000140
_0806E22C: .4byte 0x800000E0
_0806E230: .4byte 0x00000F8B
_0806E234: .4byte 0x0300137C
	.syntax divided
