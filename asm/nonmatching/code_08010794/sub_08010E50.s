	.syntax unified

	thumb_func_start sub_08010E50
sub_08010E50: @ 0x08010E50
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	movs r0, #1
	movs r1, #0
	bl advance_sprite_anim_frame
	cmp r0, #0
	beq _08010E72
	ldr r1, _08010E78 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08010E72:
	pop {r0}
	bx r0
	.align 2, 0
_08010E78: .4byte 0x0300137C
	.syntax divided
