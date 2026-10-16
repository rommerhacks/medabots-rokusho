	.syntax unified

	thumb_func_start sub_08006980
sub_08006980: @ 0x08006980
	push {r4, r5, r6, lr}
	ldr r1, _080069C8 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x5a
	ldrb r0, [r0]
	cmp r0, #0
	bne _080069C4
	adds r4, r1, #0
	adds r4, #0x97
	ldrb r6, [r4]
	ldr r5, _080069CC @ =0x03001798
	ldrb r1, [r5]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080069AA
	adds r0, r6, #0
	movs r1, #1
	bl sub_0804361C
	strb r0, [r4]
_080069AA:
	ldrb r1, [r5]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080069BE
	ldrb r0, [r4]
	movs r1, #0
	bl sub_0804361C
	strb r0, [r4]
_080069BE:
	ldrb r4, [r4]
	cmp r6, r4
	bne _080069D0
_080069C4:
	movs r0, #0
	b _080069F8
	.align 2, 0
_080069C8: .4byte 0x03000440
_080069CC: .4byte 0x03001798
_080069D0:
	movs r0, #2
	bl play_sound_effect
	bl sub_08005AD0
	bl sub_08005B44
	bl sub_08005C10
	bl sub_08005BB4
	bl medabot_detail_draw_head_skill_icon
	bl medabot_detail_draw_rarm_skill_icon
	bl medabot_detail_draw_larm_skill_icon
	bl medabot_detail_draw_legs_skill_icon
	movs r0, #1
_080069F8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
