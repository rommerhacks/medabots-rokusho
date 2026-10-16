	.syntax unified

	thumb_func_start sub_08010C28
sub_08010C28: @ 0x08010C28
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl game_state_execute_handler_b
	cmp r0, #0
	beq _08010C46
	bl sub_0803FB0C
	ldr r1, _08010C4C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08010C46:
	pop {r0}
	bx r0
	.align 2, 0
_08010C4C: .4byte 0x0300137C
	.syntax divided
