	.syntax unified

	thumb_func_start sub_0804D3EC
sub_0804D3EC: @ 0x0804D3EC
	push {r4, r5, r6, lr}
	ldr r4, _0804D42C @ =0x030057E0
	ldr r0, _0804D430 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804D434 @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #3
	bl read_map_script_bytes
	ldr r2, _0804D438 @ =0x00000C94
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r2, #1
	adds r1, r4, r2
	ldrb r1, [r1]
	bl sub_08047D9C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0804D426
	ldr r0, _0804D43C @ =0x00000C96
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804D426:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D42C: .4byte 0x030057E0
_0804D430: .4byte 0x00000C8A
_0804D434: .4byte 0x00000C8C
_0804D438: .4byte 0x00000C94
_0804D43C: .4byte 0x00000C96

	.syntax divided
