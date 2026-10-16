	.syntax unified

	thumb_func_start sub_080509A0
sub_080509A0: @ 0x080509A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0
	mov r8, r0
	ldr r0, _080509C4 @ =0x03006D20
	ldrb r6, [r0, #0xa]
	ldr r1, _080509C8 @ =0x03002C30
	lsls r0, r6, #6
	adds r5, r0, r1
	adds r4, r5, #0
	adds r4, #0x26
	ldrb r0, [r4]
	cmp r0, #0
	beq _080509CC
	cmp r0, #1
	beq _08050A18
	b _08050B44
	.align 2, 0
_080509C4: .4byte 0x03006D20
_080509C8: .4byte 0x03002C30
_080509CC:
	adds r0, r5, #0
	adds r0, #0x28
	mov r1, r8
	strb r1, [r0]
	adds r0, #2
	strb r1, [r0]
	ldr r0, _08050A10 @ =0x030057E0
	ldr r2, _08050A14 @ =0x00000C95
	adds r0, r0, r2
	ldrb r2, [r0]
	adds r1, r5, #0
	adds r1, #0x20
	strb r2, [r1]
	ldrb r1, [r0]
	adds r0, r6, #0
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl sub_080493D4
	ldr r0, [r5, #0x10]
	asrs r0, r0, #8
	strh r0, [r5, #0x34]
	movs r0, #0x70
	bl sub_08047BA8
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08050B44
	.align 2, 0
_08050A10: .4byte 0x030057E0
_08050A14: .4byte 0x00000C95
_08050A18:
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r4, [r0]
	adds r0, r6, #0
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	lsls r0, r0, #1
	cmp r4, r0
	bge _08050B28
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #1
	beq _08050A5E
	cmp r0, #1
	bgt _08050A46
	cmp r0, #0
	beq _08050A50
	b _08050A90
_08050A46:
	cmp r0, #2
	beq _08050A6C
	cmp r0, #3
	beq _08050A7A
	b _08050A90
_08050A50:
	adds r0, r6, #0
	bl sub_080518F4
	ldrh r1, [r5, #0x34]
	subs r1, r1, r0
	strh r1, [r5, #0x34]
	b _08050A90
_08050A5E:
	adds r0, r6, #0
	bl sub_080518F4
	ldrh r1, [r5, #0x34]
	adds r1, r1, r0
	strh r1, [r5, #0x34]
	b _08050A90
_08050A6C:
	adds r0, r6, #0
	bl sub_080518F4
	ldr r2, [r5, #0xc]
	asrs r1, r2, #8
	subs r1, r1, r0
	b _08050A86
_08050A7A:
	adds r0, r6, #0
	bl sub_080518F4
	ldr r2, [r5, #0xc]
	asrs r1, r2, #8
	adds r1, r1, r0
_08050A86:
	lsls r1, r1, #8
	movs r0, #0xff
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #0xc]
_08050A90:
	adds r0, r6, #0
	bl sub_080518F4
	ldr r2, _08050B18 @ =0x03002C30
	lsls r1, r6, #6
	adds r4, r1, r2
	ldrh r2, [r4, #0x34]
	ldr r7, _08050B1C @ =0x083D69A0
	adds r5, r4, #0
	adds r5, #0x28
	ldrb r1, [r5]
	lsls r0, r0, #2
	muls r0, r1, r0
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r3, #0
	ldrsh r1, [r0, r3]
	cmp r1, #0
	bge _08050AB8
	adds r1, #0xf
_08050AB8:
	asrs r1, r1, #4
	subs r1, r2, r1
	lsls r1, r1, #8
	ldrb r0, [r4, #0x10]
	orrs r0, r1
	str r0, [r4, #0x10]
	adds r0, r6, #0
	bl sub_080518F4
	ldrb r1, [r5]
	lsls r0, r0, #2
	muls r0, r1, r0
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bge _08050ADE
	adds r1, #0xf
_08050ADE:
	asrs r1, r1, #4
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldrb r0, [r4, #0xb]
	cmp r0, #0xff
	beq _08050B44
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	cmp r0, #0
	bge _08050AFC
	adds r0, #3
_08050AFC:
	asrs r2, r0, #2
	ldrh r1, [r4, #0x34]
	adds r0, r1, #0
	subs r0, #0x10
	cmp r0, #0
	bge _08050B0A
	adds r0, #3
_08050B0A:
	asrs r0, r0, #2
	cmp r2, r0
	bgt _08050B20
	movs r0, #0xfe
	strb r0, [r4, #0xb]
	b _08050B44
	.align 2, 0
_08050B18: .4byte 0x03002C30
_08050B1C: .4byte 0x083D69A0
_08050B20:
	adds r0, r6, #0
	bl sub_0804877C
	b _08050B44
_08050B28:
	adds r0, r6, #0
	bl sub_0804877C
	ldrh r0, [r5, #0x34]
	lsls r0, r0, #8
	ldrb r1, [r5, #0x10]
	orrs r1, r0
	str r1, [r5, #0x10]
	adds r0, r5, #0
	adds r0, #0x2c
	mov r3, r8
	strb r3, [r0]
	movs r0, #1
	mov r8, r0
_08050B44:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
