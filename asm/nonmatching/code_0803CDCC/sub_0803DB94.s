	.syntax unified

	thumb_func_start sub_0803DB94
sub_0803DB94: @ 0x0803DB94
	push {lr}
	bl update_scroll_movement_a
	bl game_state_execute_handler_b
	cmp r0, #0
	beq _0803DBAE
	bl sub_0803FB0C
	ldr r1, _0803DBB4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DBAE:
	pop {r0}
	bx r0
	.align 2, 0
_0803DBB4: .4byte 0x0300137C
	.syntax divided
