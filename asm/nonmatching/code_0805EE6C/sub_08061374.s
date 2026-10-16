	.syntax unified

	thumb_func_start sub_08061374
sub_08061374: @ 0x08061374
	push {r4, r5, lr}
	ldr r0, _080613A4 @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #2]
	adds r1, r0, #1
	strh r1, [r2, #2]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080613A8 @ =0x03002C30
	movs r2, #0x82
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrb r3, [r1]
	adds r5, r0, #0
	cmp r3, #4
	bls _080613B0
	subs r0, r3, #4
	strb r0, [r1]
	ldr r0, _080613AC @ =0x00000209
	adds r1, r5, r0
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	b _080613BE
	.align 2, 0
_080613A4: .4byte 0x03006F74
_080613A8: .4byte 0x03002C30
_080613AC: .4byte 0x00000209
_080613B0:
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _080613D0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
_080613BE:
	cmp r4, #0x10
	bhi _080613D8
	ldr r2, _080613D4 @ =0x04000052
	lsls r1, r4, #8
	movs r0, #0x10
	subs r0, r0, r4
	orrs r1, r0
	strh r1, [r2]
	b _08061408
	.align 2, 0
_080613D0: .4byte 0x0000BFFF
_080613D4: .4byte 0x04000052
_080613D8:
	ldr r1, _08061418 @ =0x04000052
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0806141C @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _08061420 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	bl sub_0803FB0C
	ldr r1, _08061424 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08061408:
	ldr r0, _08061428 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1, #0x19]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08061418: .4byte 0x04000052
_0806141C: .4byte 0x0000FDFF
_08061420: .4byte 0x0000BFFF
_08061424: .4byte 0x0300137C
_08061428: .4byte 0x03006F74
	.syntax divided
