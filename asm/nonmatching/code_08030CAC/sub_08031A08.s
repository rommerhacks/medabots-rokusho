	.syntax unified

	thumb_func_start sub_08031A08
sub_08031A08: @ 0x08031A08
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _08031A1A
	ldr r1, _08031A20 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08031A1A:
	pop {r0}
	bx r0
	.align 2, 0
_08031A20: .4byte 0x0300137C
	.syntax divided
