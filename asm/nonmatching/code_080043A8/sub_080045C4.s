	.syntax unified

	thumb_func_start sub_080045C4
sub_080045C4: @ 0x080045C4
	push {lr}
	bl sub_08006764
	bl assign_medal_to_team_slot
	ldr r1, _080045D8 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080045D8: .4byte 0x0300137C
	.syntax divided
