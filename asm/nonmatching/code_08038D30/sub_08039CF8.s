	.syntax unified

	thumb_func_start sub_08039CF8
sub_08039CF8: @ 0x08039CF8
	push {r4, r5, r6, r7, lr}
	bl load_battle_sequence_commands
	ldr r5, _08039DA0 @ =0x03001800
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x3c
	movs r2, #9
	bl load_battle_entity_palette
	ldr r6, _08039DA4 @ =0x03002C30
	movs r3, #0x81
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #0x97
	lsls r1, r1, #1
	adds r7, r6, r1
	strb r0, [r7]
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ldr r2, _08039DA8 @ =0x0000012F
	adds r1, r6, r2
	strb r0, [r1]
	adds r3, #0xc
	adds r0, r5, r3
	ldrh r0, [r0]
	ldr r1, _08039DAC @ =0x0000012B
	adds r2, r6, r1
	strb r0, [r2]
	subs r3, #2
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r3, #0x24
	adds r0, r6, r3
	strh r1, [r0]
	ldr r0, _08039DB0 @ =0x00000129
	adds r1, r6, r0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _08039DB4 @ =0x083CEC74
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	movs r2, #0
	bl init_game_state_entry
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r4, r6, r4
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08039DB8
	movs r2, #0x83
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #0x81
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, #0x26
	adds r0, r6, r2
	strb r1, [r0]
	b _08039DE2
	.align 2, 0
_08039DA0: .4byte 0x03001800
_08039DA4: .4byte 0x03002C30
_08039DA8: .4byte 0x0000012F
_08039DAC: .4byte 0x0000012B
_08039DB0: .4byte 0x00000129
_08039DB4: .4byte 0x083CEC74
_08039DB8:
	ldrb r2, [r7]
	lsrs r2, r2, #1
	movs r1, #0x1e
	subs r1, r1, r2
	movs r3, #0x83
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r0, r0, r2
	subs r1, r1, r0
	movs r2, #0x81
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	adds r3, #0xa
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #2
	adds r2, #0x2a
	adds r1, r6, r2
	strb r0, [r1]
_08039DE2:
	ldr r0, _08039DF8 @ =0x03002C30
	ldr r3, _08039DFC @ =0x0000012D
	adds r1, r0, r3
	movs r0, #0
	strb r0, [r1]
	bl battle_advance_sequence_counter
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039DF8: .4byte 0x03002C30
_08039DFC: .4byte 0x0000012D
	.syntax divided
