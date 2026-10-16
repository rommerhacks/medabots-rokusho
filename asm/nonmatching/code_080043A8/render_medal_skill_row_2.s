	.syntax unified

	thumb_func_start render_medal_skill_row_2
	.global render_medal_skill_row_2
render_medal_skill_row_2: @ 0x08005FEC
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r5, _08006054 @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x9a
	ldrb r0, [r1]
	cmp r0, #0x77
	bhi _080060AC
	adds r6, r5, #0
	adds r6, #0x97
	ldrb r0, [r6]
	cmp r0, #0x1d
	bhi _08006090
	ldrb r0, [r1]
	adds r4, r5, #0
	adds r4, #0xee
	movs r1, #2
	adds r2, r4, #0
	bl load_part_data
	ldr r1, _08006058 @ =0x03000BE0
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #4
	ldr r1, _0800605C @ =0x083B6158
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0x10
	bl memcpy_bytes_08041D04
	ldr r0, _08006060 @ =0x0000010F
	adds r1, r5, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08006070
	ldr r0, _08006064 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _08006068 @ =0x00000115
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r2, _0800606C @ =0xD3400000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	b _08006078
	.align 2, 0
_08006054: .4byte 0x03000440
_08006058: .4byte 0x03000BE0
_0800605C: .4byte 0x083B6158
_08006060: .4byte 0x0000010F
_08006064: .4byte 0x0400000A
_08006068: .4byte 0x00000115
_0800606C: .4byte 0xD3400000
_08006070:
	ldr r0, _08006088 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800608C @ =0x0000D340
_08006078:
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0xf
	bl fill_tilemap_rect_08042698
	b _080060C2
	.align 2, 0
_08006088: .4byte 0x0400000A
_0800608C: .4byte 0x0000D340
_08006090:
	ldr r0, _080060A8 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0xf
	bl vram_fill_tilemap_rect
	b _080060C2
	.align 2, 0
_080060A8: .4byte 0x0400000A
_080060AC:
	ldr r0, _080060CC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0xf
	bl vram_fill_tilemap_rect
_080060C2:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080060CC: .4byte 0x0400000A
	.syntax divided
