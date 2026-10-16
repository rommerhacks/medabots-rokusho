	.syntax unified

	thumb_func_start sub_08058110
	.global sub_08058110
sub_08058110: @ 0x08058110
	push {lr}
	ldr r0, _08058120 @ =0x030057A0
	ldrb r0, [r0, #0x14]
	bl dispatch_by_index
	pop {r0}
	bx r0
	.align 2, 0
_08058120: .4byte 0x030057A0
	.syntax divided
