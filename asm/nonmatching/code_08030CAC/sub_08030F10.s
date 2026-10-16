	.syntax unified

	thumb_func_start sub_08030F10
sub_08030F10: @ 0x08030F10
	push {lr}
	ldr r0, _08030F7C @ =0x084C84E4
	ldr r1, _08030F80 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08030F84 @ =0x084E2FD8
	ldr r1, _08030F88 @ =0x050003E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08030F8C @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r1, r0
	movs r3, #0
	ldr r0, _08030F90 @ =0x0000C624
	strh r0, [r2]
	ldr r2, _08030F94 @ =0x0000085C
	adds r0, r1, r2
	strb r3, [r0]
	ldr r0, _08030F98 @ =0x00000842
	adds r2, r1, r0
	movs r0, #0x78
	strh r0, [r2]
	ldr r0, _08030F9C @ =0x00000844
	adds r2, r1, r0
	movs r3, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _08030FA0 @ =0x0000084A
	adds r2, r1, r0
	movs r0, #0xf
	strb r0, [r2]
	ldr r0, _08030FA4 @ =0x0000084B
	adds r2, r1, r0
	movs r0, #0xc0
	strb r0, [r2]
	ldr r0, _08030FA8 @ =0x00000846
	adds r2, r1, r0
	adds r0, #0xbc
	strh r0, [r2]
	subs r0, #0xb9
	adds r2, r1, r0
	movs r0, #0x80
	strb r0, [r2]
	ldr r2, _08030FAC @ =0x00000848
	adds r1, r1, r2
	strb r3, [r1]
	ldr r1, _08030FB0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08030F7C: .4byte 0x084C84E4
_08030F80: .4byte 0x06014800
_08030F84: .4byte 0x084E2FD8
_08030F88: .4byte 0x050003E0
_08030F8C: .4byte 0x03002C30
_08030F90: .4byte 0x0000C624
_08030F94: .4byte 0x0000085C
_08030F98: .4byte 0x00000842
_08030F9C: .4byte 0x00000844
_08030FA0: .4byte 0x0000084A
_08030FA4: .4byte 0x0000084B
_08030FA8: .4byte 0x00000846
_08030FAC: .4byte 0x00000848
_08030FB0: .4byte 0x0300137C
_08030FB4:
	.byte 0x07, 0x48, 0x08, 0x4A, 0x81, 0x18, 0x08, 0x78, 0x40, 0x28, 0x11, 0xD1
	.byte 0x06, 0x48, 0x86, 0x30, 0x00, 0x21, 0x01, 0x80, 0x05, 0x49, 0x08, 0x68, 0x01, 0x30, 0x08, 0x60
	.byte 0x0A, 0xE0, 0x00, 0x00, 0x30, 0x2C, 0x00, 0x03, 0x49, 0x08, 0x00, 0x00, 0x40, 0x04, 0x00, 0x03
	.byte 0x7C, 0x13, 0x00, 0x03, 0x08, 0x38, 0x08, 0x70, 0x70, 0x47, 0x00, 0x00
	.syntax divided
