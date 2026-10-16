	.syntax unified

	thumb_func_start battle_field_movement_dispatch
	.global battle_field_movement_dispatch
battle_field_movement_dispatch: @ 0x08051C6C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0
	ldr r0, _08051CE8 @ =0x030057E0
	mov r8, r0
	ldr r0, _08051CEC @ =0x00000C58
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051C84
	b _08051DC4
_08051C84:
	ldr r0, _08051CF0 @ =0x03002B64
	ldr r3, [r0]
	lsls r7, r3, #0x18
	lsrs r2, r7, #0x1f
	lsls r6, r3, #0x19
	lsrs r0, r6, #0x1f
	orrs r2, r0
	lsls r5, r3, #0x1a
	lsrs r1, r5, #0x1f
	orrs r1, r2
	lsls r3, r3, #0x1b
	lsrs r0, r3, #0x1f
	orrs r0, r1
	cmp r0, #0
	bne _08051CA4
	b _08051DD8
_08051CA4:
	lsrs r0, r7, #0x1f
	lsls r1, r0, #3
	lsrs r0, r6, #0x1f
	lsls r0, r0, #2
	orrs r1, r0
	lsrs r0, r5, #0x1f
	lsls r0, r0, #1
	orrs r1, r0
	lsrs r0, r3, #0x1f
	orrs r1, r0
	ldr r0, _08051CF4 @ =0x00000C88
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08051CD6
	ldr r0, _08051CF8 @ =0x000007FE
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0x53
	bne _08051CD6
	adds r0, r1, #0
	bl handle_battle_movement_input
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_08051CD6:
	subs r0, r1, #1
	cmp r0, #9
	bhi _08051D36
	lsls r0, r0, #2
	ldr r1, _08051CFC @ =_08051D00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08051CE8: .4byte 0x030057E0
_08051CEC: .4byte 0x00000C58
_08051CF0: .4byte 0x03002B64
_08051CF4: .4byte 0x00000C88
_08051CF8: .4byte 0x000007FE
_08051CFC: .4byte _08051D00
_08051D00: @ jump table
	.4byte _08051D30 @ case 0
	.4byte _08051D34 @ case 1
	.4byte _08051D36 @ case 2
	.4byte _08051D28 @ case 3
	.4byte _08051D30 @ case 4
	.4byte _08051D34 @ case 5
	.4byte _08051D36 @ case 6
	.4byte _08051D2C @ case 7
	.4byte _08051D30 @ case 8
	.4byte _08051D34 @ case 9
_08051D28:
	movs r4, #0
	b _08051D36
_08051D2C:
	movs r4, #1
	b _08051D36
_08051D30:
	movs r4, #3
	b _08051D36
_08051D34:
	movs r4, #2
_08051D36:
	ldr r6, _08051DB0 @ =0x030057E0
	ldr r1, _08051DB4 @ =0x00000C59
	adds r5, r6, r1
	ldrb r0, [r5]
	cmp r0, r4
	beq _08051D58
	strb r4, [r5]
	adds r0, r4, #0
	bl set_battle_entity_animation_attack
	movs r0, #0x2f
	adds r1, r4, #0
	bl sub_080493D4
	movs r0, #3
	bl update_battle_direction_indicator
_08051D58:
	adds r0, r4, #0
	bl check_battle_animation_complete
	cmp r0, #0
	bne _08051DD8
	adds r0, r4, #0
	bl check_tile_and_trigger_battle_action
	cmp r0, #0
	bne _08051DD8
	movs r0, #0x2f
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	ldr r2, _08051DB8 @ =0x00000C58
	adds r1, r6, r2
	strb r0, [r1]
	ldrb r0, [r5]
	bl update_camera_scroll_and_check_events
	movs r0, #3
	bl update_battle_direction_indicator
	ldr r1, _08051DBC @ =0x00000C5C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08051D9A
	cmp r0, #9
	bne _08051DA0
_08051D9A:
	movs r0, #0x57
	bl sub_08047BA8
_08051DA0:
	ldr r0, _08051DB0 @ =0x030057E0
	ldr r2, _08051DC0 @ =0x00000C75
	adds r0, r0, r2
	ldrb r0, [r0]
	bl battle_camera_scroll_update
	b _08051DD8
	.align 2, 0
_08051DB0: .4byte 0x030057E0
_08051DB4: .4byte 0x00000C59
_08051DB8: .4byte 0x00000C58
_08051DBC: .4byte 0x00000C5C
_08051DC0: .4byte 0x00000C75
_08051DC4:
	ldr r0, _08051DE4 @ =0x00000C59
	add r0, r8
	ldrb r0, [r0]
	bl update_camera_scroll_and_check_events
	ldr r0, _08051DE8 @ =0x00000C75
	add r0, r8
	ldrb r0, [r0]
	bl battle_camera_scroll_update
_08051DD8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051DE4: .4byte 0x00000C59
_08051DE8: .4byte 0x00000C75
	.syntax divided
