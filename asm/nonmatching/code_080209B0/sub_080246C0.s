	.syntax unified

	thumb_func_start sub_080246C0
sub_080246C0: @ 0x080246C0
	push {r4, lr}
	ldr r4, _0802472C @ =0x0300052E
	ldr r0, _08024730 @ =0x03001800
	adds r0, #0x88
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0x21
	bl update_battle_sprite_animations
	adds r3, r4, #0
	subs r3, #0x6a
	ldrb r0, [r3]
	adds r2, r0, #1
	strb r2, [r3]
	subs r4, #0x65
	ldrb r0, [r4]
	cmp r0, #0
	bne _080246FC
	ldr r0, _08024734 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080246FC
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x32
	bls _080246FC
	movs r0, #0x78
	strb r0, [r3]
_080246FC:
	ldr r0, _08024738 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0x78
	bne _08024726
	ldr r4, _08024730 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	movs r1, #0x84
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_battle_sprite_slot
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08024726:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802472C: .4byte 0x0300052E
_08024730: .4byte 0x03001800
_08024734: .4byte 0x03001798
_08024738: .4byte 0x03000440
	.syntax divided
