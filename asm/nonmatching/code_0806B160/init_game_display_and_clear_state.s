	.syntax unified

	thumb_func_start init_game_display_and_clear_state
init_game_display_and_clear_state: @ 0x0806E378
	push {r4, r5, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	ldr r0, _0806E420 @ =0x040000D4
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0806E424 @ =0x85006000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0806E428 @ =0x85000100
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xe0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, _0806E42C @ =0x03002C30
	str r1, [r0, #4]
	ldr r1, _0806E430 @ =0x85000800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r5, _0806E434 @ =0x03001800
	str r5, [r0, #4]
	ldr r1, _0806E438 @ =0x85000005
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r0, #0
	bl play_song
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	movs r1, #0
	movs r0, #3
	strh r0, [r5]
	strh r4, [r5, #2]
	str r4, [r5, #8]
	ldr r0, _0806E43C @ =0x03005000
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _0806E440 @ =0x03004C30
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _0806E444 @ =0x0300057C
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _0806E448 @ =0x03001C04
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _0806E44C @ =0x03007008
	strb r1, [r0]
	movs r0, #2
	movs r1, #4
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	ldr r1, _0806E450 @ =0x0300137C
	movs r0, #4
	str r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E420: .4byte 0x040000D4
_0806E424: .4byte 0x85006000
_0806E428: .4byte 0x85000100
_0806E42C: .4byte 0x03002C30
_0806E430: .4byte 0x85000800
_0806E434: .4byte 0x03001800
_0806E438: .4byte 0x85000005
_0806E43C: .4byte 0x03005000
_0806E440: .4byte 0x03004C30
_0806E444: .4byte 0x0300057C
_0806E448: .4byte 0x03001C04
_0806E44C: .4byte 0x03007008
_0806E450: .4byte 0x0300137C
	.syntax divided
