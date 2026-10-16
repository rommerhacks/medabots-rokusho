	.syntax unified

	thumb_func_start render_medal_skill_row_0
	.global render_medal_skill_row_0
render_medal_skill_row_0: @ 0x08005D1C
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r5, _08005D84 @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x98
	ldrb r0, [r1]
	cmp r0, #0x77
	bhi _08005DDC
	adds r6, r5, #0
	adds r6, #0x97
	ldrb r0, [r6]
	cmp r0, #0x1d
	bhi _08005DC0
	ldrb r0, [r1]
	adds r4, r5, #0
	adds r4, #0xee
	movs r1, #0
	adds r2, r4, #0
	bl load_part_data
	ldr r1, _08005D88 @ =0x03000BE0
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #4
	ldr r1, _08005D8C @ =0x083B6158
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0x10
	bl memcpy_bytes_08041D04
	ldr r0, _08005D90 @ =0x0000010F
	adds r1, r5, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08005DA0
	ldr r0, _08005D94 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _08005D98 @ =0x00000115
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r2, _08005D9C @ =0xD3400000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	b _08005DA8
	.align 2, 0
_08005D84: .4byte 0x03000440
_08005D88: .4byte 0x03000BE0
_08005D8C: .4byte 0x083B6158
_08005D90: .4byte 0x0000010F
_08005D94: .4byte 0x0400000A
_08005D98: .4byte 0x00000115
_08005D9C: .4byte 0xD3400000
_08005DA0:
	ldr r0, _08005DB8 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08005DBC @ =0x0000D340
_08005DA8:
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0xb
	bl fill_tilemap_rect_08042698
	b _08005DF2
	.align 2, 0
_08005DB8: .4byte 0x0400000A
_08005DBC: .4byte 0x0000D340
_08005DC0:
	ldr r0, _08005DD8 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0xb
	bl vram_fill_tilemap_rect
	b _08005DF2
	.align 2, 0
_08005DD8: .4byte 0x0400000A
_08005DDC:
	ldr r0, _08005DFC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #0xb
	bl vram_fill_tilemap_rect
_08005DF2:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08005DFC: .4byte 0x0400000A
	.syntax divided
