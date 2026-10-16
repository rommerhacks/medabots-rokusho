	.syntax unified

	thumb_func_start draw_partial_bg1_column
	.global draw_partial_bg1_column
draw_partial_bg1_column: @ 0x08016F28
	push {lr}
	sub sp, #8
	ldr r0, _08016F58 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #4
	bhi _08016F50
	movs r3, #0x13
	subs r3, r3, r0
	ldr r0, _08016F5C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08016F60 @ =0x02020800
	str r0, [sp, #4]
	movs r0, #6
	movs r1, #5
	movs r2, #0xc
	bl write_vram_tilemap_rect
_08016F50:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08016F58: .4byte 0x03000440
_08016F5C: .4byte 0x0400000A
_08016F60: .4byte 0x02020800
	.syntax divided
