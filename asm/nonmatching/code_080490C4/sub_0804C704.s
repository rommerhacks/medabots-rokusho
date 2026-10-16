	.syntax unified

	thumb_func_start sub_0804C704
sub_0804C704: @ 0x0804C704
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804C720 @ =0x030057E0
	ldr r3, _0804C724 @ =0x00000C94
	adds r2, r1, r3
	strb r0, [r2]
	ldr r0, _0804C728 @ =0x00000C89
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804C720: .4byte 0x030057E0
_0804C724: .4byte 0x00000C94
_0804C728: .4byte 0x00000C89
	.syntax divided
