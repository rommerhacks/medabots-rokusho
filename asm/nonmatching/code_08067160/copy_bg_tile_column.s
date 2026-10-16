	.syntax unified

	thumb_func_start copy_bg_tile_column
copy_bg_tile_column: @ 0x08067390
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	cmp r1, #0xd
	ble _0806739C
	movs r0, #1
	b _080673D2
_0806739C:
	movs r6, #0
	lsls r0, r2, #1
	rsbs r1, r1, #0
	adds r2, #4
	adds r5, r0, r2
	lsls r1, r1, #6
	ldr r0, _080673D8 @ =0x06000440
	adds r4, r1, r0
_080673AC:
	lsls r0, r5, #6
	ldr r1, _080673DC @ =0x0600D800
	adds r0, r0, r1
	ldr r1, _080673E0 @ =0x04000008
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #0xb
	adds r1, r1, r4
	movs r2, #0xd
	bl CpuSet
	adds r4, #0x40
	adds r5, #1
	adds r6, #1
	cmp r6, #2
	ble _080673AC
	movs r0, #0
_080673D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080673D8: .4byte 0x06000440
_080673DC: .4byte 0x0600D800
_080673E0: .4byte 0x04000008
	.syntax divided
