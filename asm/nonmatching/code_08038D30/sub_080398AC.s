	.syntax unified

	thumb_func_start sub_080398AC
sub_080398AC: @ 0x080398AC
	push {r4, r5, r6, r7, lr}
	bl load_battle_sequence_commands
	ldr r4, _080398E0 @ =0x03000590
	ldr r3, _080398E4 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r2, r0, #8
	adds r1, r2, r4
	adds r0, r1, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080398E8
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
	b _080398F0
	.align 2, 0
_080398E0: .4byte 0x03000590
_080398E4: .4byte 0x03001800
_080398E8:
	adds r0, r1, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	adds r0, #0x50
_080398F0:
	ldr r5, _08039990 @ =0x03001800
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #9
	bl load_battle_entity_palette
	ldr r6, _08039994 @ =0x03002C30
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0x97
	lsls r2, r2, #1
	adds r7, r6, r2
	strb r0, [r7]
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ldr r3, _08039998 @ =0x0000012F
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
	ldr r0, _0803999C @ =0x00000129
	adds r1, r6, r0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080399A0 @ =0x083CEC74
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
	bne _080399A4
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
	b _080399CE
	.align 2, 0
_08039990: .4byte 0x03001800
_08039994: .4byte 0x03002C30
_08039998: .4byte 0x0000012F
_0803999C: .4byte 0x00000129
_080399A0: .4byte 0x083CEC74
_080399A4:
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
_080399CE:
	ldr r0, _080399E4 @ =0x03002C30
	ldr r3, _080399E8 @ =0x0000012D
	adds r1, r0, r3
	movs r0, #0
	strb r0, [r1]
	bl battle_advance_sequence_counter
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080399E4: .4byte 0x03002C30
_080399E8: .4byte 0x0000012D
	.syntax divided
