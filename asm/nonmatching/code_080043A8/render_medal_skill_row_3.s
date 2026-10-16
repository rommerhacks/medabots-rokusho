	.syntax unified

	thumb_func_start render_medal_skill_row_3
	.global render_medal_skill_row_3
render_medal_skill_row_3: @ 0x08006154
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r5, _080061BC @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x9b
	ldrb r0, [r1]
	cmp r0, #0x77
	bhi _08006214
	adds r6, r5, #0
	adds r6, #0x97
	ldrb r0, [r6]
	cmp r0, #0x1d
	bhi _080061F8
	ldrb r0, [r1]
	adds r4, r5, #0
	adds r4, #0xee
	movs r1, #3
	adds r2, r4, #0
	bl load_part_data
	ldr r1, _080061C0 @ =0x03000BE0
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #4
	ldr r1, _080061C4 @ =0x083B6158
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0x10
	bl memcpy_bytes_08041D04
	ldr r0, _080061C8 @ =0x0000010F
	adds r1, r5, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080061D8
	ldr r0, _080061CC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _080061D0 @ =0x00000115
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r2, _080061D4 @ =0xD3400000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	b _080061E0
	.align 2, 0
_080061BC: .4byte 0x03000440
_080061C0: .4byte 0x03000BE0
_080061C4: .4byte 0x083B6158
_080061C8: .4byte 0x0000010F
_080061CC: .4byte 0x0400000A
_080061D0: .4byte 0x00000115
_080061D4: .4byte 0xD3400000
_080061D8:
	ldr r0, _080061F0 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080061F4 @ =0x0000D340
_080061E0:
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	b _0800622A
	.align 2, 0
_080061F0: .4byte 0x0400000A
_080061F4: .4byte 0x0000D340
_080061F8:
	ldr r0, _08006210 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0x11
	bl vram_fill_tilemap_rect
	b _0800622A
	.align 2, 0
_08006210: .4byte 0x0400000A
_08006214:
	ldr r0, _08006234 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0x11
	bl vram_fill_tilemap_rect
_0800622A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08006234: .4byte 0x0400000A
	.syntax divided
