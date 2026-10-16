	.syntax unified

	thumb_func_start render_bot_cash_display
	.global render_bot_cash_display
render_bot_cash_display: @ 0x08015E68
	push {r4, r5, lr}
	sub sp, #8
	cmp r0, #2
	bhi _08015EC8
	ldr r1, _08015EB8 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xc1
	ldrb r0, [r0]
	ldr r4, _08015EBC @ =0x0400000A
	ldrh r1, [r4]
	str r1, [sp]
	ldr r5, _08015EC0 @ =0x0000D220
	str r5, [sp, #4]
	movs r1, #4
	movs r2, #0x12
	movs r3, #2
	bl divide_by_100000_08042838
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _08015EC4 @ =0x0000D21A
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r2, #6
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x50
	movs r1, #7
	movs r2, #0x12
	movs r3, #2
	bl divide_by_100000_08042838
	b _08015F0C
	.align 2, 0
_08015EB8: .4byte 0x03000590
_08015EBC: .4byte 0x0400000A
_08015EC0: .4byte 0x0000D220
_08015EC4: .4byte 0x0000D21A
_08015EC8:
	ldr r1, _08015F14 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xc1
	ldrb r0, [r0]
	ldr r4, _08015F18 @ =0x0400000A
	ldrh r1, [r4]
	str r1, [sp]
	ldr r5, _08015F1C @ =0x0000D220
	str r5, [sp, #4]
	movs r1, #0x18
	movs r2, #0x12
	movs r3, #2
	bl divide_by_100000_08042838
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _08015F20 @ =0x0000D21A
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r2, #0x1a
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x50
	movs r1, #0x1b
	movs r2, #0x12
	movs r3, #2
	bl divide_by_100000_08042838
_08015F0C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08015F14: .4byte 0x03000590
_08015F18: .4byte 0x0400000A
_08015F1C: .4byte 0x0000D220
_08015F20: .4byte 0x0000D21A
	.syntax divided
