	.syntax unified

	thumb_func_start sub_08022F50
sub_08022F50: @ 0x08022F50
	push {r4, r5, r6, lr}
	ldr r5, _08022FAC @ =0x03000590
	ldr r6, _08022FB0 @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0x40
	movs r1, #3
	strb r1, [r0]
	ldrb r0, [r4]
	adds r1, r6, #0
	adds r1, #0xec
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #0
	bl battle_calc_damage_split
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r1, r6, #0
	adds r1, #0xc8
	ldrh r1, [r1]
	adds r0, #0x59
	strb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xba
	movs r1, #1
	strb r1, [r0]
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08022FAC: .4byte 0x03000590
_08022FB0: .4byte 0x03001800
	.syntax divided
