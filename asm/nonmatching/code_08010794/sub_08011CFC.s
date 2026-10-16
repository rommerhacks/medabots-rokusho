	.syntax unified

	thumb_func_start sub_08011CFC
sub_08011CFC: @ 0x08011CFC
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	ldr r0, _08011D40 @ =0x083C65C4
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08011D3C
	ldr r0, _08011D44 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08011D3C
	ldr r1, _08011D48 @ =0x03000430
	movs r0, #0
	str r0, [r1]
	movs r0, #0xd
	bl play_sound_effect
	ldr r1, _08011D4C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08011D3C:
	pop {r0}
	bx r0
	.align 2, 0
_08011D40: .4byte 0x083C65C4
_08011D44: .4byte 0x0300058C
_08011D48: .4byte 0x03000430
_08011D4C: .4byte 0x0300137C
	.syntax divided
