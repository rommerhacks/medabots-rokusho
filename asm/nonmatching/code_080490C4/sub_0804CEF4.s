	.syntax unified

	thumb_func_start sub_0804CEF4
sub_0804CEF4: @ 0x0804CEF4
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804CF08 @ =0x030057E0
	ldr r2, _0804CF0C @ =0x00000C2C
	adds r1, r1, r2
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804CF08: .4byte 0x030057E0
_0804CF0C: .4byte 0x00000C2C
	.syntax divided
