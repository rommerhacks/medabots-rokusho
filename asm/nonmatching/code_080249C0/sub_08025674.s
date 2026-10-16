	.syntax unified

	thumb_func_start sub_08025674
sub_08025674: @ 0x08025674
	push {r4, r5, r6, lr}
	ldr r0, _080256DC @ =0x084D6BFC
	ldr r1, _080256E0 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r4, _080256E4 @ =0x0300052E
	ldr r6, _080256E8 @ =0x03001800
	adds r0, r6, #0
	adds r0, #0x51
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	adds r0, r6, #0
	adds r0, #0x88
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0x21
	bl battle_setup_text_sprites_0801A418
	adds r5, r4, #0
	adds r5, #0x20
	adds r0, r6, #0
	adds r0, #0x52
	ldrb r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl set_display_digit_type
	adds r0, r6, #0
	adds r0, #0x87
	ldrb r1, [r0]
	adds r0, r5, #0
	movs r2, #0x21
	bl battle_setup_text_sprites_0801A418
	movs r0, #0x5b
	bl play_sound_effect
	subs r4, #0x6a
	movs r0, #0
	strb r0, [r4]
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080256DC: .4byte 0x084D6BFC
_080256E0: .4byte 0x06017E00
_080256E4: .4byte 0x0300052E
_080256E8: .4byte 0x03001800
	.syntax divided
