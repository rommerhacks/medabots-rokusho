	.syntax unified

	thumb_func_start sub_0804D444
sub_0804D444: @ 0x0804D444
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804D458 @ =0x030057E0
	ldr r2, _0804D45C @ =0x00000C32
	adds r1, r1, r2
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804D458: .4byte 0x030057E0
_0804D45C: .4byte 0x00000C32
	.syntax divided
