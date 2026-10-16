	.syntax unified

	thumb_func_start sub_08011ABC
sub_08011ABC: @ 0x08011ABC
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	bl sub_08012468
	ldr r1, _08011AD8 @ =0x0300137C
	movs r0, #0x3d
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011AD8: .4byte 0x0300137C
	.syntax divided
