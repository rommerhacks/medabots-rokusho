	.syntax unified

	thumb_func_start render_medal_slots_in_menu
	.global render_medal_slots_in_menu
render_medal_slots_in_menu: @ 0x08009620
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _08009660 @ =0x03000440
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r4, r0, #1
	adds r0, r4, #6
	cmp r4, r0
	bhs _080096AE
	ldr r6, _08009664 @ =0x0400000A
	ldr r7, _08009668 @ =0x0000D32C
	movs r5, #4
_0800963C:
	ldr r1, _0800966C @ =0x03000BE0
	lsls r0, r4, #6
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08009674
	ldrb r0, [r2, #5]
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	ldrh r3, [r6]
	ldr r1, _08009670 @ =0x0000D314
	str r1, [sp]
	movs r1, #0xe
	bl fill_tilemap_pair_or_divide
	b _08009698
	.align 2, 0
_08009660: .4byte 0x03000440
_08009664: .4byte 0x0400000A
_08009668: .4byte 0x0000D32C
_0800966C: .4byte 0x03000BE0
_08009670: .4byte 0x0000D314
_08009674:
	ldrh r0, [r6]
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #1
	movs r1, #2
	movs r2, #0xe
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
	ldrh r0, [r6]
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #1
	movs r1, #2
	movs r2, #0xf
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
_08009698:
	adds r5, #2
	adds r4, #1
	ldr r0, _080096B8 @ =0x03000440
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #6
	cmp r4, r0
	blo _0800963C
_080096AE:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080096B8: .4byte 0x03000440
	.syntax divided
