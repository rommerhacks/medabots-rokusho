	.syntax unified

	thumb_func_start sub_0804B99C
sub_0804B99C: @ 0x0804B99C
	push {r4, lr}
	bl read_map_script_byte
	ldr r4, _0804B9F0 @ =0x030057E0
	ldr r2, _0804B9F4 @ =0x000007FE
	adds r1, r4, r2
	strb r0, [r1]
	bl read_map_script_byte
	ldr r2, _0804B9F8 @ =0x000007FC
	adds r1, r4, r2
	strb r0, [r1]
	bl read_map_script_byte
	ldr r2, _0804B9FC @ =0x000007FD
	adds r1, r4, r2
	strb r0, [r1]
	bl read_map_script_byte
	ldr r2, _0804BA00 @ =0x00000C56
	adds r1, r4, r2
	strb r0, [r1]
	bl read_map_script_byte
	ldr r2, _0804BA04 @ =0x00000C57
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0804BA08 @ =0x03002C30
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r2, #0x10
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0804BA0C @ =0x00000C89
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B9F0: .4byte 0x030057E0
_0804B9F4: .4byte 0x000007FE
_0804B9F8: .4byte 0x000007FC
_0804B9FC: .4byte 0x000007FD
_0804BA00: .4byte 0x00000C56
_0804BA04: .4byte 0x00000C57
_0804BA08: .4byte 0x03002C30
_0804BA0C: .4byte 0x00000C89
	.syntax divided
