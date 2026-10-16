	.syntax unified

	thumb_func_start write_vram_tilemap_rect
	.global write_vram_tilemap_rect
write_vram_tilemap_rect: @ 0x08044160
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, [sp, #0x14]
	ldr r4, [sp, #0x18]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	lsls r2, r2, #1
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r2, r2, r1
	adds r0, r0, r2
	lsls r3, r3, #6
	adds r7, r0, r3
	movs r3, #0
_08044182:
	cmp r3, r6
	bhs _080441A2
	lsls r0, r3, #6
	adds r1, r7, r0
	movs r2, #0
	adds r3, #1
	cmp r2, r5
	bhs _08044182
_08044192:
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, #2
	adds r1, #2
	adds r2, #1
	cmp r2, r5
	blo _08044192
	b _08044182
_080441A2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
