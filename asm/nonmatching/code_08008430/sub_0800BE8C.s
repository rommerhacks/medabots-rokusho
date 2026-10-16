	.syntax unified

	thumb_func_start sub_0800BE8C
sub_0800BE8C: @ 0x0800BE8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r2, _0800BEB4 @ =0x0300058C
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	ldr r7, _0800BEB8 @ =0x03000440
	cmp r0, #0
	beq _0800BEC0
	adds r3, r7, #0
	adds r3, #0x34
	ldrb r0, [r3]
	cmp r0, #0
	bne _0800BEBC
	movs r0, #2
	b _0800BEBE
	.align 2, 0
_0800BEB4: .4byte 0x0300058C
_0800BEB8: .4byte 0x03000440
_0800BEBC:
	subs r0, #1
_0800BEBE:
	strb r0, [r3]
_0800BEC0:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800BEDC
	adds r1, r7, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #2
	bne _0800BED8
	movs r0, #0
	b _0800BEDA
_0800BED8:
	adds r0, #1
_0800BEDA:
	strb r0, [r1]
_0800BEDC:
	adds r4, r7, #0
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r6, #0
	beq _0800BF08
	cmp r6, #1
	beq _0800BF84
	ldr r0, _0800BF04 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	bne _0800BEFA
	b _0800C024
_0800BEFA:
	movs r0, #0x18
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800C04E
	.align 2, 0
_0800BF04: .4byte 0x03001780
_0800BF08:
	ldr r0, _0800BF20 @ =0x03001780
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800BF24
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800BF4C
	.align 2, 0
_0800BF20: .4byte 0x03001780
_0800BF24:
	ldr r0, _0800BF7C @ =0x083ACA88
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
_0800BF4C:
	ldr r0, _0800BF7C @ =0x083ACA88
	mov sl, r0
	ldr r0, [r0, #4]
	ldr r4, _0800BF80 @ =0x030004DE
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
	b _0800BFF0
	.align 2, 0
_0800BF7C: .4byte 0x083ACA88
_0800BF80: .4byte 0x030004DE
_0800BF84:
	ldr r0, _0800BF9C @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800BFA0
	movs r0, #0x10
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800BFC6
	.align 2, 0
_0800BF9C: .4byte 0x03001780
_0800BFA0:
	ldr r0, _0800C01C @ =0x083ACA88
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
_0800BFC6:
	ldr r0, _0800C01C @ =0x083ACA88
	mov sl, r0
	ldr r0, [r0]
	ldr r4, _0800C020 @ =0x030004DE
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
_0800BFF0:
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
	b _0800C0A2
	.align 2, 0
_0800C01C: .4byte 0x083ACA88
_0800C020: .4byte 0x030004DE
_0800C024:
	ldr r0, _0800C0C4 @ =0x083ACA88
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
_0800C04E:
	ldr r0, _0800C0C4 @ =0x083ACA88
	mov sl, r0
	ldr r0, [r0, #4]
	ldr r4, _0800C0C8 @ =0x030004DE
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
_0800C0A2:
	ldr r2, _0800C0CC @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800C0D8
	ldr r0, _0800C0D0 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0x1d
	bne _0800C0D4
	movs r0, #0
	b _0800C0D6
	.align 2, 0
_0800C0C4: .4byte 0x083ACA88
_0800C0C8: .4byte 0x030004DE
_0800C0CC: .4byte 0x03001798
_0800C0D0: .4byte 0x03000440
_0800C0D4:
	adds r0, #1
_0800C0D6:
	strb r0, [r1]
_0800C0D8:
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800C100
	ldr r0, _0800C0F8 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800C0FC
	movs r0, #0x1d
	b _0800C0FE
	.align 2, 0
_0800C0F8: .4byte 0x03000440
_0800C0FC:
	subs r0, #1
_0800C0FE:
	strb r0, [r1]
_0800C100:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r7, _0800C1B0 @ =0x030004DE
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
	ldr r0, _0800C1B4 @ =0x03000477
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
	ldr r0, _0800C1B8 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0800C1C0
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800C1BC @ =0x0300137C
	mov r1, r8
	str r1, [r0]
	b _0800C27E
	.align 2, 0
_0800C1B0: .4byte 0x030004DE
_0800C1B4: .4byte 0x03000477
_0800C1B8: .4byte 0x0300058C
_0800C1BC: .4byte 0x0300137C
_0800C1C0:
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _0800C27E
	adds r4, r7, #0
	subs r4, #0x6a
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800C1E0
	cmp r0, #1
	beq _0800C224
	ldr r0, _0800C1DC @ =0x03000477
	strb r2, [r0]
	b _0800C240
	.align 2, 0
_0800C1DC: .4byte 0x03000477
_0800C1E0:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0x1d
	bhi _0800C27E
	bl find_medal_slot_by_id
	cmp r0, #0
	bne _0800C27E
	ldrb r0, [r4]
	add r0, sl
	ldrb r0, [r0]
	bl load_palette_entry
	adds r1, r0, #0
	lsls r1, r1, #0x18
	ldr r2, _0800C21C @ =0x083B6410
	ldrb r0, [r4]
	add r0, sl
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsrs r1, r1, #0x12
	ldr r2, _0800C220 @ =0x03000BEA
	adds r1, r1, r2
	movs r2, #0xb
	bl memcpy_bytes_0803F63C
	b _0800C27E
	.align 2, 0
_0800C21C: .4byte 0x083B6410
_0800C220: .4byte 0x03000BEA
_0800C224:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0x1d
	bhi _0800C27E
	bl find_medal_slot_by_id
	cmp r0, #0
	beq _0800C27E
	ldrb r0, [r4]
	add r0, sl
	ldrb r0, [r0]
	bl medal_remove_by_id
	b _0800C27E
_0800C240:
	ldr r0, _0800C290 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x37
	ldrb r0, [r4]
	bl find_medal_slot_by_id
	cmp r0, #0
	bne _0800C270
	ldrb r0, [r4]
	bl load_palette_entry
	adds r1, r0, #0
	lsls r1, r1, #0x18
	ldr r2, _0800C294 @ =0x083B6410
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsrs r1, r1, #0x12
	ldr r2, _0800C298 @ =0x03000BEA
	adds r1, r1, r2
	movs r2, #0xb
	bl memcpy_bytes_0803F63C
_0800C270:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1d
	bls _0800C240
_0800C27E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C290: .4byte 0x03000440
_0800C294: .4byte 0x083B6410
_0800C298: .4byte 0x03000BEA
	.syntax divided
