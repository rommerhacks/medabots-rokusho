	.syntax unified

	thumb_func_start sub_0804C9DC
sub_0804C9DC: @ 0x0804C9DC
	push {r4, r5, r6, lr}
	ldr r4, _0804CA20 @ =0x030057E0
	ldr r0, _0804CA24 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804CA28 @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #3
	bl read_map_script_bytes
	ldr r2, _0804CA2C @ =0x00000C94
	adds r0, r4, r2
	ldrb r0, [r0]
	bl sub_08047D8C
	adds r1, r0, #0
	cmp r1, #0
	beq _0804CA0C
	ldr r2, _0804CA30 @ =0x00000C95
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	bge _0804CA18
_0804CA0C:
	ldr r0, _0804CA34 @ =0x00000C96
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804CA18:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CA20: .4byte 0x030057E0
_0804CA24: .4byte 0x00000C8A
_0804CA28: .4byte 0x00000C8C
_0804CA2C: .4byte 0x00000C94
_0804CA30: .4byte 0x00000C95
_0804CA34: .4byte 0x00000C96
	.syntax divided
