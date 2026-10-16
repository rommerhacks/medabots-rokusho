	.syntax unified

	thumb_func_start sub_0804D048
sub_0804D048: @ 0x0804D048
	push {r4, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r4, _0804D080 @ =0x030057E0
	ldr r1, _0804D084 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	bl sub_0804DBA4
	ldr r2, _0804D088 @ =0x03006D20
	adds r0, #0x4f
	movs r3, #0
	strb r0, [r2, #0xa]
	ldr r1, _0804D08C @ =0x03002C30
	ldrb r0, [r2, #0xa]
	lsls r0, r0, #6
	adds r0, r0, r1
	adds r0, #0x26
	strb r3, [r0]
	ldr r0, _0804D090 @ =0x00000C89
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D080: .4byte 0x030057E0
_0804D084: .4byte 0x00000C94
_0804D088: .4byte 0x03006D20
_0804D08C: .4byte 0x03002C30
_0804D090: .4byte 0x00000C89
	.syntax divided
