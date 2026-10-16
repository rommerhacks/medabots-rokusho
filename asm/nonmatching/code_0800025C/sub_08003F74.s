	.syntax unified

	thumb_func_start sub_08003F74
sub_08003F74: @ 0x08003F74
	push {r4, lr}
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
	ldr r0, _08003FCC @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #8
	bhi _08003FD8
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r2, _08003FD0 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #2
	ldr r2, _08003FD4 @ =0x0000F0FF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08003FDE
	.align 2, 0
_08003FCC: .4byte 0x03000440
_08003FD0: .4byte 0x0000FFFF
_08003FD4: .4byte 0x0000F0FF
_08003FD8:
	ldr r1, _08003FE4 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
_08003FDE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08003FE4: .4byte 0x0300137C
	.syntax divided
