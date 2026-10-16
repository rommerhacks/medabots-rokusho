	.syntax unified

	thumb_func_start sub_0803A474
sub_0803A474: @ 0x0803A474
	push {r4, r5, r6, lr}
	bl load_battle_sequence_commands
	movs r0, #0x23
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r4, _0803A4B0 @ =0x03000590
	ldr r3, _0803A4B4 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r2, r0, #8
	adds r1, r2, r4
	adds r0, r1, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0803A4B8
	adds r0, r3, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r4
	adds r0, #0x49
	ldrb r0, [r0]
	b _0803A4C0
	.align 2, 0
_0803A4B0: .4byte 0x03000590
_0803A4B4: .4byte 0x03001800
_0803A4B8:
	adds r0, r1, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	adds r0, #0x50
_0803A4C0:
	ldr r4, _0803A55C @ =0x03001800
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #9
	bl load_battle_entity_palette
	ldr r5, _0803A560 @ =0x03002C30
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldr r2, _0803A564 @ =0x000008EE
	adds r6, r5, r2
	strb r0, [r6]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0xa
	adds r0, r4, r3
	ldrh r0, [r0]
	ldr r1, _0803A568 @ =0x000008EB
	adds r2, r5, r1
	strb r0, [r2]
	subs r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r3, #0x8f
	lsls r3, r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	ldr r0, _0803A56C @ =0x000008E9
	adds r1, r5, r0
	movs r0, #0x11
	strb r0, [r1]
	ldr r1, _0803A570 @ =0x083CEC74
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #1
	movs r2, #1
	bl init_game_state_entry
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0803A574 @ =0x000008C4
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803A578
	movs r3, #0x83
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r1, [r0]
	subs r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #0xa
	adds r0, r4, r3
	ldrh r1, [r0]
	adds r2, #0x2a
	adds r0, r5, r2
	strb r1, [r0]
	b _0803A5A2
	.align 2, 0
_0803A55C: .4byte 0x03001800
_0803A560: .4byte 0x03002C30
_0803A564: .4byte 0x000008EE
_0803A568: .4byte 0x000008EB
_0803A56C: .4byte 0x000008E9
_0803A570: .4byte 0x083CEC74
_0803A574: .4byte 0x000008C4
_0803A578:
	ldrb r2, [r6]
	lsrs r2, r2, #1
	movs r1, #0x1e
	subs r1, r1, r2
	movs r3, #0x83
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r0, r0, r2
	subs r1, r1, r0
	subs r1, #1
	ldr r2, _0803A5BC @ =0x000008C2
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #0xa
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #2
	adds r2, #0x2a
	adds r1, r5, r2
	strb r0, [r1]
_0803A5A2:
	ldr r0, _0803A5C0 @ =0x03002C30
	ldr r3, _0803A5C4 @ =0x000008ED
	adds r1, r0, r3
	movs r2, #0
	strb r2, [r1]
	ldr r1, _0803A5C8 @ =0x000008E8
	adds r0, r0, r1
	strb r2, [r0]
	bl battle_advance_sequence_counter
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803A5BC: .4byte 0x000008C2
_0803A5C0: .4byte 0x03002C30
_0803A5C4: .4byte 0x000008ED
_0803A5C8: .4byte 0x000008E8
	.syntax divided
