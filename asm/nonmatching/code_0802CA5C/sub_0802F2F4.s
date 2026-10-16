	.syntax unified

	thumb_func_start sub_0802F2F4
sub_0802F2F4: @ 0x0802F2F4
	push {r4, r5, r6, lr}
	ldr r0, _0802F354 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	adds r0, #0x21
	bl sub_080353CC
	ldr r4, _0802F358 @ =0x03002C30
	ldrb r0, [r5]
	adds r1, r0, #0
	adds r1, #0x21
	lsls r0, r1, #6
	adds r3, r0, r4
	adds r0, r3, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0x20
	bne _0802F374
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r0, _0802F35C @ =0x00000848
	adds r2, r4, r0
	ldrb r1, [r5]
	lsls r3, r1, #4
	ldrb r0, [r2]
	adds r0, r0, r3
	strb r0, [r2]
	ldr r0, _0802F360 @ =0x00000849
	adds r2, r4, r0
	ldrb r0, [r2]
	adds r0, r0, r3
	strb r0, [r2]
	adds r1, #1
	strb r1, [r5]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #4
	bne _0802F368
	ldr r1, _0802F364 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802F3F6
	.align 2, 0
_0802F354: .4byte 0x03000440
_0802F358: .4byte 0x03002C30
_0802F35C: .4byte 0x00000848
_0802F360: .4byte 0x00000849
_0802F364: .4byte 0x03001800
_0802F368:
	ldr r0, _0802F370 @ =0x03001800
	adds r0, #0xaa
	movs r1, #2
	b _0802F3F4
	.align 2, 0
_0802F370: .4byte 0x03001800
_0802F374:
	ldr r2, _0802F38C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _0802F390
	ldrh r0, [r3, #0x18]
	adds r0, #0x20
	b _0802F394
	.align 2, 0
_0802F38C: .4byte 0x03001800
_0802F390:
	ldrh r0, [r3, #0x18]
	subs r0, #0x20
_0802F394:
	ldr r2, _0802F3D0 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3, #0x18]
	ldr r3, _0802F3D4 @ =0x03002C30
	ldr r2, _0802F3D8 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x84
	ldrb r0, [r0]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r4, r0, r3
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r1, [r0]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0802F3E2
	adds r0, r6, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0802F3DC
	ldrh r0, [r4, #2]
	adds r0, #1
	b _0802F3E0
	.align 2, 0
_0802F3D0: .4byte 0x000003FF
_0802F3D4: .4byte 0x03002C30
_0802F3D8: .4byte 0x03000440
_0802F3DC:
	ldrh r0, [r4, #2]
	subs r0, #1
_0802F3E0:
	strh r0, [r4, #2]
_0802F3E2:
	adds r0, r2, #0
	adds r0, #0x84
	ldrb r0, [r0]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x27
	ldrb r1, [r0]
	adds r1, #1
_0802F3F4:
	strb r1, [r0]
_0802F3F6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
