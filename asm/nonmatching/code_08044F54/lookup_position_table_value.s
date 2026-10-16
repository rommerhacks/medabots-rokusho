	.syntax unified

	thumb_func_start lookup_position_table_value
	.global lookup_position_table_value
lookup_position_table_value: @ 0x08047E50
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl check_position_table_match
	adds r6, r0, #0
	cmp r6, #0
	beq _08047EDA
	movs r3, #0
	movs r2, #0
	ldr r7, _08047E88 @ =0x030017A0
	adds r1, r7, #0
_08047E72:
	ldrb r0, [r1]
	cmp r0, #3
	bne _08047EAE
	cmp r4, #1
	beq _08047E9A
	cmp r4, #1
	bgt _08047E8C
	cmp r4, #0
	beq _08047E96
	b _08047EAE
	.align 2, 0
_08047E88: .4byte 0x030017A0
_08047E8C:
	cmp r4, #2
	beq _08047E9E
	cmp r4, #3
	beq _08047EA6
	b _08047EAE
_08047E96:
	ldrb r0, [r1, #3]
	b _08047EA0
_08047E9A:
	ldrb r0, [r1, #4]
	b _08047EA0
_08047E9E:
	ldrb r0, [r1, #5]
_08047EA0:
	cmp r0, r5
	bne _08047EAE
	b _08047EBA
_08047EA6:
	ldrb r0, [r1, #6]
	cmp r0, r5
	bne _08047EAE
	movs r3, #1
_08047EAE:
	cmp r3, #0
	bne _08047EBA
	adds r1, #8
	adds r2, #1
	cmp r2, #8
	ble _08047E72
_08047EBA:
	lsls r4, r2, #3
	adds r4, r4, r7
	ldrb r0, [r4, #6]
	movs r1, #3
	mov r2, sp
	bl load_part_data
	mov r0, sp
	ldrb r0, [r0, #1]
	adds r2, r0, #0
	subs r2, #0x64
	ldr r1, _08047EE0 @ =0x03006D38
	ldrb r0, [r4, #1]
	strb r0, [r1, #6]
	cmp r6, #0
	bne _08047EE4
_08047EDA:
	movs r0, #1
	rsbs r0, r0, #0
	b _08047EE6
	.align 2, 0
_08047EE0: .4byte 0x03006D38
_08047EE4:
	adds r0, r2, #0
_08047EE6:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
