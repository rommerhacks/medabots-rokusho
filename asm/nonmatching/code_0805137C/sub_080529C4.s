	.syntax unified

	thumb_func_start sub_080529C4
	.global sub_080529C4
sub_080529C4: @ 0x080529C4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080529D8 @ =0x03004C30
	strh r0, [r1]
	ldr r1, _080529DC @ =0x0300057C
	strh r0, [r1]
	ldr r1, _080529E0 @ =0x03001C04
	strh r0, [r1]
	bx lr
	.align 2, 0
_080529D8: .4byte 0x03004C30
_080529DC: .4byte 0x0300057C
_080529E0: .4byte 0x03001C04
	.syntax divided
