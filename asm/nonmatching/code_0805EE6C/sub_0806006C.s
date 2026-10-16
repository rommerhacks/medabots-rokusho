	.syntax unified

	thumb_func_start sub_0806006C
sub_0806006C: @ 0x0806006C
	push {r4, r5, r6, lr}
	ldr r6, _080600D0 @ =0x03006F74
	ldr r1, [r6]
	ldrh r0, [r1, #0x3a]
	adds r0, #1
	strh r0, [r1, #0x3a]
	movs r2, #0x3a
	ldrsh r0, [r1, r2]
	adds r0, #8
	bl clear_or_fill_bg2_tilemap
	ldr r5, _080600D4 @ =0x03002C30
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x47
	bls _0806009A
	movs r0, #0
	strh r0, [r1]
_0806009A:
	ldr r4, _080600D8 @ =0x080AF968
	ldrh r0, [r1]
	movs r1, #6
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x46
	strh r1, [r0]
	ldr r1, [r6]
	movs r2, #0x3a
	ldrsh r0, [r1, r2]
	cmp r0, #0xd
	ble _080600C8
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080600DC @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
_080600C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080600D0: .4byte 0x03006F74
_080600D4: .4byte 0x03002C30
_080600D8: .4byte 0x080AF968
_080600DC: .4byte 0x0300137C
	.syntax divided
