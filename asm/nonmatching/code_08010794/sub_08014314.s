	.syntax unified

	thumb_func_start sub_08014314
sub_08014314: @ 0x08014314
	push {r4, lr}
	bl update_all_battle_status_sprites
	bl sub_08019078
	bl sort_active_medal_slots
	ldr r4, _08014338 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x45
	ldrb r0, [r0]
	cmp r0, #0
	bne _08014340
	ldr r1, _0801433C @ =0x0300137C
	movs r0, #0x44
	str r0, [r1]
	b _08014392
	.align 2, 0
_08014338: .4byte 0x03001800
_0801433C: .4byte 0x0300137C
_08014340:
	bl battle_calc_bot_count_minus_one_mod3
	ldr r1, _08014360 @ =0x03000590
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _08014364
	bl sub_0801A678
	b _08014392
	.align 2, 0
_08014360: .4byte 0x03000590
_08014364:
	adds r0, r1, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _08014384
	ldr r1, _08014380 @ =0x0300137C
	movs r0, #0x47
	str r0, [r1]
	b _08014392
	.align 2, 0
_08014380: .4byte 0x0300137C
_08014384:
	bl iterate_bots_setup_battle_sprites
	ldr r0, _08014398 @ =0x03002B8C
	movs r1, #8
	str r1, [r0]
	ldr r0, _0801439C @ =0x0300137C
	str r4, [r0]
_08014392:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014398: .4byte 0x03002B8C
_0801439C: .4byte 0x0300137C
	.syntax divided
