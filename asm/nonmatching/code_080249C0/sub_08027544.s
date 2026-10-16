	.syntax unified

	thumb_func_start sub_08027544
sub_08027544: @ 0x08027544
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0
	ldr r6, _08027588 @ =0x03001800
	adds r7, r6, #0
	adds r7, #0x60
	movs r0, #0xda
	adds r0, r0, r6
	mov sl, r0
	ldr r1, _0802758C @ =0x030004DE
	mov r8, r1
	movs r0, #0x14
	add r0, r8
	mov sb, r0
_08027566:
	ldrb r0, [r7]
	adds r0, r0, r5
	lsls r0, r0, #8
	ldr r1, _08027590 @ =0x03000590
	adds r0, r0, r1
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080275E4
	cmp r5, #1
	beq _080275AE
	cmp r5, #1
	blo _08027594
	cmp r5, #2
	beq _080275CA
	b _080275E4
	.align 2, 0
_08027588: .4byte 0x03001800
_0802758C: .4byte 0x030004DE
_08027590: .4byte 0x03000590
_08027594:
	lsls r0, r5, #1
	adds r1, r6, #0
	adds r1, #0xd6
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r0, r8
	movs r2, #1
	bl set_display_digit_type
	ldrb r1, [r7]
	adds r1, r1, r5
	mov r0, r8
	b _080275C2
_080275AE:
	adds r0, r6, #0
	adds r0, #0xd8
	ldrh r1, [r0]
	mov r0, sb
	movs r2, #1
	bl set_display_digit_type
	ldrb r1, [r7]
	adds r1, #1
	mov r0, sb
_080275C2:
	movs r2, #0x21
	bl render_battle_text_sprites
	b _080275E4
_080275CA:
	ldr r4, _08027610 @ =0x03000506
	mov r0, sl
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	ldrb r1, [r7]
	adds r1, #2
	adds r0, r4, #0
	movs r2, #0x21
	bl render_battle_text_sprites
_080275E4:
	adds r5, #1
	cmp r5, #2
	bls _08027566
	movs r0, #0x5b
	bl play_sound_effect
	ldr r0, _08027614 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08027618 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027610: .4byte 0x03000506
_08027614: .4byte 0x03000440
_08027618: .4byte 0x03001800
	.syntax divided
