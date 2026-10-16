	.syntax unified

	thumb_func_start options_menu_handler
options_menu_handler: @ 0x0805F320
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0805F368 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #0
	movs r2, #0x14
	bl sub_08041C14
	ldr r0, _0805F36C @ =0x03006F74
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x48
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805F34E
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805F34E
	movs r0, #2
	bl play_sound_effect
_0805F34E:
	ldr r0, _0805F370 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0805F388
	ldr r0, _0805F36C @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0805F374
	subs r0, #1
	b _0805F376
	.align 2, 0
_0805F368: .4byte 0x03001780
_0805F36C: .4byte 0x03006F74
_0805F370: .4byte 0x03001798
_0805F374:
	movs r0, #3
_0805F376:
	strb r0, [r1, #5]
	movs r0, #0
	bl play_song
	ldr r0, _0805F3A4 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x48
	movs r1, #2
	strb r1, [r0]
_0805F388:
	ldr r0, _0805F3A8 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805F3C0
	ldr r0, _0805F3A4 @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	cmp r0, #2
	bhi _0805F3AC
	adds r0, #1
	b _0805F3AE
	.align 2, 0
_0805F3A4: .4byte 0x03006F74
_0805F3A8: .4byte 0x03001798
_0805F3AC:
	movs r0, #0
_0805F3AE:
	strb r0, [r1, #5]
	movs r0, #0
	bl play_song
	ldr r0, _0805F40C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x48
	movs r1, #2
	strb r1, [r0]
_0805F3C0:
	ldr r0, _0805F410 @ =0x03002C30
	mov ip, r0
	ldr r2, _0805F40C @ =0x03006F74
	ldr r1, [r2]
	ldrb r0, [r1, #5]
	lsls r0, r0, #4
	adds r0, #0x20
	movs r5, #0
	mov r3, ip
	strh r0, [r3, #4]
	ldrb r0, [r1, #5]
	adds r6, r2, #0
	mov r4, ip
	cmp r0, #0
	beq _0805F418
	cmp r0, #1
	beq _0805F47C
	adds r3, #0x40
	ldrh r2, [r3]
	ldr r1, _0805F414 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	adds r3, #0x40
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	adds r3, #0x40
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #1
	add r2, ip
	b _0805F470
	.align 2, 0
_0805F40C: .4byte 0x03006F74
_0805F410: .4byte 0x03002C30
_0805F414: .4byte 0x0000BFFF
_0805F418:
	ldr r0, _0805F440 @ =0x03001780
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0805F444
	mov r1, ip
	adds r1, #0x40
	ldrh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r2, r3, #0
	orrs r0, r2
	strh r0, [r1]
	adds r1, #0x40
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	b _0805F45C
	.align 2, 0
_0805F440: .4byte 0x03001780
_0805F444:
	mov r3, ip
	adds r3, #0x40
	ldrh r2, [r3]
	ldr r1, _0805F478 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	mov r2, ip
	adds r2, #0x80
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
_0805F45C:
	adds r3, r4, #0
	adds r3, #0xc0
	ldrh r2, [r3]
	ldr r1, _0805F478 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r4, r0
_0805F470:
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	b _0805F4E2
	.align 2, 0
_0805F478: .4byte 0x0000BFFF
_0805F47C:
	mov r2, ip
	adds r2, #0x40
	ldrh r1, [r2]
	ldr r3, _0805F4C0 @ =0x0000BFFF
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2]
	adds r2, #0x40
	ldrh r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0805F4C4 @ =0x03001780
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0805F4C8
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r2, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	b _0805F4E2
	.align 2, 0
_0805F4C0: .4byte 0x0000BFFF
_0805F4C4: .4byte 0x03001780
_0805F4C8:
	mov r2, ip
	adds r2, #0xc0
	ldrh r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #1
	add r2, ip
	ldrh r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2]
_0805F4E2:
	ldr r2, [r6]
	ldrb r0, [r2, #5]
	cmp r0, #0
	beq _0805F4F0
	cmp r0, #1
	beq _0805F594
	b _0805F622
_0805F4F0:
	ldr r0, _0805F508 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0805F534
	adds r2, #0x2b
	ldrb r0, [r2]
	cmp r0, #0
	beq _0805F50C
	subs r0, #1
	b _0805F50E
	.align 2, 0
_0805F508: .4byte 0x03001798
_0805F50C:
	movs r0, #0x33
_0805F50E:
	strb r0, [r2]
	ldr r0, _0805F554 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	movs r2, #2
	str r2, [sp]
	ldr r2, _0805F558 @ =0x0400000A
	ldrh r2, [r2]
	lsrs r2, r2, #8
	movs r3, #0x1f
	ands r2, r3
	str r2, [sp, #4]
	movs r2, #0x10
	movs r3, #4
	bl draw_tilemap_line
_0805F534:
	ldr r0, _0805F55C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805F622
	ldr r0, _0805F554 @ =0x03006F74
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0x32
	bhi _0805F560
	adds r0, #1
	b _0805F562
	.align 2, 0
_0805F554: .4byte 0x03006F74
_0805F558: .4byte 0x0400000A
_0805F55C: .4byte 0x03001798
_0805F560:
	movs r0, #0
_0805F562:
	strb r0, [r1]
	ldr r0, _0805F58C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	movs r2, #2
	str r2, [sp]
	ldr r2, _0805F590 @ =0x0400000A
	ldrh r2, [r2]
	lsrs r2, r2, #8
	movs r3, #0x1f
	ands r2, r3
	str r2, [sp, #4]
	movs r2, #0x10
	movs r3, #4
	bl draw_tilemap_line
	b _0805F622
	.align 2, 0
_0805F58C: .4byte 0x03006F74
_0805F590: .4byte 0x0400000A
_0805F594:
	ldr r0, _0805F5AC @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0805F5D6
	ldrh r0, [r2, #0x2c]
	cmp r0, #0
	beq _0805F5B0
	subs r0, #1
	b _0805F5B2
	.align 2, 0
_0805F5AC: .4byte 0x03001798
_0805F5B0:
	movs r0, #0x75
_0805F5B2:
	strh r0, [r2, #0x2c]
	ldr r0, _0805F5F0 @ =0x03006F74
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	movs r1, #3
	rsbs r1, r1, #0
	movs r2, #2
	str r2, [sp]
	ldr r2, _0805F5F4 @ =0x0400000A
	ldrh r2, [r2]
	lsrs r2, r2, #8
	movs r3, #0x1f
	ands r2, r3
	str r2, [sp, #4]
	movs r2, #0xf
	movs r3, #6
	bl draw_tilemap_line
_0805F5D6:
	ldr r0, _0805F5F8 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805F622
	ldr r0, _0805F5F0 @ =0x03006F74
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	cmp r0, #0x74
	bhi _0805F5FC
	adds r0, #1
	b _0805F5FE
	.align 2, 0
_0805F5F0: .4byte 0x03006F74
_0805F5F4: .4byte 0x0400000A
_0805F5F8: .4byte 0x03001798
_0805F5FC:
	movs r0, #0
_0805F5FE:
	strh r0, [r1, #0x2c]
	ldr r0, _0805F678 @ =0x03006F74
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	movs r1, #3
	rsbs r1, r1, #0
	movs r2, #2
	str r2, [sp]
	ldr r2, _0805F67C @ =0x0400000A
	ldrh r2, [r2]
	lsrs r2, r2, #8
	movs r3, #0x1f
	ands r2, r3
	str r2, [sp, #4]
	movs r2, #0xf
	movs r3, #6
	bl draw_tilemap_line
_0805F622:
	ldr r5, _0805F678 @ =0x03006F74
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0x4b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805F634
	subs r0, #1
	strb r0, [r1]
_0805F634:
	ldr r1, [r5]
	adds r2, r1, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	cmp r0, #0
	beq _0805F656
	adds r0, r1, #0
	adds r0, #0x4b
	ldrb r4, [r0]
	cmp r4, #0
	bne _0805F656
	ldrb r0, [r2]
	bl play_sound_effect
	ldr r0, [r5]
	adds r0, #0x4a
	strb r4, [r0]
_0805F656:
	ldr r0, _0805F680 @ =0x0300058C
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0805F6FE
	ldr r2, _0805F678 @ =0x03006F74
	ldr r0, [r2]
	ldrb r1, [r0, #5]
	cmp r1, #1
	beq _0805F6A4
	cmp r1, #1
	bgt _0805F684
	cmp r1, #0
	beq _0805F68E
	b _0805F75E
	.align 2, 0
_0805F678: .4byte 0x03006F74
_0805F67C: .4byte 0x0400000A
_0805F680: .4byte 0x0300058C
_0805F684:
	cmp r1, #2
	beq _0805F6CC
	cmp r1, #3
	beq _0805F6F4
	b _0805F75E
_0805F68E:
	ldr r1, _0805F6A0 @ =0x080AF854
	adds r0, #0x2b
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl play_song
	b _0805F75E
	.align 2, 0
_0805F6A0: .4byte 0x080AF854
_0805F6A4:
	adds r1, r0, #0
	adds r1, #0x4b
	movs r0, #2
	strb r0, [r1]
	ldr r1, [r2]
	ldr r2, _0805F6C8 @ =0x080AF888
	ldrh r0, [r1, #0x2c]
	adds r0, r0, r2
	ldrb r0, [r0]
	adds r1, #0x4a
	strb r0, [r1]
	movs r0, #0
	bl play_song
	movs r0, #0
	bl play_sound_effect
	b _0805F75E
	.align 2, 0
_0805F6C8: .4byte 0x080AF888
_0805F6CC:
	movs r0, #4
	bl play_sound_effect
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _0805F6F0 @ =0x0300137C
	movs r0, #6
	str r0, [r1]
	b _0805F75E
	.align 2, 0
_0805F6F0: .4byte 0x0300137C
_0805F6F4:
	adds r1, r0, #0
	adds r1, #0x49
	movs r0, #0
	strb r0, [r1]
	b _0805F70E
_0805F6FE:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0805F75E
	ldr r0, _0805F768 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x49
	strb r2, [r0]
_0805F70E:
	movs r0, #0
	bl play_song
	ldr r0, _0805F768 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0805F76C @ =0x0300137C
	movs r0, #5
	str r0, [r1]
	ldr r0, _0805F770 @ =0x03002C30
	mov ip, r0
	ldrh r2, [r0]
	ldr r1, _0805F774 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r2
	mov r2, ip
	strh r0, [r2]
	mov r3, ip
	adds r3, #0x40
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	adds r3, #0x40
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	adds r3, #0x40
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #1
	add r2, ip
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
_0805F75E:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805F768: .4byte 0x03006F74
_0805F76C: .4byte 0x0300137C
_0805F770: .4byte 0x03002C30
_0805F774: .4byte 0x0000BFFF
	.syntax divided
