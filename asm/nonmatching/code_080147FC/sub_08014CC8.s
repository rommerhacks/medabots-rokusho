	.syntax unified

	thumb_func_start sub_08014CC8
sub_08014CC8: @ 0x08014CC8
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _08014CDA
	ldr r1, _08014CE0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08014CDA:
	pop {r0}
	bx r0
	.align 2, 0
_08014CE0: .4byte 0x0300137C
_08014CE4:
	.byte 0x01, 0x49, 0x40, 0x20, 0x08, 0x60, 0x70, 0x47, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
