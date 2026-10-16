	.syntax unified

	thumb_func_start sub_08065090
sub_08065090: @ 0x08065090
	push {r4, r5, r6, lr}
	movs r5, #1
	ldr r4, _080650BC @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x4c
	ldrb r0, [r0]
	cmp r0, #0
	beq _080650C0
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _080650CE
	ldr r0, [r4]
	adds r0, #0x4c
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	movs r2, #0
	bl text_window_init
	b _080650CE
	.align 2, 0
_080650BC: .4byte 0x03006F74
_080650C0:
	ldr r0, _08065128 @ =0x08485788
	ldr r0, [r0, #0x34]
	bl run_message
	cmp r0, #0
	beq _080650CE
	movs r5, #0
_080650CE:
	cmp r5, #0
	beq _080650D4
	b _08065336
_080650D4:
	ldr r5, _0806512C @ =0x03001780
	ldrb r1, [r5]
	movs r0, #8
	movs r2, #0xc
	bl sub_08041C14
	ldr r2, _08065130 @ =0x03002C30
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r4, r3, #0
	movs r3, #0
	orrs r0, r4
	strh r0, [r1]
	ldr r0, _08065134 @ =0x03006F74
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #4
	bls _080651A4
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08065140
	ldr r0, [r5]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #9
	bhi _08065138
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	b _0806514E
	.align 2, 0
_08065128: .4byte 0x08485788
_0806512C: .4byte 0x03001780
_08065130: .4byte 0x03002C30
_08065134: .4byte 0x03006F74
_08065138:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r2, r2, r1
	b _08065146
_08065140:
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r2, r2, r3
_08065146:
	ldrh r1, [r2]
	ldr r0, _08065184 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
_0806514E:
	ldr r0, _08065188 @ =0x03006F74
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	adds r0, #4
	adds r1, #0x30
	ldrb r1, [r1]
	cmp r0, r1
	bge _08065194
	ldr r0, _0806518C @ =0x03001780
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #9
	bhi _08065194
	ldr r0, _08065190 @ =0x03002C30
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r1, r2
	b _080651A2
	.align 2, 0
_08065184: .4byte 0x0000BFFF
_08065188: .4byte 0x03006F74
_0806518C: .4byte 0x03001780
_08065190: .4byte 0x03002C30
_08065194:
	ldr r0, _080651D4 @ =0x03002C30
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _080651D8 @ =0x0000BFFF
	ands r1, r2
_080651A2:
	strh r1, [r0]
_080651A4:
	ldr r0, _080651DC @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080651F4
	movs r5, #2
	ldr r0, _080651E0 @ =0x03006F74
	ldr r1, [r0]
	adds r3, r1, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	cmp r0, #0
	bne _080651EE
	adds r2, r1, #0
	adds r2, #0x2f
	ldrb r0, [r2]
	cmp r0, #0
	beq _080651E4
	subs r0, #1
	b _08065242
	.align 2, 0
_080651D4: .4byte 0x03002C30
_080651D8: .4byte 0x0000BFFF
_080651DC: .4byte 0x03001798
_080651E0: .4byte 0x03006F74
_080651E4:
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0806524E
_080651EE:
	subs r0, #1
	strb r0, [r3]
	b _08065244
_080651F4:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08065260
	movs r5, #2
	ldr r0, _0806521C @ =0x03006F74
	ldr r1, [r0]
	adds r3, r1, #0
	adds r3, #0x30
	ldrb r0, [r3]
	cmp r0, #3
	bhi _08065226
	adds r1, #0x2e
	ldrb r2, [r1]
	subs r0, #1
	cmp r2, r0
	bne _08065220
	strb r4, [r1]
	b _08065244
	.align 2, 0
_0806521C: .4byte 0x03006F74
_08065220:
	adds r0, r2, #1
	strb r0, [r1]
	b _08065244
_08065226:
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	cmp r0, #3
	bne _08065240
	adds r2, #1
	ldrb r1, [r2]
	ldrb r0, [r3]
	subs r0, #4
	cmp r1, r0
	beq _0806524E
	adds r0, r1, #1
	b _08065242
_08065240:
	adds r0, #1
_08065242:
	strb r0, [r2]
_08065244:
	cmp r5, #0
	beq _0806524E
	adds r0, r5, #0
	bl play_sound_effect
_0806524E:
	ldr r0, _0806525C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x2f
	ldrb r0, [r0]
	bl render_battle_medal_names
	b _08065318
	.align 2, 0
_0806525C: .4byte 0x03006F74
_08065260:
	ldr r0, _080652BC @ =0x0300058C
	ldrb r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080652D8
	movs r0, #4
	bl play_sound_effect
	ldr r2, _080652C0 @ =0x03002C30
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r4, r2, r3
	ldrh r3, [r4]
	ldr r1, _080652C4 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r3
	movs r5, #0
	strh r0, [r4]
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r3, r2, r0
	ldrh r0, [r3]
	ands r1, r0
	strh r1, [r3]
	ldr r1, _080652C8 @ =0x00000202
	adds r2, r2, r1
	movs r0, #0xc
	strh r0, [r2]
	ldr r0, _080652CC @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x4c
	strb r6, [r0]
	ldr r0, _080652D0 @ =0x03000440
	strb r5, [r0, #0x1b]
	ldr r1, _080652D4 @ =0x0300137C
	movs r0, #9
	str r0, [r1]
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	b _08065336
	.align 2, 0
_080652BC: .4byte 0x0300058C
_080652C0: .4byte 0x03002C30
_080652C4: .4byte 0x0000BFFF
_080652C8: .4byte 0x00000202
_080652CC: .4byte 0x03006F74
_080652D0: .4byte 0x03000440
_080652D4: .4byte 0x0300137C
_080652D8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08065336
	movs r0, #5
	bl play_sound_effect
	ldr r1, _08065308 @ =0x03002C30
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r2, [r1]
	ldr r0, _0806530C @ =0x0000BFFF
	ands r0, r2
	movs r2, #0
	strh r0, [r1]
	ldr r0, _08065310 @ =0x03000440
	strb r2, [r0, #0x1b]
	adds r0, #0x84
	strb r2, [r0]
	ldr r1, _08065314 @ =0x0300137C
	movs r0, #7
	str r0, [r1]
	b _08065336
	.align 2, 0
_08065308: .4byte 0x03002C30
_0806530C: .4byte 0x0000BFFF
_08065310: .4byte 0x03000440
_08065314: .4byte 0x0300137C
_08065318:
	ldr r2, _0806533C @ =0x03002C30
	ldr r0, _08065340 @ =0x00000202
	adds r1, r2, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r0, _08065344 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #0x1c
	movs r1, #0x81
	lsls r1, r1, #2
	adds r2, r2, r1
	strh r0, [r2]
_08065336:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806533C: .4byte 0x03002C30
_08065340: .4byte 0x00000202
_08065344: .4byte 0x03006F74
	.syntax divided
