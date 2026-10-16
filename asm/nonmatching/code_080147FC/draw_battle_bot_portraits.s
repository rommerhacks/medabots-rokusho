	.syntax unified

	thumb_func_start draw_battle_bot_portraits
	.global draw_battle_bot_portraits
draw_battle_bot_portraits: @ 0x08015760
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r4, #0
	ldr r6, _0801579C @ =0x0400000E
	movs r5, #4
_0801576A:
	ldr r1, _080157A0 @ =0x03000590
	lsls r0, r4, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080157A8
	ldrh r0, [r6]
	str r0, [sp]
	adds r0, r1, #0
	adds r0, #0x91
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r1, _080157A4 @ =0x80840000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #2
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
	b _080157BC
	.align 2, 0
_0801579C: .4byte 0x0400000E
_080157A0: .4byte 0x03000590
_080157A4: .4byte 0x80840000
_080157A8:
	ldrh r0, [r6]
	str r0, [sp]
	ldr r0, _08015800 @ =0x00008230
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #2
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
_080157BC:
	adds r5, #3
	adds r4, #1
	cmp r4, #2
	bls _0801576A
	movs r4, #0
	ldr r6, _08015804 @ =0x0400000E
	movs r5, #4
_080157CA:
	ldr r1, _08015808 @ =0x03000590
	adds r0, r4, #3
	lsls r0, r0, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08015810
	ldrh r0, [r6]
	str r0, [sp]
	adds r0, r1, #0
	adds r0, #0x91
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r1, _0801580C @ =0x80840000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x1a
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
	b _08015824
	.align 2, 0
_08015800: .4byte 0x00008230
_08015804: .4byte 0x0400000E
_08015808: .4byte 0x03000590
_0801580C: .4byte 0x80840000
_08015810:
	ldrh r0, [r6]
	str r0, [sp]
	ldr r0, _08015834 @ =0x00008230
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x1a
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
_08015824:
	adds r5, #3
	adds r4, #1
	cmp r4, #2
	bls _080157CA
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08015834: .4byte 0x00008230
	.syntax divided
