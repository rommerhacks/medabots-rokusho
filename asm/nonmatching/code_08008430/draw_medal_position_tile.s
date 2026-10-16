	.syntax unified

	thumb_func_start draw_medal_position_tile
	.global draw_medal_position_tile
draw_medal_position_tile: @ 0x08009DA0
	push {r4, lr}
	sub sp, #4
	ldr r4, _08009DF8 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x40
	lsls r0, r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x3d
	strb r0, [r1]
	ldrb r0, [r1]
	bl get_medal_active_slot
	adds r1, r0, #0
	cmp r1, #0xff
	beq _08009E28
	ldr r0, _08009DFC @ =0x030017A0
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrb r0, [r1, #6]
	cmp r0, #0x77
	bhi _08009E0C
	movs r1, #0x87
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #3
	bl load_part_data
	ldr r1, _08009E00 @ =0x0000010F
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #0x64
	ldr r1, _08009E04 @ =0x0400000A
	ldrh r3, [r1]
	ldr r1, _08009E08 @ =0x000083A0
	str r1, [sp]
	b _08009E16
	.align 2, 0
_08009DF8: .4byte 0x03000440
_08009DFC: .4byte 0x030017A0
_08009E00: .4byte 0x0000010F
_08009E04: .4byte 0x0400000A
_08009E08: .4byte 0x000083A0
_08009E0C:
	ldr r0, _08009E20 @ =0x0400000A
	ldrh r3, [r0]
	ldr r0, _08009E24 @ =0x000083A0
	str r0, [sp]
	movs r0, #0xff
_08009E16:
	movs r1, #0x1b
	movs r2, #0x11
	bl draw_tilemap_with_offset
	b _08009E3A
	.align 2, 0
_08009E20: .4byte 0x0400000A
_08009E24: .4byte 0x000083A0
_08009E28:
	ldr r0, _08009E44 @ =0x0400000A
	ldrh r3, [r0]
	ldr r0, _08009E48 @ =0x000083A0
	str r0, [sp]
	movs r0, #0xff
	movs r1, #0x1b
	movs r2, #0x11
	bl draw_tilemap_with_offset
_08009E3A:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08009E44: .4byte 0x0400000A
_08009E48: .4byte 0x000083A0
	.syntax divided
