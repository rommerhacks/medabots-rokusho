	.syntax unified

	thumb_func_start sub_08010478
sub_08010478: @ 0x08010478
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _08010490 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x48
	ldrh r1, [r2]
	adds r7, r0, #0
	cmp r1, #4
	bhi _08010494
	movs r6, #0
	b _08010498
	.align 2, 0
_08010490: .4byte 0x03000440
_08010494:
	ldrh r0, [r2]
	subs r6, r0, #4
_08010498:
	adds r4, r6, #0
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r0]
	cmp r4, r1
	bgt _080104D2
	adds r5, r0, #0
_080104A6:
	cmp r4, #0xe
	bgt _080104CA
	ldr r0, _08010530 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	ldrh r0, [r5]
	subs r0, r0, r4
	ldr r1, _08010534 @ =0xFFFFD130
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #0x14
	adds r2, r4, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
_080104CA:
	adds r4, #1
	ldrh r0, [r5]
	cmp r4, r0
	ble _080104A6
_080104D2:
	adds r4, r6, #0
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r0]
	cmp r4, r1
	bgt _0801050E
	adds r5, r0, #0
_080104E0:
	cmp r4, #0xe
	bgt _08010506
	movs r2, #0x1d
	subs r2, r2, r4
	ldr r0, _08010530 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	ldrh r0, [r5]
	subs r0, r0, r4
	ldr r1, _08010534 @ =0xFFFFD130
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #0x14
	movs r3, #0
	bl vram_fill_tilemap_rect
_08010506:
	adds r4, #1
	ldrh r0, [r5]
	cmp r4, r0
	ble _080104E0
_0801050E:
	adds r1, r7, #0
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _08010528
	ldr r1, _08010538 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08010528:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010530: .4byte 0x04000008
_08010534: .4byte 0xFFFFD130
_08010538: .4byte 0x0300137C
	.syntax divided
