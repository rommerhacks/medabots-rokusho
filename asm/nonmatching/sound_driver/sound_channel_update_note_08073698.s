	.syntax unified

	thumb_func_start sound_channel_update_note_08073698
sound_channel_update_note_08073698: @ 0x08073698
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov r8, r1
	adds r2, r6, #0
	adds r2, #0x66
	ldrb r1, [r2]
	adds r0, #0x40
	ldrh r0, [r0]
	adds r3, r1, #0
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r4, _080736FC @ =0xFFFFF000
	adds r1, r4, #0
	ands r0, r1
	movs r1, #0x4a
	adds r1, r1, r6
	mov ip, r1
	strh r0, [r1]
	movs r3, #0x50
	adds r3, r3, r6
	mov sb, r3
	ldrb r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080736D6
	b _080737EE
_080736D6:
	ldrb r0, [r2]
	cmp r0, #0
	bne _080736DE
	b _080737DC
_080736DE:
	ldr r0, _08073700 @ =0x03007014
	ldr r3, [r0]
	ldr r7, [r6, #0x28]
	adds r0, r6, #0
	adds r0, #0x62
	ldrb r0, [r0]
	cmp r0, #0
	beq _08073706
	adds r0, r6, #0
	adds r0, #0x5e
	ldrb r0, [r0]
	cmp r7, r0
	bls _08073704
	subs r7, r7, r0
	b _08073706
	.align 2, 0
_080736FC: .4byte 0xFFFFF000
_08073700: .4byte 0x03007014
_08073704:
	movs r7, #1
_08073706:
	adds r0, r6, #0
	adds r0, #0x63
	ldrb r0, [r0]
	cmp r0, #1
	beq _08073754
	cmp r0, #1
	bgt _0807371A
	cmp r0, #0
	beq _08073720
	b _080737E2
_0807371A:
	cmp r0, #2
	beq _08073792
	b _080737E2
_08073720:
	adds r0, r6, #0
	adds r0, #0x67
	ldrb r0, [r0]
	movs r4, #0xe4
	lsls r4, r4, #3
	adds r1, r3, r4
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r6, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r1, #0x6a
	movs r3, #0
	ldrsb r3, [r1, r3]
	ldrh r0, [r0]
	adds r3, r3, r0
	mov r1, ip
	ldrh r0, [r1]
	lsrs r0, r0, #0xc
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x6f
	b _080737C2
_08073754:
	adds r0, r6, #0
	adds r0, #0x67
	ldrb r0, [r0]
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r1, r3, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r3, [r0]
	mov r4, ip
	ldrh r0, [r4]
	lsrs r0, r0, #0xc
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x70
	ldrb r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	mov r1, r8
	bl sound_channel_setup_alt
	b _080737E2
_08073792:
	adds r5, r6, #0
	adds r5, #0x48
	ldrh r4, [r5]
	ldr r1, _080737D8 @ =0x00000724
	adds r0, r3, r1
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #0xe5
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ldrh r3, [r0, #2]
	adds r3, r3, r4
	mov r4, ip
	ldrh r0, [r4]
	lsrs r0, r0, #0xc
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [r1]
	ldrh r1, [r5]
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080737C2:
	ldrb r0, [r0]
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x70
	ldrb r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	mov r1, r8
	bl sound_channel_setup
	b _080737E2
	.align 2, 0
_080737D8: .4byte 0x00000724
_080737DC:
	mov r0, r8
	bl sub_08073CA4
_080737E2:
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #0xef
	ands r0, r1
	mov r1, sb
	strb r0, [r1]
_080737EE:
	adds r0, r6, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	beq _08073808
	ldr r0, [r6, #0x38]
	asrs r0, r0, #4
	mov r2, r8
	str r0, [r2, #0x14]
	ldr r0, [r2, #0xc]
	movs r1, #2
	orrs r0, r1
	str r0, [r2, #0xc]
_08073808:
	adds r3, r6, #0
	adds r3, #0x50
	ldrb r2, [r3]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0807383E
	adds r0, r6, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	mov r1, r8
	adds r1, #0x3f
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x70
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x40
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4, #0xc]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0xc]
	movs r0, #0xbf
	ands r0, r2
	strb r0, [r3]
_0807383E:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
