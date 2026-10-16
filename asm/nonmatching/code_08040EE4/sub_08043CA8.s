	.syntax unified

	thumb_func_start sub_08043CA8
	.global sub_08043CA8
sub_08043CA8: @ 0x08043CA8
	ldr r1, _08043CC4 @ =0x03005000
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, _08043CC8 @ =0x03004C30
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, _08043CCC @ =0x0300057C
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, _08043CD0 @ =0x03001C04
	strh r0, [r1]
	strh r0, [r1, #2]
	bx lr
	.align 2, 0
_08043CC4: .4byte 0x03005000
_08043CC8: .4byte 0x03004C30
_08043CCC: .4byte 0x0300057C
_08043CD0: .4byte 0x03001C04
	.syntax divided
