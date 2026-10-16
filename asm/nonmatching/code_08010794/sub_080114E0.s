	.syntax unified

	thumb_func_start sub_080114E0
sub_080114E0: @ 0x080114E0
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	ldr r1, _080114FC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080114FC: .4byte 0x0300137C
	.syntax divided
