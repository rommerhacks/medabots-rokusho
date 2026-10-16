	.syntax unified

	thumb_func_start sub_08009900
	.global sub_08009900
sub_08009900: @ 0x08009900
	ldr r3, _0800993C @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xc0
	movs r2, #0
	ldr r0, _08009940 @ =0x0000C804
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x18
	strh r0, [r1]
	ldr r0, _08009944 @ =0x03000440
	adds r0, #0x40
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #0x28
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08009948 @ =0x00000307
	strh r0, [r1]
	adds r1, #4
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xdc
	strb r2, [r0]
	adds r1, #1
	movs r0, #0x41
	strb r0, [r1]
	bx lr
	.align 2, 0
_0800993C: .4byte 0x03002C30
_08009940: .4byte 0x0000C804
_08009944: .4byte 0x03000440
_08009948: .4byte 0x00000307
	.syntax divided
