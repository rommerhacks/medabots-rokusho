	.syntax unified

	thumb_func_start sub_080529E4
	.global sub_080529E4
sub_080529E4: @ 0x080529E4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080529F8 @ =0x03004C30
	strh r0, [r1, #2]
	ldr r1, _080529FC @ =0x0300057C
	strh r0, [r1, #2]
	ldr r1, _08052A00 @ =0x03001C04
	strh r0, [r1, #2]
	bx lr
	.align 2, 0
_080529F8: .4byte 0x03004C30
_080529FC: .4byte 0x0300057C
_08052A00: .4byte 0x03001C04
	.syntax divided
