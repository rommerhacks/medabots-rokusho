	.syntax unified

	thumb_func_start sub_08024538
sub_08024538: @ 0x08024538
	push {r4, r5, r6, lr}
	movs r4, #0
_0802453C:
	adds r0, r4, #0
	adds r0, #0x26
	bl update_sprite_animation_position
	adds r4, #1
	cmp r4, #3
	bls _0802453C
	ldr r0, _08024620 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #0x10
	bne _08024630
	movs r0, #0x26
	movs r1, #4
	bl clear_battle_sprite_slot
	ldr r4, _08024624 @ =0x030034B0
	ldr r6, _08024628 @ =0x03001800
	adds r5, r6, #0
	adds r5, #0x88
	ldrb r1, [r5]
	lsls r1, r1, #8
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r4, r2
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r4, #0
	adds r0, #0x40
	ldrb r1, [r5]
	lsls r1, r1, #8
	movs r3, #0xe4
	lsls r3, r3, #4
	adds r2, r4, r3
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r4, #0
	adds r0, #0x80
	ldrb r1, [r5]
	lsls r1, r1, #8
	movs r3, #0xe8
	lsls r3, r3, #4
	adds r2, r4, r3
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r1, [r5]
	lsls r1, r1, #8
	movs r3, #0xec
	lsls r3, r3, #4
	adds r2, r4, r3
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldr r0, _0802462C @ =0xFFFFF780
	adds r4, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0xb4
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0xb6
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r3, #0xb8
	lsls r3, r3, #5
	adds r0, r0, r3
	adds r0, r0, r4
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	movs r0, #0x21
	movs r1, #4
	bl clear_battle_sprite_slot
	adds r6, #0xaa
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _08024634
	.align 2, 0
_08024620: .4byte 0x03000440
_08024624: .4byte 0x030034B0
_08024628: .4byte 0x03001800
_0802462C: .4byte 0xFFFFF780
_08024630:
	adds r0, #1
	strb r0, [r1]
_08024634:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
