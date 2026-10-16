	.syntax unified

	thumb_func_start sub_08037330
	.global sub_08037330
sub_08037330: @ 0x08037330
	push {r4, r5, lr}
	ands r1, r2
	cmp r1, #0
	beq _08037380
	ldr r3, _0803737C @ =0x03002C30
	lsls r4, r0, #2
	adds r0, r4, #0
	adds r0, #0x5a
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #8
	adds r2, r5, #0
	orrs r1, r2
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0x5b
	lsls r1, r1, #6
	adds r1, r1, r3
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x5c
	lsls r1, r1, #6
	adds r1, r1, r3
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x5d
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r1, [r0]
	orrs r2, r1
	b _080373C4
	.align 2, 0
_0803737C: .4byte 0x03002C30
_08037380:
	ldr r4, _080373CC @ =0x03002C30
	lsls r0, r0, #2
	mov ip, r0
	mov r1, ip
	adds r1, #0x5a
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrh r3, [r1]
	ldr r2, _080373D0 @ =0x00007FFF
	adds r0, r2, #0
	ands r0, r3
	strh r0, [r1]
	mov r1, ip
	adds r1, #0x5b
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrh r3, [r1]
	adds r0, r2, #0
	ands r0, r3
	strh r0, [r1]
	mov r1, ip
	adds r1, #0x5c
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrh r3, [r1]
	adds r0, r2, #0
	ands r0, r3
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x5d
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrh r1, [r0]
	ands r2, r1
_080373C4:
	strh r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080373CC: .4byte 0x03002C30
_080373D0: .4byte 0x00007FFF
	.syntax divided
