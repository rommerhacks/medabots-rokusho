	.syntax unified

	thumb_func_start apply_battle_damage_and_render
apply_battle_damage_and_render: @ 0x0802D3D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r5, #0
	ldr r7, _0802D41C @ =0x03001800
	adds r6, r7, #0
	adds r6, #0x60
	movs r0, #0xec
	adds r0, r0, r7
	mov sb, r0
	ldr r1, _0802D420 @ =0x030004DE
	mov r8, r1
_0802D3EE:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D4A0
	ldr r1, _0802D424 @ =0x03000590
	ldrb r0, [r6]
	adds r3, r0, r5
	lsls r0, r3, #8
	adds r0, r0, r1
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0802D428
	adds r0, r3, #0
	movs r1, #0
	movs r2, #1
	bl battle_set_damage_vs_armor
	b _0802D436
	.align 2, 0
_0802D41C: .4byte 0x03001800
_0802D420: .4byte 0x030004DE
_0802D424: .4byte 0x03000590
_0802D428:
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r3, #0
	movs r1, #0
	bl battle_set_damage_vs_armor
_0802D436:
	ldr r2, _0802D454 @ =0x03001800
	lsls r1, r5, #1
	adds r0, r2, #0
	adds r0, #0xd6
	adds r1, r1, r0
	adds r2, #0xc8
	ldrh r0, [r2]
	strh r0, [r1]
	cmp r5, #1
	beq _0802D46A
	cmp r5, #1
	blo _0802D458
	cmp r5, #2
	beq _0802D488
	b _0802D4A0
	.align 2, 0
_0802D454: .4byte 0x03001800
_0802D458:
	ldrh r1, [r2]
	mov r0, r8
	movs r2, #1
	bl set_display_digit_type
	ldrb r1, [r6]
	adds r1, r1, r5
	mov r0, r8
	b _0802D47C
_0802D46A:
	ldr r4, _0802D484 @ =0x030004F2
	ldrh r1, [r2]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	ldrb r1, [r6]
	adds r1, #1
	adds r0, r4, #0
_0802D47C:
	movs r2, #0x21
	bl render_battle_text_sprites
	b _0802D4A0
	.align 2, 0
_0802D484: .4byte 0x030004F2
_0802D488:
	ldr r4, _0802D4CC @ =0x03000506
	ldrh r1, [r2]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	ldrb r1, [r6]
	adds r1, #2
	adds r0, r4, #0
	movs r2, #0x21
	bl render_battle_text_sprites
_0802D4A0:
	adds r5, #1
	cmp r5, #2
	bls _0802D3EE
	movs r0, #0x5b
	bl play_sound_effect
	ldr r0, _0802D4D0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0802D4D4 @ =0x03001800
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
_0802D4CC: .4byte 0x03000506
_0802D4D0: .4byte 0x03000440
_0802D4D4: .4byte 0x03001800
	.syntax divided
