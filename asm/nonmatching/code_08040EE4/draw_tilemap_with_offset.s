	.syntax unified

	thumb_func_start draw_tilemap_with_offset
	.global draw_tilemap_with_offset
draw_tilemap_with_offset: @ 0x080435B0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r2, r1, #0
	cmp r4, #0xff
	bne _080435D4
	str r3, [sp]
	ldr r2, _080435D0 @ =0x0000101C
	adds r0, r1, r2
	b _080435E6
	.align 2, 0
_080435D0: .4byte 0x0000101C
_080435D4:
	lsrs r0, r4, #2
	cmp r0, #0
	beq _080435FA
	str r3, [sp]
	lsls r0, r4, #2
	adds r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
_080435E6:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	adds r2, r5, #0
	adds r3, r6, #0
	bl fill_tilemap_rect_08042698
	b _08043612
_080435FA:
	str r3, [sp]
	lsls r0, r4, #2
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	adds r2, r5, #0
	adds r3, r6, #0
	bl fill_tilemap_rect_08042698
_08043612:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
