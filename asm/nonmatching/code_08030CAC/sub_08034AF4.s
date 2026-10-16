	.syntax unified

	thumb_func_start sub_08034AF4
sub_08034AF4: @ 0x08034AF4
	push {r4, r5, lr}
	ldr r4, _08034B20 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl sub_08032FB8
	adds r4, #0x60
	strb r0, [r4]
	ldrb r0, [r4]
	ldrb r1, [r5]
	bl battle_select_random_target
	adds r2, r0, #0
	cmp r2, #0xff
	beq _08034B28
	ldr r0, _08034B24 @ =0x03000590
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r0
	adds r0, r2, #1
	b _08034B40
	.align 2, 0
_08034B20: .4byte 0x03001800
_08034B24: .4byte 0x03000590
_08034B28:
	ldrb r0, [r5]
	bl sub_08032FB8
	strb r0, [r4]
	ldrb r0, [r4]
	bl select_random_battle_target
	ldr r2, _08034B60 @ =0x03000590
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r2
	adds r0, #1
_08034B40:
	adds r1, #0xe0
	strb r0, [r1]
	ldr r4, _08034B64 @ =0x03001800
	adds r4, #0x87
	ldrb r0, [r4]
	bl calc_bot_evasion_modifier
	ldrb r0, [r4]
	bl sub_080355C4
	bl sub_08034F08
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034B60: .4byte 0x03000590
_08034B64: .4byte 0x03001800
	.syntax divided
