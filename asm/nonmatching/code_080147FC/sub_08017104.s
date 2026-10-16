	.syntax unified

	thumb_func_start sub_08017104
	.global sub_08017104
sub_08017104: @ 0x08017104
	ldr r1, _08017124 @ =0x03002C30
	movs r2, #0
	ldr r0, _08017128 @ =0x0000C404
	strh r0, [r1]
	strb r2, [r1, #0x1c]
	movs r0, #0x78
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	movs r0, #0xa
	strb r0, [r1, #0xa]
	movs r0, #0xc0
	strb r0, [r1, #0xb]
	ldr r0, _0801712C @ =0x0000061A
	strh r0, [r1, #6]
	bx lr
	.align 2, 0
_08017124: .4byte 0x03002C30
_08017128: .4byte 0x0000C404
_0801712C: .4byte 0x0000061A
	.syntax divided
