	.syntax unified

	thumb_func_start sub_0800442C
sub_0800442C: @ 0x0800442C
	push {lr}
	bl sub_08004E74
	bl sub_08006764
	bl toggle_sprite_pair_visibility
	bl dispatch_game_substate_handler_08006824
	bl battle_update_medabot_display
	bl sub_08006F14
	bl sub_080068EC
	cmp r0, #0
	bne _080044F0
	bl sub_08006980
	cmp r0, #0
	bne _080044F0
	bl sub_08006A00
	cmp r0, #0
	bne _080044F0
	bl sub_08006A98
	cmp r0, #0
	bne _080044F0
	bl sub_08006B30
	cmp r0, #0
	bne _080044F0
	bl sub_08006BC8
	cmp r0, #0
	bne _080044F0
	bl sub_08006C64
	cmp r0, #0
	bne _080044F0
	ldr r2, _08004498 @ =0x0300058C
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080044A0
	movs r0, #5
	bl play_sound_effect
	ldr r1, _0800449C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080044EE
	.align 2, 0
_08004498: .4byte 0x0300058C
_0800449C: .4byte 0x0300137C
_080044A0:
	ldrb r1, [r2, #1]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080044CC
	movs r0, #2
	bl play_sound_effect
	ldr r0, _080044C8 @ =0x03000440
	adds r0, #0x5e
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
	bl setup_scene_with_link_check
	bl setup_battle_sprite_from_game_state
	b _080044F0
	.align 2, 0
_080044C8: .4byte 0x03000440
_080044CC:
	bl sub_08006F34
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _080044E0
	movs r0, #6
	bl play_sound_effect
	b _080044F0
_080044E0:
	cmp r0, #1
	bne _080044F0
	movs r0, #4
	bl play_sound_effect
	ldr r1, _080044F4 @ =0x0300137C
	movs r0, #0x18
_080044EE:
	str r0, [r1]
_080044F0:
	pop {r0}
	bx r0
	.align 2, 0
_080044F4: .4byte 0x0300137C
	.syntax divided
