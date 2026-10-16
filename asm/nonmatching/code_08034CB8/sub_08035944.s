	.syntax unified

	thumb_func_start sub_08035944
	.global sub_08035944
sub_08035944: @ 0x08035944
	ldr r2, _08035958 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xe1
	strb r1, [r0]
	ldr r0, _0803595C @ =0x03001800
	subs r1, #1
	adds r0, #0x8b
	strb r1, [r0]
	bx lr
	.align 2, 0
_08035958: .4byte 0x03000590
_0803595C: .4byte 0x03001800
	.syntax divided
