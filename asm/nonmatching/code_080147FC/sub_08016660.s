	.syntax unified

	thumb_func_start sub_08016660
	.global sub_08016660
sub_08016660: @ 0x08016660
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _080166A0 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08016696
	ldr r5, _080166A4 @ =0x0400000A
	ldrh r0, [r5]
	str r0, [sp]
	ldr r4, _080166A8 @ =0x02020800
	str r4, [sp, #4]
	movs r0, #6
	movs r1, #6
	movs r2, #0xc
	movs r3, #0xe
	bl read_vram_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #6
	movs r1, #6
	movs r2, #0xc
	movs r3, #0xf
	bl write_vram_tilemap_rect
_08016696:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080166A0: .4byte 0x03000440
_080166A4: .4byte 0x0400000A
_080166A8: .4byte 0x02020800
	.syntax divided
