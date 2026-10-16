	.syntax unified

	thumb_func_start menu_tab_select_handler_b
menu_tab_select_handler_b: @ 0x0800C2BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r2, _0800C2E4 @ =0x0300058C
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	ldr r7, _0800C2E8 @ =0x03000440
	cmp r0, #0
	beq _0800C2F0
	adds r3, r7, #0
	adds r3, #0x34
	ldrb r0, [r3]
	cmp r0, #0
	bne _0800C2EC
	movs r0, #2
	b _0800C2EE
	.align 2, 0
_0800C2E4: .4byte 0x0300058C
_0800C2E8: .4byte 0x03000440
_0800C2EC:
	subs r0, #1
_0800C2EE:
	strb r0, [r3]
_0800C2F0:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800C30C
	adds r1, r7, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #2
	bne _0800C308
	movs r0, #0
	b _0800C30A
_0800C308:
	adds r0, #1
_0800C30A:
	strb r0, [r1]
_0800C30C:
	adds r4, r7, #0
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r6, #0
	beq _0800C338
	cmp r6, #1
	beq _0800C3B4
	ldr r0, _0800C334 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	bne _0800C32A
	b _0800C454
_0800C32A:
	movs r0, #0x18
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800C47E
	.align 2, 0
_0800C334: .4byte 0x03001780
_0800C338:
	ldr r0, _0800C350 @ =0x03001780
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800C354
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800C37C
	.align 2, 0
_0800C350: .4byte 0x03001780
_0800C354:
	ldr r0, _0800C3AC @ =0x083ACAAC
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
_0800C37C:
	ldr r0, _0800C3AC @ =0x083ACAAC
	mov sl, r0
	ldr r0, [r0, #4]
	ldr r4, _0800C3B0 @ =0x030004DE
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
	b _0800C420
	.align 2, 0
_0800C3AC: .4byte 0x083ACAAC
_0800C3B0: .4byte 0x030004DE
_0800C3B4:
	ldr r0, _0800C3CC @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800C3D0
	movs r0, #0x10
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800C3F6
	.align 2, 0
_0800C3CC: .4byte 0x03001780
_0800C3D0:
	ldr r0, _0800C44C @ =0x083ACAAC
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
_0800C3F6:
	ldr r0, _0800C44C @ =0x083ACAAC
	mov sl, r0
	ldr r0, [r0]
	ldr r4, _0800C450 @ =0x030004DE
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
_0800C420:
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
	b _0800C4D2
	.align 2, 0
_0800C44C: .4byte 0x083ACAAC
_0800C450: .4byte 0x030004DE
_0800C454:
	ldr r0, _0800C4F4 @ =0x083ACAAC
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
_0800C47E:
	ldr r0, _0800C4F4 @ =0x083ACAAC
	mov sl, r0
	ldr r0, [r0, #4]
	ldr r4, _0800C4F8 @ =0x030004DE
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
_0800C4D2:
	ldr r2, _0800C4FC @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800C508
	ldr r0, _0800C500 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0x77
	bne _0800C504
	movs r0, #0
	b _0800C506
	.align 2, 0
_0800C4F4: .4byte 0x083ACAAC
_0800C4F8: .4byte 0x030004DE
_0800C4FC: .4byte 0x03001798
_0800C500: .4byte 0x03000440
_0800C504:
	adds r0, #1
_0800C506:
	strb r0, [r1]
_0800C508:
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800C530
	ldr r0, _0800C528 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800C52C
	movs r0, #0x77
	b _0800C52E
	.align 2, 0
_0800C528: .4byte 0x03000440
_0800C52C:
	subs r0, #1
_0800C52E:
	strb r0, [r1]
_0800C530:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r7, _0800C5E0 @ =0x030004DE
	movs r0, #0x69
	rsbs r0, r0, #0
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl divide_by_100000_08041370
	movs r6, #3
	str r6, [sp]
	movs r5, #0xf
	str r5, [sp, #4]
	movs r1, #1
	mov sb, r1
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
	mov sl, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl divide_by_100000_08041370
	str r6, [sp]
	str r5, [sp, #4]
	mov r1, sb
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
	ldr r0, _0800C5E4 @ =0x03000477
	ldrb r1, [r0]
	adds r0, r7, #0
	bl divide_by_100000_08041370
	str r6, [sp]
	str r5, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r7, #0
	movs r1, #0x26
	movs r2, #8
	movs r3, #6
	bl render_text_sprites_08040DB8
	ldr r0, _0800C5E8 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0800C5F0
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800C5EC @ =0x0300137C
	mov r1, sb
	str r1, [r0]
	b _0800C6C2
	.align 2, 0
_0800C5E0: .4byte 0x030004DE
_0800C5E4: .4byte 0x03000477
_0800C5E8: .4byte 0x0300058C
_0800C5EC: .4byte 0x0300137C
_0800C5F0:
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0800C6C2
	adds r4, r7, #0
	subs r4, #0x6a
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800C610
	cmp r0, #1
	beq _0800C64C
	ldr r0, _0800C60C @ =0x03000477
	strb r2, [r0]
	b _0800C688
	.align 2, 0
_0800C60C: .4byte 0x03000477
_0800C610:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0x77
	bhi _0800C6C2
	movs r1, #0
	movs r2, #1
	bl medapart_add_quantity
	ldrb r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #1
	movs r2, #1
	bl medapart_add_quantity
	ldrb r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #2
	movs r2, #1
	bl medapart_add_quantity
	ldrb r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #3
	movs r2, #1
	bl medapart_add_quantity
	b _0800C6C2
_0800C64C:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0x77
	bhi _0800C6C2
	movs r1, #0
	movs r2, #1
	bl reduce_medapart_stat
	ldrb r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #1
	movs r2, #1
	bl reduce_medapart_stat
	ldrb r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #2
	movs r2, #1
	bl reduce_medapart_stat
	ldrb r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #3
	movs r2, #1
	bl reduce_medapart_stat
	b _0800C6C2
_0800C688:
	ldr r4, _0800C6D4 @ =0x03000440
	adds r4, #0x37
	ldrb r0, [r4]
	movs r1, #0
	movs r2, #1
	bl medapart_add_quantity
	ldrb r0, [r4]
	movs r1, #1
	movs r2, #1
	bl medapart_add_quantity
	ldrb r0, [r4]
	movs r1, #2
	movs r2, #1
	bl medapart_add_quantity
	ldrb r0, [r4]
	movs r1, #3
	movs r2, #1
	bl medapart_add_quantity
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x77
	bls _0800C688
_0800C6C2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C6D4: .4byte 0x03000440
	.syntax divided
