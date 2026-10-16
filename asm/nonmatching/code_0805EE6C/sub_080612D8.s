	.syntax unified

	thumb_func_start sub_080612D8
sub_080612D8: @ 0x080612D8
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _080612F2
	ldr r0, _080612F8 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080612FC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080612F2:
	pop {r0}
	bx r0
	.align 2, 0
_080612F8: .4byte 0x03000440
_080612FC: .4byte 0x0300137C
	.syntax divided
