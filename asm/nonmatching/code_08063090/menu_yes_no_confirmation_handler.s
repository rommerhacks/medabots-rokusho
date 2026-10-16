	.syntax unified

	thumb_func_start menu_yes_no_confirmation_handler
menu_yes_no_confirmation_handler: @ 0x08066580
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, _080665F8 @ =0x08485BD8
	ldr r5, [r0, #0x3c]
	ldr r3, _080665FC @ =0x03006F74
	ldr r1, [r3]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r4, r1, r0
	movs r0, #0xfb
	strb r0, [r4]
	ldr r0, _08066600 @ =0x00000271
	adds r4, r1, r0
	movs r2, #0
	strb r2, [r4]
	adds r0, #1
	adds r4, r1, r0
	movs r0, #0xc
	strb r0, [r4]
	ldr r0, _08066604 @ =0x00000273
	adds r4, r1, r0
	strb r2, [r4]
	adds r0, #1
	adds r4, r1, r0
	movs r2, #0
	adds r1, r4, #0
_080665B4:
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, #1
	adds r2, #1
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080665B4
	adds r1, r4, r2
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	adds r1, r4, r2
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r3]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r0, r1
	bl run_message
	cmp r0, #0
	beq _0806667E
	ldr r0, _08066608 @ =0x03000440
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _08066610
	ldr r1, _0806660C @ =0x03005010
	movs r0, #0xff
	lsls r0, r0, #8
	b _08066614
	.align 2, 0
_080665F8: .4byte 0x08485BD8
_080665FC: .4byte 0x03006F74
_08066600: .4byte 0x00000271
_08066604: .4byte 0x00000273
_08066608: .4byte 0x03000440
_0806660C: .4byte 0x03005010
_08066610:
	ldr r1, _08066660 @ =0x03005010
	ldr r0, _08066664 @ =0x0000FF01
_08066614:
	strh r0, [r1, #6]
	ldrh r6, [r1, #0xa]
	ldrh r4, [r1, #0xe]
	movs r0, #0xff
	lsls r0, r0, #8
	adds r1, r6, #0
	ands r1, r0
	cmp r1, r0
	bne _0806667E
	adds r5, r4, #0
	ands r5, r1
	cmp r5, r1
	bne _0806667E
	bl sub_0803FB0C
	cmp r6, r4
	bne _08066670
	ldr r4, _08066668 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x50
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl init_blend_effect
	ldr r1, _0806666C @ =0x0300137C
	movs r0, #5
	str r0, [r1]
	ldr r1, [r4]
	eors r6, r5
	rsbs r0, r6, #0
	lsrs r0, r0, #0x1f
	adds r1, #0x4a
	strb r0, [r1]
	b _0806667E
	.align 2, 0
_08066660: .4byte 0x03005010
_08066664: .4byte 0x0000FF01
_08066668: .4byte 0x03006F74
_0806666C: .4byte 0x0300137C
_08066670:
	ldr r1, _08066688 @ =0x0300137C
	movs r0, #3
	str r0, [r1]
	ldr r0, _0806668C @ =0x03006F74
	ldr r1, [r0]
	movs r0, #6
	strb r0, [r1, #5]
_0806667E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08066688: .4byte 0x0300137C
_0806668C: .4byte 0x03006F74
	.syntax divided
