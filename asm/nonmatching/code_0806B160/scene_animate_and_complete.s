	.syntax unified

	thumb_func_start scene_animate_and_complete
scene_animate_and_complete: @ 0x0806EA18
	push {r4, r5, lr}
	sub sp, #4
	ldr r4, _0806EA80 @ =0x03001800
	adds r1, r4, #0
	adds r1, #0xf0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r1]
	adds r0, #0x6f
	strh r0, [r1]
	bl battle_timer_digit_extract
	bl update_sprite_animations_080703D8
	bl execute_scene_step
	cmp r0, #0
	beq _0806EA76
	str r5, [sp]
	ldr r1, _0806EA84 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _0806EA88 @ =0x03002C30
	str r0, [r1, #4]
	ldr r0, _0806EA8C @ =0x85000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0806EA90 @ =0x03000430
	str r5, [r0]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0806EA94 @ =0x000080FF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0806EA98 @ =0x0300178C
	ldrh r0, [r4]
	str r0, [r1]
	ldr r1, _0806EA9C @ =0x03002B8C
	ldrh r0, [r4, #2]
	str r0, [r1]
	ldr r1, _0806EAA0 @ =0x0300137C
	ldrh r0, [r4, #4]
	str r0, [r1]
_0806EA76:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806EA80: .4byte 0x03001800
_0806EA84: .4byte 0x040000D4
_0806EA88: .4byte 0x03002C30
_0806EA8C: .4byte 0x85000800
_0806EA90: .4byte 0x03000430
_0806EA94: .4byte 0x000080FF
_0806EA98: .4byte 0x0300178C
_0806EA9C: .4byte 0x03002B8C
_0806EAA0: .4byte 0x0300137C
	.syntax divided
