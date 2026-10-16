	.syntax unified

	thumb_func_start sub_0804A654
sub_0804A654: @ 0x0804A654
	push {lr}
	bl update_battle_field_frame
	bl load_battlefield_data_to_buffer
	movs r0, #0
	movs r1, #0
	bl dispatch_jump_table_29
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
