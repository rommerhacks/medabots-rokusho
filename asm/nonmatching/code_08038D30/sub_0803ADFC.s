	.syntax unified

	thumb_func_start sub_0803ADFC
sub_0803ADFC: @ 0x0803ADFC
	push {r4, r5, r6, lr}
	bl load_battle_sequence_commands
	ldr r4, _0803AE30 @ =0x03000590
	ldr r3, _0803AE34 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r2, r0, #8
	adds r1, r2, r4
	adds r0, r1, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0803AE38
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
	b _0803AE40
	.align 2, 0
_0803AE30: .4byte 0x03000590
_0803AE34: .4byte 0x03001800
_0803AE38:
	adds r0, r1, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	adds r0, #0x50
_0803AE40:
	ldr r5, _0803AEDC @ =0x03001800
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #9
	bl load_battle_entity_palette
	ldr r6, _0803AEE0 @ =0x03002C30
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0x97
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ldr r3, _0803AEE4 @ =0x0000012F
	adds r1, r6, r3
	strb r0, [r1]
	movs r1, #0x87
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	subs r3, #4
	adds r2, r6, r3
	strb r0, [r2]
	subs r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r3, #5
	adds r0, r6, r3
	strh r1, [r0]
	ldr r0, _0803AEE8 @ =0x00000129
	adds r1, r6, r0
	movs r0, #0x13
	strb r0, [r1]
	ldr r1, _0803AEEC @ =0x083CEC74
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	movs r2, #0
	bl init_game_state_entry
	adds r4, r6, r4
	movs r0, #4
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803AEF0
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0x81
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r3, #0x88
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, #0x2a
	adds r0, r6, r2
	strb r1, [r0]
	b _0803AF0E
	.align 2, 0
_0803AEDC: .4byte 0x03001800
_0803AEE0: .4byte 0x03002C30
_0803AEE4: .4byte 0x0000012F
_0803AEE8: .4byte 0x00000129
_0803AEEC: .4byte 0x083CEC74
_0803AEF0:
	movs r3, #0x84
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r2, #0x81
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	adds r3, #8
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #2
	adds r2, #0x2a
	adds r1, r6, r2
	strb r0, [r1]
_0803AF0E:
	ldr r0, _0803AF24 @ =0x03002C30
	ldr r3, _0803AF28 @ =0x0000012D
	adds r1, r0, r3
	movs r0, #0
	strb r0, [r1]
	bl battle_advance_sequence_counter
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803AF24: .4byte 0x03002C30
_0803AF28: .4byte 0x0000012D
	.syntax divided
