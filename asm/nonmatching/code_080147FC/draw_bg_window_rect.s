	.syntax unified

	thumb_func_start draw_bg_window_rect
draw_bg_window_rect: @ 0x08017C50
	push {lr}
	sub sp, #8
	cmp r0, #0
	bne _08017CA0
	ldr r0, _08017C74 @ =0x03000440
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	bne _08017C80
	ldr r0, _08017C78 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08017C7C @ =0x00008304
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x1a
	b _08017C92
	.align 2, 0
_08017C74: .4byte 0x03000440
_08017C78: .4byte 0x04000008
_08017C7C: .4byte 0x00008304
_08017C80:
	ldr r0, _08017C9C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0x83
	lsls r0, r0, #8
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #2
_08017C92:
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	b _08017CDE
	.align 2, 0
_08017C9C: .4byte 0x04000008
_08017CA0:
	ldr r0, _08017CC0 @ =0x03000440
	adds r0, #0x3c
	ldrb r1, [r0]
	cmp r1, #0
	bne _08017CC8
	ldr r0, _08017CC4 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x1a
	movs r3, #0x11
	bl vram_fill_tilemap_rect
	b _08017CDE
	.align 2, 0
_08017CC0: .4byte 0x03000440
_08017CC4: .4byte 0x04000008
_08017CC8:
	ldr r0, _08017CE4 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #2
	movs r3, #0x11
	bl vram_fill_tilemap_rect
_08017CDE:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08017CE4: .4byte 0x04000008
	.syntax divided
