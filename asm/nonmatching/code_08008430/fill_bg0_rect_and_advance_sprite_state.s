	.syntax unified

	thumb_func_start fill_bg0_rect_and_advance_sprite_state
fill_bg0_rect_and_advance_sprite_state: @ 0x0800B858
	push {lr}
	sub sp, #8
	ldr r0, _0800B884 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #8
	movs r2, #0x12
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r0, _0800B888 @ =0x03002C30
	ldr r2, _0800B88C @ =0x000001E9
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800B884: .4byte 0x04000008
_0800B888: .4byte 0x03002C30
_0800B88C: .4byte 0x000001E9
	.syntax divided
