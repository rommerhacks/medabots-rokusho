	.syntax unified

	thumb_func_start advance_substate_on_handler_complete_1c
advance_substate_on_handler_complete_1c: @ 0x08062488
	push {lr}
	ldr r0, _080624A4 @ =0x08485788
	ldr r0, [r0, #0x1c]
	bl run_message
	cmp r0, #0
	beq _0806249E
	ldr r1, _080624A8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0806249E:
	pop {r0}
	bx r0
	.align 2, 0
_080624A4: .4byte 0x08485788
_080624A8: .4byte 0x0300137C
	.syntax divided
