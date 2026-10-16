	.syntax unified

	thumb_func_start sub_0800D3E4
sub_0800D3E4: @ 0x0800D3E4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r0, _0800D420 @ =0x0300058C
	ldr r0, [r0]
	lsls r1, r0, #0x19
	lsrs r1, r1, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1f
	orrs r1, r0
	ldr r4, _0800D424 @ =0x03000440
	cmp r1, #0
	beq _0800D40E
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_0800D40E:
	adds r2, r4, #0
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r6, #0
	beq _0800D428
	cmp r6, #1
	beq _0800D4A4
	b _0800D510
	.align 2, 0
_0800D420: .4byte 0x0300058C
_0800D424: .4byte 0x03000440
_0800D428:
	ldr r0, _0800D440 @ =0x03001780
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D444
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800D46E
	.align 2, 0
_0800D440: .4byte 0x03001780
_0800D444:
	ldr r0, _0800D49C @ =0x083ACB40
	ldr r0, [r0]
	adds r4, r2, #0
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800D46E:
	ldr r0, _0800D49C @ =0x083ACB40
	ldr r0, [r0, #4]
	ldr r4, _0800D4A0 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	bl render_text_sprites_08040DB8
	b _0800D510
	.align 2, 0
_0800D49C: .4byte 0x083ACB40
_0800D4A0: .4byte 0x030004DE
_0800D4A4:
	ldr r0, _0800D4BC @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800D4C0
	movs r0, #0x10
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800D4E6
	.align 2, 0
_0800D4BC: .4byte 0x03001780
_0800D4C0:
	ldr r0, _0800D538 @ =0x083ACB40
	ldr r0, [r0, #4]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	bl render_text_sprites_08040DB8
_0800D4E6:
	ldr r0, _0800D538 @ =0x083ACB40
	ldr r0, [r0]
	ldr r4, _0800D53C @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800D510:
	ldr r2, _0800D540 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D55C
	ldr r0, _0800D544 @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x34
	ldrb r4, [r3]
	cmp r4, #0
	bne _0800D548
	adds r0, #0x35
	ldrb r3, [r3]
	adds r3, r0, r3
	ldrb r0, [r3]
	cmp r0, #0x7f
	bne _0800D558
	strb r4, [r3]
	b _0800D55C
	.align 2, 0
_0800D538: .4byte 0x083ACB40
_0800D53C: .4byte 0x030004DE
_0800D540: .4byte 0x03001798
_0800D544: .4byte 0x03000440
_0800D548:
	adds r0, #0x35
	ldrb r3, [r3]
	adds r3, r0, r3
	ldrb r0, [r3]
	cmp r0, #0x35
	bne _0800D558
	movs r0, #0
	b _0800D55A
_0800D558:
	adds r0, #1
_0800D55A:
	strb r0, [r3]
_0800D55C:
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D59E
	ldr r2, _0800D584 @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D588
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D59A
	movs r0, #0x7f
	b _0800D59C
	.align 2, 0
_0800D584: .4byte 0x03000440
_0800D588:
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D59A
	movs r0, #0x35
	b _0800D59C
_0800D59A:
	subs r0, #1
_0800D59C:
	strb r0, [r1]
_0800D59E:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r7, _0800D624 @ =0x030004DE
	movs r0, #0x69
	rsbs r0, r0, #0
	adds r0, r0, r7
	mov sb, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl divide_by_100000_08041370
	movs r6, #3
	str r6, [sp]
	movs r5, #0xf
	str r5, [sp, #4]
	movs r1, #1
	mov r8, r1
	str r1, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	adds r0, r7, #0
	movs r1, #0x20
	movs r2, #8
	movs r3, #2
	bl render_text_sprites_08040DB8
	movs r0, #0x23
	movs r1, #3
	bl clear_battle_sprite_slot
	adds r0, r7, #0
	subs r0, #0x68
	ldrb r1, [r0]
	adds r0, r7, #0
	bl divide_by_100000_08041370
	str r6, [sp]
	str r5, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r7, #0
	movs r1, #0x23
	movs r2, #8
	movs r3, #4
	bl render_text_sprites_08040DB8
	ldr r0, _0800D628 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D630
	movs r0, #0
	bl play_song
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800D62C @ =0x0300137C
	mov r1, r8
	str r1, [r0]
	b _0800D656
	.align 2, 0
_0800D624: .4byte 0x030004DE
_0800D628: .4byte 0x0300058C
_0800D62C: .4byte 0x0300137C
_0800D630:
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _0800D656
	adds r1, r7, #0
	subs r1, #0x6a
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D64C
	add r0, sb
	ldrb r0, [r0]
	bl play_sound_effect
	b _0800D656
_0800D64C:
	ldrb r0, [r1]
	add r0, sb
	ldrb r0, [r0]
	bl play_song
_0800D656:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
