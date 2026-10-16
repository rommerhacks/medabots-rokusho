	.syntax unified

	thumb_func_start sub_08034F08
	.global sub_08034F08
sub_08034F08: @ 0x08034F08
	ldr r2, _08034F38 @ =0x03001800
	adds r1, r2, #0
	adds r1, #0xaa
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08034F3C @ =0x083C6B28
	adds r0, r2, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _08034F40 @ =0x083C6D38
	adds r2, #0xbc
	ldrh r1, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, r0, r3
	adds r1, #1
	ldrb r0, [r0]
	adds r1, r1, r0
	strh r1, [r2]
	bx lr
	.align 2, 0
_08034F38: .4byte 0x03001800
_08034F3C: .4byte 0x083C6B28
_08034F40: .4byte 0x083C6D38
	.syntax divided
