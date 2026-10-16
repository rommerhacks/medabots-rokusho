	.syntax unified

	thumb_func_start sub_0804D3B4
sub_0804D3B4: @ 0x0804D3B4
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804D3CC @ =0x03006D38
	strb r0, [r1, #1]
	ldr r0, _0804D3D0 @ =0x030057E0
	ldr r1, _0804D3D4 @ =0x00000C89
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0804D3CC: .4byte 0x03006D38
_0804D3D0: .4byte 0x030057E0
_0804D3D4: .4byte 0x00000C89
_0804D3D8:
	.byte 0x02, 0x48, 0x03, 0x49, 0x40, 0x18, 0x01, 0x21
	.byte 0x01, 0x70, 0x70, 0x47, 0xE0, 0x57, 0x00, 0x03, 0x89, 0x0C, 0x00, 0x00
	.syntax divided
