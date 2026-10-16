	.syntax unified

	thumb_func_start sub_08057EBC
sub_08057EBC: @ 0x08057EBC
	push {lr}
	movs r0, #0x20
	bl clear_battle_sprite_entry
	movs r0, #0x21
	bl clear_battle_sprite_entry
	movs r0, #0x22
	bl clear_battle_sprite_entry
	movs r0, #0x23
	bl clear_battle_sprite_entry
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
