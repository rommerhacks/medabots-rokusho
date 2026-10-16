	.syntax unified

	thumb_func_start sub_0800CBC8
sub_0800CBC8: @ 0x0800CBC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0800CC08 @ =0x0300058C
	ldr r0, [r0]
	lsls r1, r0, #0x19
	lsrs r1, r1, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1f
	orrs r1, r0
	ldr r4, _0800CC0C @ =0x03000440
	cmp r1, #0
	beq _0800CBF4
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_0800CBF4:
	adds r2, r4, #0
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r6, #0
	beq _0800CC10
	cmp r6, #1
	beq _0800CC8C
	b _0800CCF8
	.align 2, 0
_0800CC08: .4byte 0x0300058C
_0800CC0C: .4byte 0x03000440
_0800CC10:
	ldr r0, _0800CC28 @ =0x03001780
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800CC2C
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800CC56
	.align 2, 0
_0800CC28: .4byte 0x03001780
_0800CC2C:
	ldr r0, _0800CC84 @ =0x083ACAF8
	ldr r0, [r0]
	adds r4, r2, #0
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
_0800CC56:
	ldr r0, _0800CC84 @ =0x083ACAF8
	ldr r0, [r0, #4]
	ldr r4, _0800CC88 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	bl render_text_sprites_08040DB8
	b _0800CCF8
	.align 2, 0
_0800CC84: .4byte 0x083ACAF8
_0800CC88: .4byte 0x030004DE
_0800CC8C:
	ldr r0, _0800CCA4 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800CCA8
	movs r0, #0x10
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800CCCE
	.align 2, 0
_0800CCA4: .4byte 0x03001780
_0800CCA8:
	ldr r0, _0800CD20 @ =0x083ACAF8
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
_0800CCCE:
	ldr r0, _0800CD20 @ =0x083ACAF8
	ldr r0, [r0]
	ldr r4, _0800CD24 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800CCF8:
	ldr r2, _0800CD28 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800CD44
	ldr r0, _0800CD2C @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x34
	ldrb r4, [r3]
	cmp r4, #0
	bne _0800CD30
	adds r0, #0x35
	ldrb r3, [r3]
	adds r3, r0, r3
	ldrb r0, [r3]
	cmp r0, #0xaf
	bne _0800CD40
	strb r4, [r3]
	b _0800CD44
	.align 2, 0
_0800CD20: .4byte 0x083ACAF8
_0800CD24: .4byte 0x030004DE
_0800CD28: .4byte 0x03001798
_0800CD2C: .4byte 0x03000440
_0800CD30:
	adds r0, #0x35
	ldrb r3, [r3]
	adds r3, r0, r3
	ldrb r0, [r3]
	cmp r0, #8
	bne _0800CD40
	movs r0, #0
	b _0800CD42
_0800CD40:
	adds r0, #1
_0800CD42:
	strb r0, [r3]
_0800CD44:
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800CD86
	ldr r2, _0800CD6C @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800CD70
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800CD82
	movs r0, #0xaf
	b _0800CD84
	.align 2, 0
_0800CD6C: .4byte 0x03000440
_0800CD70:
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800CD82
	movs r0, #8
	b _0800CD84
_0800CD82:
	subs r0, #1
_0800CD84:
	strb r0, [r1]
_0800CD86:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r4, _0800CE24 @ =0x030004DE
	movs r0, #0x69
	rsbs r0, r0, #0
	adds r0, r0, r4
	mov sl, r0
	ldrb r1, [r0]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	movs r6, #3
	str r6, [sp]
	movs r5, #0xf
	str r5, [sp, #4]
	movs r1, #1
	mov sb, r1
	str r1, [sp, #8]
	movs r2, #0
	mov r8, r2
	str r2, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x20
	movs r2, #8
	movs r3, #2
	bl render_text_sprites_08040DB8
	movs r0, #0x23
	movs r1, #3
	bl clear_battle_sprite_slot
	adds r7, r4, #0
	subs r7, #0x68
	ldrb r1, [r7]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	str r6, [sp]
	str r5, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x23
	movs r2, #8
	movs r3, #4
	bl render_text_sprites_08040DB8
	ldr r0, _0800CE28 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0800CE34
	ldr r0, _0800CE2C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r0, #0x11
	movs r1, #8
	movs r2, #0
	movs r3, #7
	bl vram_fill_tilemap_rect
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800CE30 @ =0x0300137C
	mov r1, sb
	str r1, [r0]
	b _0800CE5E
	.align 2, 0
_0800CE24: .4byte 0x030004DE
_0800CE28: .4byte 0x0300058C
_0800CE2C: .4byte 0x04000008
_0800CE30: .4byte 0x0300137C
_0800CE34:
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0800CE5E
	mov r2, sl
	ldrb r0, [r2]
	ldrb r1, [r7]
	mov r2, sb
	str r2, [sp]
	movs r2, #0
	movs r3, #7
	bl load_bg0_tilemap
	mov r1, sl
	ldrb r0, [r1]
	ldrb r1, [r7]
	str r4, [sp]
	movs r2, #9
	movs r3, #7
	bl load_bg0_tilemap
_0800CE5E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
