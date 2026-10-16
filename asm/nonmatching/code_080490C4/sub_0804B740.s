	.syntax unified

	thumb_func_start sub_0804B740
sub_0804B740: @ 0x0804B740
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804B75C @ =0x030057E0
	ldr r3, _0804B760 @ =0x00000C94
	adds r2, r1, r3
	strb r0, [r2]
	ldr r0, _0804B764 @ =0x00000C89
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804B75C: .4byte 0x030057E0
_0804B760: .4byte 0x00000C94
_0804B764: .4byte 0x00000C89
_0804B768:
	.byte 0x02, 0x48, 0x03, 0x49, 0x40, 0x18, 0x01, 0x21
	.byte 0x01, 0x70, 0x70, 0x47, 0xE0, 0x57, 0x00, 0x03, 0x89, 0x0C, 0x00, 0x00
	.syntax divided
