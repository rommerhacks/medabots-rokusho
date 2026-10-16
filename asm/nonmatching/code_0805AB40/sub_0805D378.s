	.syntax unified

	thumb_func_start sub_0805D378
sub_0805D378: @ 0x0805D378
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0805D38A
	ldr r1, _0805D390 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805D38A:
	pop {r0}
	bx r0
	.align 2, 0
_0805D390: .4byte 0x0300137C
	.syntax divided
