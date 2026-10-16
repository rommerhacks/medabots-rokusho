	.syntax unified

	thumb_func_start sub_0803D424
	.global sub_0803D424
sub_0803D424: @ 0x0803D424
	ldr r1, _0803D448 @ =0x083CDFE4
	ldr r2, _0803D44C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0803D448: .4byte 0x083CDFE4
_0803D44C: .4byte 0x03001800
	.syntax divided
