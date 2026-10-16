	.syntax unified

	thumb_func_start update_battle_gauge_display
update_battle_gauge_display: @ 0x0803EB0C
	push {lr}
	ldr r0, _0803EB24 @ =0x03000440
	adds r0, #0x86
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0803EB28
	bl draw_battle_gauge_bar
	b _0803EB2C
	.align 2, 0
_0803EB24: .4byte 0x03000440
_0803EB28:
	bl fill_bg1_tilemap_column
_0803EB2C:
	pop {r0}
	bx r0
	.syntax divided
