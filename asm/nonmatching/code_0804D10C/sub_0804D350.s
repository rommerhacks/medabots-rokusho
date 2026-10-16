	.syntax unified

	thumb_func_start sub_0804D350
sub_0804D350: @ 0x0804D350
	push {r4, r5, r6, lr}
	ldr r4, _0804D384 @ =0x030057E0
	ldr r0, _0804D388 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804D38C @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804D390 @ =0x03006D38
	ldr r2, _0804D394 @ =0x00000C94
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bl sub_08047F50
	cmp r0, #2
	ble _0804D39C
	ldr r0, _0804D398 @ =0x00000C89
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0804D3A8
	.align 2, 0
_0804D384: .4byte 0x030057E0
_0804D388: .4byte 0x00000C8A
_0804D38C: .4byte 0x00000C8C
_0804D390: .4byte 0x03006D38
_0804D394: .4byte 0x00000C94
_0804D398: .4byte 0x00000C89
_0804D39C:
	ldr r2, _0804D3B0 @ =0x00000C95
	adds r1, r4, r2
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804D3A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D3B0: .4byte 0x00000C95
	.syntax divided
