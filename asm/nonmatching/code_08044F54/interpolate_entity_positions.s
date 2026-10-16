	.syntax unified

	thumb_func_start interpolate_entity_positions
	.global interpolate_entity_positions
interpolate_entity_positions: @ 0x08047428
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r4, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	ldr r0, [sp, #0x44]
	ldr r1, [sp, #0x48]
	ldr r2, [sp, #0x4c]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0
	str r0, [sp, #0x18]
	lsls r0, r1, #1
	adds r7, r7, r0
	adds r5, r5, r0
	cmp r3, #0
	bne _0804745A
	b _0804755C
_0804745A:
	adds r0, r3, r1
	ldrb r0, [r0]
	mov sb, r0
	cmp r2, #1
	bgt _08047466
	b _0804755C
_08047466:
	adds r4, #0x10
	subs r2, #1
	mov r8, r2
_0804746C:
	cmp sl, sb
	bhs _08047528
	mov r1, sb
	mov r2, sl
	subs r1, r1, r2
	str r1, [sp, #0x1c]
	movs r6, #0
	ldrsh r2, [r7, r6]
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	subs r3, r2, r0
	str r3, [sp]
	movs r6, #0xc
	ldrsh r1, [r4, r6]
	ldr r0, _080474D4 @ =0xFFFF0000
	adds r1, r1, r0
	subs r1, r2, r1
	str r1, [sp, #8]
	movs r0, #0xc
	ldrsh r6, [r4, r0]
	mov ip, r6
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	subs r0, r2, r0
	str r0, [sp, #0x10]
	str r3, [sp, #4]
	str r1, [sp, #0xc]
	str r0, [sp, #0x14]
	cmp r3, #0
	bge _080474AE
	rsbs r0, r3, #0
	str r0, [sp, #4]
_080474AE:
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bge _080474B8
	rsbs r0, r0, #0
	str r0, [sp, #0xc]
_080474B8:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bge _080474C2
	rsbs r0, r0, #0
	str r0, [sp, #0x14]
_080474C2:
	ldr r2, [sp, #4]
	ldr r1, [sp, #0xc]
	cmp r2, r1
	ble _080474D8
	ldr r0, [sp, #0x14]
	cmp r1, r0
	bgt _080474DE
	ldr r2, [sp, #8]
	b _080474E4
	.align 2, 0
_080474D4: .4byte 0xFFFF0000
_080474D8:
	ldr r0, [sp, #0x14]
	cmp r2, r0
	ble _080474E2
_080474DE:
	ldr r2, [sp, #0x10]
	b _080474E4
_080474E2:
	ldr r2, [sp]
_080474E4:
	adds r0, r2, #0
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r4, #0xc]
	adds r1, r1, r0
	strh r1, [r4, #0xc]
	cmp r5, #0
	beq _08047546
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #8
	movs r2, #8
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r4, #8]
	adds r1, r1, r0
	strh r1, [r4, #8]
	movs r0, #1
	ldrsb r0, [r5, r0]
	lsls r0, r0, #8
	movs r6, #0xa
	ldrsh r1, [r4, r6]
	subs r0, r0, r1
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r4, #0xa]
	adds r1, r1, r0
	strh r1, [r4, #0xa]
	b _08047546
_08047528:
	ldrh r0, [r7]
	strh r0, [r4, #0xc]
	cmp r5, #0
	beq _08047540
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #8
	strh r0, [r4, #8]
	movs r0, #1
	ldrsb r0, [r5, r0]
	lsls r0, r0, #8
	strh r0, [r4, #0xa]
_08047540:
	ldr r0, [sp, #0x18]
	adds r0, #1
	str r0, [sp, #0x18]
_08047546:
	adds r4, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	ldr r2, [sp, #0x50]
	lsls r0, r2, #1
	adds r7, r7, r0
	adds r5, r5, r0
	mov r6, r8
	cmp r6, #0
	bne _0804746C
_0804755C:
	ldr r0, [sp, #0x18]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	.syntax divided
