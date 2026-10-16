	.syntax unified

	thumb_func_start sub_0804C174
sub_0804C174: @ 0x0804C174
	push {r4, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r4, _0804C1B0 @ =0x030057E0
	ldr r1, _0804C1B4 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	bl sub_0804DBA4
	ldr r1, _0804C1B8 @ =0x03006D20
	adds r0, #0x4f
	movs r2, #0
	strb r0, [r1, #0xa]
	ldr r3, _0804C1BC @ =0x00000C95
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r1]
	strb r2, [r1, #1]
	movs r0, #8
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	ldr r0, _0804C1C0 @ =0x00000C89
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C1B0: .4byte 0x030057E0
_0804C1B4: .4byte 0x00000C94
_0804C1B8: .4byte 0x03006D20
_0804C1BC: .4byte 0x00000C95
_0804C1C0: .4byte 0x00000C89
	.syntax divided
