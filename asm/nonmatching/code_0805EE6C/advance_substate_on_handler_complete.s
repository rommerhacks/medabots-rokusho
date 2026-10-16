	.syntax unified

	thumb_func_start advance_substate_on_handler_complete
advance_substate_on_handler_complete: @ 0x0805F7F8
	push {lr}
	ldr r0, _0805F814 @ =0x08485788
	ldr r0, [r0, #0xc]
	bl run_message
	cmp r0, #0
	beq _0805F80E
	ldr r1, _0805F818 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805F80E:
	pop {r0}
	bx r0
	.align 2, 0
_0805F814: .4byte 0x08485788
_0805F818: .4byte 0x0300137C
	.syntax divided
