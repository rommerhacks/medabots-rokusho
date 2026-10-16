	.syntax unified

	thumb_func_start sub_08014920
sub_08014920: @ 0x08014920
	push {r4, r5, lr}
	bl update_all_battle_status_sprites
	bl iterate_bots_setup_battle_sprites
	movs r4, #0
	ldr r5, _08014984 @ =0x0300052E
_0801492E:
	ldr r1, _08014988 @ =0x03000590
	lsls r0, r4, #8
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08014962
	adds r0, r2, #0
	adds r0, #0xce
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08014962
	adds r0, r2, #0
	adds r0, #0xcd
	ldrb r1, [r0]
	adds r0, r5, #0
	movs r2, #1
	bl set_display_digit_type
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_0801A144
_08014962:
	adds r4, #1
	cmp r4, #5
	bls _0801492E
	movs r0, #0x5b
	bl play_sound_effect
	ldr r0, _0801498C @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08014990 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014984: .4byte 0x0300052E
_08014988: .4byte 0x03000590
_0801498C: .4byte 0x03000440
_08014990: .4byte 0x0300137C
	.syntax divided
