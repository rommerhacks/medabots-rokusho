	.syntax unified

	thumb_func_start sub_08013438
sub_08013438: @ 0x08013438
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r0, _080134C8 @ =0x03001800
	adds r6, r0, #0
	adds r6, #0x80
	ldrb r0, [r6]
	bl animate_battle_sprites
	ldrb r1, [r6]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldr r7, _080134CC @ =0x03000440
	adds r5, r7, #0
	adds r5, #0x84
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	strb r0, [r5]
	bl sub_0801767C
	bl sub_080175FC
	movs r0, #1
	bl sub_080173B4
	ldr r0, _080134D0 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080134DC
	movs r0, #5
	bl play_sound_effect
	ldr r0, _080134D4 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #8
	movs r1, #1
	movs r2, #1
	movs r3, #0x11
	bl vram_fill_tilemap_rect
	ldrb r0, [r6]
	bl render_bot_cash_display
	movs r0, #0
	movs r1, #5
	bl clear_battle_sprite_slot
	movs r0, #0x14
	movs r1, #0x24
	bl clear_battle_sprite_slot
	mov r1, r8
	strb r1, [r5]
	ldr r1, _080134D8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080134F4
	.align 2, 0
_080134C8: .4byte 0x03001800
_080134CC: .4byte 0x03000440
_080134D0: .4byte 0x0300058C
_080134D4: .4byte 0x04000008
_080134D8: .4byte 0x0300137C
_080134DC:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080134F6
	movs r0, #4
	bl play_sound_effect
	adds r0, r7, #0
	adds r0, #0x86
	strh r4, [r0]
	ldr r1, _08013504 @ =0x0300137C
	movs r0, #0x1d
_080134F4:
	str r0, [r1]
_080134F6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013504: .4byte 0x0300137C
	.syntax divided
