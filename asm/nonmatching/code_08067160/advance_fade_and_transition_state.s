	.syntax unified

	thumb_func_start advance_fade_and_transition_state
advance_fade_and_transition_state: @ 0x08068234
	push {lr}
	ldr r0, _0806825C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _08068256
	ldr r1, _08068260 @ =0x0300178C
	movs r0, #0
	str r0, [r1]
	ldr r1, _08068264 @ =0x03002B8C
	movs r0, #6
	str r0, [r1]
	ldr r1, _08068268 @ =0x0300137C
	movs r0, #0x50
	str r0, [r1]
_08068256:
	pop {r0}
	bx r0
	.align 2, 0
_0806825C: .4byte 0x03006F74
_08068260: .4byte 0x0300178C
_08068264: .4byte 0x03002B8C
_08068268: .4byte 0x0300137C
	.syntax divided
