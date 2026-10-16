	.syntax unified

	thumb_func_start sub_08010968
sub_08010968: @ 0x08010968
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08010998 @ =0x083B53F8
	ldr r0, [r0, #0x54]
	bl run_message
	cmp r0, #0
	beq _08010994
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	movs r0, #0x32
	movs r1, #1
	bl sub_08042318
	ldr r1, _0801099C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08010994:
	pop {r0}
	bx r0
	.align 2, 0
_08010998: .4byte 0x083B53F8
_0801099C: .4byte 0x0300137C
	.syntax divided
