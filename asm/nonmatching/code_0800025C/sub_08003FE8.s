	.syntax unified

	thumb_func_start sub_08003FE8
sub_08003FE8: @ 0x08003FE8
	push {lr}
	bl sub_08004E74
	movs r0, #0
	bl update_battle_sprite_orbit_clockwise
	movs r0, #1
	bl update_battle_sprite_orbit_clockwise
	movs r0, #2
	bl update_battle_sprite_orbit_clockwise
	movs r0, #3
	bl update_battle_sprite_orbit_clockwise
	bl setup_overworld_scene_from_position
	bl check_and_update_battle_sprite_orbit
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _08004024 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08004024: .4byte 0x0300137C
	.syntax divided
