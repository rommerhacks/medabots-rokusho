	.syntax unified

	thumb_func_start sub_0801CA60
sub_0801CA60: @ 0x0801CA60
	push {r4, r5, lr}
	ldr r4, _0801CAA0 @ =0x0300052E
	ldr r5, _0801CAA4 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	adds r0, r5, #0
	adds r0, #0x87
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
_0801CAA0: .4byte 0x0300052E
_0801CAA4: .4byte 0x03001800
	.syntax divided
