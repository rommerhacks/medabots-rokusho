	.syntax unified

	thumb_func_start sub_0804C42C
sub_0804C42C: @ 0x0804C42C
	push {r4, r5, r6, lr}
	ldr r4, _0804C458 @ =0x030057E0
	ldr r0, _0804C45C @ =0x00000C8A
	adds r6, r4, r0
	ldrh r5, [r6]
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804C460 @ =0x00000C94
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #8
	ldr r0, _0804C464 @ =0x00000C95
	adds r4, r4, r0
	ldrb r0, [r4]
	orrs r0, r1
	adds r5, r5, r0
	strh r5, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804C458: .4byte 0x030057E0
_0804C45C: .4byte 0x00000C8A
_0804C460: .4byte 0x00000C94
_0804C464: .4byte 0x00000C95
	.syntax divided
