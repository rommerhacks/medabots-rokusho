	.syntax unified

	thumb_func_start sub_0805D4F0
sub_0805D4F0: @ 0x0805D4F0
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0805D502
	ldr r1, _0805D508 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805D502:
	pop {r0}
	bx r0
	.align 2, 0
_0805D508: .4byte 0x0300137C
	.syntax divided
