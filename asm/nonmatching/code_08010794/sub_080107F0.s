	.syntax unified

	thumb_func_start sub_080107F0
sub_080107F0: @ 0x080107F0
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _08010810 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08010810: .4byte 0x0300137C
	.syntax divided
