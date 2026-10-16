	.syntax unified

	thumb_func_start sub_0805DB48
sub_0805DB48: @ 0x0805DB48
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0805DB5A
	ldr r1, _0805DB60 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805DB5A:
	pop {r0}
	bx r0
	.align 2, 0
_0805DB60: .4byte 0x0300137C
	.syntax divided
