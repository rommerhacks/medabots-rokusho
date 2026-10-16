	.syntax unified

	thumb_func_start sub_08003D4C
sub_08003D4C: @ 0x08003D4C
	push {r4, r5, lr}
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
	ldr r1, _08003DB4 @ =0x03000440
	adds r4, r1, #0
	adds r4, #0x56
	ldrb r0, [r4]
	cmp r0, #1
	bne _08003DC0
	adds r5, r1, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08003DC8
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _08003DB8 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #2
	subs r4, r4, r0
	ldr r2, _08003DBC @ =0x0000F0FF
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08003DD4
	.align 2, 0
_08003DB4: .4byte 0x03000440
_08003DB8: .4byte 0x0000FFFF
_08003DBC: .4byte 0x0000F0FF
_08003DC0:
	bl update_blend_effect
	cmp r0, #0
	beq _08003DD4
_08003DC8:
	movs r0, #0
	strb r0, [r4]
	ldr r1, _08003DDC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08003DD4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003DDC: .4byte 0x0300137C
	.syntax divided
