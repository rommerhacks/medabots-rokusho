	.syntax unified

	thumb_func_start check_vehicle_usability
check_vehicle_usability: @ 0x08057C38
	push {r4, r5, lr}
	movs r5, #0
	cmp r0, #1
	beq _08057CD8
	cmp r0, #1
	bgt _08057C4A
	cmp r0, #0
	beq _08057C56
	b _08057E10
_08057C4A:
	cmp r0, #2
	beq _08057D10
	cmp r0, #3
	bne _08057C54
	b _08057DA0
_08057C54:
	b _08057E10
_08057C56:
	movs r0, #0x12
	bl sub_08047D8C
	movs r5, #1
	cmp r0, #0
	bne _08057C64
	b _08057E10
_08057C64:
	movs r0, #0x55
	movs r1, #0
	bl check_position_table_match
	adds r4, r0, #0
	movs r0, #0x55
	movs r1, #1
	bl check_position_table_match
	adds r4, r4, r0
	movs r0, #0x55
	movs r1, #2
	bl check_position_table_match
	adds r4, r4, r0
	movs r0, #0x55
	movs r1, #3
	bl check_position_table_match
	adds r4, r4, r0
	movs r5, #2
	cmp r4, #4
	beq _08057C94
	b _08057E10
_08057C94:
	movs r0, #0
	bl sub_0804803C
	adds r2, r0, #0
	movs r5, #3
	cmp r2, #0
	bne _08057CA4
	b _08057E10
_08057CA4:
	ldr r2, _08057CCC @ =0x030057E0
	ldr r1, _08057CD0 @ =0x00000C5D
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	movs r5, #4
	cmp r0, #0
	beq _08057CB8
	b _08057E10
_08057CB8:
	movs r5, #0
	ldr r1, _08057CD4 @ =0x00000C5C
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08057CC6
	b _08057E10
_08057CC6:
	movs r5, #5
	b _08057E10
	.align 2, 0
_08057CCC: .4byte 0x030057E0
_08057CD0: .4byte 0x00000C5D
_08057CD4: .4byte 0x00000C5C
_08057CD8:
	movs r0, #0x18
	bl sub_08047D8C
	movs r5, #1
	cmp r0, #0
	bne _08057CE6
	b _08057E10
_08057CE6:
	ldr r2, _08057D04 @ =0x030057E0
	ldr r5, _08057D08 @ =0x00000C5D
	adds r0, r2, r5
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	movs r5, #4
	cmp r0, #0
	beq _08057CFA
	b _08057E10
_08057CFA:
	movs r5, #0
	ldr r1, _08057D0C @ =0x00000C5C
	adds r0, r2, r1
	b _08057D80
	.align 2, 0
_08057D04: .4byte 0x030057E0
_08057D08: .4byte 0x00000C5D
_08057D0C: .4byte 0x00000C5C
_08057D10:
	movs r0, #0x19
	bl sub_08047D8C
	movs r5, #1
	cmp r0, #0
	beq _08057E10
	movs r0, #0xb
	movs r1, #0
	bl check_position_table_match
	adds r4, r0, #0
	movs r0, #0xb
	movs r1, #1
	bl check_position_table_match
	adds r4, r4, r0
	movs r0, #0xb
	movs r1, #2
	bl check_position_table_match
	adds r4, r4, r0
	movs r0, #0xb
	movs r1, #3
	bl check_position_table_match
	adds r4, r4, r0
	movs r5, #2
	cmp r4, #4
	bne _08057E10
	movs r0, #1
	bl sub_0804803C
	adds r2, r0, #0
	ldr r1, _08057D90 @ =0x083D29EB
	ldr r3, _08057D94 @ =0x030057E0
	ldr r5, _08057D98 @ =0x000007FE
	adds r0, r3, r5
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _08057D66
	movs r2, #0
_08057D66:
	movs r5, #3
	cmp r2, #0
	beq _08057E10
	ldr r1, _08057D9C @ =0x00000C5D
	adds r0, r3, r1
	ldrb r0, [r0]
	ands r4, r0
	movs r5, #4
	cmp r4, #0
	bne _08057E10
	movs r5, #0
	subs r1, #1
	adds r0, r3, r1
_08057D80:
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08057E10
	movs r5, #5
	b _08057E10
	.align 2, 0
_08057D90: .4byte 0x083D29EB
_08057D94: .4byte 0x030057E0
_08057D98: .4byte 0x000007FE
_08057D9C: .4byte 0x00000C5D
_08057DA0:
	movs r0, #0x26
	bl sub_08047D8C
	movs r5, #1
	cmp r0, #0
	beq _08057E10
	movs r0, #0x6b
	movs r1, #0
	bl check_position_table_match
	adds r4, r0, #0
	movs r0, #0x6b
	movs r1, #1
	bl check_position_table_match
	adds r4, r4, r0
	movs r0, #0x6b
	movs r1, #2
	bl check_position_table_match
	adds r4, r4, r0
	movs r0, #0x6b
	movs r1, #3
	bl check_position_table_match
	adds r4, r4, r0
	movs r5, #2
	cmp r4, #4
	bne _08057E10
	ldr r2, _08057E18 @ =0x030057E0
	ldr r5, _08057E1C @ =0x00000C5D
	adds r0, r2, r5
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	movs r5, #4
	cmp r0, #0
	bne _08057E10
	ldr r1, _08057E20 @ =0x00000C5C
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r5, #5
	cmp r0, #1
	bls _08057E10
	movs r5, #0
	adds r1, #0xb
	adds r0, r2, r1
	ldrb r0, [r0]
	bl get_adjacent_tile_value
	cmp r0, #3
	beq _08057E10
	movs r5, #6
_08057E10:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08057E18: .4byte 0x030057E0
_08057E1C: .4byte 0x00000C5D
_08057E20: .4byte 0x00000C5C
	.syntax divided
