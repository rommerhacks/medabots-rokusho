	.syntax unified

	thumb_func_start sub_0802CFAC
sub_0802CFAC: @ 0x0802CFAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov sl, r0
	mov sb, r0
	movs r6, #0
	ldr r1, _0802D00C @ =0x03001800
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #6
	adds r7, r2, #0
_0802CFC8:
	mov r0, r8
	adds r0, #0xd2
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802CFD6
	b _0802D13A
_0802CFD6:
	movs r0, #1
	add sb, r0
	ldr r1, _0802D010 @ =0x03002C30
	adds r5, r6, #0
	adds r5, #0x21
	lsls r0, r5, #6
	adds r4, r0, r1
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0802D042
	adds r0, r5, #0
	movs r1, #0
	bl advance_sprite_anim_frame
	cmp r0, #0
	beq _0802D014
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	b _0802D042
	.align 2, 0
_0802D00C: .4byte 0x03001800
_0802D010: .4byte 0x03002C30
_0802D014:
	ldr r0, _0802D02C @ =0x030018F8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0802D030
	ldrh r0, [r4, #2]
	subs r0, #1
	strh r0, [r4, #2]
	ldrh r0, [r4, #0x18]
	subs r0, #0x10
	b _0802D03A
	.align 2, 0
_0802D02C: .4byte 0x030018F8
_0802D030:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	ldrh r0, [r4, #0x18]
	adds r0, #0x10
_0802D03A:
	ldr r2, _0802D18C @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4, #0x18]
_0802D042:
	mov r4, r8
	adds r4, #0x60
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, #0x5a
	bl sub_080353CC
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, #0x5b
	bl sub_080353CC
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, #0x5c
	bl sub_080353CC
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, #0x5d
	bl sub_080353CC
	add sl, r0
	ldr r2, _0802D190 @ =0x03002C30
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r1, r0, #2
	adds r0, r1, #0
	adds r0, #0x5d
	lsls r0, r0, #6
	adds r0, r0, r2
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _0802D128
	adds r1, #0x5a
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrh r0, [r1, #4]
	adds r0, #8
	strh r0, [r1, #4]
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r1, #0xb6
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #4]
	subs r1, #8
	strh r1, [r0, #4]
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #4]
	subs r1, #8
	strh r1, [r0, #4]
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #4]
	subs r1, #8
	strh r1, [r0, #4]
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r1, #0xb4
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	orrs r1, r7
	strh r1, [r0]
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r1, #0xb6
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	orrs r1, r7
	strh r1, [r0]
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	orrs r1, r7
	strh r1, [r0]
	ldrb r0, [r4]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	orrs r1, r7
	strh r1, [r0]
_0802D128:
	ldrb r1, [r4]
	adds r0, r1, r6
	lsls r0, r0, #2
	adds r0, #0x5d
	adds r2, r6, #0
	adds r2, #0x72
	adds r1, r1, r2
	bl check_sprite_overlap_and_adjust
_0802D13A:
	adds r6, #1
	cmp r6, #2
	bhi _0802D142
	b _0802CFC8
_0802D142:
	cmp sl, sb
	bne _0802D17C
	movs r6, #0
	ldr r4, _0802D194 @ =0x03001800
	adds r7, r4, #0
	adds r7, #0x60
_0802D14E:
	adds r5, r4, #0
	adds r5, #0xd2
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D166
	adds r0, r6, #0
	adds r0, #0x72
	ldrb r2, [r7]
	adds r0, r0, r2
	bl sub_080356B4
_0802D166:
	adds r6, #1
	cmp r6, #2
	bls _0802D14E
	movs r0, #0x41
	bl play_sound_effect
	adds r1, r5, #0
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802D17C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D18C: .4byte 0x000003FF
_0802D190: .4byte 0x03002C30
_0802D194: .4byte 0x03001800
	.syntax divided
