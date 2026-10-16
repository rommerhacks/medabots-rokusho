	.syntax unified

	thumb_func_start sub_0800D27C
sub_0800D27C: @ 0x0800D27C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r0, _0800D298 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800D29C
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800D2C4
	.align 2, 0
_0800D298: .4byte 0x03001780
_0800D29C:
	ldr r0, _0800D358 @ =0x083ACB2C
	ldr r0, [r0]
	ldr r4, _0800D35C @ =0x030004DE
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
_0800D2C4:
	ldr r2, _0800D360 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D2E2
	ldr r0, _0800D364 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_0800D2E2:
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D2FE
	ldr r0, _0800D364 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
_0800D2FE:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r4, _0800D35C @ =0x030004DE
	adds r7, r4, #0
	subs r7, #0x6a
	ldrb r0, [r7]
	adds r6, r4, #0
	subs r6, #0x69
	adds r0, r0, r6
	ldrb r1, [r0]
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
	ldr r0, _0800D368 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0800D370
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800D36C @ =0x0300137C
	str r5, [r0]
	b _0800D3AA
	.align 2, 0
_0800D358: .4byte 0x083ACB2C
_0800D35C: .4byte 0x030004DE
_0800D360: .4byte 0x03001798
_0800D364: .4byte 0x03000440
_0800D368: .4byte 0x0300058C
_0800D36C: .4byte 0x0300137C
_0800D370:
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0800D3AA
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r1, _0800D3B4 @ =0x030057E0
	ldr r2, _0800D3B8 @ =0x00000C2E
	adds r0, r1, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r1, r2
	strb r4, [r0]
	subs r2, #2
	adds r0, r1, r2
	strb r5, [r0]
	ldrb r0, [r7]
	adds r0, r0, r6
	ldrb r0, [r0]
	subs r2, #3
	adds r1, r1, r2
	strb r0, [r1]
	ldr r1, _0800D3BC @ =0x03002B8C
	movs r0, #6
	str r0, [r1]
	ldr r0, _0800D3C0 @ =0x0300137C
	str r4, [r0]
_0800D3AA:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D3B4: .4byte 0x030057E0
_0800D3B8: .4byte 0x00000C2E
_0800D3BC: .4byte 0x03002B8C
_0800D3C0: .4byte 0x0300137C
	.syntax divided
