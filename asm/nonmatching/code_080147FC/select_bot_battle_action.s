	.syntax unified

	thumb_func_start select_bot_battle_action
select_bot_battle_action: @ 0x08015464
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080154AC @ =0x03000590
	lsls r1, r5, #8
	adds r1, r1, r0
	adds r1, #0xc1
	ldrb r0, [r1]
	cmp r0, #0x50
	bne _08015490
	bl rng_next_080424B8
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _08015490
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl check_medaforce_availability
	cmp r0, #0
	beq _080154DA
_08015490:
	bl set_random_battle_formation
	movs r6, #0
	ldr r0, _080154B0 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0x64
_0801549C:
	ldrb r0, [r4]
	cmp r0, #0xff
	bne _080154B4
	adds r0, r5, #0
	movs r1, #0
	bl battle_bot_select_part
	b _080154DA
	.align 2, 0
_080154AC: .4byte 0x03000590
_080154B0: .4byte 0x03001800
_080154B4:
	ldrb r1, [r4]
	adds r0, r5, #0
	bl can_bot_perform_action
	cmp r0, #0
	bne _080154CA
	ldrb r1, [r4]
	adds r0, r5, #0
	bl battle_bot_select_part
	b _080154DA
_080154CA:
	adds r4, #1
	adds r6, #1
	cmp r6, #3
	bls _0801549C
	adds r0, r5, #0
	movs r1, #0
	bl battle_bot_select_part
_080154DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
