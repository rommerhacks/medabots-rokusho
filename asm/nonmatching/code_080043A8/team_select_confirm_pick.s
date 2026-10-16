	.syntax unified

	thumb_func_start team_select_confirm_pick
	.global team_select_confirm_pick
team_select_confirm_pick: @ 0x080072EC
	push {r4, r5, r6, r7, lr}
	ldr r1, _08007358 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x50
	ldrb r2, [r0]
	adds r0, r1, #0
	cmp r2, #3
	bgt _080073CA
	cmp r2, #1
	blt _080073CA
	movs r5, #0
_08007302:
	ldr r0, _0800735C @ =0x03001800
	adds r0, #0x41
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	bne _080073BC
	adds r0, r5, #0
	bl check_target_not_in_battle_list
	cmp r0, #0
	beq _080073B4
	ldr r0, _08007360 @ =0x030017A0
	ldr r7, _08007358 @ =0x03000440
	adds r4, r7, #0
	adds r4, #0x51
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _080073B4
	movs r0, #4
	bl play_sound_effect
	ldrb r0, [r4]
	adds r0, #0x10
	strb r0, [r6]
	bl sub_0800712C
	cmp r5, #2
	bne _08007368
	adds r0, r7, #0
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #2
	bgt _0800734E
	cmp r0, #1
	bge _080073F0
_0800734E:
	ldr r1, _08007364 @ =0x0300137C
	movs r0, #0x28
	str r0, [r1]
	b _08007402
	.align 2, 0
_08007358: .4byte 0x03000440
_0800735C: .4byte 0x03001800
_08007360: .4byte 0x030017A0
_08007364: .4byte 0x0300137C
_08007368:
	bl sub_080440B4
	adds r1, r5, #1
	cmp r0, r1
	beq _080073F0
	ldr r0, _080073B0 @ =0x083AC468
	ldrb r1, [r4]
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r4]
	movs r0, #0
	bl update_battle_sprite_orbit_clockwise
	movs r0, #1
	bl update_battle_sprite_orbit_clockwise
	movs r0, #2
	bl update_battle_sprite_orbit_clockwise
	movs r0, #3
	bl update_battle_sprite_orbit_clockwise
	bl sub_08005118
	bl sub_0800519C
	bl sub_0800522C
	bl sub_080053C8
	bl sub_08005000
	bl sub_08005948
	b _08007402
	.align 2, 0
_080073B0: .4byte 0x083AC468
_080073B4:
	movs r0, #6
	bl play_sound_effect
	b _08007402
_080073BC:
	movs r0, #6
	bl play_sound_effect
	adds r5, #1
	cmp r5, #2
	bls _08007302
	b _08007402
_080073CA:
	ldr r1, _080073E8 @ =0x030017A0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080073FC
	movs r0, #4
	bl play_sound_effect
	ldr r1, _080073EC @ =0x0300137C
	movs r0, #8
	str r0, [r1]
	b _08007402
	.align 2, 0
_080073E8: .4byte 0x030017A0
_080073EC: .4byte 0x0300137C
_080073F0:
	ldr r1, _080073F8 @ =0x0300137C
	movs r0, #0x20
	str r0, [r1]
	b _08007402
	.align 2, 0
_080073F8: .4byte 0x0300137C
_080073FC:
	movs r0, #6
	bl play_sound_effect
_08007402:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
