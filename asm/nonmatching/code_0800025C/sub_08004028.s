	.syntax unified

	thumb_func_start sub_08004028
sub_08004028: @ 0x08004028
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
	ldr r0, _08004064 @ =0x083B53F8
	ldr r0, [r0, #0x58]
	bl run_message
	cmp r0, #0
	beq _08004060
	ldr r1, _08004068 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_08004060:
	pop {r0}
	bx r0
	.align 2, 0
_08004064: .4byte 0x083B53F8
_08004068: .4byte 0x0300137C
	.syntax divided
