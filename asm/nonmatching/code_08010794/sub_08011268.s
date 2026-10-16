	.syntax unified

	thumb_func_start sub_08011268
sub_08011268: @ 0x08011268
	push {r4, lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r1, _0801128C @ =0x03001800
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r3, r1, r0
	ldrb r0, [r3]
	cmp r0, #3
	bne _08011294
	movs r0, #0
	strb r0, [r3]
	ldr r1, _08011290 @ =0x0300137C
	movs r0, #0x58
	str r0, [r1]
	b _080112BC
	.align 2, 0
_0801128C: .4byte 0x03001800
_08011290: .4byte 0x0300137C
_08011294:
	ldrb r2, [r3]
	lsls r0, r2, #3
	ldr r4, _080112B0 @ =0x0000016F
	adds r1, r1, r4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080112B8
	ldr r1, _080112B4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _080112BC
	.align 2, 0
_080112B0: .4byte 0x0000016F
_080112B4: .4byte 0x0300137C
_080112B8:
	adds r0, r2, #1
	strb r0, [r3]
_080112BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
