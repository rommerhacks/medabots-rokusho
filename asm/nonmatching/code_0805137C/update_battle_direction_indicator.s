	.syntax unified

	thumb_func_start update_battle_direction_indicator
	.global update_battle_direction_indicator
update_battle_direction_indicator: @ 0x08051EB0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r4, _08051EF4 @ =0x030057E0
	ldr r0, _08051EF8 @ =0x00000C75
	adds r5, r4, r0
	ldrb r2, [r5]
	mov sb, r2
	subs r0, #2
	adds r7, r4, r0
	ldr r2, _08051EFC @ =0x00000C57
	adds r6, r4, r2
	ldrb r0, [r7]
	ldrb r2, [r6]
	cmp r0, r2
	bne _08051F70
	ldr r0, _08051F00 @ =0x00000C72
	adds r0, r0, r4
	mov r8, r0
	ldr r2, _08051F04 @ =0x00000C56
	adds r7, r4, r2
	ldrb r0, [r0]
	ldrb r2, [r7]
	cmp r0, r2
	bne _08051F0C
	ldr r0, _08051F08 @ =0x00000C74
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _08051FC4
	.align 2, 0
_08051EF4: .4byte 0x030057E0
_08051EF8: .4byte 0x00000C75
_08051EFC: .4byte 0x00000C57
_08051F00: .4byte 0x00000C72
_08051F04: .4byte 0x00000C56
_08051F08: .4byte 0x00000C74
_08051F0C:
	movs r6, #2
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	beq _08051F2A
	movs r0, #0x30
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	ldr r2, _08051F3C @ =0x00000C74
	adds r1, r4, r2
	strb r0, [r1]
_08051F2A:
	mov r1, r8
	ldrb r0, [r1]
	ldrb r7, [r7]
	cmp r0, r7
	bhs _08051F40
	movs r0, #3
	strb r0, [r5]
	b _08051F42
	.align 2, 0
_08051F3C: .4byte 0x00000C74
_08051F40:
	strb r6, [r5]
_08051F42:
	ldr r0, _08051F68 @ =0x030057E0
	ldr r2, _08051F6C @ =0x00000C75
	adds r4, r0, r2
	ldrb r0, [r4]
	cmp r0, sb
	beq _08051FC4
	bl set_battle_state_byte_c83
	ldrb r1, [r4]
	movs r0, #0x30
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
	b _08051FC4
	.align 2, 0
_08051F68: .4byte 0x030057E0
_08051F6C: .4byte 0x00000C75
_08051F70:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051F8C
	movs r0, #0x30
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	ldr r2, _08051F98 @ =0x00000C74
	adds r1, r4, r2
	strb r0, [r1]
_08051F8C:
	ldrb r0, [r7]
	ldrb r6, [r6]
	cmp r0, r6
	bhs _08051F9C
	movs r0, #1
	b _08051F9E
	.align 2, 0
_08051F98: .4byte 0x00000C74
_08051F9C:
	movs r0, #0
_08051F9E:
	strb r0, [r5]
	ldr r0, _08051FE0 @ =0x030057E0
	ldr r1, _08051FE4 @ =0x00000C75
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, sb
	beq _08051FC4
	bl set_battle_state_byte_c83
	ldrb r1, [r4]
	movs r0, #0x30
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
_08051FC4:
	ldr r0, _08051FE8 @ =0x03002C30
	ldr r2, _08051FEC @ =0x00000BEA
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r2, #0x40
	adds r0, r0, r2
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051FE0: .4byte 0x030057E0
_08051FE4: .4byte 0x00000C75
_08051FE8: .4byte 0x03002C30
_08051FEC: .4byte 0x00000BEA
	.syntax divided
