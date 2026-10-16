	.syntax unified

	thumb_func_start sub_0804C954
sub_0804C954: @ 0x0804C954
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804C970 @ =0x030057E0
	ldr r2, _0804C974 @ =0x00000C94
	adds r1, r1, r2
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #3
	bl dispatch_jump_table_29
	pop {r0}
	bx r0
	.align 2, 0
_0804C970: .4byte 0x030057E0
_0804C974: .4byte 0x00000C94
	.syntax divided
