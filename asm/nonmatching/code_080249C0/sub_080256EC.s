	.syntax unified

	thumb_func_start sub_080256EC
sub_080256EC: @ 0x080256EC
	push {r4, r5, lr}
	ldr r5, _08025780 @ =0x0300052E
	ldr r4, _08025784 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r1, [r0]
	adds r0, r5, #0
	movs r2, #0x21
	bl update_battle_sprite_animations
	adds r0, r5, #0
	adds r0, #0x20
	adds r4, #0x87
	ldrb r1, [r4]
	movs r2, #0x21
	bl update_battle_sprite_animations
	adds r3, r5, #0
	subs r3, #0x6a
	ldrb r0, [r3]
	adds r2, r0, #1
	strb r2, [r3]
	subs r5, #0x65
	ldrb r0, [r5]
	cmp r0, #0
	bne _08025738
	ldr r0, _08025788 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08025738
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x32
	bls _08025738
	movs r0, #0x78
	strb r0, [r3]
_08025738:
	ldr r0, _0802578C @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0x78
	bne _0802577A
	ldr r4, _08025784 @ =0x03001800
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
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	movs r1, #0x84
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_battle_sprite_slot
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802577A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08025780: .4byte 0x0300052E
_08025784: .4byte 0x03001800
_08025788: .4byte 0x03001798
_0802578C: .4byte 0x03000440
	.syntax divided
