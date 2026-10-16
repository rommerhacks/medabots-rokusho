	.syntax unified

	thumb_func_start process_fade_transition_step
process_fade_transition_step: @ 0x08064908
	push {r4, r5, r6, r7, lr}
	ldr r0, _08064974 @ =0x03000B90
	ldrb r0, [r0]
	movs r1, #0
	ldr r5, _08064978 @ =0x03005010
	cmp r0, #0
	bne _08064918
	movs r1, #4
_08064918:
	adds r0, r5, #0
	adds r0, #0xa
	adds r0, r1, r0
	ldrh r2, [r0]
	ldr r1, _0806497C @ =0x03006F74
	ldr r4, [r1]
	adds r0, r4, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #0
	bne _08064980
	movs r6, #0xfc
	lsls r6, r6, #8
	adds r0, r2, #0
	ands r0, r6
	movs r1, #0xf4
	lsls r1, r1, #8
	cmp r0, r1
	bne _08064966
	lsrs r3, r2, #8
	movs r0, #3
	ands r3, r0
	movs r0, #0xff
	ands r2, r0
	lsls r0, r3, #3
	lsls r2, r0
	ldr r0, [r4, #0x1c]
	orrs r0, r2
	str r0, [r4, #0x1c]
	adds r2, r4, #0
	adds r2, #0x48
	movs r0, #1
	lsls r0, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08064966:
	ldr r0, [r7]
	adds r0, #0x48
	ldrb r0, [r0]
	orrs r0, r6
	strh r0, [r5, #6]
	b _080649C8
	.align 2, 0
_08064974: .4byte 0x03000B90
_08064978: .4byte 0x03005010
_0806497C: .4byte 0x03006F74
_08064980:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r2
	movs r1, #0xfc
	lsls r1, r1, #8
	cmp r0, r1
	bne _080649C8
	ldr r0, _08064998 @ =0x0000FC0F
	cmp r2, r0
	bne _080649B0
	strh r2, [r5, #6]
	b _080649C8
	.align 2, 0
_08064998: .4byte 0x0000FC0F
_0806499C:
	movs r0, #0xff
	ands r3, r0
	lsls r0, r1, #8
	movs r2, #0xf4
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
	orrs r3, r0
	strh r3, [r5, #6]
	b _080649C8
_080649B0:
	ldr r3, [r4, #0x1c]
	movs r1, #0
	movs r4, #1
_080649B6:
	adds r0, r2, #0
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _0806499C
	lsrs r3, r3, #8
	adds r1, #1
	cmp r1, #3
	ble _080649B6
_080649C8:
	ldrh r1, [r5, #0xa]
	ldr r0, _080649F4 @ =0x0000FC0F
	cmp r1, r0
	bne _08064A0C
	ldrh r0, [r5, #0xe]
	cmp r0, r1
	bne _08064A0C
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08064A00
	ldr r1, _080649F8 @ =0x03002B8C
	movs r0, #0x11
	str r0, [r1]
	ldr r1, _080649FC @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	b _08064A0C
	.align 2, 0
_080649F4: .4byte 0x0000FC0F
_080649F8: .4byte 0x03002B8C
_080649FC: .4byte 0x0300137C
_08064A00:
	ldr r1, _08064A14 @ =0x03002B68
	ldr r0, [r2, #0x1c]
	str r0, [r1]
	movs r0, #0
	bl init_game_mode
_08064A0C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08064A14: .4byte 0x03002B68
	.syntax divided
