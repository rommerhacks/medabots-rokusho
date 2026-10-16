	.syntax unified

	thumb_func_start sub_08068CF4
sub_08068CF4: @ 0x08068CF4
	push {lr}
	bl scene_transition_step_080686F4
	cmp r0, #0
	beq _08068D06
	ldr r0, _08068D0C @ =0x0300137C
	ldr r1, _08068D10 @ =0x03006F80
	ldr r1, [r1]
	str r1, [r0]
_08068D06:
	pop {r0}
	bx r0
	.align 2, 0
_08068D0C: .4byte 0x0300137C
_08068D10: .4byte 0x03006F80
	.syntax divided
