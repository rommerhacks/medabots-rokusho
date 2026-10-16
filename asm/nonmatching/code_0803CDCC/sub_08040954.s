	.syntax unified

	thumb_func_start sub_08040954
sub_08040954: @ 0x08040954
	push {lr}
	ldr r1, _0804096C @ =0x083B2808
	ldr r0, _08040970 @ =0x03000440
	ldrb r0, [r0, #0x1b]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0804096C: .4byte 0x083B2808
_08040970: .4byte 0x03000440
	.syntax divided
