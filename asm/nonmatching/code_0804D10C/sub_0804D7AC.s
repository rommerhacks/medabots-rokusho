	.syntax unified

	thumb_func_start sub_0804D7AC
sub_0804D7AC: @ 0x0804D7AC
	push {r4, r5, r6, lr}
	ldr r4, _0804D7E0 @ =0x030057E0
	ldr r0, _0804D7E4 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r5, [r6]
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804D7E8 @ =0x00000C76
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804D7DA
	ldr r2, _0804D7EC @ =0x00000C94
	adds r0, r4, r2
	ldrb r1, [r0]
	lsls r1, r1, #8
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	orrs r0, r1
	adds r0, r5, r0
	strh r0, [r6]
_0804D7DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D7E0: .4byte 0x030057E0
_0804D7E4: .4byte 0x00000C8A
_0804D7E8: .4byte 0x00000C76
_0804D7EC: .4byte 0x00000C94
	.syntax divided
