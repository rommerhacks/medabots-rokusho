	.syntax unified

	thumb_func_start draw_battle_panel_left_a
	.global draw_battle_panel_left_a
draw_battle_panel_left_a: @ 0x08015BA8
	push {lr}
	sub sp, #8
	cmp r0, #2
	bhi _08015BD0
	ldr r0, _08015BC8 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08015BCC @ =0x0000D20A
	str r0, [sp, #4]
	movs r0, #3
	movs r1, #1
	movs r2, #1
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	b _08015BE6
	.align 2, 0
_08015BC8: .4byte 0x0400000A
_08015BCC: .4byte 0x0000D20A
_08015BD0:
	ldr r0, _08015BEC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08015BF0 @ =0x0000D20A
	str r0, [sp, #4]
	movs r0, #3
	movs r1, #1
	movs r2, #0x15
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
_08015BE6:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08015BEC: .4byte 0x0400000A
_08015BF0: .4byte 0x0000D20A
	.syntax divided
