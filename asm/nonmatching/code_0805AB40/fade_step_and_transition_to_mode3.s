	.syntax unified

	thumb_func_start fade_step_and_transition_to_mode3
fade_step_and_transition_to_mode3: @ 0x0805C98C
	push {lr}
	ldr r0, _0805C9AC @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _0805C9A8
	ldr r1, _0805C9B0 @ =0x03002B8C
	movs r0, #3
	str r0, [r1]
	ldr r1, _0805C9B4 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_0805C9A8:
	pop {r0}
	bx r0
	.align 2, 0
_0805C9AC: .4byte 0x03006F74
_0805C9B0: .4byte 0x03002B8C
_0805C9B4: .4byte 0x0300137C
	.syntax divided
