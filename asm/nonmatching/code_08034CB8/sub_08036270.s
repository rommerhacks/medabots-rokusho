	.syntax unified

	thumb_func_start sub_08036270
	.global sub_08036270
sub_08036270: @ 0x08036270
	ldr r0, _08036288 @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x89
	ldrb r1, [r1]
	lsls r1, r1, #3
	adds r1, r1, r0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08036288: .4byte 0x03001800
	.syntax divided
