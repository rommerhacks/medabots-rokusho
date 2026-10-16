	.syntax unified

	thumb_func_start sub_0804C220
sub_0804C220: @ 0x0804C220
	push {r4, lr}
	bl read_map_script_byte
	ldr r4, _0804C268 @ =0x030057E0
	ldr r2, _0804C26C @ =0x00000C94
	adds r1, r4, r2
	strb r0, [r1]
	ldrb r0, [r1]
	bl sub_0804DBA4
	ldr r1, _0804C270 @ =0x03006D20
	adds r0, #0x4f
	strb r0, [r1, #0xa]
	ldr r3, _0804C274 @ =0x03002C30
	ldrb r0, [r1, #0xa]
	lsls r0, r0, #6
	adds r0, r0, r3
	ldr r0, [r0, #0x10]
	asrs r0, r0, #8
	movs r2, #0
	strh r0, [r1, #8]
	ldrb r0, [r1, #0xa]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x28
	strb r2, [r0]
	movs r0, #0x70
	bl sub_08047BA8
	ldr r0, _0804C278 @ =0x00000C89
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C268: .4byte 0x030057E0
_0804C26C: .4byte 0x00000C94
_0804C270: .4byte 0x03006D20
_0804C274: .4byte 0x03002C30
_0804C278: .4byte 0x00000C89
	.syntax divided
