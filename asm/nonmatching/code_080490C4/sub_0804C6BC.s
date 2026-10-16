	.syntax unified

	thumb_func_start sub_0804C6BC
sub_0804C6BC: @ 0x0804C6BC
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r0, _0804C6D4 @ =0x030057E0
	ldr r1, _0804C6D8 @ =0x00000C89
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0804C6D4: .4byte 0x030057E0
_0804C6D8: .4byte 0x00000C89
	.syntax divided
