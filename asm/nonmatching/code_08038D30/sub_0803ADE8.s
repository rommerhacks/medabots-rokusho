	.syntax unified

	thumb_func_start sub_0803ADE8
sub_0803ADE8: @ 0x0803ADE8
	push {lr}
	movs r0, #0xc
	movs r1, #2
	bl clear_battle_sprite_slot
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
