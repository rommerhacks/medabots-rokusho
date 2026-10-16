	.syntax unified

	thumb_func_start check_position_table_match
	.global check_position_table_match
check_position_table_match: @ 0x08047EF0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r4, #0
	movs r5, #0
	ldr r3, _08047F14 @ =0x030017A0
_08047F00:
	ldrb r0, [r3]
	cmp r0, #3
	bne _08047F3C
	cmp r1, #1
	beq _08047F26
	cmp r1, #1
	bgt _08047F18
	cmp r1, #0
	beq _08047F22
	b _08047F3C
	.align 2, 0
_08047F14: .4byte 0x030017A0
_08047F18:
	cmp r1, #2
	beq _08047F2A
	cmp r1, #3
	beq _08047F34
	b _08047F3C
_08047F22:
	ldrb r0, [r3, #3]
	b _08047F2C
_08047F26:
	ldrb r0, [r3, #4]
	b _08047F2C
_08047F2A:
	ldrb r0, [r3, #5]
_08047F2C:
	cmp r0, r2
	bne _08047F3C
	movs r4, #1
	b _08047F48
_08047F34:
	ldrb r0, [r3, #6]
	cmp r0, r2
	bne _08047F3C
	movs r4, #1
_08047F3C:
	cmp r4, #0
	bne _08047F48
	adds r3, #8
	adds r5, #1
	cmp r5, #8
	ble _08047F00
_08047F48:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
