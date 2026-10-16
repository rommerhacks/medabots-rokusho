	.syntax unified

	thumb_func_start sub_0802463C
sub_0802463C: @ 0x0802463C
	push {r4, r5, lr}
	ldr r1, _08024664 @ =0x03000590
	ldr r2, _08024668 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x88
	ldrb r3, [r0]
	lsls r0, r3, #8
	adds r0, r0, r1
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0802466C
	adds r0, r3, #0
	movs r1, #0
	movs r2, #1
	bl battle_set_damage_vs_armor
	b _0802467C
	.align 2, 0
_08024664: .4byte 0x03000590
_08024668: .4byte 0x03001800
_0802466C:
	adds r0, r2, #0
	adds r0, #0xec
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r3, #0
	movs r1, #0
	bl battle_set_damage_vs_armor
_0802467C:
	ldr r4, _080246B8 @ =0x0300052E
	ldr r5, _080246BC @ =0x03001800
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	adds r0, r5, #0
	adds r0, #0x88
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0x21
	bl render_battle_text_sprites
	movs r0, #0x5b
	bl play_sound_effect
	subs r4, #0x6a
	movs r0, #0
	strb r0, [r4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080246B8: .4byte 0x0300052E
_080246BC: .4byte 0x03001800
	.syntax divided
