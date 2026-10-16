	.syntax unified

	thumb_func_start battle_loss_take_part
battle_loss_take_part: @ 0x08011C88
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08011CAC @ =0x030057E0
	ldr r1, _08011CB0 @ =0x00000C2E
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08011CB8
	movs r0, #0
	strb r0, [r2]
	ldr r1, _08011CB4 @ =0x0300137C
	movs r0, #0x40
	b _08011CE4
	.align 2, 0
_08011CAC: .4byte 0x030057E0
_08011CB0: .4byte 0x00000C2E
_08011CB4: .4byte 0x0300137C
_08011CB8:
	movs r0, #0
	bl sub_080122F4
	ldr r1, _08011CEC @ =0x03000590
	ldr r2, _08011CF0 @ =0x03001800
	ldr r3, _08011CF4 @ =0x00000187
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0x47
	ldrb r0, [r0]
	subs r3, #0x1f
	adds r1, r2, r3
	ldrb r1, [r1]
	bl sub_080421B4
	bl sub_0803FB0C
	ldr r1, _08011CF8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_08011CE4:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011CEC: .4byte 0x03000590
_08011CF0: .4byte 0x03001800
_08011CF4: .4byte 0x00000187
_08011CF8: .4byte 0x0300137C
	.syntax divided
