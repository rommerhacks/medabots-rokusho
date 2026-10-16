	.syntax unified

	thumb_func_start sub_08003EA0
sub_08003EA0: @ 0x08003EA0
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
	bl update_blend_effect
	cmp r0, #0
	beq _08003ED6
	ldr r1, _08003EDC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08003ED6:
	pop {r0}
	bx r0
	.align 2, 0
_08003EDC: .4byte 0x0300137C
	.syntax divided
