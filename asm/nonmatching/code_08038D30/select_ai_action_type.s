	.syntax unified

	thumb_func_start select_ai_action_type
	.global select_ai_action_type
select_ai_action_type: @ 0x08039250
	push {r4, r5, r6, lr}
	ldr r4, _08039278 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x87
	ldrb r2, [r6]
	adds r5, r4, #0
	adds r5, #0xa7
	ldrb r1, [r5]
	adds r0, r2, #0
	bl check_bot_can_shoot
	cmp r0, #0
	beq _0803927C
	adds r0, r4, #0
	adds r0, #0xb8
	movs r1, #2
	strb r1, [r0]
	adds r0, #6
	strb r1, [r0]
	b _080392D0
	.align 2, 0
_08039278: .4byte 0x03001800
_0803927C:
	ldrb r2, [r6]
	ldrb r1, [r5]
	adds r0, r2, #0
	bl check_bot_can_support
	cmp r0, #0
	beq _08039298
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #2
	strb r0, [r1]
	adds r1, #6
	movs r0, #3
	b _080392CE
_08039298:
	ldrb r2, [r6]
	ldrb r1, [r5]
	adds r0, r2, #0
	bl check_bot_can_use_shoot_part
	cmp r0, #0
	beq _080392B4
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #2
	strb r0, [r1]
	adds r1, #6
	movs r0, #4
	b _080392CE
_080392B4:
	ldrb r2, [r6]
	ldrb r1, [r5]
	adds r0, r2, #0
	bl check_bot_status_effect_4
	cmp r0, #0
	beq _080392D0
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #2
	strb r0, [r1]
	adds r1, #6
	movs r0, #6
_080392CE:
	strb r0, [r1]
_080392D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
