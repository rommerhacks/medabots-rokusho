	.syntax unified

	thumb_func_start sub_08057C08
sub_08057C08: @ 0x08057C08
	push {lr}
	ldr r0, _08057C2C @ =0x08414968
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _08057C28
	ldr r1, _08057C30 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_08057C28:
	pop {r0}
	bx r0
	.align 2, 0
_08057C2C: .4byte 0x08414968
_08057C30: .4byte 0x0300137C

	.syntax divided
