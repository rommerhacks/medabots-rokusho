	.syntax unified

	thumb_func_start clear_tilemap_and_advance_state
clear_tilemap_and_advance_state: @ 0x0804172C
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, _08041774 @ =0x03000440
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r2, [r0]
	adds r0, #1
	ldrb r3, [r0]
	ldr r5, _08041778 @ =0x04000008
	ldrh r0, [r5]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #8
	movs r1, #6
	bl vram_fill_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #8
	movs r1, #6
	movs r2, #0
	movs r3, #0x15
	bl vram_fill_tilemap_rect
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08041774: .4byte 0x03000440
_08041778: .4byte 0x04000008
	.syntax divided
