	.syntax unified

	thumb_func_start check_tile_and_trigger_battle_action
check_tile_and_trigger_battle_action: @ 0x08052570
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r4, _080525CC @ =0x030057E0
	ldr r0, _080525D0 @ =0x00000C5C
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, #2
	bne _080525A2
	adds r0, r5, #0
	bl get_adjacent_tile_value
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08052594
	cmp r1, #2
	bne _080525A2
_08052594:
	ldr r1, _080525D4 @ =0x00000C69
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r6]
	movs r0, #0
	bl load_battle_palette_via_dma
_080525A2:
	adds r0, r5, #0
	bl get_adjacent_tile_value
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, _080525CC @ =0x030057E0
	movs r2, #0xc1
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r1, r0
	ldrb r4, [r0]
	cmp r4, #0
	beq _080525C2
	adds r0, r5, #0
	bl set_battle_entity_animation_attack
_080525C2:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080525CC: .4byte 0x030057E0
_080525D0: .4byte 0x00000C5C
_080525D4: .4byte 0x00000C69
	.syntax divided
