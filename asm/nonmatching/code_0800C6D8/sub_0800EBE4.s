	.syntax unified

	thumb_func_start sub_0800EBE4
sub_0800EBE4: @ 0x0800EBE4
	push {lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_08043CA8
	movs r0, #2
	bl sub_08044CDC
	pop {r0}
	bx r0
	.syntax divided
