	.syntax unified

	thumb_func_start sub_08038650
sub_08038650: @ 0x08038650
	push {r4, r5, r6, lr}
	ldr r0, _080386EC @ =0x03000440
	ldr r1, _080386F0 @ =0x0000012F
	adds r5, r0, r1
	ldrb r0, [r5]
	bl move_sprite_toward_target
	cmp r0, #0
	beq _080386E4
	ldr r6, _080386F4 @ =0x083B5F80
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	ldrb r1, [r5]
	bl init_battle_sprite_entry_08040B90
	ldr r4, _080386F8 @ =0x03002C30
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	movs r2, #0
	movs r1, #6
	strb r1, [r0, #0xa]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x28
	strb r2, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x29
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r1, [r5]
	lsls r1, r1, #6
	adds r0, r1, r4
	adds r2, r4, #0
	adds r2, #0xc0
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	ldrb r1, [r5]
	adds r1, #3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	ldrb r0, [r5]
	adds r2, r0, #3
	lsls r2, r2, #6
	adds r2, r2, r4
	ldr r1, _080386FC @ =0x03001800
	adds r1, #0x60
	adds r0, #0xdf
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x59
	strb r0, [r2, #0xb]
	ldrb r0, [r5]
	adds r0, #3
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x29
	movs r1, #3
	strb r1, [r0]
_080386E4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080386EC: .4byte 0x03000440
_080386F0: .4byte 0x0000012F
_080386F4: .4byte 0x083B5F80
_080386F8: .4byte 0x03002C30
_080386FC: .4byte 0x03001800
	.syntax divided
