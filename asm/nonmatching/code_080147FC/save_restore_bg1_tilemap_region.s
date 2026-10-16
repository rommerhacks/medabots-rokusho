	.syntax unified

	thumb_func_start save_restore_bg1_tilemap_region
	.global save_restore_bg1_tilemap_region
save_restore_bg1_tilemap_region: @ 0x08016E90
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _08016ED0 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0xb
	bhi _08016EC6
	ldr r5, _08016ED4 @ =0x0400000A
	ldrh r0, [r5]
	str r0, [sp]
	ldr r4, _08016ED8 @ =0x02021000
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #7
	movs r2, #0x11
	movs r3, #0xd
	bl read_vram_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #7
	movs r2, #0x12
	movs r3, #0xd
	bl write_vram_tilemap_rect
_08016EC6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016ED0: .4byte 0x03000440
_08016ED4: .4byte 0x0400000A
_08016ED8: .4byte 0x02021000
	.syntax divided
