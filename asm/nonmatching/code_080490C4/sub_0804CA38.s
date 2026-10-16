	.syntax unified

	thumb_func_start sub_0804CA38
sub_0804CA38: @ 0x0804CA38
	push {r4, r5, r6, lr}
	ldr r4, _0804CA74 @ =0x030057E0
	ldr r0, _0804CA78 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804CA7C @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #3
	bl read_map_script_bytes
	ldr r2, _0804CA80 @ =0x00000C94
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r2, #1
	adds r1, r4, r2
	ldrb r1, [r1]
	bl lookup_position_table_value
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804CA84
	movs r2, #0xc6
	lsls r2, r2, #4
	adds r0, r4, r2
	strb r1, [r0]
	b _0804CA90
	.align 2, 0
_0804CA74: .4byte 0x030057E0
_0804CA78: .4byte 0x00000C8A
_0804CA7C: .4byte 0x00000C8C
_0804CA80: .4byte 0x00000C94
_0804CA84:
	ldr r0, _0804CA98 @ =0x00000C96
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804CA90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CA98: .4byte 0x00000C96
	.syntax divided
