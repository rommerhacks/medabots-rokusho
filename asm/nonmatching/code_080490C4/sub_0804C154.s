	.syntax unified

	thumb_func_start sub_0804C154
sub_0804C154: @ 0x0804C154
	push {lr}
	bl read_map_script_byte
	ldr r1, _0804C16C @ =0x030057E0
	ldr r2, _0804C170 @ =0x00000C94
	adds r1, r1, r2
	strb r0, [r1]
	ldrb r0, [r1]
	bl sub_08050508
	pop {r0}
	bx r0
	.align 2, 0
_0804C16C: .4byte 0x030057E0
_0804C170: .4byte 0x00000C94
	.syntax divided
