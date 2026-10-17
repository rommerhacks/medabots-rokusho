	.syntax unified

	thumb_func_start sub_08017734
sub_08017734: @ 0x08017734
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	movs r6, #0
	cmp r0, #0
	beq _08017744
	b _08017880
_08017744:
	ldr r1, _080177F0 @ =0x03000590
	ldr r5, _080177F4 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	ldrb r1, [r0, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _080177F8 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _080177FC @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	adds r5, #0x82
	ldrb r0, [r5]
	subs r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08017800 @ =0x083B7CD4
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x20
	movs r2, #6
	bl memcpy_bytes_08041D04
	adds r4, #0x22
	ldrb r0, [r4]
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r5, #0
	movs r1, #8
	subs r1, r1, r0
	cmp r6, r1
	bhs _080177BE
	adds r7, r1, #0
_0801779E:
	adds r4, r6, #1
	ldr r0, _08017804 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0x11
	bl vram_fill_tilemap_rect
	adds r6, r4, #0
	adds r5, #1
	cmp r5, r7
	blo _0801779E
_080177BE:
	adds r5, r6, #0
	cmp r6, #7
	bhi _0801782E
	ldr r0, _08017808 @ =0x030004C4
	mov r8, r0
	ldr r7, _08017804 @ =0x04000008
_080177CA:
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08017810
	adds r4, r6, #1
	ldrh r0, [r7]
	str r0, [sp]
	ldr r0, _0801780C @ =0x0000B208
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	b _08017826
	.align 2, 0
_080177F0: .4byte 0x03000590
_080177F4: .4byte 0x03001800
_080177F8: .4byte 0x083B7E0C
_080177FC: .4byte 0x0300052E
_08017800: .4byte 0x083B7CD4
_08017804: .4byte 0x04000008
_08017808: .4byte 0x030004C4
_0801780C: .4byte 0x0000B208
_08017810:
	adds r4, r6, #1
	ldrh r0, [r7]
	str r0, [sp]
	ldr r0, _0801786C @ =0x0000C208
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
_08017826:
	adds r6, r4, #0
	adds r5, #1
	cmp r5, #7
	bls _080177CA
_0801782E:
	ldr r4, _08017870 @ =0x0400000A
	ldrh r0, [r4]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #5
	movs r1, #1
	movs r2, #4
	movs r3, #0x12
	bl vram_fill_tilemap_rect
	ldr r0, _08017874 @ =0x03000440
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrh r1, [r4]
	str r1, [sp]
	ldr r1, _08017878 @ =0x0000D220
	str r1, [sp, #4]
	movs r1, #4
	movs r2, #0x12
	movs r3, #2
	bl divide_by_100000_08042838
	ldr r0, _0801787C @ =0x03001800
	adds r0, #0x80
	ldrb r0, [r0]
	bl draw_battle_panel_left_b
	b _080178B4
	.align 2, 0
_0801786C: .4byte 0x0000C208
_08017870: .4byte 0x0400000A
_08017874: .4byte 0x03000440
_08017878: .4byte 0x0000D220
_0801787C: .4byte 0x03001800
_08017880:
	ldr r0, _080178C0 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #8
	movs r1, #1
	movs r2, #1
	movs r3, #0x11
	bl vram_fill_tilemap_rect
	ldr r4, _080178C4 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl draw_medaforce_gauge_value
	ldr r1, _080178C8 @ =0x03000590
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r1
	adds r0, #0xc1
	ldrb r0, [r0]
	cmp r0, #0x50
	beq _080178B4
	adds r0, r2, #0
	bl draw_battle_panel_left_a
_080178B4:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080178C0: .4byte 0x04000008
_080178C4: .4byte 0x03001800
_080178C8: .4byte 0x03000590
	.syntax divided
