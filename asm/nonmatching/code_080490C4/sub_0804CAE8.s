	.syntax unified

	thumb_func_start sub_0804CAE8
sub_0804CAE8: @ 0x0804CAE8
	push {r4, r5, r6, lr}
	ldr r4, _0804CB30 @ =0x030057E0
	ldr r0, _0804CB34 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804CB38 @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #3
	bl read_map_script_bytes
	bl sub_08047D4C
	ldr r2, _0804CB3C @ =0x00000C94
	adds r1, r4, r2
	ldrb r2, [r1]
	lsls r2, r2, #8
	ldr r3, _0804CB40 @ =0x00000C95
	adds r1, r4, r3
	ldrb r1, [r1]
	orrs r2, r1
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	cmp r0, r1
	bge _0804CB28
	ldr r0, _0804CB44 @ =0x00000C96
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804CB28:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CB30: .4byte 0x030057E0
_0804CB34: .4byte 0x00000C8A
_0804CB38: .4byte 0x00000C8C
_0804CB3C: .4byte 0x00000C94
_0804CB40: .4byte 0x00000C95
_0804CB44: .4byte 0x00000C96
	.syntax divided
