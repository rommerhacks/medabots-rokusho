	.syntax unified

	thumb_func_start init_battle_screen
init_battle_screen: @ 0x0806B5D0
	push {r4, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	ldr r1, _0806B660 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0806B664 @ =0x85006000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0x60
	strh r0, [r2]
	str r4, [sp]
	mov r0, sp
	str r0, [r1]
	ldr r0, _0806B668 @ =0x03002C30
	str r0, [r1, #4]
	ldr r0, _0806B66C @ =0x85000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r4, [sp]
	mov r0, sp
	str r0, [r1]
	ldr r2, _0806B670 @ =0x03001800
	str r2, [r1, #4]
	ldr r0, _0806B674 @ =0x85000012
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r1, #0
	movs r0, #3
	strh r0, [r2]
	movs r0, #5
	strh r0, [r2, #2]
	str r4, [r2, #8]
	movs r0, #0xc
	strb r0, [r2, #0xd]
	movs r0, #0x32
	strb r0, [r2, #0xc]
	strb r1, [r2, #0xe]
	movs r0, #0
	bl play_song
	movs r0, #3
	movs r1, #2
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	ldr r0, _0806B678 @ =0x03005000
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _0806B67C @ =0x03004C30
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _0806B680 @ =0x0300057C
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _0806B684 @ =0x03001C04
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r1, _0806B688 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806B660: .4byte 0x040000D4
_0806B664: .4byte 0x85006000
_0806B668: .4byte 0x03002C30
_0806B66C: .4byte 0x85000800
_0806B670: .4byte 0x03001800
_0806B674: .4byte 0x85000012
_0806B678: .4byte 0x03005000
_0806B67C: .4byte 0x03004C30
_0806B680: .4byte 0x0300057C
_0806B684: .4byte 0x03001C04
_0806B688: .4byte 0x0300137C
	.syntax divided
