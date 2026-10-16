	.syntax unified

	thumb_func_start transition_fade_to_battle
transition_fade_to_battle: @ 0x0806231C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0806234C @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #8
	bhi _08062358
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r2, _08062350 @ =0x0000FFFE
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #2
	ldr r2, _08062354 @ =0x00007FFD
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08062466
	.align 2, 0
_0806234C: .4byte 0x03000440
_08062350: .4byte 0x0000FFFE
_08062354: .4byte 0x00007FFD
_08062358:
	ldr r0, _08062380 @ =0x03006F74
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x48
	ldrb r0, [r0]
	cmp r0, #0
	beq _08062388
	ldrb r0, [r1, #0x19]
	movs r2, #0x81
	lsls r2, r2, #0x12
	ldrb r1, [r1, #0x1a]
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r1, [r1]
	bl init_battle_scene
	ldr r1, _08062384 @ =0x0300178C
	movs r0, #0
	b _08062464
	.align 2, 0
_08062380: .4byte 0x03006F74
_08062384: .4byte 0x0300178C
_08062388:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0806246C @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0
	ldr r6, _08062470 @ =0x03002C30
	ldr r7, _08062474 @ =0x03002B8C
	ldr r1, _08062478 @ =0x0300137C
	mov ip, r1
	adds r4, r6, #0
	ldr r5, _0806247C @ =0x0000BFFF
_080623A2:
	lsls r1, r0, #0x18
	asrs r1, r1, #0x18
	adds r2, r1, #0
	adds r2, #0xb
	lsls r2, r2, #6
	adds r2, r2, r4
	ldrh r3, [r2]
	adds r0, r5, #0
	ands r0, r3
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #1
	ble _080623A2
	movs r0, #0
	ldr r4, _08062470 @ =0x03002C30
	ldr r5, _0806247C @ =0x0000BFFF
_080623C8:
	lsls r1, r0, #0x18
	asrs r1, r1, #0x18
	adds r2, r1, #0
	adds r2, #0x68
	lsls r2, r2, #6
	adds r2, r2, r4
	ldrh r3, [r2]
	adds r0, r5, #0
	ands r0, r3
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #1
	ble _080623C8
	movs r0, #0
	ldr r4, _08062470 @ =0x03002C30
	ldr r5, _0806247C @ =0x0000BFFF
_080623EE:
	lsls r1, r0, #0x18
	asrs r1, r1, #0x18
	adds r2, r1, #0
	adds r2, #0x6a
	lsls r2, r2, #6
	adds r2, r2, r4
	ldrh r3, [r2]
	adds r0, r5, #0
	ands r0, r3
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #3
	ble _080623EE
	movs r0, #0
	ldr r4, _08062470 @ =0x03002C30
	ldr r5, _0806247C @ =0x0000BFFF
_08062414:
	lsls r1, r0, #0x18
	asrs r1, r1, #0x18
	adds r2, r1, #0
	adds r2, #0x6e
	lsls r2, r2, #6
	adds r2, r2, r4
	ldrh r3, [r2]
	adds r0, r5, #0
	ands r0, r3
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #3
	ble _08062414
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r1, [r2]
	ldr r0, _0806247C @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08062480 @ =0x04000052
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0x48
	ldr r2, _08062484 @ =0x00001E05
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #0xff
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0xb
	str r0, [r7]
	movs r0, #1
	mov r1, ip
_08062464:
	str r0, [r1]
_08062466:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806246C: .4byte 0x0000FDFF
_08062470: .4byte 0x03002C30
_08062474: .4byte 0x03002B8C
_08062478: .4byte 0x0300137C
_0806247C: .4byte 0x0000BFFF
_08062480: .4byte 0x04000052
_08062484: .4byte 0x00001E05
	.syntax divided
