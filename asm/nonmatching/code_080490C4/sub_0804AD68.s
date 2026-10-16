	.syntax unified

	thumb_func_start sub_0804AD68
sub_0804AD68: @ 0x0804AD68
	push {r4, r5, r6, lr}
	bl sub_0804B694
	cmp r0, #0
	beq _0804ADF8
	ldr r6, _0804AE00 @ =0x030057E0
	ldr r1, _0804AE04 @ =0x00000C69
	adds r0, r6, r1
	ldrb r1, [r0]
	ldr r2, _0804AE08 @ =0x00000C5C
	adds r0, r6, r2
	movs r5, #0
	strb r1, [r0]
	movs r0, #0
	bl load_battle_palette_via_dma
	ldr r0, _0804AE0C @ =0x00000C67
	adds r4, r6, r0
	movs r0, #1
	strb r0, [r4]
	ldr r0, _0804AE10 @ =0x03005310
	strb r5, [r0, #1]
	bl init_battle_field_setup
	bl update_bg_scroll_offsets_a
	ldrb r0, [r4]
	bl field_set_player_facing
	ldr r1, _0804AE14 @ =0x00000C76
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804ADEE
	ldr r2, _0804AE18 @ =0x00000C52
	adds r0, r6, r2
	ldrh r1, [r0]
	adds r2, #0x1c
	adds r0, r6, r2
	strh r1, [r0]
	ldr r1, _0804AE1C @ =0x00000C54
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldr r4, _0804AE20 @ =0x03002C30
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	bl set_battle_state_byte_c83
	ldr r2, _0804AE24 @ =0x00000C2B
	adds r0, r4, r2
	ldrb r1, [r0]
	movs r0, #0xc2
	lsls r0, r0, #4
	adds r4, r4, r0
	lsls r1, r1, #2
	ldrb r4, [r4]
	adds r1, r1, r4
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
_0804ADEE:
	bl update_battle_entity_status_chars
	ldr r1, _0804AE28 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
_0804ADF8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804AE00: .4byte 0x030057E0
_0804AE04: .4byte 0x00000C69
_0804AE08: .4byte 0x00000C5C
_0804AE0C: .4byte 0x00000C67
_0804AE10: .4byte 0x03005310
_0804AE14: .4byte 0x00000C76
_0804AE18: .4byte 0x00000C52
_0804AE1C: .4byte 0x00000C54
_0804AE20: .4byte 0x03002C30
_0804AE24: .4byte 0x00000C2B
_0804AE28: .4byte 0x0300137C

	.syntax divided
