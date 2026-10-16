	.syntax unified

	thumb_func_start sub_08057BCC
sub_08057BCC: @ 0x08057BCC
	push {lr}
	ldr r0, _08057BF0 @ =0x08414968
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _08057BEC
	ldr r1, _08057BF4 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_08057BEC:
	pop {r0}
	bx r0
	.align 2, 0
_08057BF0: .4byte 0x08414968
_08057BF4: .4byte 0x0300137C
	.syntax divided
