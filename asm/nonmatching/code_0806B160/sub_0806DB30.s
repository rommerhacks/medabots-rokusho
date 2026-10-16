	.syntax unified

	thumb_func_start sub_0806DB30
sub_0806DB30: @ 0x0806DB30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r2, _0806DC60 @ =0x00007FFF
	movs r0, #4
	movs r1, #2
	bl setup_screen_transition_effect_080682CC
	ldr r1, _0806DC64 @ =0x04000054
	movs r0, #0
	strh r0, [r1]
	movs r0, #0
	bl play_song
	movs r0, #0xc4
	lsls r0, r0, #8
	mov sb, r0
	ldr r2, _0806DC68 @ =0x0000021B
	movs r5, #3
	str r5, [sp]
	movs r0, #0
	mov r1, sb
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	movs r1, #0x80
	lsls r1, r1, #0x13
	mov r8, r1
	ldrh r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r2, #0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	ldr r7, _0806DC6C @ =0x03002C30
	movs r4, #0x78
	strh r4, [r7, #2]
	movs r2, #0x3c
	mov sl, r2
	mov r0, sl
	strh r0, [r7, #4]
	movs r1, #0x10
	strb r1, [r7, #0xb]
	movs r0, #0
	movs r1, #0
	bl sub_0806DF80
	ldr r2, _0806DC70 @ =0x00000211
	str r5, [sp]
	movs r0, #1
	mov r1, sb
	movs r3, #1
	bl init_battle_sprite_entry_08048818
	adds r0, r7, #0
	adds r0, #0x42
	strh r4, [r0]
	adds r0, #2
	movs r4, #0x55
	strh r4, [r0]
	adds r1, r7, #0
	adds r1, #0x4b
	movs r0, #0x20
	strb r0, [r1]
	movs r0, #0
	movs r1, #1
	bl sub_0806DF80
	movs r1, #0xc0
	lsls r1, r1, #8
	ldr r2, _0806DC74 @ =0x00000213
	str r5, [sp]
	movs r0, #3
	movs r3, #3
	bl init_battle_sprite_entry_08048818
	adds r0, r7, #0
	adds r0, #0xc2
	movs r6, #0x96
	lsls r6, r6, #1
	strh r6, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r1, r7, #0
	adds r1, #0xcb
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf2
	movs r4, #0x80
	strh r4, [r0]
	movs r0, #7
	movs r1, #3
	bl sub_0806DF80
	movs r2, #0x87
	lsls r2, r2, #2
	str r5, [sp]
	movs r0, #4
	mov r1, sb
	movs r3, #5
	bl init_battle_sprite_entry_08048818
	movs r2, #0x81
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, sl
	strh r2, [r0]
	adds r1, #7
	adds r0, r7, r1
	movs r2, #0x10
	strb r2, [r0]
	adds r1, #0x27
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #8
	movs r1, #4
	bl sub_0806DF80
	mov r2, r8
	ldrh r0, [r2]
	movs r2, #0x98
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	ldr r1, _0806DC78 @ =0x03001800
	movs r0, #7
	strh r0, [r1, #4]
	movs r2, #0
	str r2, [r1, #8]
	ldr r1, _0806DC7C @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806DC60: .4byte 0x00007FFF
_0806DC64: .4byte 0x04000054
_0806DC68: .4byte 0x0000021B
_0806DC6C: .4byte 0x03002C30
_0806DC70: .4byte 0x00000211
_0806DC74: .4byte 0x00000213
_0806DC78: .4byte 0x03001800
_0806DC7C: .4byte 0x0300137C
	.syntax divided
