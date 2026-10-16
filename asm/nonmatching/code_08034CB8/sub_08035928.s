	.syntax unified

	thumb_func_start sub_08035928
	.global sub_08035928
sub_08035928: @ 0x08035928
	ldr r2, _0803593C @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xe0
	strb r1, [r0]
	ldr r0, _08035940 @ =0x03001800
	subs r1, #1
	adds r0, #0x88
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803593C: .4byte 0x03000590
_08035940: .4byte 0x03001800
	.syntax divided
