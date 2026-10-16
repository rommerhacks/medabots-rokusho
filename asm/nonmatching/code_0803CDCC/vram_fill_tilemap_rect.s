	.syntax unified

	thumb_func_start vram_fill_tilemap_rect
	.global vram_fill_tilemap_rect
vram_fill_tilemap_rect: @ 0x0803EF8C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	lsls r2, r2, #1
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	adds r1, r1, r2
	lsls r3, r3, #6
	adds r7, r1, r3
	movs r1, #0
	cmp r1, r6
	bhs _0803EFD2
_0803EFB6:
	lsls r0, r1, #6
	adds r2, r7, r0
	movs r3, #0
	adds r0, r1, #1
	cmp r3, r4
	bhs _0803EFCC
_0803EFC2:
	strh r5, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, r4
	blo _0803EFC2
_0803EFCC:
	adds r1, r0, #0
	cmp r1, r6
	blo _0803EFB6
_0803EFD2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
