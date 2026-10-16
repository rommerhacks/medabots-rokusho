	.syntax unified

	thumb_func_start draw_medal_skill_bars
draw_medal_skill_bars: @ 0x0800B174
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	movs r4, #0
	ldr r7, _0800B1A8 @ =0x03000BE0
	movs r5, #2
	ldr r6, _0800B1AC @ =0x0300047D
_0800B180:
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r7
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, r4
	bls _0800B1B8
	ldr r0, _0800B1B0 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800B1B4 @ =0x0000D3D0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #9
	bl fill_tilemap_rect_08042698
	b _0800B1CE
	.align 2, 0
_0800B1A8: .4byte 0x03000BE0
_0800B1AC: .4byte 0x0300047D
_0800B1B0: .4byte 0x0400000A
_0800B1B4: .4byte 0x0000D3D0
_0800B1B8:
	ldr r0, _0800B204 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #9
	bl vram_fill_tilemap_rect
_0800B1CE:
	adds r5, #1
	adds r4, #1
	cmp r4, #7
	bls _0800B180
	movs r4, #0
	ldr r7, _0800B208 @ =0x03000BE0
	movs r5, #2
	ldr r6, _0800B20C @ =0x0300047D
_0800B1DE:
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r7
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, r4
	bls _0800B214
	ldr r0, _0800B204 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800B210 @ =0x0000D3D0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0xc
	bl fill_tilemap_rect_08042698
	b _0800B22A
	.align 2, 0
_0800B204: .4byte 0x0400000A
_0800B208: .4byte 0x03000BE0
_0800B20C: .4byte 0x0300047D
_0800B210: .4byte 0x0000D3D0
_0800B214:
	ldr r0, _0800B260 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
_0800B22A:
	adds r5, #1
	adds r4, #1
	cmp r4, #7
	bls _0800B1DE
	movs r4, #0
	ldr r7, _0800B264 @ =0x03000BE0
	movs r5, #0x10
	ldr r6, _0800B268 @ =0x0300047D
_0800B23A:
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r7
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, r4
	bls _0800B270
	ldr r0, _0800B260 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800B26C @ =0x0000D3D3
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #9
	bl fill_tilemap_rect_08042698
	b _0800B286
	.align 2, 0
_0800B260: .4byte 0x0400000A
_0800B264: .4byte 0x03000BE0
_0800B268: .4byte 0x0300047D
_0800B26C: .4byte 0x0000D3D3
_0800B270:
	ldr r0, _0800B2BC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #9
	bl vram_fill_tilemap_rect
_0800B286:
	adds r5, #1
	adds r4, #1
	cmp r4, #7
	bls _0800B23A
	movs r4, #0
	ldr r7, _0800B2C0 @ =0x03000BE0
	movs r5, #0x10
	ldr r6, _0800B2C4 @ =0x0300047D
_0800B296:
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r7
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, r4
	bls _0800B2CC
	ldr r0, _0800B2BC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800B2C8 @ =0x0000D3D3
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0xc
	bl fill_tilemap_rect_08042698
	b _0800B2E2
	.align 2, 0
_0800B2BC: .4byte 0x0400000A
_0800B2C0: .4byte 0x03000BE0
_0800B2C4: .4byte 0x0300047D
_0800B2C8: .4byte 0x0000D3D3
_0800B2CC:
	ldr r0, _0800B318 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
_0800B2E2:
	adds r5, #1
	adds r4, #1
	cmp r4, #7
	bls _0800B296
	movs r4, #0
	ldr r7, _0800B31C @ =0x03000BE0
	movs r5, #2
	ldr r6, _0800B320 @ =0x0300047D
_0800B2F2:
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r7
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, r4
	bls _0800B328
	ldr r0, _0800B318 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800B324 @ =0x0000D3D1
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0xf
	bl fill_tilemap_rect_08042698
	b _0800B33E
	.align 2, 0
_0800B318: .4byte 0x0400000A
_0800B31C: .4byte 0x03000BE0
_0800B320: .4byte 0x0300047D
_0800B324: .4byte 0x0000D3D1
_0800B328:
	ldr r0, _0800B374 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0xf
	bl vram_fill_tilemap_rect
_0800B33E:
	adds r5, #1
	adds r4, #1
	cmp r4, #7
	bls _0800B2F2
	movs r4, #0
	ldr r7, _0800B378 @ =0x03000BE0
	movs r5, #2
	ldr r6, _0800B37C @ =0x0300047D
_0800B34E:
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r7
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, r4
	bls _0800B384
	ldr r0, _0800B374 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800B380 @ =0x0000D3D2
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	b _0800B39A
	.align 2, 0
_0800B374: .4byte 0x0400000A
_0800B378: .4byte 0x03000BE0
_0800B37C: .4byte 0x0300047D
_0800B380: .4byte 0x0000D3D2
_0800B384:
	ldr r0, _0800B3D0 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0x12
	bl vram_fill_tilemap_rect
_0800B39A:
	adds r5, #1
	adds r4, #1
	cmp r4, #7
	bls _0800B34E
	movs r4, #0
	ldr r7, _0800B3D4 @ =0x03000BE0
	movs r5, #0x10
	ldr r6, _0800B3D8 @ =0x0300047D
_0800B3AA:
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r7
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, r4
	bls _0800B3E0
	ldr r0, _0800B3D0 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800B3DC @ =0x0000D3D4
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0xf
	bl fill_tilemap_rect_08042698
	b _0800B3F6
	.align 2, 0
_0800B3D0: .4byte 0x0400000A
_0800B3D4: .4byte 0x03000BE0
_0800B3D8: .4byte 0x0300047D
_0800B3DC: .4byte 0x0000D3D4
_0800B3E0:
	ldr r0, _0800B42C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0xf
	bl vram_fill_tilemap_rect
_0800B3F6:
	adds r5, #1
	adds r4, #1
	cmp r4, #7
	bls _0800B3AA
	movs r4, #0
	ldr r7, _0800B430 @ =0x03000BE0
	movs r5, #0x10
	ldr r6, _0800B434 @ =0x0300047D
_0800B406:
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r0, r7
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, r4
	bls _0800B43C
	ldr r0, _0800B42C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800B438 @ =0x0000D3D0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	b _0800B452
	.align 2, 0
_0800B42C: .4byte 0x0400000A
_0800B430: .4byte 0x03000BE0
_0800B434: .4byte 0x0300047D
_0800B438: .4byte 0x0000D3D0
_0800B43C:
	ldr r0, _0800B464 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0x12
	bl vram_fill_tilemap_rect
_0800B452:
	adds r5, #1
	adds r4, #1
	cmp r4, #7
	bls _0800B406
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B464: .4byte 0x0400000A
	.syntax divided
