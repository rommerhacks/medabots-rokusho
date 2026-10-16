	.syntax unified

	thumb_func_start draw_battle_stat_value
	.global draw_battle_stat_value
draw_battle_stat_value: @ 0x080063B4
	push {r4, lr}
	sub sp, #4
	ldr r4, _080063EC @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x9b
	ldrb r0, [r1]
	cmp r0, #0x77
	bhi _080063F4
	adds r2, r4, #0
	adds r2, #0xee
	movs r1, #3
	bl load_part_data
	adds r0, r4, #0
	adds r0, #0xef
	ldrb r0, [r0]
	subs r0, #0x64
	ldr r1, _080063F0 @ =0x0400000A
	ldrh r3, [r1]
	movs r1, #0x83
	lsls r1, r1, #8
	str r1, [sp]
	movs r1, #0x14
	movs r2, #6
	bl draw_tilemap_with_offset
	b _08006408
	.align 2, 0
_080063EC: .4byte 0x03000440
_080063F0: .4byte 0x0400000A
_080063F4:
	ldr r0, _08006410 @ =0x0400000A
	ldrh r3, [r0]
	movs r0, #0x83
	lsls r0, r0, #8
	str r0, [sp]
	movs r0, #0xff
	movs r1, #0x14
	movs r2, #6
	bl draw_tilemap_with_offset
_08006408:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08006410: .4byte 0x0400000A
	.syntax divided
