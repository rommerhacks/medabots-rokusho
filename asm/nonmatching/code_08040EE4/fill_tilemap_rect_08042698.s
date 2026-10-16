	.syntax unified

	thumb_func_start fill_tilemap_rect_08042698
	.global fill_tilemap_rect_08042698
fill_tilemap_rect_08042698: @ 0x08042698
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
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
	adds r1, r1, r3
	mov ip, r1
	movs r1, #0
	cmp r1, r7
	bhs _080426EA
_080426C4:
	lsls r0, r1, #6
	mov r3, ip
	adds r2, r3, r0
	movs r3, #0
	adds r4, r1, #1
	cmp r3, r6
	bhs _080426E4
_080426D2:
	adds r1, r5, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	strh r1, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, r6
	blo _080426D2
_080426E4:
	adds r1, r4, #0
	cmp r1, r7
	blo _080426C4
_080426EA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
