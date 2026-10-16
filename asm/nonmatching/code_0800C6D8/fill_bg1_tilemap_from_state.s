	.syntax unified

	thumb_func_start fill_bg1_tilemap_from_state
fill_bg1_tilemap_from_state: @ 0x0800F8A0
	push {lr}
	sub sp, #8
	ldr r0, _0800F8CC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800F8D0 @ =0x03000440
	adds r0, #0xf1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r1, _0800F8D4 @ =0x73880000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x15
	movs r3, #3
	bl fill_tilemap_rect_08042698
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800F8CC: .4byte 0x0400000A
_0800F8D0: .4byte 0x03000440
_0800F8D4: .4byte 0x73880000
	.syntax divided
