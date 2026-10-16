	.syntax unified

	thumb_func_start sub_08010F08
sub_08010F08: @ 0x08010F08
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	bl sub_08012468
	ldr r0, _08010F44 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08010F50
	movs r0, #1
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r1, _08010F48 @ =0x03000430
	movs r0, #0
	str r0, [r1]
	movs r0, #0xd
	bl play_sound_effect
	ldr r1, _08010F4C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08010F62
	.align 2, 0
_08010F44: .4byte 0x0300058C
_08010F48: .4byte 0x03000430
_08010F4C: .4byte 0x0300137C
_08010F50:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08010F64
	movs r0, #4
	bl play_sound_effect
	ldr r1, _08010F68 @ =0x0300137C
	movs r0, #0x60
_08010F62:
	str r0, [r1]
_08010F64:
	pop {r0}
	bx r0
	.align 2, 0
_08010F68: .4byte 0x0300137C
	.syntax divided
