	.syntax unified

	thumb_func_start sub_0800C804
sub_0800C804: @ 0x0800C804
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r2, _0800C82C @ =0x0300058C
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	ldr r7, _0800C830 @ =0x03000440
	cmp r0, #0
	beq _0800C838
	adds r3, r7, #0
	adds r3, #0x34
	ldrb r0, [r3]
	cmp r0, #0
	bne _0800C834
	movs r0, #2
	b _0800C836
	.align 2, 0
_0800C82C: .4byte 0x0300058C
_0800C830: .4byte 0x03000440
_0800C834:
	subs r0, #1
_0800C836:
	strb r0, [r3]
_0800C838:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800C854
	adds r1, r7, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #2
	bne _0800C850
	movs r0, #0
	b _0800C852
_0800C850:
	adds r0, #1
_0800C852:
	strb r0, [r1]
_0800C854:
	adds r4, r7, #0
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r6, #0
	beq _0800C880
	cmp r6, #1
	beq _0800C8FC
	ldr r0, _0800C87C @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	bne _0800C872
	b _0800C99C
_0800C872:
	movs r0, #0x18
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800C9C6
	.align 2, 0
_0800C87C: .4byte 0x03001780
_0800C880:
	ldr r0, _0800C898 @ =0x03001780
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800C89C
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800C8C4
	.align 2, 0
_0800C898: .4byte 0x03001780
_0800C89C:
	ldr r0, _0800C8F4 @ =0x083ACADC
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800C8C4:
	ldr r0, _0800C8F4 @ =0x083ACADC
	mov sl, r0
	ldr r0, [r0, #4]
	ldr r4, _0800C8F8 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r1, #8
	mov sb, r1
	str r1, [sp]
	movs r0, #0xf
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #1
	str r6, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	b _0800C968
	.align 2, 0
_0800C8F4: .4byte 0x083ACADC
_0800C8F8: .4byte 0x030004DE
_0800C8FC:
	ldr r0, _0800C914 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800C918
	movs r0, #0x10
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800C93E
	.align 2, 0
_0800C914: .4byte 0x03001780
_0800C918:
	ldr r0, _0800C994 @ =0x083ACADC
	ldr r0, [r0, #4]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	bl render_text_sprites_08040DB8
_0800C93E:
	ldr r0, _0800C994 @ =0x083ACADC
	mov sl, r0
	ldr r0, [r0]
	ldr r4, _0800C998 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r1, #8
	mov sb, r1
	str r1, [sp]
	movs r0, #0xf
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #1
	str r6, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #2
_0800C968:
	bl render_text_sprites_08040DB8
	mov r1, sl
	ldr r0, [r1, #8]
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	mov r0, sb
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #2
	movs r3, #6
	bl render_text_sprites_08040DB8
	b _0800CA1A
	.align 2, 0
_0800C994: .4byte 0x083ACADC
_0800C998: .4byte 0x030004DE
_0800C99C:
	ldr r0, _0800CA3C @ =0x083ACADC
	ldr r0, [r0, #8]
	adds r4, r7, #0
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #2
	movs r3, #6
	bl render_text_sprites_08040DB8
_0800C9C6:
	ldr r0, _0800CA3C @ =0x083ACADC
	mov sl, r0
	ldr r0, [r0, #4]
	ldr r4, _0800CA40 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r1, #8
	mov sb, r1
	str r1, [sp]
	movs r0, #0xf
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #1
	str r6, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	bl render_text_sprites_08040DB8
	mov r1, sl
	ldr r0, [r1]
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	mov r0, sb
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800CA1A:
	ldr r2, _0800CA44 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800CA50
	ldr r0, _0800CA48 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0x3e
	bne _0800CA4C
	movs r0, #0
	b _0800CA4E
	.align 2, 0
_0800CA3C: .4byte 0x083ACADC
_0800CA40: .4byte 0x030004DE
_0800CA44: .4byte 0x03001798
_0800CA48: .4byte 0x03000440
_0800CA4C:
	adds r0, #1
_0800CA4E:
	strb r0, [r1]
_0800CA50:
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800CA78
	ldr r0, _0800CA70 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800CA74
	movs r0, #0x3e
	b _0800CA76
	.align 2, 0
_0800CA70: .4byte 0x03000440
_0800CA74:
	subs r0, #1
_0800CA76:
	strb r0, [r1]
_0800CA78:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r7, _0800CB28 @ =0x030004DE
	movs r0, #0x69
	rsbs r0, r0, #0
	adds r0, r0, r7
	mov sl, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl divide_by_100000_08041370
	movs r6, #3
	str r6, [sp]
	movs r5, #0xf
	str r5, [sp, #4]
	movs r1, #1
	mov r8, r1
	str r1, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	adds r0, r7, #0
	movs r1, #0x20
	movs r2, #8
	movs r3, #2
	bl render_text_sprites_08040DB8
	movs r0, #0x23
	movs r1, #3
	bl clear_battle_sprite_slot
	movs r0, #0x68
	rsbs r0, r0, #0
	adds r0, r0, r7
	mov sb, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl divide_by_100000_08041370
	str r6, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r7, #0
	movs r1, #0x23
	movs r2, #8
	movs r3, #4
	bl render_text_sprites_08040DB8
	movs r0, #0x26
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r0, _0800CB2C @ =0x03000477
	ldrb r1, [r0]
	adds r0, r7, #0
	bl divide_by_100000_08041370
	str r6, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r7, #0
	movs r1, #0x26
	movs r2, #8
	movs r3, #6
	bl render_text_sprites_08040DB8
	ldr r0, _0800CB30 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0800CB38
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800CB34 @ =0x0300137C
	mov r1, r8
	str r1, [r0]
	b _0800CB92
	.align 2, 0
_0800CB28: .4byte 0x030004DE
_0800CB2C: .4byte 0x03000477
_0800CB30: .4byte 0x0300058C
_0800CB34: .4byte 0x0300137C
_0800CB38:
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _0800CB92
	adds r0, r7, #0
	subs r0, #0x6a
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800CB58
	cmp r0, #1
	beq _0800CB68
	ldr r0, _0800CB54 @ =0x03000477
	strb r2, [r0]
	b _0800CB78
	.align 2, 0
_0800CB54: .4byte 0x03000477
_0800CB58:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _0800CB92
	movs r1, #1
	bl sub_080422B8
	b _0800CB92
_0800CB68:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _0800CB92
	movs r1, #1
	bl sub_08042318
	b _0800CB92
_0800CB78:
	ldr r4, _0800CBA4 @ =0x03000440
	adds r4, #0x37
	ldrb r0, [r4]
	movs r1, #1
	bl sub_080422B8
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3e
	bls _0800CB78
_0800CB92:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800CBA4: .4byte 0x03000440
	.syntax divided
