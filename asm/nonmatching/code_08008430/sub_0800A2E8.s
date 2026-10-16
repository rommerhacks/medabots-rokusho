	.syntax unified

	thumb_func_start sub_0800A2E8
	.global sub_0800A2E8
sub_0800A2E8: @ 0x0800A2E8
	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x1e
	movs r1, #0x3c
	bl clear_sprite_table_mask
	ldr r0, _0800A388 @ =0x03000BE0
	ldr r5, _0800A38C @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #9
	bls _0800A3A4
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _0800A390 @ =0x083B7E0C
	adds r0, r0, r1
	adds r4, r5, #0
	adds r4, #0xee
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0800A394 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _0800A398 @ =0x083B7338
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r4, #0x50
	adds r1, r4, #0
	movs r2, #0x11
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x1e
	movs r2, #2
	movs r3, #6
	bl render_text_sprites_08040DB8
	ldr r0, _0800A39C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _0800A3A0 @ =0x00000113
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	movs r2, #0xa6
	lsls r2, r2, #0x17
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xc
	movs r3, #6
	bl fill_tilemap_rect_08042698
	b _0800A3DE
	.align 2, 0
_0800A388: .4byte 0x03000BE0
_0800A38C: .4byte 0x03000440
_0800A390: .4byte 0x083B7E0C
_0800A394: .4byte 0x083B7CD4
_0800A398: .4byte 0x083B7338
_0800A39C: .4byte 0x0400000A
_0800A3A0: .4byte 0x00000113
_0800A3A4:
	adds r4, r5, #0
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xd
	bl fill_text_blank
	movs r0, #0xa
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x1e
	movs r2, #2
	movs r3, #6
	bl render_text_sprites_08040DB8
	ldr r0, _0800A460 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xc
	movs r3, #6
	bl vram_fill_tilemap_rect
_0800A3DE:
	ldr r0, _0800A464 @ =0x03000BE0
	ldr r5, _0800A468 @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x1d
	bls _0800A478
	adds r4, r5, #0
	adds r4, #0xef
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0800A46C @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _0800A470 @ =0x083B7338
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r4, #0x51
	adds r1, r4, #0
	movs r2, #0x11
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x32
	movs r2, #2
	movs r3, #8
	bl render_text_sprites_08040DB8
	ldr r0, _0800A460 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _0800A474 @ =0x00000113
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	movs r2, #0xa6
	lsls r2, r2, #0x17
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xc
	movs r3, #8
	bl fill_tilemap_rect_08042698
	b _0800A4B2
	.align 2, 0
_0800A460: .4byte 0x0400000A
_0800A464: .4byte 0x03000BE0
_0800A468: .4byte 0x03000440
_0800A46C: .4byte 0x083B7CD4
_0800A470: .4byte 0x083B7338
_0800A474: .4byte 0x00000113
_0800A478:
	adds r4, r5, #0
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xd
	bl fill_text_blank
	movs r0, #0xa
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x32
	movs r2, #2
	movs r3, #8
	bl render_text_sprites_08040DB8
	ldr r0, _0800A534 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xc
	movs r3, #8
	bl vram_fill_tilemap_rect
_0800A4B2:
	ldr r0, _0800A538 @ =0x03000BE0
	ldr r5, _0800A53C @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x3b
	bls _0800A54C
	adds r4, r5, #0
	adds r4, #0xf0
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0800A540 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _0800A544 @ =0x083B7338
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r4, #0x52
	adds r1, r4, #0
	movs r2, #0x11
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x46
	movs r2, #2
	movs r3, #0xa
	bl render_text_sprites_08040DB8
	ldr r0, _0800A534 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _0800A548 @ =0x00000113
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	movs r2, #0xa6
	lsls r2, r2, #0x17
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xc
	movs r3, #0xa
	bl fill_tilemap_rect_08042698
	b _0800A586
	.align 2, 0
_0800A534: .4byte 0x0400000A
_0800A538: .4byte 0x03000BE0
_0800A53C: .4byte 0x03000440
_0800A540: .4byte 0x083B7CD4
_0800A544: .4byte 0x083B7338
_0800A548: .4byte 0x00000113
_0800A54C:
	adds r4, r5, #0
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xd
	bl fill_text_blank
	movs r0, #0xa
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x46
	movs r2, #2
	movs r3, #0xa
	bl render_text_sprites_08040DB8
	ldr r0, _0800A590 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xc
	movs r3, #0xa
	bl vram_fill_tilemap_rect
_0800A586:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800A590: .4byte 0x0400000A
	.syntax divided
