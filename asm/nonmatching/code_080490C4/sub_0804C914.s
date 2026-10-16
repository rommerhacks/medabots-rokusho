	.syntax unified

	thumb_func_start sub_0804C914
sub_0804C914: @ 0x0804C914
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804C930 @ =0x030057E0
	ldr r2, _0804C934 @ =0x00000C94
	adds r1, r1, r2
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #1
	bl dispatch_jump_table_29
	pop {r0}
	bx r0
	.align 2, 0
_0804C930: .4byte 0x030057E0
_0804C934: .4byte 0x00000C94
	.syntax divided
