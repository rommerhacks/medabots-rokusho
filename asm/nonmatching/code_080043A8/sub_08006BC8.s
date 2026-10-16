	.syntax unified

	thumb_func_start sub_08006BC8
sub_08006BC8: @ 0x08006BC8
	push {r4, r5, r6, r7, lr}
	ldr r4, _08006C30 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x5a
	ldrb r0, [r0]
	cmp r0, #4
	bne _08006C2C
	adds r5, r4, #0
	adds r5, #0x9b
	ldrb r7, [r5]
	ldr r6, _08006C34 @ =0x03001798
	ldrb r1, [r6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08006C02
	ldr r1, _08006C38 @ =0x030017A0
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r3, [r0, #1]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #1
	bl find_next_available_medapart_slot
	strb r0, [r5]
_08006C02:
	ldrb r1, [r6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08006C26
	ldrb r0, [r5]
	ldr r2, _08006C38 @ =0x030017A0
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r1, [r1]
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrb r3, [r1, #1]
	movs r1, #3
	movs r2, #0
	bl find_next_available_medapart_slot
	strb r0, [r5]
_08006C26:
	ldrb r5, [r5]
	cmp r7, r5
	bne _08006C3C
_08006C2C:
	movs r0, #0
	b _08006C5C
	.align 2, 0
_08006C30: .4byte 0x03000440
_08006C34: .4byte 0x03001798
_08006C38: .4byte 0x030017A0
_08006C3C:
	movs r0, #2
	bl play_sound_effect
	bl medabot_detail_draw_legs_name
	bl medabot_detail_draw_legs_skill_icon
	bl medabot_detail_draw_legs_type_icon
	bl decompress_sprite_from_game_state
	bl setup_battle_sprite_from_game_state
	bl setup_scene_with_link_check
	movs r0, #1
_08006C5C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
