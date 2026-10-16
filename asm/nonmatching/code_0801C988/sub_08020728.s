	.syntax unified

	thumb_func_start sub_08020728
sub_08020728: @ 0x08020728
	push {r4, r5, r6, lr}
	ldr r4, _08020764 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x87
	ldrb r0, [r6]
	adds r5, r4, #0
	adds r5, #0xa7
	ldrb r1, [r5]
	movs r2, #0xff
	bl reduce_bot_part_stat
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
	ldrb r0, [r5]
	cmp r0, #0
	bne _08020752
	ldrb r0, [r6]
	bl add_bot_to_defeated_list
_08020752:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08020764: .4byte 0x03001800
	.syntax divided
