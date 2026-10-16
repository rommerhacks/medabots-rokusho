	.syntax unified

	thumb_func_start sub_0804C790
sub_0804C790: @ 0x0804C790
	push {r4, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804C7C0 @ =0x030057E0
	ldr r2, _0804C7C4 @ =0x00000C94
	adds r0, r1, r2
	ldrb r3, [r0]
	cmp r3, #0
	bne _0804C7CC
	ldr r4, _0804C7C8 @ =0x00000CBC
	adds r2, r1, r4
	subs r4, #0x27
	adds r0, r1, r4
	ldrb r1, [r2]
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	cmp r1, #0
	bge _0804C7E6
	strb r3, [r2]
	b _0804C7E6
	.align 2, 0
_0804C7C0: .4byte 0x030057E0
_0804C7C4: .4byte 0x00000C94
_0804C7C8: .4byte 0x00000CBC
_0804C7CC:
	ldr r0, _0804C7EC @ =0x00000CBD
	adds r2, r1, r0
	ldr r3, _0804C7F0 @ =0x00000C95
	adds r0, r1, r3
	ldrb r1, [r2]
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	cmp r1, #0
	bge _0804C7E6
	movs r0, #0
	strb r0, [r2]
_0804C7E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C7EC: .4byte 0x00000CBD
_0804C7F0: .4byte 0x00000C95
	.syntax divided
