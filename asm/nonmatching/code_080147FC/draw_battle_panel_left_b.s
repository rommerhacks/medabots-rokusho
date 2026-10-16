	.syntax unified

	thumb_func_start draw_battle_panel_left_b
	.global draw_battle_panel_left_b
draw_battle_panel_left_b: @ 0x08015BF4
	push {lr}
	sub sp, #8
	cmp r0, #2
	bhi _08015C1C
	ldr r0, _08015C14 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08015C18 @ =0x0000D20D
	str r0, [sp, #4]
	movs r0, #3
	movs r1, #1
	movs r2, #1
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	b _08015C32
	.align 2, 0
_08015C14: .4byte 0x0400000A
_08015C18: .4byte 0x0000D20D
_08015C1C:
	ldr r0, _08015C38 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08015C3C @ =0x0000D20D
	str r0, [sp, #4]
	movs r0, #3
	movs r1, #1
	movs r2, #0x15
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
_08015C32:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08015C38: .4byte 0x0400000A
_08015C3C: .4byte 0x0000D20D
	.syntax divided
