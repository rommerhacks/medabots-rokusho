	.syntax unified

	thumb_func_start sub_08071F08
sub_08071F08: @ 0x08071F08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08071F2C @ =0x03001800
	ldrb r1, [r0, #0x11]
	adds r2, r1, #0
	adds r5, r0, #0
	cmp r2, #0x40
	bls _08071F30
	movs r0, #0xa
	bl play_sound_effect
	ldrb r0, [r5, #0x10]
	adds r0, #1
	strb r0, [r5, #0x10]
	b _08071FD0
	.align 2, 0
_08071F2C: .4byte 0x03001800
_08071F30:
	cmp r2, #0x1f
	bhi _08071F3A
	movs r0, #0x20
	subs r0, r0, r1
	b _08071F3E
_08071F3A:
	adds r0, r1, #0
	subs r0, #0x20
_08071F3E:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldrb r0, [r5, #0x11]
	cmp r0, #0x20
	bne _08071F4E
	movs r0, #0
	bl sub_0806B584
_08071F4E:
	ldrb r0, [r5, #0x11]
	cmp r0, #0x14
	bne _08071F5A
	movs r0, #0x51
	bl play_sound_effect
_08071F5A:
	movs r0, #0x20
	subs r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r6, #0
	ldr r1, _08071FF4 @ =0x0300700C
	mov sl, r1
	lsls r1, r0, #5
	subs r7, r1, r0
	movs r2, #0xf8
	lsls r2, r2, #2
	mov r8, r2
	movs r0, #0xf8
	lsls r0, r0, #7
	mov ip, r0
	lsls r1, r7, #0xa
	mov sb, r1
	ldr r5, _08071FF8 @ =0x0202FE00
_08071F7E:
	lsls r0, r6, #1
	mov r2, sl
	ldr r1, [r2]
	adds r0, r0, r1
	ldrh r3, [r0]
	movs r0, #0x1f
	ands r0, r3
	adds r2, r0, #0
	muls r2, r4, r2
	adds r2, r2, r7
	asrs r2, r2, #5
	mov r0, r8
	ands r0, r3
	muls r0, r4, r0
	lsls r1, r7, #5
	adds r0, r0, r1
	asrs r0, r0, #5
	mov r1, r8
	ands r0, r1
	adds r2, r2, r0
	mov r0, ip
	ands r0, r3
	muls r0, r4, r0
	add r0, sb
	asrs r0, r0, #5
	mov r1, ip
	ands r0, r1
	adds r2, r2, r0
	strh r2, [r5]
	adds r5, #2
	adds r6, #1
	cmp r6, #0xff
	ble _08071F7E
	ldr r1, _08071FFC @ =0x040000D4
	ldr r2, _08071FF8 @ =0x0202FE00
	str r2, [r1]
	ldr r0, _08072000 @ =0x05000200
	str r0, [r1, #4]
	ldr r0, _08072004 @ =0x84000080
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08071FD0:
	ldr r0, _08072008 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08071FE4
	ldr r1, _0807200C @ =0x03001800
	ldrb r0, [r1, #0x11]
	adds r0, #1
	strb r0, [r1, #0x11]
_08071FE4:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08071FF4: .4byte 0x0300700C
_08071FF8: .4byte 0x0202FE00
_08071FFC: .4byte 0x040000D4
_08072000: .4byte 0x05000200
_08072004: .4byte 0x84000080
_08072008: .4byte 0x03001780
_0807200C: .4byte 0x03001800
	.syntax divided
