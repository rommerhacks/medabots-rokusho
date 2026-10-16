	.syntax unified

	thumb_func_start handle_options_menu_input
handle_options_menu_input: @ 0x0800C6F8
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r0, _0800C714 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800C718
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800C740
	.align 2, 0
_0800C714: .4byte 0x03001780
_0800C718:
	ldr r0, _0800C7AC @ =0x083ACAC0
	ldr r0, [r0]
	ldr r4, _0800C7B0 @ =0x030004DE
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
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800C740:
	ldr r0, _0800C7B4 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0800C760
	ldr r0, _0800C7B8 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_0800C760:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r4, _0800C7B0 @ =0x030004DE
	adds r6, r4, #0
	subs r6, #0x69
	ldrb r1, [r6]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	movs r0, #3
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r5, #1
	str r5, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x20
	movs r2, #8
	movs r3, #2
	bl render_text_sprites_08040DB8
	ldr r0, _0800C7BC @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800C7C4
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800C7C0 @ =0x0300137C
	str r5, [r0]
	b _0800C7DA
	.align 2, 0
_0800C7AC: .4byte 0x083ACAC0
_0800C7B0: .4byte 0x030004DE
_0800C7B4: .4byte 0x03001798
_0800C7B8: .4byte 0x03000440
_0800C7BC: .4byte 0x0300058C
_0800C7C0: .4byte 0x0300137C
_0800C7C4:
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0800C7DA
	bl sub_08042218
	cmp r0, #0
	bne _0800C7DA
	ldrb r0, [r6]
	bl add_position_entry
_0800C7DA:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
