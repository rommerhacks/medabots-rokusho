	.syntax unified

	thumb_func_start render_shop_price_display
render_shop_price_display: @ 0x0800FA7C
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, _0800FA98 @ =0x03000440
	adds r0, r6, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #2
	bgt _0800FA9C
	cmp r0, #1
	bge _0800FB14
	cmp r0, #0
	beq _0800FAA4
	b _0800FC50
	.align 2, 0
_0800FA98: .4byte 0x03000440
_0800FA9C:
	cmp r0, #3
	bne _0800FAA2
	b _0800FBC8
_0800FAA2:
	b _0800FC50
_0800FAA4:
	adds r0, r6, #0
	adds r0, #0xf2
	ldrb r0, [r0]
	ldr r5, _0800FB0C @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _0800FB10 @ =0x000053C4
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #6
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf3
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #7
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf4
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #8
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf6
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #9
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf5
	ldrb r1, [r0]
	cmp r1, #0
	bne _0800FB90
	b _0800FBB4
	.align 2, 0
_0800FB0C: .4byte 0x0400000A
_0800FB10: .4byte 0x000053C4
_0800FB14:
	adds r0, r6, #0
	adds r0, #0xf2
	ldrb r0, [r0]
	ldr r5, _0800FBA8 @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _0800FBAC @ =0x000053C4
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #6
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf3
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #7
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf4
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #8
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf6
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #9
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf7
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #0xa
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf5
	ldrb r1, [r0]
	cmp r1, #0
	beq _0800FBB4
_0800FB90:
	ldrh r0, [r5]
	str r0, [sp]
	ldr r0, _0800FBB0 @ =0x00005384
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x19
	movs r3, #8
	bl fill_tilemap_rect_08042698
	b _0800FC50
	.align 2, 0
_0800FBA8: .4byte 0x0400000A
_0800FBAC: .4byte 0x000053C4
_0800FBB0: .4byte 0x00005384
_0800FBB4:
	ldrh r0, [r5]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x19
	movs r3, #8
	bl vram_fill_tilemap_rect
	b _0800FC50
_0800FBC8:
	adds r0, r6, #0
	adds r0, #0xf2
	ldrb r0, [r0]
	ldr r5, _0800FC58 @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _0800FC5C @ =0x000053C4
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #6
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf3
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #7
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf4
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #8
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf5
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #9
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf6
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #0xa
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r6, #0
	adds r0, #0xf7
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1a
	movs r2, #0xb
	movs r3, #3
	bl divide_by_100000_08042838
_0800FC50:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800FC58: .4byte 0x0400000A
_0800FC5C: .4byte 0x000053C4
	.syntax divided
