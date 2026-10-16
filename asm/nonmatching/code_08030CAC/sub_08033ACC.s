	.syntax unified

	thumb_func_start sub_08033ACC
sub_08033ACC: @ 0x08033ACC
	push {r4, r5, lr}
	ldr r0, _08033B74 @ =0x03001800
	adds r5, r0, #0
	adds r5, #0xde
	ldrb r0, [r5]
	cmp r0, #0
	beq _08033B68
	ldr r4, _08033B78 @ =0x03003470
	adds r1, r0, #0
	subs r1, #1
	lsls r1, r1, #8
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r0, r4, r2
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r4, #0
	adds r0, #0x40
	ldrb r1, [r5]
	subs r1, #1
	lsls r1, r1, #8
	movs r3, #0xe8
	lsls r3, r3, #4
	adds r2, r4, r3
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r4, #0
	adds r0, #0x80
	ldrb r1, [r5]
	subs r1, #1
	lsls r1, r1, #8
	movs r3, #0xec
	lsls r3, r3, #4
	adds r2, r4, r3
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r1, [r5]
	subs r1, #1
	lsls r1, r1, #8
	movs r2, #0xf0
	lsls r2, r2, #4
	adds r4, r4, r2
	adds r1, r1, r4
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	movs r0, #0x21
	movs r1, #4
	bl clear_battle_sprite_slot
	ldrb r0, [r5]
	lsls r0, r0, #0x1a
	movs r3, #0xac
	lsls r3, r3, #0x17
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	movs r1, #4
	bl set_sprite_hidden_flags
	ldrb r0, [r5]
	subs r0, #1
	bl init_battle_sprite_entry_0801BC04
	movs r0, #0
	strb r0, [r5]
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
_08033B68:
	bl sub_08034F08
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08033B74: .4byte 0x03001800
_08033B78: .4byte 0x03003470
	.syntax divided
