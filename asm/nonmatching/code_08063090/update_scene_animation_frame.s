	.syntax unified

	thumb_func_start update_scene_animation_frame
	.global update_scene_animation_frame
update_scene_animation_frame: @ 0x08066BF8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	bl rng_next_080424B8
	ldr r4, _08066C40 @ =0x03006F74
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0x48
	ldrb r0, [r1]
	cmp r0, #0
	bne _08066C44
	bl rng_next_080424B8
	ldr r1, [r4]
	adds r1, #0x48
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0x48
	ldrb r0, [r1]
	cmp r0, #0
	bne _08066C2E
	adds r0, #1
	strb r0, [r1]
_08066C2E:
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0x48
	ldrb r1, [r1]
	lsrs r1, r1, #1
	adds r0, #0x49
	strb r1, [r0]
	b _08066C72
	.align 2, 0
_08066C40: .4byte 0x03006F74
_08066C44:
	subs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0x48
	adds r0, #0x49
	ldrb r1, [r1]
	ldrb r0, [r0]
	lsls r3, r1, #0x18
	lsls r2, r0, #0x18
	cmp r1, r0
	bhs _08066C66
	lsrs r0, r3, #0x1a
	adds r0, #0x14
	bl ring_points_place_on_hexagon
	b _08066C72
_08066C66:
	lsrs r0, r2, #0x19
	lsrs r1, r3, #0x1a
	subs r1, #0x14
	subs r0, r0, r1
	bl ring_points_place_on_hexagon
_08066C72:
	ldr r7, _08066F30 @ =0x03006F74
	ldr r3, [r7]
	adds r0, r3, #0
	adds r0, #0x80
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, r3, #0
	adds r4, #0x8a
	movs r5, #0
	ldrsh r0, [r4, r5]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066C8E
	adds r0, #0xf
_08066C8E:
	asrs r0, r0, #4
	ldrh r6, [r4]
	adds r0, r0, r6
	strh r0, [r4]
	adds r0, r3, #0
	adds r0, #0x82
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r5, r3, #0
	adds r5, #0x92
	movs r6, #0
	ldrsh r0, [r5, r6]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066CAE
	adds r0, #0xf
_08066CAE:
	asrs r0, r0, #4
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	adds r0, r3, #0
	adds r0, #0x84
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r2, r3, #0
	adds r2, #0x9a
	movs r6, #0
	ldrsh r0, [r2, r6]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066CCE
	adds r0, #0xf
_08066CCE:
	asrs r0, r0, #4
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	movs r6, #0
	ldrsh r1, [r4, r6]
	adds r4, r3, #0
	adds r4, #0x8c
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066CEA
	adds r0, #0xf
_08066CEA:
	asrs r0, r0, #4
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r6, #0
	ldrsh r1, [r5, r6]
	adds r5, r3, #0
	adds r5, #0x94
	movs r6, #0
	ldrsh r0, [r5, r6]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066D06
	adds r0, #0xf
_08066D06:
	asrs r0, r0, #4
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	movs r6, #0
	ldrsh r1, [r2, r6]
	adds r6, r3, #0
	adds r6, #0x9c
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066D22
	adds r0, #0xf
_08066D22:
	asrs r0, r0, #4
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r4, r3, #0
	adds r4, #0x8e
	movs r2, #0
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066D3E
	adds r0, #0xf
_08066D3E:
	asrs r0, r0, #4
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r2, r3, #0
	adds r2, #0x96
	movs r5, #0
	ldrsh r0, [r2, r5]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066D5A
	adds r0, #0xf
_08066D5A:
	asrs r0, r0, #4
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	movs r2, #0
	ldrsh r1, [r6, r2]
	adds r2, r3, #0
	adds r2, #0x9e
	movs r5, #0
	ldrsh r0, [r2, r5]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066D76
	adds r0, #0xf
_08066D76:
	asrs r0, r0, #4
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	movs r0, #0
	ldrsh r1, [r4, r0]
	adds r2, r3, #0
	adds r2, #0x90
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066D92
	adds r0, #0xf
_08066D92:
	ldr r3, [r7]
	adds r1, r3, #0
	adds r1, #0x90
	asrs r0, r0, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0x96
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r2, r3, #0
	adds r2, #0x98
	movs r5, #0
	ldrsh r0, [r2, r5]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066DB8
	adds r0, #0xf
