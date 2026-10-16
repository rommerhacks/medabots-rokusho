	.syntax unified

	thumb_func_start sub_0804B6A8
sub_0804B6A8: @ 0x0804B6A8
	push {r4, lr}
	bl read_map_script_byte
	ldr r1, _0804B6D8 @ =0x030057E0
	ldr r2, _0804B6DC @ =0x00000C92
	adds r3, r1, r2
	movs r2, #0
	strb r0, [r3]
	ldr r4, _0804B6E0 @ =0x00000C89
	adds r0, r1, r4
	strb r2, [r0]
	ldr r0, _0804B6E4 @ =0x00000C93
	adds r1, r1, r0
	strb r2, [r1]
	ldr r1, _0804B6E8 @ =0x083D20AC
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B6D8: .4byte 0x030057E0
_0804B6DC: .4byte 0x00000C92
_0804B6E0: .4byte 0x00000C89
_0804B6E4: .4byte 0x00000C93
_0804B6E8: .4byte 0x083D20AC
	.syntax divided
