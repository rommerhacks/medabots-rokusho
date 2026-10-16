	.syntax unified

	thumb_func_start sub_08003DE0
sub_08003DE0: @ 0x08003DE0
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
	bl sub_0800712C
	bl sub_080058A4
	cmp r0, #0
	bne _08003E4E
	bl sub_08005588
	cmp r0, #0
	bne _08003E4E
	ldr r0, _08003E30 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08003E34
	bl sub_0800725C
	b _08003E4E
	.align 2, 0
_08003E30: .4byte 0x0300058C
_08003E34:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08003E42
	bl team_select_confirm_pick
	b _08003E4E
_08003E42:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08003E4E
	bl battle_play_alert_sound
_08003E4E:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
