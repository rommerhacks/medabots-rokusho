	.syntax unified

	thumb_func_start sub_08003F28
sub_08003F28: @ 0x08003F28
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
	bl update_battle_icon_blink_and_orbit
	bl check_and_update_battle_sprite_orbit
	bl copy_obj_palette_to_buffer
	ldr r0, _08003F6C @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08003F70 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08003F6C: .4byte 0x03000440
_08003F70: .4byte 0x0300137C
	.syntax divided
