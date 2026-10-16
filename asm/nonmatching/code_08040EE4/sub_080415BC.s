	.syntax unified

	thumb_func_start sub_080415BC
	.global sub_080415BC
sub_080415BC: @ 0x080415BC
	ldr r1, _080415D8 @ =0x03005000
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, _080415DC @ =0x03004C30
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, _080415E0 @ =0x0300057C
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, _080415E4 @ =0x03001C04
	strh r0, [r1]
	strh r0, [r1, #2]
	bx lr
	.align 2, 0
_080415D8: .4byte 0x03005000
_080415DC: .4byte 0x03004C30
_080415E0: .4byte 0x0300057C
_080415E4: .4byte 0x03001C04
	.syntax divided
