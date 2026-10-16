	.syntax unified

	thumb_func_start sub_0804D1BC
sub_0804D1BC: @ 0x0804D1BC
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804D1D0 @ =0x030057E0
	ldr r2, _0804D1D4 @ =0x000007FF
	adds r1, r1, r2
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804D1D0: .4byte 0x030057E0
_0804D1D4: .4byte 0x000007FF
	.syntax divided
