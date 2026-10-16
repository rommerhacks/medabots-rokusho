	.syntax unified

	thumb_func_start sub_080349D8
sub_080349D8: @ 0x080349D8
	push {r4, r5, r6, lr}
	ldr r5, _08034A18 @ =0x03001800
	adds r6, r5, #0
	adds r6, #0x87
	ldrb r0, [r6]
	bl sub_08032FB8
	adds r4, r5, #0
	adds r4, #0x60
	strb r0, [r4]
	ldrb r0, [r4]
	bl sub_08037798
	adds r3, r0, #0
	cmp r3, #0xff
	beq _08034A20
	ldr r2, _08034A1C @ =0x03000590
	ldrb r0, [r6]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r1, r3, #1
	adds r0, #0xe0
	strb r1, [r0]
	ldrb r1, [r6]
	lsls r1, r1, #8
	adds r1, r1, r2
	lsls r0, r3, #8
	adds r0, r0, r2
	adds r0, #0xde
	ldrb r0, [r0]
	adds r1, #0xe1
	b _08034A48
	.align 2, 0
_08034A18: .4byte 0x03001800
_08034A1C: .4byte 0x03000590
_08034A20:
	ldrb r0, [r6]
	bl sub_08032FB8
	strb r0, [r4]
	ldrb r0, [r4]
	bl select_random_battle_target
	ldr r2, _08034A60 @ =0x03000590
	ldrb r1, [r6]
	lsls r1, r1, #8
	adds r1, r1, r2
	adds r0, #1
	adds r1, #0xe0
	strb r0, [r1]
	ldrb r0, [r6]
	bl calc_bot_evasion_modifier
	adds r1, r5, #0
	adds r1, #0xb8
	movs r0, #2
_08034A48:
	strb r0, [r1]
	ldr r0, _08034A64 @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_080355C4
	bl sub_08034F08
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034A60: .4byte 0x03000590
_08034A64: .4byte 0x03001800
	.syntax divided
