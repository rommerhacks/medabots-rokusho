	.syntax unified

	thumb_func_start sub_0804A6E8
sub_0804A6E8: @ 0x0804A6E8
	push {lr}
	bl check_room_exit_at_position
	ldr r1, _0804A710 @ =0x08411D54
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804A70A
	ldr r1, _0804A714 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
_0804A70A:
	pop {r0}
	bx r0
	.align 2, 0
_0804A710: .4byte 0x08411D54
_0804A714: .4byte 0x0300137C
	.syntax divided
