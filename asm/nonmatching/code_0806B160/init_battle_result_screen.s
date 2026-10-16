	.syntax unified

	thumb_func_start init_battle_result_screen
init_battle_result_screen: @ 0x0806EF8C
	push {r4, r5, lr}
	sub sp, #0x24
	movs r5, #0x2a
	bl init_scene_buffers_080445F4
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r4, _0806F014 @ =0x040000D4
	add r0, sp, #0x20
	str r0, [r4]
	ldr r0, _0806F018 @ =0x03002414
	ldr r0, [r0]
	ldr r1, _0806F01C @ =0x00000B84
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _0806F020 @ =0x85000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r5, [sp]
	movs r0, #0x78
	str r0, [sp, #4]
	movs r0, #0x50
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #0xc
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	movs r1, #0x2a
	movs r2, #0x2a
	movs r3, #0x2a
	bl setup_scene_with_bg_and_sprites
	ldr r0, _0806F024 @ =0x08485FD8
	ldr r0, [r0, #4]
	str r0, [r4]
	ldr r0, _0806F028 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _0806F02C @ =0x80000050
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806F030 @ =0x03001800
	movs r0, #0xf
	strh r0, [r1, #4]
	ldr r1, _0806F034 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	add sp, #0x24
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806F014: .4byte 0x040000D4
_0806F018: .4byte 0x03002414
_0806F01C: .4byte 0x00000B84
_0806F020: .4byte 0x85000100
_0806F024: .4byte 0x08485FD8
_0806F028: .4byte 0x05000200
_0806F02C: .4byte 0x80000050
_0806F030: .4byte 0x03001800
_0806F034: .4byte 0x0300137C
	.syntax divided
