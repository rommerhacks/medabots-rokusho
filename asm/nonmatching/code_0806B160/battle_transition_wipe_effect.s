	.syntax unified

	thumb_func_start battle_transition_wipe_effect
battle_transition_wipe_effect: @ 0x0806D914
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, _0806D978 @ =0x03001800
	ldr r1, [r0, #8]
	adds r5, r0, #0
	cmp r1, #0
	bne _0806D9C0
	movs r0, #2
	bl play_song
	ldr r1, _0806D97C @ =0x04000050
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0806D980 @ =0x04000200
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0806D984 @ =0x04000004
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806D988 @ =0x03002C20
	ldr r0, _0806D98C @ =0x0806D421
	str r0, [r1]
	movs r4, #0
	movs r6, #0x80
	lsls r6, r6, #1
	ldr r5, _0806D990 @ =0x03000030
_0806D96E:
	cmp r4, #0x1f
	bgt _0806D994
	lsls r0, r4, #2
	b _0806D99E
	.align 2, 0
_0806D978: .4byte 0x03001800
_0806D97C: .4byte 0x04000050
_0806D980: .4byte 0x04000200
_0806D984: .4byte 0x04000004
_0806D988: .4byte 0x03002C20
_0806D98C: .4byte 0x0806D421
_0806D990: .4byte 0x03000030
_0806D994:
	cmp r4, #0x7f
	ble _0806D9AC
	movs r0, #0x9f
	subs r0, r0, r4
	lsls r0, r0, #2
_0806D99E:
	subs r1, r6, r0
	movs r0, #0x80
	lsls r0, r0, #9
	bl sub_0807CD58
	strh r0, [r5]
	b _0806D9AE
_0806D9AC:
	strh r6, [r5]
_0806D9AE:
	adds r5, #2
	adds r4, #1
	cmp r4, #0x9f
	ble _0806D96E
	ldr r5, _0806D9BC @ =0x03001800
	b _0806DA10
	.align 2, 0
_0806D9BC: .4byte 0x03001800
_0806D9C0:
	cmp r1, #0x40
	ble _0806D9F0
	ldr r1, _0806D9E4 @ =0x03002C30
	adds r1, #0x80
	ldrh r2, [r1]
	ldr r0, _0806D9E8 @ =0x0000FDFF
	ands r0, r2
	movs r4, #0
	strh r0, [r1]
	movs r0, #5
	movs r1, #2
	bl sub_0806DF80
	str r4, [r5, #8]
	ldr r1, _0806D9EC @ =0x0300137C
	movs r0, #8
	str r0, [r1]
	b _0806DA52
	.align 2, 0
_0806D9E4: .4byte 0x03002C30
_0806D9E8: .4byte 0x0000FDFF
_0806D9EC: .4byte 0x0300137C
_0806D9F0:
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0806DA10
	ldr r2, _0806DA5C @ =0x04000052
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	bne _0806DA10
	ldrh r0, [r2]
	ldr r1, _0806DA60 @ =0xFFFFFF00
	adds r0, r0, r1
	strh r0, [r2]
_0806DA10:
	ldr r0, [r5, #8]
	cmp r0, #0x39
	bne _0806DA4C
	movs r1, #0xc6
	lsls r1, r1, #8
	ldr r2, _0806DA64 @ =0x00000212
	movs r0, #3
	str r0, [sp]
	movs r0, #2
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806DA68 @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x82
	movs r0, #0x78
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x73
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x40
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	movs r0, #4
	movs r1, #2
	bl sub_0806DF80
_0806DA4C:
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
_0806DA52:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806DA5C: .4byte 0x04000052
_0806DA60: .4byte 0xFFFFFF00
_0806DA64: .4byte 0x00000212
_0806DA68: .4byte 0x03002C30
	.syntax divided
