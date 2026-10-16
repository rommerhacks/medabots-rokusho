	.syntax unified

	thumb_func_start sub_08067A48
	.global sub_08067A48
sub_08067A48: @ 0x08067A48
	ldr r1, _08067A60 @ =0x030017EC
	strb r0, [r1]
	ldr r1, _08067A64 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08067A68 @ =0x03002B8C
	movs r0, #0x18
	str r0, [r1]
	ldr r1, _08067A6C @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08067A60: .4byte 0x030017EC
_08067A64: .4byte 0x0300178C
_08067A68: .4byte 0x03002B8C
_08067A6C: .4byte 0x0300137C
	.syntax divided
