	.syntax unified

	thumb_func_start battle_begin_action_phase
	.global battle_begin_action_phase
battle_begin_action_phase: @ 0x08038E54
	push {lr}
	ldr r1, _08038E84 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xee
	movs r0, #0
	strh r0, [r2]
	ldr r2, _08038E88 @ =0x03000590
	adds r1, #0x88
	ldrb r0, [r1]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08038E8C
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08038E8C
	bl battle_calculate_damage_modifier
	b _08038E98
	.align 2, 0
_08038E84: .4byte 0x03001800
_08038E88: .4byte 0x03000590
_08038E8C:
	bl battle_calculate_turn_speed
	cmp r0, #0
	bne _08038E98
	bl battle_process_speed_and_action
_08038E98:
	pop {r0}
	bx r0
	.syntax divided
