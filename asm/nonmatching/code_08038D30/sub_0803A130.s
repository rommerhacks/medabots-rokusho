	.syntax unified

	thumb_func_start sub_0803A130
sub_0803A130: @ 0x0803A130
	push {r4, r5, r6, r7, lr}
	bl load_battle_sequence_commands
	movs r3, #0
	ldr r0, _0803A14C @ =0x03002C30
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803A150
	movs r5, #0xa
	b _0803A168
	.align 2, 0
_0803A14C: .4byte 0x03002C30
_0803A150:
	adds r3, #1
	cmp r3, #8
	bhi _0803A168
	ldr r0, _0803A218 @ =0x03002C30
	adds r2, r3, #0
	adds r2, #0xa
	lsls r1, r2, #6
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0803A150
	adds r5, r2, #0
_0803A168:
	lsls r4, r5, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0803A218 @ =0x03002C30
	lsls r0, r5, #6
	adds r5, r0, r1
	ldr r6, _0803A21C @ =0x03001800
	movs r2, #0x87
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	lsls r0, r0, #0xa
	ldr r2, _0803A220 @ =0x00004004
	adds r1, r2, #0
	movs r7, #0
	orrs r0, r1
	strh r0, [r5]
	strb r7, [r5, #0x1c]
	movs r0, #0xe
	strb r0, [r5, #0xa]
	movs r0, #0x80
	strb r0, [r5, #0xb]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r2, r5, #0
	adds r2, #0x2d
	strb r0, [r2]
	ldr r1, _0803A224 @ =0x083B5F80
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r4, #0
	bl init_battle_sprite_entry_08040B90
	movs r2, #0x81
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x2b
	strb r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	strh r0, [r5, #4]
	adds r2, #8
	adds r0, r6, r2
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x2c
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0xb
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803A228
	subs r2, #6
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r5, #2]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x25
	strb r1, [r0]
	b _0803A258
	.align 2, 0
_0803A218: .4byte 0x03002C30
_0803A21C: .4byte 0x03001800
_0803A220: .4byte 0x00004004
_0803A224: .4byte 0x083B5F80
_0803A228:
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r0, #0xf0
	subs r0, r0, r1
	strh r0, [r5, #2]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrb r1, [r0]
	movs r0, #0x20
	subs r0, r0, r1
	movs r1, #0x1f
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x25
	strb r0, [r1]
_0803A258:
	bl battle_advance_sequence_counter
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
