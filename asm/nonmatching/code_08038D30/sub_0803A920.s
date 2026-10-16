	.syntax unified

	thumb_func_start sub_0803A920
sub_0803A920: @ 0x0803A920
	push {lr}
	ldr r0, _0803A934 @ =0x03002C30
	ldr r1, _0803A938 @ =0x000008E7
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_0803A934: .4byte 0x03002C30
_0803A938: .4byte 0x000008E7
	.syntax divided
