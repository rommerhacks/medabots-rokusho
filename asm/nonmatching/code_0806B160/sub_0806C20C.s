	.syntax unified

	thumb_func_start sub_0806C20C
sub_0806C20C: @ 0x0806C20C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r0, #0
	str r0, [sp, #4]
	ldr r6, _0806C258 @ =0x03002C30
	adds r2, r6, #0
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r1, r6, r1
	str r1, [sp, #8]
	movs r3, #0x28
	str r3, [sp, #0xc]
	ldr r0, _0806C25C @ =0x00000A21
	adds r0, r0, r6
	mov sl, r0
	ldr r1, _0806C260 @ =0x00000C02
	adds r1, r1, r6
	mov sb, r1
	ldr r3, _0806C264 @ =0x00000A02
	adds r4, r6, r3
_0806C23C:
	ldrb r5, [r4, #0x1e]
	cmp r5, #1
	beq _0806C268
	cmp r5, #1
	bgt _0806C248
	b _0806C498
_0806C248:
	cmp r5, #2
	bne _0806C24E
	b _0806C428
_0806C24E:
	cmp r5, #3
	bne _0806C254
	b _0806C46A
_0806C254:
	b _0806C498
	.align 2, 0
_0806C258: .4byte 0x03002C30
_0806C25C: .4byte 0x00000A21
_0806C260: .4byte 0x00000C02
_0806C264: .4byte 0x00000A02
_0806C268:
	ldrb r1, [r4, #0x1f]
	subs r1, #1
	ldrh r0, [r4, #0x18]
	lsrs r0, r0, #2
	adds r0, #0x18
	muls r1, r0, r1
	adds r1, #0x78
	movs r3, #0
	strh r1, [r4]
	ldrh r0, [r4, #0x18]
	lsls r0, r0, #1
	adds r0, #0xc
	strh r0, [r4, #2]
	ldr r0, [sp, #4]
	adds r0, #0x30
	lsls r0, r0, #6
	adds r2, r0, r2
	strh r1, [r2, #2]
	ldrh r0, [r4, #2]
	adds r0, #4
	strh r0, [r2, #4]
	ldrh r0, [r4, #0x18]
	cmp r0, #0x38
	bhi _0806C29A
	b _0806C490
_0806C29A:
	cmp r0, #0x3f
	bls _0806C378
	movs r0, #3
	strb r0, [r4, #0x1e]
	strh r3, [r4, #0x18]
	movs r0, #0x90
	strh r0, [r4, #2]
	movs r0, #0xc8
	strh r0, [r2, #4]
	ldr r1, _0806C2E8 @ =0x000007A1
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _0806C350
	strb r5, [r0]
	ldr r2, _0806C2EC @ =0x0000079A
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _0806C2F0 @ =0x03001800
	adds r5, r0, #0
	adds r5, #0x41
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #5
	bl sub_0807CBBC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C2F8
	ldrb r0, [r4, #0x1f]
	movs r1, #2
	eors r0, r1
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	ldr r3, _0806C2F4 @ =0x000007A2
	adds r1, r6, r3
	strb r0, [r1]
	b _0806C30A
	.align 2, 0
_0806C2E8: .4byte 0x000007A1
_0806C2EC: .4byte 0x0000079A
_0806C2F0: .4byte 0x03001800
_0806C2F4: .4byte 0x000007A2
_0806C2F8:
	movs r1, #0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _0806C304
	movs r1, #1
_0806C304:
	ldr r2, _0806C358 @ =0x000007A2
	adds r0, r6, r2
	strb r1, [r0]
_0806C30A:
	movs r3, #0x9c
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r2, #0
	strb r2, [r0]
	ldr r1, _0806C35C @ =0x000004E1
	adds r0, r6, r1
	strb r2, [r0]
	subs r3, #0x1c
	adds r1, r6, r3
	movs r0, #0xc8
	strh r0, [r1]
	ldr r1, _0806C360 @ =0x000004DA
	adds r0, r6, r1
	strh r2, [r0]
	movs r0, #3
	str r0, [sp]
	movs r0, #0x21
	ldr r1, _0806C364 @ =0x0000CC08
	movs r2, #0x12
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806C368 @ =0x00000782
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _0806C36C @ =0x00000842
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _0806C370 @ =0x00000784
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #0xc
	ldr r2, _0806C374 @ =0x03003474
	strh r0, [r2]
_0806C350:
	movs r0, #0x3b
	bl play_sound_effect
	b _0806C490
	.align 2, 0
_0806C358: .4byte 0x000007A2
_0806C35C: .4byte 0x000004E1
_0806C360: .4byte 0x000004DA
_0806C364: .4byte 0x0000CC08
_0806C368: .4byte 0x00000782
_0806C36C: .4byte 0x00000842
_0806C370: .4byte 0x00000784
_0806C374: .4byte 0x03003474
_0806C378:
	ldr r3, _0806C410 @ =0x000007A1
	adds r0, r6, r3
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _0806C386
	b _0806C490
_0806C386:
	ldr r7, _0806C414 @ =0x03001800
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #5
	bl sub_0807CBBC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	mov r1, sl
	ldrb r1, [r1]
	cmp r0, r1
	bne _0806C490
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0806C3B8
	ldrb r1, [r7, #0xe]
	movs r0, #2
	ands r0, r1
	mov r2, sl
	strb r0, [r2]
_0806C3B8:
	movs r0, #2
	strb r0, [r4, #0x1e]
	movs r0, #3
	str r0, [sp]
	movs r0, #0x38
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r2, #0x17
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	ldrh r1, [r4]
	ldr r3, _0806C418 @ =0x00000E02
	adds r0, r6, r3
	strh r1, [r0]
	ldr r2, _0806C41C @ =0x08485E84
	ldrh r1, [r4, #0x18]
	movs r0, #0x3f
	ands r0, r1
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r4, #2]
	subs r0, r0, r1
	ldr r2, _0806C420 @ =0x00000E04
	adds r1, r6, r2
	strh r0, [r1]
	adds r3, #0x1e
	adds r0, r6, r3
	strb r5, [r0]
	ldr r1, _0806C424 @ =0x00000E1A
	adds r0, r6, r1
	mov r2, r8
	strh r2, [r0]
	movs r3, #0x9c
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x68
	bl play_sound_effect
	b _0806C490
	.align 2, 0
_0806C410: .4byte 0x000007A1
_0806C414: .4byte 0x03001800
_0806C418: .4byte 0x00000E02
_0806C41C: .4byte 0x08485E84
_0806C420: .4byte 0x00000E04
_0806C424: .4byte 0x00000E1A
_0806C428:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _0806C434
	ldrh r0, [r4]
	subs r0, #4
	b _0806C438
_0806C434:
	ldrh r0, [r4]
	adds r0, #4
_0806C438:
	strh r0, [r4]
	ldrh r0, [r4, #0x18]
	lsls r0, r0, #1
	adds r0, #0xc
	movs r1, #0
	strh r0, [r4, #2]
	ldrh r0, [r4]
	mov r3, sb
	strh r0, [r3]
	ldrh r0, [r4, #2]
	adds r0, #4
	strh r0, [r3, #2]
	ldrh r0, [r4, #0x18]
	cmp r0, #0x27
	bhi _0806C460
	strb r1, [r4, #0x1f]
	strb r1, [r4, #0x1e]
	movs r0, #0xc8
	strh r0, [r4, #2]
	strh r0, [r3, #2]
_0806C460:
	ldr r1, [sp, #8]
	ldrh r0, [r1, #0x1a]
	subs r0, #1
	strh r0, [r1, #0x1a]
	b _0806C498
_0806C46A:
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	bne _0806C482
	str r5, [sp]
	ldr r0, [sp, #0xc]
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r2, #0x13
	movs r3, #3
	bl init_battle_sprite_entry_08048818
	b _0806C490
_0806C482:
	cmp r0, #0xf
	bls _0806C490
	ldr r2, [sp, #0xc]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	bl clear_sprite_entry
_0806C490:
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
	ldr r2, _0806C4C8 @ =0x03002C30
_0806C498:
	ldr r3, [sp, #8]
	adds r3, #0x40
	str r3, [sp, #8]
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	movs r1, #0x40
	add sl, r1
	add sb, r1
	adds r4, #0x40
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
	cmp r3, #7
	bgt _0806C4B8
	b _0806C23C
_0806C4B8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C4C8: .4byte 0x03002C30
	.syntax divided
