	.syntax unified

	thumb_func_start update_fade_transition_state_080662CC
update_fade_transition_state_080662CC: @ 0x080662CC
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, _080662EC @ =0x03006F74
	ldr r4, [r1]
	adds r2, r4, #0
	adds r2, #0x7a
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r5, r1, #0
	cmp r0, #0
	beq _080662F8
	ldr r1, _080662F0 @ =0x03005010
	ldr r0, _080662F4 @ =0x0000FE0F
	strh r0, [r1, #6]
	adds r6, r1, #0
	b _08066350
	.align 2, 0
_080662EC: .4byte 0x03006F74
_080662F0: .4byte 0x03005010
_080662F4: .4byte 0x0000FE0F
_080662F8:
	ldr r0, _08066320 @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806633C
	ldr r0, _08066324 @ =0x03005010
	ldrh r3, [r0, #0xa]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r3
	movs r2, #0xef
	lsls r2, r2, #8
	adds r6, r0, #0
	cmp r1, r2
	bne _08066328
	strb r3, [r4, #5]
	ldr r0, [r5]
	adds r0, #0x7a
	movs r1, #1
	strb r1, [r0]
	b _08066350
	.align 2, 0
_08066320: .4byte 0x03000B90
_08066324: .4byte 0x03005010
_08066328:
	lsls r0, r3, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08066338 @ =0x0000FE0F
	cmp r1, r0
	bne _08066350
	strh r1, [r6, #6]
	b _08066350
	.align 2, 0
_08066338: .4byte 0x0000FE0F
_0806633C:
	strb r0, [r2]
	ldr r2, _0806636C @ =0x03005010
	ldr r0, [r5]
	ldrb r0, [r0, #5]
	movs r3, #0xef
	lsls r3, r3, #8
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #6]
	adds r6, r2, #0
_08066350:
	ldrh r1, [r6, #0xe]
	ldr r0, _08066370 @ =0x0000FE0F
	cmp r1, r0
	bne _08066392
	ldr r1, [r5]
	ldrb r0, [r1, #5]
	cmp r0, #4
	bne _08066378
	ldr r1, _08066374 @ =0x0300137C
	movs r0, #8
	str r0, [r1]
	bl sub_0803FB0C
	b _08066392
	.align 2, 0
_0806636C: .4byte 0x03005010
_08066370: .4byte 0x0000FE0F
_08066374: .4byte 0x0300137C
_08066378:
	adds r0, r1, #0
	adds r0, #0x50
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl init_blend_effect
	ldr r1, _0806639C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
_08066392:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806639C: .4byte 0x0300137C
	.syntax divided
