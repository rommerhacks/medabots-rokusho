	.syntax unified

	thumb_func_start sub_0804AF80
sub_0804AF80: @ 0x0804AF80
	push {lr}
	bl sub_0805937C
	cmp r0, #0
	beq _0804AF8E
	bl handle_battle_end_state_transition
_0804AF8E:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
