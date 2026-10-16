	.syntax unified

	thumb_func_start sub_0804C8E0
sub_0804C8E0: @ 0x0804C8E0
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r0, _0804C8F8 @ =0x030057E0
	ldr r1, _0804C8FC @ =0x00000C89
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0804C8F8: .4byte 0x030057E0
_0804C8FC: .4byte 0x00000C89
	.syntax divided
