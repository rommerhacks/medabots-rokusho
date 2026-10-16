	.syntax unified

	thumb_func_start sub_080391C4
	.global sub_080391C4
sub_080391C4: @ 0x080391C4
	push {r4, r5, r6, r7, lr}
	ldr r4, _080391F0 @ =0x03001800
	adds r7, r4, #0
	adds r7, #0x87
	ldrb r0, [r7]
	adds r6, r4, #0
	adds r6, #0xa7
	ldrb r1, [r6]
	adds r5, r4, #0
	adds r5, #0x88
	ldrb r2, [r5]
	bl check_bot_can_shoot
	cmp r0, #0
	beq _080391F4
	adds r0, r4, #0
	adds r0, #0xb8
	movs r1, #2
	strb r1, [r0]
	adds r0, #6
	strb r1, [r0]
	b _08039248
	.align 2, 0
_080391F0: .4byte 0x03001800
_080391F4:
	ldrb r0, [r7]
	ldrb r1, [r6]
	ldrb r2, [r5]
	bl check_bot_can_support
	cmp r0, #0
	beq _08039210
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #2
	strb r0, [r1]
	adds r1, #6
	movs r0, #3
	b _08039246
_08039210:
	ldrb r0, [r7]
	ldrb r1, [r6]
	ldrb r2, [r5]
	bl check_bot_can_use_shoot_part
	cmp r0, #0
	beq _0803922C
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #2
	strb r0, [r1]
	adds r1, #6
	movs r0, #4
	b _08039246
_0803922C:
	ldrb r0, [r7]
	ldrb r1, [r6]
	ldrb r2, [r5]
	bl check_bot_status_effect_4
	cmp r0, #0
	beq _08039248
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #2
	strb r0, [r1]
	adds r1, #6
	movs r0, #6
_08039246:
	strb r0, [r1]
_08039248:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
