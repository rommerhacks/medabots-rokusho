	.syntax unified

	thumb_func_start fill_tilemap_rect_0804916C
	.global fill_tilemap_rect_0804916C
fill_tilemap_rect_0804916C: @ 0x0804916C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r0, [sp, #0x14]
	mov ip, r0
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _08049182
	cmp r0, #1
	beq _08049186
	b _08049188
_08049182:
	movs r6, #0x20
	b _08049188
_08049186:
	movs r6, #0x40
_08049188:
	adds r0, r6, #0
	muls r0, r1, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r1, #0
	cmp r1, ip
	bge _080491BE
	lsls r7, r6, #1
	ldr r0, [sp, #0x1c]
	lsls r6, r0, #0xc
_0804919E:
	adds r0, r4, #0
	adds r3, r1, #1
	cmp r5, #0
	ble _080491B6
	ldr r1, [sp, #0x18]
	adds r2, r1, r6
	adds r1, r5, #0
_080491AC:
	strh r2, [r4]
	adds r4, #2
	subs r1, #1
	cmp r1, #0
	bne _080491AC
_080491B6:
	adds r4, r0, r7
	adds r1, r3, #0
	cmp r1, ip
	blt _0804919E
_080491BE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
