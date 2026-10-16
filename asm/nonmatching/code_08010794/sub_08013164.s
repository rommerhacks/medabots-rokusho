	.syntax unified

	thumb_func_start sub_08013164
sub_08013164: @ 0x08013164
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r4, _080131E8 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl sub_0801B9C4
	ldr r6, _080131EC @ =0x03000440
	adds r5, r6, #0
	adds r5, #0x84
	ldrb r0, [r5]
	adds r0, #1
	movs r7, #0
	strb r0, [r5]
	bl sub_080168F4
	bl sub_080169AC
	bl sub_08016C0C
	ldr r0, _080131F0 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080131FC
	movs r0, #5
	bl play_sound_effect
	movs r0, #0
	movs r1, #6
	bl clear_battle_sprite_slot
	bl sub_0801BACC
	movs r0, #0x14
	movs r1, #0x26
	bl clear_battle_sprite_slot
	ldr r0, _080131F4 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #7
	movs r1, #1
	movs r2, #0xe
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	strb r7, [r5]
	ldr r1, _080131F8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08013218
	.align 2, 0
_080131E8: .4byte 0x03001800
_080131EC: .4byte 0x03000440
_080131F0: .4byte 0x0300058C
_080131F4: .4byte 0x04000008
_080131F8: .4byte 0x0300137C
_080131FC:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801321A
	movs r0, #4
	bl play_sound_effect
	bl sub_0801BACC
	adds r0, r6, #0
	adds r0, #0x86
	strh r4, [r0]
	ldr r1, _08013224 @ =0x0300137C
	movs r0, #0x15
_08013218:
	str r0, [r1]
_0801321A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013224: .4byte 0x0300137C
	.syntax divided
