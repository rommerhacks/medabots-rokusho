	.syntax unified

	thumb_func_start render_sprite_node_recursive
render_sprite_node_recursive: @ 0x080465B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov r8, r0
	str r1, [sp, #0x20]
	str r3, [sp, #0x24]
	ldr r0, [sp, #0x70]
	ldr r3, [sp, #0x74]
	ldr r1, [sp, #0x78]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sl, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r3, r3, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x2c]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x30]
	ldr r1, [sp, #0x6c]
	str r1, [sp, #0x34]
	mov r6, r8
	ldr r5, [r6, #4]
	mov r1, sl
	lsls r0, r1, #2
	adds r0, r0, r5
	ldr r0, [r0]
	mov sb, r0
	lsls r0, r1, #4
	ldr r4, [r6, #8]
	adds r0, r4, r0
	str r0, [sp, #0x40]
	ldr r0, _08046648 @ =0x080ABBF4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, _0804664C @ =0x01000100
	str r0, [sp, #0x10]
	lsrs r6, r3, #0x10
	str r6, [sp, #0x28]
	rsbs r3, r3, #0
	lsrs r3, r3, #0x10
	ldr r1, _08046650 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	orrs r0, r3
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _08046658
	ldr r0, _08046654 @ =0x08081320
	add r0, sl
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r5
	ldr r0, [r0]
	mov sb, r0
	lsls r1, r1, #4
	adds r1, r1, r4
	ldrh r3, [r1, #0xc]
	str r3, [sp, #0x38]
	movs r6, #8
	ldrsh r3, [r1, r6]
	movs r0, #0xa
	ldrsh r4, [r1, r0]
	b _08046668
	.align 2, 0
_08046648: .4byte gUnk_080ABBF4
_0804664C: .4byte 0x01000100
_08046650: .4byte 0xFFFF0000
_08046654: .4byte gUnk_08081320
_08046658:
	ldr r1, [sp, #0x40]
	ldrh r1, [r1, #0xc]
	str r1, [sp, #0x38]
	ldr r6, [sp, #0x40]
	movs r0, #8
	ldrsh r3, [r6, r0]
	movs r1, #0xa
	ldrsh r4, [r6, r1]
_08046668:
	mov r6, sb
	movs r0, #0xe
	ldrsb r0, [r6, r0]
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	str r0, [sp, #0x3c]
	str r2, [sp, #0x48]
	cmp r1, #0
	bge _08046684
	movs r1, #0
	str r1, [sp, #0x3c]
_08046684:
	mov r2, sb
	movs r1, #0xc
	ldrsb r1, [r2, r1]
	asrs r0, r3, #8
	adds r5, r1, r0
	movs r1, #0xd
	ldrsb r1, [r2, r1]
	asrs r0, r4, #8
	adds r6, r1, r0
	add r7, sp, #0x10
	add r4, sp, #0x18
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldr r3, [sp, #0x2c]
	cmp r3, #0
	beq _080466B2
	ldrh r0, [r7, #4]
	rsbs r0, r0, #0
	strh r0, [r7, #4]
_080466B2:
	mov r1, sp
	movs r2, #0x1a
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	movs r3, #0x1e
	ldrsh r1, [r1, r3]
	muls r1, r5, r1
	adds r0, r0, r1
	ldr r1, [sp, #0x24]
	adds r1, r1, r0
	str r1, [sp, #0x24]
	ldr r2, [sp, #0x2c]
	cmp r2, #0
	beq _080466E6
	mov r3, sp
	movs r1, #0x18
	ldrsh r0, [r3, r1]
	muls r0, r6, r0
	movs r2, #0x1c
	ldrsh r1, [r3, r2]
	muls r1, r5, r1
	adds r0, r0, r1
	ldr r3, [sp, #0x6c]
	subs r3, r3, r0
	str r3, [sp, #0x6c]
	b _080466FC
_080466E6:
	mov r1, sp
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	movs r3, #0x1c
	ldrsh r1, [r1, r3]
	muls r1, r5, r1
	adds r0, r0, r1
	ldr r6, [sp, #0x6c]
	adds r6, r6, r0
	str r6, [sp, #0x6c]
_080466FC:
	ldr r0, _08046740 @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x96
	ldrb r0, [r3]
	movs r7, #1
	cmp r0, #0
	beq _0804670C
	movs r7, #0
_0804670C:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _08046758
	movs r4, #0
	ldrb r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	mov r1, sl
	lsls r1, r1, #2
	str r1, [sp, #0x44]
	cmp r0, #0
	beq _08046760
	mov r2, sl
	adds r5, r3, #0
	ldr r3, [sp, #0x20]
_0804672A:
	ldr r1, [r3]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1a
	cmp r2, r0
	bne _0804674A
	ldrb r0, [r5]
	cmp r0, #0
	beq _08046744
	movs r7, #0
	b _080468BC
	.align 2, 0
_08046740: .4byte 0x03000440
_08046744:
	lsls r0, r1, #0x11
	lsrs r7, r0, #0x1f
	b _08046766
_0804674A:
	adds r3, #4
	ldrb r1, [r3]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _0804672A
	b _08046760
_08046758:
	movs r4, #1
	mov r2, sl
	lsls r2, r2, #2
	str r2, [sp, #0x44]
_08046760:
	cmp r4, #0
	bne _08046766
	b _080469BA
_08046766:
	cmp r7, #0
	bne _0804676C
	b _080468BC
_0804676C:
	ldr r3, [sp, #0x2c]
	cmp r3, #0
	beq _0804677C
	add r1, sp, #0x10
	ldrh r0, [r1, #4]
	ldr r6, [sp, #0x38]
	adds r0, r0, r6
	b _08046784
_0804677C:
	add r1, sp, #0x10
	ldrh r0, [r1, #4]
	ldr r2, [sp, #0x38]
	subs r0, r0, r2
_08046784:
	strh r0, [r1, #4]
	add r6, sp, #0x18
	add r0, sp, #0x10
	adds r1, r6, #0
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	mov r3, r8
	ldr r0, [r3]
	ldr r3, _080468B4 @ =0x00001095
	adds r0, r0, r3
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #1
	ldr r2, [sp, #0x40]
	ldrb r1, [r2, #3]
	movs r2, #0xf
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	ldr r0, [sp, #0x40]
	strb r2, [r0, #3]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r3
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1b
	lsls r0, r0, #4
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	ldr r2, [sp, #0x40]
	strb r1, [r2, #3]
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r3
	ldrb r2, [r0]
	movs r0, #0x10
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1c
	lsls r0, r0, #5
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	ldr r0, [sp, #0x40]
	strb r1, [r0, #3]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r3
	ldrb r2, [r0]
	lsls r5, r2, #2
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0804680E
	ldrh r0, [r6]
	rsbs r0, r0, #0
	add r1, sp, #0x18
	strh r0, [r1]
	ldrh r0, [r6, #2]
	rsbs r0, r0, #0
	strh r0, [r6, #2]
_0804680E:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r2, #3
	ldr r2, _080468B8 @ =0x00000F8C
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r1, [r6]
	strh r1, [r0]
	adds r5, #1
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #1
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r1, [r6, #2]
	strh r1, [r0]
	adds r5, #1
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #1
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r1, [r6, #4]
	strh r1, [r0]
	adds r5, #1
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #1
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r1, [r6, #6]
	strh r1, [r0]
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _0804686A
	ldr r0, [r2]
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
_0804686A:
	cmp r7, #0
	beq _080468BC
	mov r3, sb
	ldrb r0, [r3, #0x12]
	lsrs r3, r0, #1
	mov r6, sb
	ldrb r0, [r6, #0x13]
	lsrs r4, r0, #1
	ldr r0, [r6, #4]
	subs r5, r0, r3
	ldr r0, [r6, #8]
	subs r6, r0, r4
	mov r1, sp
	movs r2, #0x1a
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	movs r2, #0x1e
	ldrsh r1, [r1, r2]
	mov sb, r1
	mov r1, sb
	muls r1, r5, r1
	adds r0, r0, r1
	lsls r1, r3, #8
	adds r0, r0, r1
	ldr r1, [sp, #0x24]
	subs r3, r1, r0
	mov r2, sp
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	muls r0, r6, r0
	movs r6, #0x1c
	ldrsh r1, [r2, r6]
	muls r1, r5, r1
	adds r0, r0, r1
	lsls r1, r4, #8
	adds r0, r0, r1
	b _080468D4
	.align 2, 0
_080468B4: .4byte 0x00001095
_080468B8: .4byte 0x00000F8C
_080468BC:
	mov r2, sb
	ldr r0, [r2, #4]
	lsls r0, r0, #8
	ldr r6, [sp, #0x24]
	subs r3, r6, r0
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _080468DA
	ldrb r0, [r2, #0x13]
	ldr r1, [r2, #8]
	subs r0, r0, r1
	lsls r0, r0, #8
_080468D4:
	ldr r1, [sp, #0x6c]
	subs r4, r1, r0
	b _080468E4
_080468DA:
	mov r2, sb
	ldr r0, [r2, #8]
	lsls r0, r0, #8
	ldr r6, [sp, #0x6c]
	subs r4, r6, r0
_080468E4:
	ldr r1, _08046968 @ =0x03002414
	ldr r0, [r1]
	ldr r2, _0804696C @ =0x00001094
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r6, [sp, #0x3c]
	lsls r5, r6, #0x10
	asrs r6, r3, #8
	asrs r4, r4, #8
_080468FA:
	cmp r0, #0
	blt _080468FA
	ldr r2, [r1]
	ldr r1, _08046970 @ =0x00000B84
	adds r0, r2, r1
	ldr r3, _0804696C @ =0x00001094
	adds r2, r2, r3
	ldrb r1, [r2]
	adds r3, r1, #1
	strb r3, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	asrs r3, r5, #0x10
	movs r2, #1
	bl sorted_array_insert_shift
	adds r2, r0, #0
	ldr r3, [sp, #0x40]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sp
	ldrh r0, [r0, #0x3c]
	strh r0, [r2, #6]
	cmp r7, #0
	bne _0804693E
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _0804693E
	ldrb r0, [r2, #3]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #3]
_0804693E:
	strb r6, [r2]
	ldr r0, _08046974 @ =0x000003FF
	ands r4, r0
	ldr r3, _08046978 @ =0x000001FF
	adds r0, r3, #0
	ands r4, r0
	ldrh r1, [r2, #2]
	ldr r0, _0804697C @ =0xFFFFFE00
	ands r0, r1
	orrs r0, r4
	strh r0, [r2, #2]
	ldr r6, [sp, #0x48]
	asrs r1, r6, #0x10
	ldr r0, _08046980 @ =0x0000017B
	cmp r1, r0
	ble _08046984
	ldrb r0, [r2, #5]
	movs r1, #0xc
	orrs r0, r1
	b _080469B8
	.align 2, 0
_08046968: .4byte 0x03002414
_0804696C: .4byte 0x00001094
_08046970: .4byte 0x00000B84
_08046974: .4byte 0x000003FF
_08046978: .4byte 0x000001FF
_0804697C: .4byte 0xFFFFFE00
_08046980: .4byte 0x0000017B
_08046984:
	ldr r0, _08046998 @ =0x00000117
	cmp r1, r0
	ble _0804699C
	ldrb r0, [r2, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #8
	b _080469AA
	.align 2, 0
_08046998: .4byte 0x00000117
_0804699C:
	cmp r1, #0xb3
	ble _080469B0
	ldrb r0, [r2, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #4
_080469AA:
	orrs r1, r0
	strb r1, [r2, #5]
	b _080469BA
_080469B0:
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
_080469B8:
	strb r0, [r2, #5]
_080469BA:
	mov r1, r8
	ldr r0, [r1, #4]
	ldr r2, [sp, #0x44]
	adds r0, r2, r0
	ldr r1, [r0]
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _08046A1E
	cmp r7, #0
	bne _080469EE
	adds r2, r0, #0
	ldr r3, [sp, #0x6c]
	str r3, [sp]
	ldr r6, [sp, #0x3c]
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #4]
	str r7, [sp, #8]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc]
	mov r0, r8
	ldr r1, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl render_sprite_node_recursive
	b _08046A1E
_080469EE:
	ldrb r2, [r1, #0x10]
	ldr r1, [sp, #0x6c]
	str r1, [sp]
	ldr r3, [sp, #0x3c]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r6, [sp, #0x38]
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp, #0x28]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xc]
	mov r0, r8
	ldr r1, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl render_sprite_node_recursive
_08046A1E:
	mov r1, r8
	ldr r0, [r1, #4]
	ldr r2, [sp, #0x44]
	adds r0, r2, r0
	ldr r1, [r0]
	ldrb r0, [r1, #0xf]
	cmp r0, #0
	beq _08046A50
	adds r2, r0, #0
	ldr r3, [sp, #0x34]
	str r3, [sp]
	ldr r6, [sp, #0x48]
	asrs r0, r6, #0x10
	str r0, [sp, #4]
	ldr r1, [sp, #0x28]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r3, [sp, #0x2c]
	str r3, [sp, #0xc]
	mov r0, r8
	ldr r1, [sp, #0x20]
	ldr r3, [sp, #0x30]
	bl render_sprite_node_recursive
_08046A50:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
