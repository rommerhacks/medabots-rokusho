	.syntax unified

	thumb_func_start sub_0803DBB8
sub_0803DBB8: @ 0x0803DBB8
	push {lr}
	bl update_scroll_movement_a
	ldr r0, _0803DBD8 @ =0x083CF3B0
	ldr r0, [r0, #4]
	bl run_message
	cmp r0, #0
	beq _0803DBD2
	ldr r1, _0803DBDC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DBD2:
	pop {r0}
	bx r0
	.align 2, 0
_0803DBD8: .4byte 0x083CF3B0
_0803DBDC: .4byte 0x0300137C
	.syntax divided
