	.syntax unified

	thumb_func_start sub_0805C428
sub_0805C428: @ 0x0805C428
	push {r4, r5, lr}
	ldr r5, _0805C494 @ =0x03006F74
	ldr r0, [r5]
	movs r1, #0x3a
	ldrsh r0, [r0, r1]
	bl sub_0805BB10
	ldr r1, [r5]
	strh r0, [r1, #0x3a]
	ldr r4, _0805C498 @ =0x03001780
	ldrb r1, [r4]
	movs r0, #0xe
	movs r2, #0x20
	bl sub_08041C14
	ldr r0, [r4]
	movs r1, #0x1f
	ands r0, r1
	bl sub_0805BDC8
	ldr r1, [r5]
	ldrb r0, [r1, #5]
	ldrb r2, [r1, #2]
	movs r1, #0x14
	subs r1, r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0805BB64
	ldr r1, [r5]
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq _0805C46E
	subs r0, #1
	strh r0, [r1, #2]
_0805C46E:
	ldr r3, _0805C49C @ =0x0300058C
	ldrb r2, [r3]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0805C4A4
	movs r0, #1
	bl play_song
	movs r0, #2
	bl play_sound_effect
	ldr r1, [r5]
	ldrb r0, [r1, #5]
	cmp r0, #0
	bne _0805C4A0
	movs r0, #2
	b _0805C4C6
	.align 2, 0
_0805C494: .4byte 0x03006F74
_0805C498: .4byte 0x03001780
_0805C49C: .4byte 0x0300058C
_0805C4A0:
	subs r0, #1
	b _0805C4C6
_0805C4A4:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _0805C4F4
	movs r0, #1
	bl play_song
	movs r0, #2
	bl play_sound_effect
	ldr r1, [r5]
	ldrb r0, [r1, #5]
	cmp r0, #2
	bne _0805C4C4
	movs r0, #0
	b _0805C4C6
_0805C4C4:
	adds r0, #1
_0805C4C6:
	strb r0, [r1, #5]
	ldr r4, _0805C4E8 @ =0x03006F74
	ldr r0, [r4]
	ldrb r0, [r0, #5]
	cmp r0, #2
	bne _0805C4E0
	ldr r1, _0805C4EC @ =0x080AF752
	ldr r0, _0805C4F0 @ =0x03000B94
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl play_song
_0805C4E0:
	ldr r1, [r4]
	movs r0, #0x14
	strh r0, [r1, #2]
	b _0805C668
	.align 2, 0
_0805C4E8: .4byte 0x03006F74
_0805C4EC: .4byte 0x080AF752
_0805C4F0: .4byte 0x03000B94
_0805C4F4:
	ldr r0, [r5]
	ldrb r1, [r0, #5]
	cmp r1, #1
	beq _0805C55E
	cmp r1, #1
	bgt _0805C506
	cmp r1, #0
	beq _0805C50C
	b _0805C5E8
_0805C506:
	cmp r1, #2
	beq _0805C584
	b _0805C5E8
_0805C50C:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0805C530
	movs r0, #2
	bl play_sound_effect
	ldr r1, _0805C528 @ =0x03001788
	ldrb r0, [r1]
	cmp r0, #0
	bne _0805C52C
	movs r0, #2
	b _0805C52E
	.align 2, 0
_0805C528: .4byte 0x03001788
_0805C52C:
	subs r0, #1
_0805C52E:
	strb r0, [r1]
_0805C530:
	ldr r0, _0805C550 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C5E8
	movs r0, #2
	bl play_sound_effect
	ldr r1, _0805C554 @ =0x03001788
	ldrb r0, [r1]
	cmp r0, #2
	bne _0805C558
	movs r0, #0
	strb r0, [r1]
	b _0805C5E8
	.align 2, 0
_0805C550: .4byte 0x0300058C
_0805C554: .4byte 0x03001788
_0805C558:
	adds r0, #1
	strb r0, [r1]
	b _0805C5E8
_0805C55E:
	ldr r0, [r3]
	lsls r1, r0, #0x1a
	lsrs r1, r1, #0x1f
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1f
	orrs r1, r0
	cmp r1, #0
	beq _0805C5E8
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0805C580 @ =0x03001360
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
	b _0805C5E8
	.align 2, 0
_0805C580: .4byte 0x03001360
_0805C584:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0805C5B0
	ldr r0, _0805C59C @ =0x03000B94
	ldrb r2, [r0]
	adds r3, r0, #0
	cmp r2, #0
	bne _0805C5A0
	strb r1, [r3]
	b _0805C5A4
	.align 2, 0
_0805C59C: .4byte 0x03000B94
_0805C5A0:
	subs r0, r2, #1
	strb r0, [r3]
_0805C5A4:
	ldr r0, _0805C5CC @ =0x080AF752
	ldrb r1, [r3]
	adds r1, r1, r0
	ldrb r0, [r1]
	bl play_song
_0805C5B0:
	ldr r0, _0805C5D0 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C5E8
	ldr r0, _0805C5D4 @ =0x03000B94
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #2
	bne _0805C5D8
	movs r0, #0
	b _0805C5DA
	.align 2, 0
_0805C5CC: .4byte 0x080AF752
_0805C5D0: .4byte 0x0300058C
_0805C5D4: .4byte 0x03000B94
_0805C5D8:
	adds r0, r1, #1
_0805C5DA:
	strb r0, [r3]
	ldr r0, _0805C650 @ =0x080AF752
	ldrb r1, [r3]
	adds r1, r1, r0
	ldrb r0, [r1]
	bl play_song
_0805C5E8:
	ldr r4, _0805C654 @ =0x0300058C
	ldrb r1, [r4]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0805C5FE
	ldr r0, _0805C658 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	bl sub_0805BCC0
_0805C5FE:
	ldr r0, [r4]
	lsls r1, r0, #0x1f
	lsrs r1, r1, #0x1f
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	orrs r1, r0
	cmp r1, #0
	beq _0805C698
	movs r0, #1
	bl play_song
	movs r0, #4
	bl play_sound_effect
	ldr r0, _0805C658 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #2
	strb r0, [r1, #5]
	ldr r1, _0805C65C @ =0x03002C30
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _0805C660 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldr r1, _0805C664 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #3
	bl sub_0805BBF8
	movs r0, #3
	movs r1, #0
	bl sub_0805BB64
	movs r0, #3
	bl sub_0805BCC0
	b _0805C698
	.align 2, 0
_0805C650: .4byte 0x080AF752
_0805C654: .4byte 0x0300058C
_0805C658: .4byte 0x03006F74
_0805C65C: .4byte 0x03002C30
_0805C660: .4byte 0x0000BFFF
_0805C664: .4byte 0x0300137C
_0805C668:
	ldr r4, _0805C6A0 @ =0x03006F74
	ldr r0, [r4]
	ldrb r0, [r0, #5]
	bl sub_0805BBF8
	ldr r0, [r4]
	ldrb r0, [r0, #5]
	bl sub_0805BCC0
	ldr r2, _0805C6A4 @ =0x03002C30
	ldr r0, _0805C6A8 @ =0x00000382
	adds r1, r2, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, [r4]
	ldrb r1, [r0, #5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x50
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r2, r2, r1
	strh r0, [r2]
_0805C698:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805C6A0: .4byte 0x03006F74
_0805C6A4: .4byte 0x03002C30
_0805C6A8: .4byte 0x00000382
	.syntax divided
