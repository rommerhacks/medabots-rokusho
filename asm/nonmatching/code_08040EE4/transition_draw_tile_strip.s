	.syntax unified

	thumb_func_start transition_draw_tile_strip
transition_draw_tile_strip: @ 0x08041818
	push {r4, r5, r6, r7, lr}
	ldr r3, _080418B0 @ =0x03000440
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r2, [r0]
	lsls r2, r2, #6
	subs r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldr r1, _080418B4 @ =0x06002800
	adds r0, r0, r1
	adds r2, r2, r0
	adds r4, r2, #0
	movs r1, #0
	adds r7, r3, #0
	movs r0, #0
_08041838:
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _08041838
	adds r4, #0x40
	ldr r3, _080418B8 @ =0x06002D40
	adds r6, r3, #0
	adds r2, r4, #0
	movs r5, #0
_0804184C:
	movs r1, #0
_0804184E:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _0804184E
	adds r2, r4, #0
	adds r2, #0x40
	adds r4, r2, #0
	adds r6, #0x40
	adds r3, r6, #0
	adds r5, #1
	cmp r5, #1
	bls _0804184C
	ldr r3, _080418BC @ =0x06002E40
	adds r6, r3, #0
	movs r5, #0
_08041872:
	movs r1, #0
	adds r4, #0x40
	adds r6, #0x40
	adds r5, #1
_0804187A:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _0804187A
	adds r2, r4, #0
	adds r3, r6, #0
	cmp r5, #1
	bls _08041872
	movs r1, #0
	movs r0, #0
_08041894:
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _08041894
	adds r1, r7, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080418B0: .4byte 0x03000440
_080418B4: .4byte 0x06002800
_080418B8: .4byte 0x06002D40
_080418BC: .4byte 0x06002E40
	.syntax divided
