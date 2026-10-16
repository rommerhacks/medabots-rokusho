	.syntax unified

	thumb_func_start sub_080242F8
sub_080242F8: @ 0x080242F8
	push {r4, r5, r6, r7, lr}
	ldr r4, _08024324 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08024372
	movs r0, #0x21
	movs r1, #0
	bl advance_sprite_anim_frame
	cmp r0, #0
	beq _08024328
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	b _08024372
	.align 2, 0
_08024324: .4byte 0x03002C30
_08024328:
	ldr r0, _0802434C @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08024358
	ldr r3, _08024350 @ =0x00000842
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r7, _08024354 @ =0x00000858
	adds r2, r4, r7
	ldrh r0, [r2]
	subs r0, #0x10
	b _0802436A
	.align 2, 0
_0802434C: .4byte 0x03001800
_08024350: .4byte 0x00000842
_08024354: .4byte 0x00000858
_08024358:
	ldr r7, _08024474 @ =0x00000842
	adds r1, r4, r7
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _08024478 @ =0x00000858
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r0, #0x10
_0802436A:
	ldr r3, _0802447C @ =0x000003FF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2]
_08024372:
	ldr r6, _08024480 @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, #0x5a
	bl sub_080353CC
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, #0x5b
	bl sub_080353CC
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, #0x5c
	bl sub_080353CC
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, #0x5d
	bl sub_080353CC
	adds r5, r0, #0
	ldr r3, _08024484 @ =0x03002C30
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r0, r1, #0
	adds r0, #0x5d
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _08024446
	adds r1, #0x5a
	lsls r1, r1, #6
	adds r1, r1, r3
	ldrh r0, [r1, #4]
	adds r0, #8
	strh r0, [r1, #4]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r7, #0xb6
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r1, [r0, #4]
	subs r1, #8
	strh r1, [r0, #4]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r1, [r0, #4]
	subs r1, #8
	strh r1, [r0, #4]
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r7, #0x80
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r1, [r0, #4]
	subs r1, #8
	strh r1, [r0, #4]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r1, #0xb4
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #6
	adds r2, r7, #0
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r1, #0xb6
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r7, #0xb8
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
_08024446:
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5d
	adds r1, #0x72
	bl check_sprite_overlap_and_adjust
	cmp r5, #0
	beq _0802446E
	ldrb r0, [r4]
	adds r0, #0x72
	bl sub_080356B4
	movs r0, #0x41
	bl play_sound_effect
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802446E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024474: .4byte 0x00000842
_08024478: .4byte 0x00000858
_0802447C: .4byte 0x000003FF
_08024480: .4byte 0x03001800
_08024484: .4byte 0x03002C30
	.syntax divided
