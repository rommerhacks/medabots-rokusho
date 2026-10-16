	.syntax unified

	thumb_func_start sub_0805F898
sub_0805F898: @ 0x0805F898
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0805F8A8
	ldr r1, _0805F8AC @ =0x0300137C
	movs r0, #4
	str r0, [r1]
_0805F8A8:
	pop {r0}
	bx r0
	.align 2, 0
_0805F8AC: .4byte 0x0300137C
	.syntax divided
