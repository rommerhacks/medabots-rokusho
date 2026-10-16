	.syntax unified

	thumb_func_start init_battle_bot_display_digits
init_battle_bot_display_digits: @ 0x08029C64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r4, #0
	ldr r5, _08029C9C @ =0x03001800
	ldr r7, _08029CA0 @ =0x030004DE
	movs r0, #0x14
	adds r0, r0, r7
	mov sb, r0
	adds r6, r5, #0
	adds r6, #0x60
	movs r0, #0x28
	adds r0, r0, r7
	mov r8, r0
_08029C82:
	adds r0, r5, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029CF4
	cmp r4, #1
	beq _08029CBE
	cmp r4, #1
	blo _08029CA4
	cmp r4, #2
	beq _08029CDA
	b _08029CF4
	.align 2, 0
_08029C9C: .4byte 0x03001800
_08029CA0: .4byte 0x030004DE
_08029CA4:
	lsls r0, r4, #1
	adds r1, r5, #0
	adds r1, #0xd6
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	movs r2, #0
	bl set_display_digit_type
	ldrb r1, [r6]
	adds r1, r1, r4
	adds r0, r7, #0
	b _08029CD2
_08029CBE:
	adds r0, r5, #0
	adds r0, #0xd8
	ldrh r1, [r0]
	mov r0, sb
	movs r2, #0
	bl set_display_digit_type
	ldrb r1, [r6]
	adds r1, #1
	mov r0, sb
_08029CD2:
	movs r2, #0x21
	bl render_battle_text_sprites
	b _08029CF4
_08029CDA:
	adds r0, r5, #0
	adds r0, #0xda
	ldrh r1, [r0]
	mov r0, r8
	movs r2, #0
	bl set_display_digit_type
	ldrb r1, [r6]
	adds r1, #2
	mov r0, r8
	movs r2, #0x21
	bl render_battle_text_sprites
_08029CF4:
	adds r4, #1
	cmp r4, #2
	bls _08029C82
	movs r0, #0x5b
	bl play_sound_effect
	ldr r0, _08029D20 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08029D24 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029D20: .4byte 0x03000440
_08029D24: .4byte 0x03001800
	.syntax divided
