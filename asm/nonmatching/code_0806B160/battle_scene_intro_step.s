	.syntax unified

	thumb_func_start battle_scene_intro_step
battle_scene_intro_step: @ 0x0806D814
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _0806D8EC @ =0x03001800
	mov r8, r0
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _0806D85E
	movs r0, #0
	bl play_song
	movs r1, #0xc4
	lsls r1, r1, #8
	ldr r2, _0806D8F0 @ =0x00000211
	movs r0, #3
	str r0, [sp]
	movs r0, #1
	movs r3, #1
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806D8F4 @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x42
	movs r0, #0x8c
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x55
	strh r0, [r1]
	adds r1, #7
	movs r0, #0x20
	strb r0, [r1]
	movs r0, #3
	movs r1, #1
	bl sub_0806DF80
_0806D85E:
	ldr r6, _0806D8F4 @ =0x03002C30
	adds r0, r6, #0
	adds r0, #0x60
	ldrb r7, [r0]
	cmp r7, #0
	bne _0806D900
	movs r1, #0xc0
	lsls r1, r1, #8
	ldr r2, _0806D8F8 @ =0x00000213
	movs r5, #3
	str r5, [sp]
	movs r0, #3
	movs r3, #3
	bl init_battle_sprite_entry_08048818
	adds r0, r6, #0
	adds r0, #0xc2
	movs r4, #0x96
	lsls r4, r4, #1
	strh r4, [r0]
	adds r1, r6, #0
	adds r1, #0xc4
	movs r0, #0x55
	strh r0, [r1]
	adds r1, #7
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xf2
	strh r7, [r0]
	movs r0, #7
	movs r1, #3
	bl sub_0806DF80
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r2, #0x87
	lsls r2, r2, #2
	str r5, [sp]
	movs r0, #4
	movs r3, #5
	bl init_battle_sprite_entry_08048818
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x3c
	strh r0, [r1]
	adds r0, #0xcf
	adds r1, r6, r0
	movs r0, #0x10
	strb r0, [r1]
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r7, [r0]
	movs r0, #8
	movs r1, #4
	bl sub_0806DF80
	mov r0, r8
	str r7, [r0, #8]
	ldr r1, _0806D8FC @ =0x0300137C
	movs r0, #7
	str r0, [r1]
	b _0806D908
	.align 2, 0
_0806D8EC: .4byte 0x03001800
_0806D8F0: .4byte 0x00000211
_0806D8F4: .4byte 0x03002C30
_0806D8F8: .4byte 0x00000213
_0806D8FC: .4byte 0x0300137C
_0806D900:
	mov r1, r8
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
_0806D908:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
