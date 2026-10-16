	.syntax unified

	thumb_func_start sub_080402B4
sub_080402B4: @ 0x080402B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _080402E8 @ =0x03000440
	ldrb r0, [r1, #0x18]
	adds r4, r1, #0
	cmp r0, #0
	bne _08040390
	movs r5, #0
	mov r8, r5
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x24
	mov r1, r8
	strb r1, [r0]
_080402D2:
	ldrh r0, [r4, #0xc]
	ldr r1, [r4, #8]
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	cmp r0, #4
	bhi _0804031C
	lsls r0, r0, #2
	ldr r1, _080402EC @ =_080402F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080402E8: .4byte 0x03000440
_080402EC: .4byte _080402F0
_080402F0: @ jump table
	.4byte _0804031C @ case 0
	.4byte _08040304 @ case 1
	.4byte _0804030A @ case 2
	.4byte _08040310 @ case 3
	.4byte _08040316 @ case 4
_08040304:
	adds r0, r4, #0
	adds r0, #0x9e
	b _0804031E
_0804030A:
	adds r0, r4, #0
	adds r0, #0xb2
	b _0804031E
_08040310:
	adds r0, r4, #0
	adds r0, #0xc6
	b _0804031E
_08040316:
	adds r0, r4, #0
	adds r0, #0xda
	b _0804031E
_0804031C:
	ldr r0, _08040348 @ =0x03002B74
_0804031E:
	str r0, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r1, [r0]
	mov r2, r8
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, [r4, #0x20]
	adds r1, r1, r2
	adds r0, r0, r1
	ldrb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _08040350
	ldr r0, _0804034C @ =0x083B4E88
	b _08040352
	.align 2, 0
_08040348: .4byte 0x03002B74
_0804034C: .4byte 0x083B4E88
_08040350:
	ldr r0, _08040388 @ =0x083B4C88
_08040352:
	lsls r1, r2, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, r5, r0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	ldr r1, [r4, #0x20]
	add r0, r8
	adds r1, r1, r0
	ldrb r2, [r1]
	cmp r2, #0xf7
	bls _08040372
	movs r3, #1
_08040372:
	cmp r3, #0
	beq _080402D2
	strb r5, [r4, #0x15]
	ldrb r0, [r4, #0x14]
	adds r0, r0, r5
	cmp r0, #0xd0
	ble _0804038C
	movs r0, #1
	strb r0, [r4, #0x19]
	b _08040390
	.align 2, 0
_08040388: .4byte 0x083B4C88
_0804038C:
	movs r0, #1
	strb r0, [r4, #0x18]
_08040390:
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _08040398
	b _08040552
_08040398:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r1, [r0]
	ldr r0, [r4, #0x20]
	adds r0, r0, r1
	ldrb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _080403B8
	ldr r0, _080403B4 @ =0x083B4E88
	b _080403BA
	.align 2, 0
_080403B4: .4byte 0x083B4E88
_080403B8:
	ldr r0, _080403E0 @ =0x083B4C88
_080403BA:
	lsls r1, r2, #1
	adds r0, r1, r0
	ldrb r5, [r0]
	ldrb r0, [r4, #0x14]
	adds r0, r5, r0
	strb r0, [r4, #0x14]
	ldrb r0, [r4, #0x15]
	subs r0, r0, r5
	strb r0, [r4, #0x15]
	ldrb r0, [r4, #0x16]
	cmp r0, #0
	bne _08040424
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _080403E8
	ldr r0, _080403E4 @ =0x083B4E88
	b _080403EA
	.align 2, 0
_080403E0: .4byte 0x083B4C88
_080403E4: .4byte 0x083B4E88
_080403E8:
	ldr r0, _08040400 @ =0x083B4C88
_080403EA:
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r4, #0x16]
	ldr r0, _08040404 @ =0x03000440
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804040C
	lsls r0, r2, #6
	ldr r1, _08040408 @ =0x084C5188
	b _08040410
	.align 2, 0
_08040400: .4byte 0x083B4C88
_08040404: .4byte 0x03000440
_08040408: .4byte 0x084C5188
_0804040C:
	lsls r0, r2, #6
	ldr r1, _0804041C @ =0x084C01C8
_08040410:
	adds r0, r0, r1
	ldr r1, _08040420 @ =0x02020000
	movs r2, #0x20
	bl CpuSet
	b _08040486
	.align 2, 0
_0804041C: .4byte 0x084C01C8
_08040420: .4byte 0x02020000
_08040424:
	ldrb r0, [r4, #0x16]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804044C
	lsls r0, r2, #6
	ldr r1, _08040444 @ =0x084C5188
	adds r0, r0, r1
	ldr r1, _08040448 @ =0x02020040
	movs r2, #0x20
	bl CpuSet
	b _0804045A
	.align 2, 0
_08040444: .4byte 0x084C5188
_08040448: .4byte 0x02020040
_0804044C:
	lsls r0, r2, #6
	ldr r1, _080404C8 @ =0x084C01C8
	adds r0, r0, r1
	ldr r1, _080404CC @ =0x02020040
	movs r2, #0x20
	bl CpuSet
_0804045A:
	movs r3, #0
	ldr r7, _080404D0 @ =0x02020000
	ldr r6, _080404CC @ =0x02020040
	mov r1, r8
	lsls r4, r1, #2
_08040464:
	lsls r0, r3, #2
	adds r2, r0, r7
	adds r0, r0, r6
	ldr r1, [r0]
	lsls r1, r4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bls _08040464
	ldr r1, _080404D4 @ =0x03000440
	ldrb r0, [r1, #0x16]
	adds r0, r5, r0
	strb r0, [r1, #0x16]
_08040486:
	ldr r1, _080404D4 @ =0x03000440
	ldrb r0, [r1, #0x16]
	adds r4, r1, #0
	cmp r0, #7
	bls _08040538
	ldrb r1, [r4, #0x14]
	lsrs r1, r1, #3
	subs r1, #1
	lsls r1, r1, #0x18
	ldr r5, _080404D0 @ =0x02020000
	lsrs r1, r1, #0x12
	ldrb r2, [r4, #0x17]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r2, _080404D8 @ =0x06000280
	adds r0, r0, r2
	adds r1, r1, r0
	adds r0, r5, #0
	movs r2, #0x20
	bl CpuSet
	movs r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x16]
	cmp r0, #8
	bne _080404DC
	movs r0, #0
	strb r0, [r4, #0x16]
	b _08040538
	.align 2, 0
_080404C8: .4byte 0x084C01C8
_080404CC: .4byte 0x02020040
_080404D0: .4byte 0x02020000
_080404D4: .4byte 0x03000440
_080404D8: .4byte 0x06000280
_080404DC:
	subs r0, #8
	strb r0, [r4, #0x16]
	movs r0, #8
	mov r1, r8
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _08040508
	ldr r0, _08040504 @ =0x084C5188
	adds r1, r5, #0
	movs r2, #0x20
	bl CpuSet
	b _08040512
	.align 2, 0
_08040504: .4byte 0x084C5188
_08040508:
	ldr r0, _0804055C @ =0x084C01C8
	adds r1, r5, #0
	movs r2, #0x20
	bl CpuSet
_08040512:
	movs r3, #0
	ldr r4, _08040560 @ =0x03000440
	ldr r7, _08040564 @ =0x02020000
	ldr r6, _08040568 @ =0x02020040
	mov r2, r8
	lsls r5, r2, #2
_0804051E:
	lsls r0, r3, #2
	adds r2, r0, r7
	adds r0, r0, r6
	ldr r1, [r0]
	lsrs r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bls _0804051E
_08040538:
	adds r1, r4, #0
	ldrb r0, [r1, #0x15]
	cmp r0, #0
	bne _08040548
	strb r0, [r1, #0x18]
	ldrh r0, [r1, #0xc]
	adds r0, #2
	strh r0, [r1, #0xc]
_08040548:
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08040552:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804055C: .4byte 0x084C01C8
_08040560: .4byte 0x03000440
_08040564: .4byte 0x02020000
_08040568: .4byte 0x02020040
	.syntax divided
