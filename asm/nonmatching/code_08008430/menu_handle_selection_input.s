	.syntax unified

	thumb_func_start menu_handle_selection_input
menu_handle_selection_input: @ 0x0800B938
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r0, _0800B958 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800B964
	ldr r0, _0800B95C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0xa
	bne _0800B960
	movs r0, #0
	b _0800B962
	.align 2, 0
_0800B958: .4byte 0x0300058C
_0800B95C: .4byte 0x03000440
_0800B960:
	adds r0, #1
_0800B962:
	strb r0, [r1]
_0800B964:
	ldr r0, _0800B980 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800B98C
	ldr r0, _0800B984 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800B988
	movs r0, #0xa
	b _0800B98A
	.align 2, 0
_0800B980: .4byte 0x0300058C
_0800B984: .4byte 0x03000440
_0800B988:
	subs r0, #1
_0800B98A:
	strb r0, [r1]
_0800B98C:
	ldr r0, _0800B9A4 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800B9A8
	movs r0, #0
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800B9DC
	.align 2, 0
_0800B9A4: .4byte 0x03001780
_0800B9A8:
	ldr r1, _0800B9F4 @ =0x083ACA20
	ldr r4, _0800B9F8 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
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
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl render_text_sprites_08040DB8
_0800B9DC:
	ldr r0, _0800B9FC @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0800BA04
	ldr r1, _0800BA00 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0800BA5C
	.align 2, 0
_0800B9F4: .4byte 0x083ACA20
_0800B9F8: .4byte 0x03000440
_0800B9FC: .4byte 0x0300058C
_0800BA00: .4byte 0x0300137C
_0800BA04:
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0800BA5E
	ldr r1, _0800BA68 @ =0x083ACA20
	ldr r5, _0800BA6C @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r5, #0
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl render_text_sprites_08040DB8
	adds r0, r5, #0
	adds r0, #0x33
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	ldr r1, _0800BA70 @ =0x0300137C
	movs r0, #3
_0800BA5C:
	str r0, [r1]
_0800BA5E:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BA68: .4byte 0x083ACA20
_0800BA6C: .4byte 0x03000440
_0800BA70: .4byte 0x0300137C
_0800BA74:
	.byte 0x09, 0x49, 0x0A, 0x48, 0x08, 0x60, 0x0A, 0x48, 0x48, 0x60, 0x0A, 0x48
	.byte 0x88, 0x60, 0x88, 0x68, 0x09, 0x4A, 0x0A, 0x49, 0x08, 0x1C, 0x30, 0x30, 0x00, 0x78, 0x10, 0x60
	.byte 0x08, 0x4A, 0x31, 0x31, 0x08, 0x78, 0x10, 0x60, 0x70, 0x47, 0x00, 0x00, 0xD4, 0x00, 0x00, 0x04
	.byte 0x00, 0x08, 0x02, 0x02, 0x30, 0x2C, 0x00, 0x03, 0x00, 0x04, 0x00, 0x84, 0x8C, 0x2B, 0x00, 0x03
	.byte 0x40, 0x04, 0x00, 0x03, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
