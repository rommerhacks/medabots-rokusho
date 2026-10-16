	.syntax unified

	thumb_func_start bg_tilemap_scroll_up_row
bg_tilemap_scroll_up_row: @ 0x080673E4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	cmp r5, #3
	ble _080673F2
	movs r0, #1
	b _08067432
_080673F2:
	movs r4, #0
	ldr r3, _0806743C @ =0x04000008
	movs r7, #0x1f
	movs r6, #0xc0
	lsls r6, r6, #0x13
_080673FC:
	ldrh r0, [r3]
	lsrs r0, r0, #8
	ands r0, r7
	lsls r0, r0, #0xb
	adds r1, r4, #4
	subs r1, r1, r5
	lsls r1, r1, #6
	adds r1, r1, r6
	adds r0, r0, r1
	ldrh r1, [r3]
	lsrs r1, r1, #8
	ands r1, r7
	lsls r1, r1, #0xb
	adds r2, r4, #3
	subs r2, r2, r5
	lsls r2, r2, #6
	adds r2, r2, r6
	adds r1, r1, r2
	movs r2, #0xd
	str r3, [sp]
	bl CpuSet
	adds r4, #1
	ldr r3, [sp]
	cmp r4, #2
	ble _080673FC
	movs r0, #0
_08067432:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806743C: .4byte 0x04000008
	.syntax divided
