	.syntax unified

	thumb_func_start sub_0804763C
sub_0804763C: @ 0x0804763C
	push {lr}
	ldr r1, _08047654 @ =0x083D1F84
	ldr r0, _08047658 @ =0x03002B8C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08047654: .4byte 0x083D1F84
_08047658: .4byte 0x03002B8C
	.syntax divided
