	.syntax unified

	thumb_func_start sub_0806C500
sub_0806C500: @ 0x0806C500
	push {r4, r5, r6, lr}
	sub sp, #0x10
	mov r0, sp
	ldr r1, _0806C57C @ =0x080AFF34
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r5, _0806C580 @ =0x03002C30
	ldr r0, _0806C584 @ =0x0000079A
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r3, r5, #0
	cmp r0, #0x4f
	bhi _0806C5EC
	adds r1, r0, #0
	movs r2, #0xf4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	cmp r1, r0
	bgt _0806C59C
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne _0806C59C
	movs r1, #0
	ldr r6, _0806C588 @ =0x083F7FF4
	ldr r0, _0806C58C @ =0x00000A02
	adds r4, r5, r0
_0806C540:
	ldrb r2, [r4, #0x1e]
	cmp r2, #0
	bne _0806C594
	movs r0, #3
	strb r0, [r4, #0x1e]
	ldr r0, _0806C590 @ =0x03001780
	ldr r0, [r0]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	adds r0, r0, r6
	ldrb r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	adds r0, #0x58
	strh r0, [r4]
	movs r0, #0x90
	strh r0, [r4, #2]
	strh r2, [r4, #0x18]
	ldr r1, _0806C584 @ =0x0000079A
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0806C59C
	movs r0, #0x3b
	bl play_sound_effect
	b _0806C59C
	.align 2, 0
_0806C57C: .4byte 0x080AFF34
_0806C580: .4byte 0x03002C30
_0806C584: .4byte 0x0000079A
_0806C588: .4byte 0x083F7FF4
_0806C58C: .4byte 0x00000A02
_0806C590: .4byte 0x03001780
_0806C594:
	adds r4, #0x40
	adds r1, #1
	cmp r1, #7
	ble _0806C540
_0806C59C:
	ldr r0, _0806C5B4 @ =0x03002C30
	ldr r2, _0806C5B8 @ =0x000007A2
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r3, r0, #0
	cmp r1, #0
	beq _0806C5C0
	ldr r4, _0806C5BC @ =0x00000782
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r0, #2
	b _0806C5C8
	.align 2, 0
_0806C5B4: .4byte 0x03002C30
_0806C5B8: .4byte 0x000007A2
_0806C5BC: .4byte 0x00000782
_0806C5C0:
	ldr r0, _0806C5E0 @ =0x00000782
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r0, #2
_0806C5C8:
	strh r0, [r1]
	ldr r2, _0806C5E4 @ =0x00000784
	adds r1, r3, r2
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	ldr r4, _0806C5E8 @ =0x0000079A
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0806C6E6
	.align 2, 0
_0806C5E0: .4byte 0x00000782
_0806C5E4: .4byte 0x00000784
_0806C5E8: .4byte 0x0000079A
_0806C5EC:
	movs r0, #0xf4
	lsls r0, r0, #3
	adds r4, r5, r0
	ldrb r0, [r4]
	subs r0, #1
	movs r6, #0
	strb r0, [r4]
	bl set_bot_y_positions_by_count
	ldrb r4, [r4]
	cmp r4, #0
	beq _0806C6D0
	ldr r0, _0806C6A0 @ =0x0300137C
	movs r1, #3
	str r1, [r0]
	adds r0, r5, #0
	adds r0, #0x20
	strb r1, [r0]
	ldr r1, _0806C6A4 @ =0x000007A1
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _0806C6A8 @ =0x00000786
	adds r0, r5, r2
	movs r2, #0
	strh r6, [r0]
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r6, [r0]
	ldr r4, _0806C6AC @ =0x00000782
	adds r0, r5, r4
	movs r3, #0x78
	strh r3, [r0]
	ldr r0, _0806C6B0 @ =0x00000784
	adds r1, r5, r0
	movs r0, #0x80
	strh r0, [r1]
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0x40
	strb r1, [r0]
	adds r4, #7
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _0806C6B4 @ =0x000007A2
	adds r0, r5, r1
	strb r2, [r0]
	ldr r4, _0806C6B8 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x41
	strb r2, [r0]
	ldr r2, _0806C6BC @ =0x00000806
	adds r1, r5, r2
	movs r0, #7
	strh r0, [r1]
	ldr r1, _0806C6C0 @ =0x00000802
	adds r0, r5, r1
	strh r3, [r0]
	subs r2, #2
	adds r1, r5, r2
	movs r0, #0x10
	strh r0, [r1]
	ldr r3, _0806C6C4 @ =0x0000081A
	adds r0, r5, r3
	strh r6, [r0]
	add r0, sp, #0xc
	strh r6, [r0]
	ldr r1, _0806C6C8 @ =0x040000D4
	str r0, [r1]
	adds r2, #0x1c
	adds r0, r5, r2
	str r0, [r1, #4]
	ldr r0, _0806C6CC @ =0x81000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r4, #0xe]
	adds r0, #0xa
	strb r0, [r4, #0xc]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x32
	ble _0806C696
	movs r0, #0x32
	strb r0, [r4, #0xc]
_0806C696:
	ldrb r0, [r4, #0xd]
	adds r0, #4
	strb r0, [r4, #0xd]
	str r6, [r4, #8]
	b _0806C6E6
	.align 2, 0
_0806C6A0: .4byte 0x0300137C
_0806C6A4: .4byte 0x000007A1
_0806C6A8: .4byte 0x00000786
_0806C6AC: .4byte 0x00000782
_0806C6B0: .4byte 0x00000784
_0806C6B4: .4byte 0x000007A2
_0806C6B8: .4byte 0x03001800
_0806C6BC: .4byte 0x00000806
_0806C6C0: .4byte 0x00000802
_0806C6C4: .4byte 0x0000081A
_0806C6C8: .4byte 0x040000D4
_0806C6CC: .4byte 0x81000008
_0806C6D0:
	movs r0, #0
	bl play_song
	movs r0, #0xf
	bl play_song
	ldr r0, _0806C6F0 @ =0x0300137C
	movs r1, #7
	str r1, [r0]
	ldr r0, _0806C6F4 @ =0x03001800
	str r4, [r0, #8]
_0806C6E6:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806C6F0: .4byte 0x0300137C
_0806C6F4: .4byte 0x03001800
	.syntax divided
