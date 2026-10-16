	.syntax unified

	thumb_func_start sub_0804BD24
sub_0804BD24: @ 0x0804BD24
	push {r4, r5, r6, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r5, _0804BD74 @ =0x030057E0
	ldr r0, _0804BD78 @ =0x00000C94
	adds r6, r5, r0
	ldrb r0, [r6]
	lsls r0, r0, #8
	ldr r1, _0804BD7C @ =0x00000C95
	adds r4, r5, r1
	ldrb r1, [r4]
	orrs r1, r0
	ldr r2, _0804BD80 @ =0x00000C8E
	adds r0, r5, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _0804BD84 @ =0x00000C8A
	adds r0, r5, r1
	strh r2, [r0]
	ldrb r1, [r6]
	lsls r1, r1, #8
	ldrb r0, [r4]
	orrs r0, r1
	bl battle_find_entity_by_id
	cmp r0, #0
	beq _0804BD6E
	ldrb r1, [r6]
	lsls r1, r1, #8
	ldrb r0, [r4]
	orrs r0, r1
	bl sub_0804D8A8
	ldr r2, _0804BD88 @ =0x00000CB4
	adds r1, r5, r2
	strb r0, [r1]
_0804BD6E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BD74: .4byte 0x030057E0
_0804BD78: .4byte 0x00000C94
_0804BD7C: .4byte 0x00000C95
_0804BD80: .4byte 0x00000C8E
_0804BD84: .4byte 0x00000C8A
_0804BD88: .4byte 0x00000CB4
	.syntax divided
