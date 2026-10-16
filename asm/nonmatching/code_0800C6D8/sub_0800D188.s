	.syntax unified

	thumb_func_start sub_0800D188
sub_0800D188: @ 0x0800D188
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r0, _0800D1A4 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800D1A8
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800D1D0
	.align 2, 0
_0800D1A4: .4byte 0x03001780
_0800D1A8:
	ldr r0, _0800D240 @ =0x083ACB20
	ldr r0, [r0]
	ldr r4, _0800D244 @ =0x030004DE
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
_0800D1D0:
	ldr r0, _0800D248 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0800D1EA
	ldr r0, _0800D24C @ =0x030057E0
	ldr r1, _0800D250 @ =0x00000C2C
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_0800D1EA:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r4, _0800D244 @ =0x030004DE
	ldr r0, _0800D24C @ =0x030057E0
	ldr r1, _0800D250 @ =0x00000C2C
	adds r0, r0, r1
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
	ldr r0, _0800D254 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D236
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800D258 @ =0x0300137C
	str r5, [r0]
_0800D236:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D240: .4byte 0x083ACB20
_0800D244: .4byte 0x030004DE
_0800D248: .4byte 0x03001798
_0800D24C: .4byte 0x030057E0
_0800D250: .4byte 0x00000C2C
_0800D254: .4byte 0x0300058C
_0800D258: .4byte 0x0300137C
	.syntax divided
