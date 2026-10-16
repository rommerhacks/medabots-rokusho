	.syntax unified

	thumb_func_start sub_080178CC
	.global sub_080178CC
sub_080178CC: @ 0x080178CC
	push {lr}
	ldr r0, _08017900 @ =0x03000590
	ldr r3, _08017904 @ =0x03001800
	adds r2, r3, #0
	adds r2, #0x80
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r1, r1, r0
	adds r1, #0xc1
	ldrb r0, [r1]
	cmp r0, #0x50
	bne _0801790E
	adds r0, r3, #0
	adds r0, #0x85
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #8
	ands r1, r0
	cmp r1, #0
	beq _08017908
	ldrb r0, [r2]
	bl draw_battle_panel_left_b
	b _0801790E
	.align 2, 0
_08017900: .4byte 0x03000590
_08017904: .4byte 0x03001800
_08017908:
	ldrb r0, [r2]
	bl draw_battle_panel_left_a
_0801790E:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
