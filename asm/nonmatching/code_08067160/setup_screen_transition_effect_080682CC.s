	.syntax unified

	thumb_func_start setup_screen_transition_effect_080682CC
	.global setup_screen_transition_effect_080682CC
setup_screen_transition_effect_080682CC: @ 0x080682CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08068314 @ =0xFFFFF680
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r6, r3, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r2, _08068318 @ =0x03000000
	movs r0, #0
	str r0, [r2]
	ldr r2, _0806831C @ =0x03000028
	strh r5, [r2]
	ldr r0, _08068320 @ =0x03000004
	strb r3, [r0]
	ldr r4, _08068324 @ =0x03000005
	strb r1, [r4]
	mov sb, r2
	cmp r1, #0
	bne _08068304
	movs r0, #1
	strb r0, [r4]
_08068304:
	cmp r3, #2
	beq _08068340
	cmp r3, #2
	bgt _08068328
	cmp r3, #1
	beq _08068334
	b _080684C8
	.align 2, 0
_08068314: .4byte 0xFFFFF680
_08068318: .4byte 0x03000000
_0806831C: .4byte 0x03000028
_08068320: .4byte 0x03000004
_08068324: .4byte 0x03000005
_08068328:
	cmp r6, #3
	beq _08068354
	cmp r6, #4
	bne _08068332
	b _08068488
_08068332:
	b _080684C8
_08068334:
	ldr r1, _0806833C @ =0x04000050
	movs r0, #0xbf
	b _08068344
	.align 2, 0
_0806833C: .4byte 0x04000050
_08068340:
	ldr r1, _08068350 @ =0x04000050
	movs r0, #0xff
_08068344:
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	b _080684C8
	.align 2, 0
_08068350: .4byte 0x04000050
_08068354:
	add r0, sp, #0x80
	mov ip, r0
	ldr r1, _08068440 @ =0x03001780
	mov sl, r1
	movs r1, #0x11
	mov r0, sp
	adds r0, #0x7f
_08068362:
	strb r1, [r0]
	subs r0, #1
	cmp r0, sp
	bge _08068362
	ldr r1, _08068444 @ =0x040000D4
	mov r2, sp
	str r2, [r1]
	ldr r0, _08068448 @ =0x0600FF80
	str r0, [r1, #4]
	ldr r0, _0806844C @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r4, #0
	ldr r3, _08068450 @ =0x0000027F
	mov r8, r3
	ldr r7, _08068454 @ =0x083F7FF4
	ldr r0, _08068440 @ =0x03001780
	ldr r3, [r0]
	mov r1, ip
	movs r2, #0xff
	movs r6, #3
	ldr r0, _08068458 @ =0x0000F1FC
	adds r5, r0, #0
_08068390:
	adds r0, r3, r4
	ands r0, r2
	adds r0, r0, r7
	ldrb r0, [r0]
	ands r0, r6
	adds r0, r0, r5
	strh r0, [r1]
	adds r1, #2
	adds r4, #1
	cmp r4, r8
	ble _08068390
	ldr r0, _08068444 @ =0x040000D4
	mov r1, ip
	str r1, [r0]
	ldr r1, _0806845C @ =0x0600F800
	str r1, [r0, #4]
	ldr r1, _08068460 @ =0x84000140
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	mov r2, sb
	str r2, [r0]
	ldr r1, _08068464 @ =0x050001E2
	str r1, [r0, #4]
	ldr r1, _08068468 @ =0x80000001
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _0806846C @ =0x04000008
	ldr r3, _08068470 @ =0x00001F0C
	adds r0, r3, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08068474 @ =0x04000054
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	ldr r0, _08068478 @ =0x03000008
	ldr r5, _0806847C @ =0x00003F92
	ldr r3, _08068480 @ =0x00003F90
	ldr r2, _08068484 @ =0x00003F82
	movs r1, #0xfe
	lsls r1, r1, #6
_080683F0:
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #4]
	strh r5, [r0, #6]
	adds r0, #8
	adds r5, #0x20
	adds r3, #0x20
	adds r2, #0x20
	adds r1, #0x20
	adds r4, #1
	cmp r4, #3
	ble _080683F0
	movs r4, #0
	ldr r5, _08068478 @ =0x03000008
	adds r6, r5, #0
_0806840E:
	mov r1, sl
	ldr r0, [r1]
	adds r0, r0, r4
	movs r1, #0xff
	ands r0, r1
	ldr r2, _08068454 @ =0x083F7FF4
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #0x10
	subs r1, r1, r4
	bl sub_0807CC88
	adds r0, r0, r4
	ldrh r2, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	strh r1, [r5]
	strh r2, [r0]
	adds r5, #2
	adds r4, #1
	cmp r4, #0xe
	ble _0806840E
	b _080684C8
	.align 2, 0
_08068440: .4byte 0x03001780
_08068444: .4byte 0x040000D4
_08068448: .4byte 0x0600FF80
_0806844C: .4byte 0x80000040
_08068450: .4byte 0x0000027F
_08068454: .4byte 0x083F7FF4
_08068458: .4byte 0x0000F1FC
_0806845C: .4byte 0x0600F800
_08068460: .4byte 0x84000140
_08068464: .4byte 0x050001E2
_08068468: .4byte 0x80000001
_0806846C: .4byte 0x04000008
_08068470: .4byte 0x00001F0C
_08068474: .4byte 0x04000054
_08068478: .4byte 0x03000008
_0806847C: .4byte 0x00003F92
_08068480: .4byte 0x00003F90
_08068484: .4byte 0x00003F82
_08068488:
	ldr r0, _080684DC @ =0x0300002C
	ldr r2, _080684E0 @ =0x0202F800
	str r2, [r0]
	ldr r1, _080684E4 @ =0x040000D4
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1]
	str r2, [r1, #4]
	ldr r0, _080684E8 @ =0x80000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xb0
	lsls r0, r0, #3
	add r0, sp
	movs r4, #0x80
	lsls r4, r4, #2
_080684A8:
	strh r5, [r0]
	adds r0, #2
	subs r4, #1
	cmp r4, #0
	bne _080684A8
	ldr r1, _080684E4 @ =0x040000D4
	movs r0, #0xb0
	lsls r0, r0, #3
	add r0, sp
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _080684EC @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_080684C8:
	movs r3, #0x98
	lsls r3, r3, #4
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080684DC: .4byte 0x0300002C
_080684E0: .4byte 0x0202F800
_080684E4: .4byte 0x040000D4
_080684E8: .4byte 0x80000200
_080684EC: .4byte 0x84000100
	.syntax divided
