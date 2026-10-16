	.syntax unified

	thumb_func_start sub_0804ABC8
sub_0804ABC8: @ 0x0804ABC8
	push {r4, r5, r6, lr}
	movs r0, #0x2f
	bl sub_080518F4
	adds r1, r0, #0
	ldr r4, _0804AC58 @ =0x030057E0
	movs r0, #0x10
	bl sub_0807CBBC
	ldr r2, _0804AC5C @ =0x00000C58
	adds r1, r4, r2
	strb r0, [r1]
	ldr r6, _0804AC60 @ =0x03002C30
	movs r0, #0xbe
	lsls r0, r0, #4
	adds r5, r6, r0
	ldrb r0, [r5]
	bl field_set_player_facing
	ldrb r1, [r5]
	movs r0, #0x2f
	bl sub_080493D4
	ldr r1, _0804AC64 @ =0x00000C76
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804AC3A
	ldr r2, _0804AC68 @ =0x00000C52
	adds r0, r4, r2
	ldrh r1, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, _0804AC6C @ =0x00000C54
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r5]
	bl set_battle_state_byte_c83
	ldr r1, _0804AC70 @ =0x00000C2B
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #4
	adds r0, r6, r2
	lsls r1, r1, #2
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
_0804AC3A:
	movs r0, #1
	bl update_battle_direction_indicator
	movs r0, #0x57
	bl sub_08047BA8
	ldr r1, _0804AC74 @ =0x03005310
	movs r0, #1
	strb r0, [r1, #1]
	ldr r1, _0804AC78 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804AC58: .4byte 0x030057E0
_0804AC5C: .4byte 0x00000C58
_0804AC60: .4byte 0x03002C30
_0804AC64: .4byte 0x00000C76
_0804AC68: .4byte 0x00000C52
_0804AC6C: .4byte 0x00000C54
_0804AC70: .4byte 0x00000C2B
_0804AC74: .4byte 0x03005310
_0804AC78: .4byte 0x0300137C
	.syntax divided
