	.syntax unified

	thumb_func_start sub_080487E4
	.global sub_080487E4
sub_080487E4: @ 0x080487E4
	ldr r1, _08048800 @ =0x04000050
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08048804 @ =0x03006F40
	ldr r0, _08048808 @ =0x41400000
	str r0, [r1, #0xc]
	ldr r0, _0804880C @ =0x41200000
	str r0, [r1, #0x10]
	ldr r1, _08048810 @ =0x04000052
	ldr r0, _08048814 @ =0x00000A0C
	strh r0, [r1]
	bx lr
	.align 2, 0
_08048800: .4byte 0x04000050
_08048804: .4byte 0x03006F40
_08048808: .4byte 0x41400000
_0804880C: .4byte 0x41200000
_08048810: .4byte 0x04000052
_08048814: .4byte 0x00000A0C
	.syntax divided
