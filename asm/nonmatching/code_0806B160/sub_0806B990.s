	.syntax unified

	thumb_func_start sub_0806B990
sub_0806B990: @ 0x0806B990
	push {lr}
	bl scene_transition_step_080686F4
	cmp r0, #0
	beq _0806B9A8
	movs r0, #0x14
	bl play_song
	ldr r1, _0806B9AC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0806B9A8:
	pop {r0}
	bx r0
	.align 2, 0
_0806B9AC: .4byte 0x0300137C
	.syntax divided
