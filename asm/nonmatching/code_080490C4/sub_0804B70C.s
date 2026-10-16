	.syntax unified

	thumb_func_start sub_0804B70C
sub_0804B70C: @ 0x0804B70C
	push {lr}
	movs r0, #3
	bl read_map_script_bytes
	ldr r0, _0804B724 @ =0x030057E0
	ldr r1, _0804B728 @ =0x00000C89
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0804B724: .4byte 0x030057E0
_0804B728: .4byte 0x00000C89
	.syntax divided
