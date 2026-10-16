	.syntax unified

	thumb_func_start sub_08006B30
sub_08006B30: @ 0x08006B30
	push {r4, r5, r6, r7, lr}
	ldr r4, _08006B98 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x5a
	ldrb r0, [r0]
	cmp r0, #3
	bne _08006B94
	adds r5, r4, #0
	adds r5, #0x9a
	ldrb r7, [r5]
	ldr r6, _08006B9C @ =0x03001798
	ldrb r1, [r6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08006B6A
	ldr r1, _08006BA0 @ =0x030017A0
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r3, [r0, #1]
	adds r0, r7, #0
	movs r1, #2
	movs r2, #1
	bl find_next_available_medapart_slot
	strb r0, [r5]
_08006B6A:
	ldrb r1, [r6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08006B8E
	ldrb r0, [r5]
	ldr r2, _08006BA0 @ =0x030017A0
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r1, [r1]
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrb r3, [r1, #1]
	movs r1, #2
	movs r2, #0
	bl find_next_available_medapart_slot
	strb r0, [r5]
_08006B8E:
	ldrb r5, [r5]
	cmp r7, r5
	bne _08006BA4
_08006B94:
	movs r0, #0
	b _08006BC0
	.align 2, 0
_08006B98: .4byte 0x03000440
_08006B9C: .4byte 0x03001798
_08006BA0: .4byte 0x030017A0
_08006BA4:
	movs r0, #2
	bl play_sound_effect
	bl medabot_detail_draw_larm_name
	bl medabot_detail_draw_larm_skill_icon
	bl decompress_sprite_from_game_state
	bl setup_battle_sprite_from_game_state
	bl setup_scene_with_link_check
	movs r0, #1
_08006BC0:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
