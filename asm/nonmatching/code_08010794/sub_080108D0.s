	.syntax unified

	thumb_func_start sub_080108D0
sub_080108D0: @ 0x080108D0
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _080108F4
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _080108F8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080108F4:
	pop {r0}
	bx r0
	.align 2, 0
_080108F8: .4byte 0x0300137C
	.syntax divided
