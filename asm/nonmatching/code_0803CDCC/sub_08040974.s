	.syntax unified

	thumb_func_start sub_08040974
sub_08040974: @ 0x08040974
	push {lr}
	ldr r1, _0804098C @ =0x083B2810
	ldr r0, _08040990 @ =0x03000440
	ldrb r0, [r0, #0x1b]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0804098C: .4byte 0x083B2810
_08040990: .4byte 0x03000440
	.syntax divided
