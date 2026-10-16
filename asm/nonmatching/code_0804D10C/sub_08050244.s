	.syntax unified

	thumb_func_start sub_08050244
sub_08050244: @ 0x08050244
	ldr r0, _08050258 @ =0x030057E0
	ldr r2, _0805025C @ =0x00000C93
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r1, _08050260 @ =0x00000C89
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_08050258: .4byte 0x030057E0
_0805025C: .4byte 0x00000C93
_08050260: .4byte 0x00000C89
	.syntax divided