_08066DB8:
	asrs r0, r0, #4
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0x9e
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r2, r3, #0
	adds r2, #0xa0
	movs r4, #0
	ldrsh r0, [r2, r4]
	subs r0, r1, r0
	cmp r0, #0
	bge _08066DD8
	adds r0, #0xf
_08066DD8:
	asrs r0, r0, #4
	ldrh r5, [r2]
	adds r0, r0, r5
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0xa5
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	movs r2, #0x7f
	bl u8_difference_divide
	ldr r1, [r7]
	adds r1, #0xa6
	strb r0, [r1]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xa4
	ldrb r0, [r0]
	adds r1, #0xa5
	ldrb r1, [r1]
	movs r2, #0x7f
	bl u8_difference_divide
	ldr r1, [r7]
	adds r1, #0xa5
	strb r0, [r1]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	adds r1, #0xa4
	ldrb r1, [r1]
	movs r2, #0x7f
	bl u8_difference_divide
	ldr r1, [r7]
	adds r1, #0xa4
	strb r0, [r1]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xa2
	ldrb r0, [r0]
	adds r1, #0xa3
	ldrb r1, [r1]
	movs r2, #0x7f
	bl u8_difference_divide
	ldr r1, [r7]
	adds r1, #0xa3
	strb r0, [r1]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	adds r1, #0xab
	ldrb r1, [r1]
	movs r2, #0x7f
	bl u8_difference_divide
	ldr r1, [r7]
	adds r1, #0xab
	strb r0, [r1]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xa9
	ldrb r0, [r0]
	adds r1, #0xaa
	ldrb r1, [r1]
	movs r2, #0x7f
	bl u8_difference_divide
	ldr r1, [r7]
	adds r1, #0xaa
	strb r0, [r1]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	adds r1, #0xa9
	ldrb r1, [r1]
	movs r2, #0x7f
	bl u8_difference_divide
	ldr r1, [r7]
	adds r1, #0xa9
	strb r0, [r1]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	adds r1, #0xa8
	ldrb r1, [r1]
	movs r2, #0x7f
	bl u8_difference_divide
	ldr r1, [r7]
	adds r1, #0xa8
	strb r0, [r1]
	bl matrix_set_identity
	ldr r1, [r7]
	ldrh r0, [r1, #0x3c]
	adds r0, #1
	strh r0, [r1, #0x3c]
	movs r4, #0xff
	ands r0, r4
	cmp r0, #0
	bne _08066EFA
	bl rng_next_080424B8
	ands r0, r4
	ldr r3, [r7]
	ldr r4, _08066F34 @ =0x080AE77C
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0
	ldrsh r2, [r1, r6]
	lsls r1, r2, #2
	adds r1, r1, r2
	asrs r1, r1, #5
	adds r3, #0xa2
	strb r1, [r3]
	ldr r2, [r7]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #5
	adds r2, #0xa7
	strb r0, [r2]
	ldr r1, [r7]
	adds r1, #0xa2
	ldrb r0, [r1]
	adds r0, #0x78
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0xa7
	ldrb r0, [r1]
	adds r0, #0x50
	strb r0, [r1]
_08066EFA:
	ldr r0, [r7]
	ldrh r1, [r0, #0x3c]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08066F14
	bl rng_next_080424B8
	ldr r1, [r7]
	movs r2, #3
	ands r0, r2
	adds r1, #0x7e
	strb r0, [r1]
_08066F14:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0x7e
	ldrb r0, [r0]
	movs r2, #3
	ands r2, r0
	cmp r2, #1
	beq _08066F54
	cmp r2, #1
	bgt _08066F38
	cmp r2, #0
	beq _08066F42
	b _08066F9E
	.align 2, 0
_08066F30: .4byte 0x03006F74
_08066F34: .4byte 0x080AE77C
_08066F38:
	cmp r2, #2
	beq _08066F70
	cmp r2, #3
	beq _08066F82
	b _08066F9E
_08066F42:
	adds r1, #0x86
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0x87
	ldrb r0, [r1]
	adds r0, #1
	b _08066F9C
_08066F54:
	adds r1, #0x86
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0x87
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0x88
	ldrb r0, [r1]
	adds r0, #3
	b _08066F9C
_08066F70:
	adds r1, #0x86
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0x88
	ldrb r0, [r1]
	adds r0, #2
	b _08066F9C
_08066F82:
	adds r1, #0x86
	ldrb r0, [r1]
	adds r0, #5
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0x87
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0x88
	ldrb r0, [r1]
	subs r0, #2
_08066F9C:
	strb r0, [r1]
_08066F9E:
	ldr r1, _08067158 @ =0x03006F74
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0x86
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r3, #0x10
	rsbs r3, r3, #0
	cmp r0, r3
	bge _08066FB6
	movs r0, #0xf0
	strb r0, [r2]
_08066FB6:
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0x87
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r3
	bge _08066FC6
	strb r3, [r2]
_08066FC6:
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0x88
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r3
	bge _08066FD6
	strb r3, [r2]
_08066FD6:
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0x86
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x10
	ble _08066FE8
	movs r0, #0x10
	strb r0, [r2]
_08066FE8:
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0x87
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x10
	ble _08066FFA
	movs r0, #0x10
	strb r0, [r2]
_08066FFA:
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0x88
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x10
	ble _0806700C
	movs r0, #0x10
	strb r0, [r2]
_0806700C:
	ldr r2, [r1]
	adds r1, r2, #0
	adds r1, #0x80
	adds r0, r2, #0
	adds r0, #0x86
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	adds r1, #2
	adds r0, r2, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	adds r1, #2
	adds r0, r2, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	movs r0, #0
	mov r8, r0
	movs r1, #0xff
	mov sb, r1
_0806704E:
	mov r0, r8
	movs r1, #0x12
	bl sub_0807CC88
	adds r5, r0, #0
	cmp r5, #0
	bne _0806709E
	bl matrix_set_identity
	ldr r0, _08067158 @ =0x03006F74
	ldr r4, [r0]
	mov r0, r8
	movs r1, #0x12
	bl sub_0807CBBC
	adds r2, r0, #0
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r0, #0x8a
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	mov r3, sb
	ands r0, r3
	adds r1, r4, #0
	adds r1, #0x92
	adds r1, r1, r2
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	ands r1, r3
	adds r4, #0x9a
	adds r4, r4, r2
	ldrh r2, [r4]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x14
	ands r2, r3
	bl matrix_rotate_xyz
_0806709E:
	ldr r0, _08067158 @ =0x03006F74
	ldr r7, [r0]
	lsls r0, r5, #4
	adds r3, r7, r0
	adds r0, r3, #0
	adds r0, #0xd2
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r0, #2
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r0, #2
	movs r6, #0
	ldrsh r3, [r0, r6]
	movs r4, #0xf8
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r5, r1, #0
	muls r5, r0, r5
	movs r6, #0x80
	lsls r6, r6, #2
	adds r0, r7, r6
	ldr r0, [r0]
	muls r0, r2, r0
	adds r5, r5, r0
	adds r4, #0x20
	adds r0, r7, r4
	ldr r0, [r0]
	muls r0, r3, r0
	adds r5, r5, r0
	adds r6, #0x20
	adds r0, r7, r6
	ldr r0, [r0]
	adds r5, r5, r0
	subs r4, #0x18
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r1, #0
	muls r4, r0, r4
	subs r6, #0x18
	adds r0, r7, r6
	ldr r0, [r0]
	muls r0, r2, r0
	adds r4, r4, r0
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	muls r0, r3, r0
	adds r4, r4, r0
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	adds r4, r4, r0
	asrs r5, r5, #8
	asrs r4, r4, #8
	ldr r0, _0806715C @ =0x03002C30
	mov r2, r8
	adds r2, #1
	lsls r6, r2, #6
	adds r6, r6, r0
	mov r0, r8
	movs r1, #0x12
	str r2, [sp]
	bl sub_0807CBBC
	adds r0, #1
	adds r1, r7, #0
	adds r1, #0xa2
	adds r1, r1, r0
	ldrb r1, [r1]
	adds r1, r1, r5
	strh r1, [r6, #2]
	adds r1, r7, #0
	adds r1, #0xa7
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, r0, r4
	strh r0, [r6, #4]
	ldr r2, [sp]
	mov r8, r2
	cmp r2, #0x47
	ble _0806704E
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067158: .4byte 0x03006F74
_0806715C: .4byte 0x03002C30
	.syntax divided
