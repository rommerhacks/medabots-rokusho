	.syntax unified

	thumb_func_start battle_calculate_damage_modifier
battle_calculate_damage_modifier: @ 0x08038E9C
	push {r4, r5, r6, r7, lr}
	ldr r4, _08038EC4 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x87
	ldrb r0, [r6]
	adds r5, r4, #0
	adds r5, #0xa7
	ldrb r1, [r5]
	adds r7, r4, #0
	adds r7, #0x88
	ldrb r2, [r7]
	bl check_bot_ability_type_strike
	cmp r0, #0
	beq _08038EC8
	adds r0, r4, #0
	adds r0, #0xee
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _08038F20
	.align 2, 0
_08038EC4: .4byte 0x03001800
_08038EC8:
	ldrb r0, [r6]
	ldrb r1, [r5]
	ldrb r2, [r7]
	bl check_bot_ability_type_shoot
	cmp r0, #0
	beq _08038EE0
	adds r0, r4, #0
	adds r0, #0xee
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _08038F20
_08038EE0:
	ldr r2, _08038F04 @ =0x03000590
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r6]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #3
	bne _08038F08
	adds r0, r4, #0
	adds r0, #0xee
	ldrh r0, [r0]
	lsls r0, r0, #0x11
	b _08038F1E
	.align 2, 0
_08038F04: .4byte 0x03000590
_08038F08:
	cmp r0, #0
	bne _08038F16
	adds r0, r4, #0
	adds r0, #0xee
	ldrh r0, [r0]
	lsls r0, r0, #0x12
	b _08038F1E
_08038F16:
	adds r0, r4, #0
	adds r0, #0xee
	ldrh r0, [r0]
	lsls r0, r0, #0x13
_08038F1E:
	asrs r0, r0, #0x10
_08038F20:
	bl battle_check_damage_threshold
	cmp r0, #0
	bne _08038F2C
	movs r0, #0
	b _08038F2E
_08038F2C:
	movs r0, #1
_08038F2E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
