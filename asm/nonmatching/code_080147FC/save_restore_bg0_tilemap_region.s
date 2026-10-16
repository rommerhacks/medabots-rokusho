	.syntax unified

	thumb_func_start save_restore_bg0_tilemap_region
	.global save_restore_bg0_tilemap_region
save_restore_bg0_tilemap_region: @ 0x08016EDC
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _08016F1C @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #3
	bhi _08016F12
	ldr r5, _08016F20 @ =0x04000008
	ldrh r0, [r5]
	str r0, [sp]
	ldr r4, _08016F24 @ =0x02020800
	str r4, [sp, #4]
	movs r0, #0xc
	movs r1, #5
	movs r2, #9
	movs r3, #0xf
	bl read_vram_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xc
	movs r1, #5
	movs r2, #9
	movs r3, #0x10
	bl write_vram_tilemap_rect
_08016F12:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016F1C: .4byte 0x03000440
_08016F20: .4byte 0x04000008
_08016F24: .4byte 0x02020800
	.syntax divided
