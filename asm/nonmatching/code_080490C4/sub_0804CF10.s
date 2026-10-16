	.syntax unified

	thumb_func_start sub_0804CF10
sub_0804CF10: @ 0x0804CF10
	push {r4, lr}
	movs r0, #3
	bl read_map_script_bytes
	ldr r2, _0804CF2C @ =0x030057E0
	ldr r1, _0804CF30 @ =0x00000C94
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804CF34
	cmp r0, #1
	beq _0804CF58
	b _0804CFB6
	.align 2, 0
_0804CF2C: .4byte 0x030057E0
_0804CF30: .4byte 0x00000C94
_0804CF34:
	ldr r3, _0804CF54 @ =0x00000C96
	adds r4, r2, r3
	ldrb r0, [r4]
	bl sub_0804DBA4
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _0804CFB6
	ldrb r0, [r4]
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #0x18
	b _0804CF82
	.align 2, 0
_0804CF54: .4byte 0x00000C96
_0804CF58:
	ldr r1, _0804CF8C @ =0x00000C95
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #8
	ldr r3, _0804CF90 @ =0x00000C96
	adds r1, r2, r3
	ldrb r1, [r1]
	orrs r1, r0
	cmp r1, #0
	beq _0804CF94
	adds r0, r1, #0
	bl battle_find_entity_by_id
	cmp r0, #0
	beq _0804CFB6
	ldrb r0, [r0, #4]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r1, #0xc4
	lsls r1, r1, #0x16
	adds r0, r0, r1
_0804CF82:
	lsrs r0, r0, #0x18
	bl sub_0804D9AC
	b _0804CFB6
	.align 2, 0
_0804CF8C: .4byte 0x00000C95
_0804CF90: .4byte 0x00000C96
_0804CF94:
	ldr r3, _0804CFBC @ =0x00000CB4
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r3, #0xc4
	lsls r3, r3, #0x16
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	bl sub_0804D9AC
_0804CFB6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804CFBC: .4byte 0x00000CB4
	.syntax divided
