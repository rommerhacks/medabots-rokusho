	.syntax unified

	thumb_func_start sub_08003504
sub_08003504: @ 0x08003504
	push {r4, lr}
	bl sub_080039BC
	ldr r0, _08003530 @ =0x083B5F80
	ldr r0, [r0]
	movs r1, #0
	bl process_sprite_anim_commands
	ldr r0, _08003534 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08003566
	ldr r0, _08003538 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x8f
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800353C
	movs r0, #2
	b _0800353E
	.align 2, 0
_08003530: .4byte 0x083B5F80
_08003534: .4byte 0x03001798
_08003538: .4byte 0x03000440
_0800353C:
	subs r0, #1
_0800353E:
	strb r0, [r1]
	movs r0, #2
	bl play_sound_effect
	bl sub_08003904
	ldr r3, _08003584 @ =0x03002C30
	ldr r2, _08003588 @ =0x03000440
	adds r2, #0x8f
	ldrb r1, [r2]
	lsls r1, r1, #3
	movs r0, #0x88
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r3, #4]
_08003566:
	ldr r0, _0800358C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080035BA
	ldr r0, _08003588 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x8f
	ldrb r0, [r1]
	cmp r0, #2
	bne _08003590
	movs r0, #0
	b _08003592
	.align 2, 0
_08003584: .4byte 0x03002C30
_08003588: .4byte 0x03000440
_0800358C: .4byte 0x03001798
_08003590:
	adds r0, #1
_08003592:
	strb r0, [r1]
	movs r0, #2
	bl play_sound_effect
	bl sub_08003904
	ldr r3, _0800360C @ =0x03002C30
	ldr r2, _08003610 @ =0x03000440
	adds r2, #0x8f
	ldrb r1, [r2]
	lsls r1, r1, #3
	movs r0, #0x88
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r3, #4]
_080035BA:
	ldr r4, _08003614 @ =0x0300058C
	ldrb r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080035D4
	movs r0, #5
	bl play_sound_effect
	ldr r1, _08003618 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080035D4:
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08003606
	movs r0, #4
	bl play_sound_effect
	ldr r0, _0800361C @ =0x083B5F80
	ldr r0, [r0, #4]
	movs r1, #0
	bl init_battle_sprite_entry_08040B90
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r0, _08003610 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08003618 @ =0x0300137C
	movs r0, #8
	str r0, [r1]
_08003606:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800360C: .4byte 0x03002C30
_08003610: .4byte 0x03000440
_08003614: .4byte 0x0300058C
_08003618: .4byte 0x0300137C
_0800361C: .4byte 0x083B5F80
	.syntax divided
