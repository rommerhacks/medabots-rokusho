	.syntax unified

	thumb_func_start battle_process_speed_and_action
battle_process_speed_and_action: @ 0x08039068
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _0803910C @ =0x03001800
	adds r4, r1, #0
	adds r4, #0xee
	movs r0, #0
	strh r0, [r4]
	adds r7, r1, #0
	adds r7, #0xe8
	ldrh r0, [r7]
	movs r2, #0xf2
	adds r2, r2, r1
	mov r8, r2
	strh r0, [r2]
	ldr r6, _08039110 @ =0x03000590
	adds r5, r1, #0
	adds r5, #0x88
	ldrb r2, [r5]
	lsls r0, r2, #8
	adds r0, r0, r6
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08039126
	adds r0, r2, #0
	bl accumulate_battle_speed_value
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xa4
	ldrh r1, [r4]
	ldrb r0, [r0]
	adds r1, r1, r0
	strh r1, [r4]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080390CE
	adds r0, r4, #0
	movs r1, #8
	bl sub_08035754
_080390CE:
	bl battle_calculate_damage_modifier
	cmp r0, #0
	bne _08039126
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x1f
	ble _08039126
	adds r1, r0, #0
	adds r0, r7, #0
	bl sub_08035754
	ldrh r0, [r7]
	mov r1, r8
	strh r0, [r1]
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r6
	adds r1, #0xbc
	ldrb r2, [r1]
	movs r0, #0x20
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r5]
	bl sub_08039134
	cmp r0, #1
	bne _08039114
	movs r1, #1
	b _0803911C
	.align 2, 0
_0803910C: .4byte 0x03001800
_08039110: .4byte 0x03000590
_08039114:
	ldrb r0, [r5]
	bl battle_find_strongest_part
	adds r1, r0, #0
_0803911C:
	ldr r0, _08039130 @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08035944
_08039126:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039130: .4byte 0x03001800
	.syntax divided
