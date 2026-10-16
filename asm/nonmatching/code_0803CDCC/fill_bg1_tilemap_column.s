	.syntax unified

	thumb_func_start fill_bg1_tilemap_column
fill_bg1_tilemap_column: @ 0x0803EAD8
	push {r4, lr}
	sub sp, #8
	movs r4, #0
_0803EADE:
	adds r2, r4, #7
	ldr r0, _0803EB04 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0803EB08 @ =0x000053D0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	adds r4, #1
	cmp r4, #0xb
	bls _0803EADE
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EB04: .4byte 0x0400000A
_0803EB08: .4byte 0x000053D0
	.syntax divided
