	.syntax unified

	thumb_func_start sub_0802A5C0
sub_0802A5C0: @ 0x0802A5C0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0802A600 @ =0x084D6BFC
	ldr r1, _0802A604 @ =0x06017E00
	bl lz_decompress_dispatch
	movs r4, #0
	ldr r5, _0802A608 @ =0x03001800
	ldr r7, _0802A60C @ =0x030004DE
	movs r0, #0x14
	adds r0, r0, r7
	mov sb, r0
	adds r6, r5, #0
	adds r6, #0x60
	movs r0, #0x28
	adds r0, r0, r7
	mov r8, r0
_0802A5E6:
	adds r0, r5, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A660
	cmp r4, #1
	beq _0802A62A
	cmp r4, #1
	blo _0802A610
	cmp r4, #2
	beq _0802A646
	b _0802A660
	.align 2, 0
_0802A600: .4byte 0x084D6BFC
_0802A604: .4byte 0x06017E00
_0802A608: .4byte 0x03001800
_0802A60C: .4byte 0x030004DE
_0802A610:
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
	b _0802A63E
_0802A62A:
	adds r0, r5, #0
	adds r0, #0xd8
	ldrh r1, [r0]
	mov r0, sb
	movs r2, #0
	bl set_display_digit_type
	ldrb r1, [r6]
	adds r1, #1
	mov r0, sb
_0802A63E:
	movs r2, #0x21
	bl battle_setup_text_sprites_0801A418
	b _0802A660
_0802A646:
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
	bl battle_setup_text_sprites_0801A418
_0802A660:
	adds r4, #1
	cmp r4, #2
	bls _0802A5E6
	movs r0, #0x5b
	bl play_sound_effect
	ldr r0, _0802A68C @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0802A690 @ =0x03001800
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
_0802A68C: .4byte 0x03000440
_0802A690: .4byte 0x03001800
_0802A694:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x54, 0x20, 0x10, 0x70, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
