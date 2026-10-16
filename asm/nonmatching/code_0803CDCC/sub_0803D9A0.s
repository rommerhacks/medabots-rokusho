	.syntax unified

	thumb_func_start sub_0803D9A0
sub_0803D9A0: @ 0x0803D9A0
	push {lr}
	bl update_scroll_movement_a
	ldr r0, _0803D9C0 @ =0x083C2BBC
	ldr r0, [r0, #4]
	bl run_message
	cmp r0, #0
	beq _0803D9BA
	ldr r1, _0803D9C4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803D9BA:
	pop {r0}
	bx r0
	.align 2, 0
_0803D9C0: .4byte 0x083C2BBC
_0803D9C4: .4byte 0x0300137C
	.syntax divided
