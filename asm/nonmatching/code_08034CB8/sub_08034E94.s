	.syntax unified

	thumb_func_start sub_08034E94
	.global sub_08034E94
sub_08034E94: @ 0x08034E94
	ldr r2, _08034EB0 @ =0x083C6B28
	ldr r1, _08034EB4 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r1, #0xbc
	ldrh r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08034EB0: .4byte 0x083C6B28
_08034EB4: .4byte 0x03001800
	.syntax divided
