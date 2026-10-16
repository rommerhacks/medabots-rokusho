	.syntax unified

	thumb_func_start sub_0804CD38
sub_0804CD38: @ 0x0804CD38
	push {lr}
	movs r0, #1
	bl read_map_script_bytes
	ldr r0, _0804CD50 @ =0x030057E0
	ldr r1, _0804CD54 @ =0x00000C89
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0804CD50: .4byte 0x030057E0
_0804CD54: .4byte 0x00000C89
	.syntax divided
