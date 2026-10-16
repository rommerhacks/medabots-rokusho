	.syntax unified

	thumb_func_start handle_battle_menu_selection
handle_battle_menu_selection: @ 0x080660EC
	push {r4, lr}
	ldr r1, _08066148 @ =0x03005010
	ldr r0, _0806614C @ =0x03000B90
	ldrb r2, [r0]
	movs r0, #0
	cmp r2, #0
	bne _080660FC
	movs r0, #4
_080660FC:
	adds r3, r1, #0
	adds r3, #0xa
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	movs r1, #0xef
	lsls r1, r1, #8
	cmp r0, r1
	bne _0806615C
	ldr r4, _08066150 @ =0x03006F74
	ldr r1, [r4]
	movs r0, #0
	cmp r2, #0
	bne _0806611E
	movs r0, #4
_0806611E:
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r1, #5]
	ldr r0, [r4]
	adds r0, #0x7a
	movs r1, #1
	strb r1, [r0]
	ldr r1, _08066154 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #4
	bl play_sound_effect
	ldr r1, _08066158 @ =0x03002C30
	ldr r0, [r4]
	ldrb r0, [r0, #5]
	lsls r0, r0, #4
	adds r0, #0x1c
	strh r0, [r1, #4]
	b _080662BC
	.align 2, 0
_08066148: .4byte 0x03005010
_0806614C: .4byte 0x03000B90
_08066150: .4byte 0x03006F74
_08066154: .4byte 0x0300137C
_08066158: .4byte 0x03002C30
_0806615C:
	ldr r0, _0806617C @ =0x03001780
	ldrb r1, [r0]
	movs r0, #0
	movs r2, #0xc
	bl sub_08041C14
	ldr r0, _08066180 @ =0x03006F74
	ldr r3, [r0]
	ldrb r0, [r3, #5]
	cmp r0, #6
	bne _08066188
	ldr r0, _08066184 @ =0x080AFB30
	bl run_message
	b _0806619C
	.align 2, 0
_0806617C: .4byte 0x03001780
_08066180: .4byte 0x03006F74
_08066184: .4byte 0x080AFB30
_08066188:
	ldr r2, _080661C8 @ =0x08485BD8
	ldr r1, _080661CC @ =0x080AFB3F
	ldrb r0, [r3, #5]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl run_message
_0806619C:
	ldr r0, _080661D0 @ =0x03006F74
	ldr r3, [r0]
	ldrb r4, [r3, #5]
	adds r2, r4, #0
	cmp r2, #4
	bls _080661D8
	ldr r0, _080661D4 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0xc1
	ands r0, r1
	cmp r0, #0
	bne _080661B6
	b _080662BC
_080661B6:
	movs r0, #4
	cmp r2, #5
	bne _080661BE
	movs r0, #1
_080661BE:
	strb r0, [r3, #5]
	bl sub_0803FB0C
	b _080662BC
	.align 2, 0
_080661C8: .4byte 0x08485BD8
_080661CC: .4byte 0x080AFB3F
_080661D0: .4byte 0x03006F74
_080661D4: .4byte 0x03001798
_080661D8:
	ldr r0, _080661F0 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08066202
	adds r0, r3, #0
	cmp r2, #0
	beq _080661F4
	subs r1, r4, #1
	b _080661F6
	.align 2, 0
_080661F0: .4byte 0x03001798
_080661F4:
	movs r1, #4
_080661F6:
	strb r1, [r0, #5]
	bl sub_0803FB0C
	movs r0, #2
	bl play_sound_effect
_08066202:
	ldr r0, _0806621C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08066232
	ldr r0, _08066220 @ =0x03006F74
	ldr r0, [r0]
	ldrb r1, [r0, #5]
	cmp r1, #3
	bhi _08066224
	adds r1, #1
	b _08066226
	.align 2, 0
_0806621C: .4byte 0x03001798
_08066220: .4byte 0x03006F74
_08066224:
	movs r1, #0
_08066226:
	strb r1, [r0, #5]
	bl sub_0803FB0C
	movs r0, #2
	bl play_sound_effect
_08066232:
	ldr r1, _0806626C @ =0x03002C30
	ldr r2, _08066270 @ =0x03006F74
	ldr r3, [r2]
	ldrb r0, [r3, #5]
	lsls r0, r0, #4
	adds r0, #0x1c
	strh r0, [r1, #4]
	ldr r0, _08066274 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _080662BC
	ldrb r0, [r3, #5]
	cmp r0, #1
	bne _08066278
	adds r0, r3, #0
	adds r0, #0x7b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08066278
	movs r0, #5
	strb r0, [r3, #5]
	bl sub_0803FB0C
	b _0806628E
	.align 2, 0
_0806626C: .4byte 0x03002C30
_08066270: .4byte 0x03006F74
_08066274: .4byte 0x03001798
_08066278:
	ldr r1, [r4]
	ldrb r0, [r1, #5]
	cmp r0, #2
	bne _08066296
	adds r0, r1, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08066296
_0806628E:
	movs r0, #6
	bl play_sound_effect
	b _080662BC
_08066296:
	ldr r0, [r4]
	adds r0, #0x7a
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080662C4 @ =0x03005010
	ldr r0, [r4]
	ldrb r0, [r0, #5]
	movs r3, #0xef
	lsls r3, r3, #8
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r1, _080662C8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #4
	bl play_sound_effect
_080662BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080662C4: .4byte 0x03005010
_080662C8: .4byte 0x0300137C
	.syntax divided
