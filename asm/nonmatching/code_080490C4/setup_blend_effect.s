	.syntax unified

	thumb_func_start setup_blend_effect
	.global setup_blend_effect
setup_blend_effect: @ 0x08049794
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	ldr r7, [sp, #0x38]
	mov r8, r7
	ldr r7, [sp, #0x3c]
	mov sb, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sl, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #8]
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	mov r1, sb
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	mov r4, sl
	cmp r4, #0
	bne _080497EA
	movs r7, #1
	mov sl, r7
_080497EA:
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _080497F4
	movs r1, #1
	str r1, [sp, #8]
_080497F4:
	ldr r1, _0804981C @ =0x03006F40
	mov r4, sp
	ldrb r4, [r4]
	strb r4, [r1]
	strb r2, [r1, #1]
	ldr r0, _08049820 @ =0x00000000
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #2]
	movs r0, #0x80
	ldr r7, [sp]
	ands r0, r7
	adds r5, r1, #0
	cmp r0, #0
	beq _08049824
	movs r0, #0x20
	ldr r1, [sp, #4]
	orrs r1, r0
	str r1, [sp, #4]
	b _0804982C
	.align 2, 0
_0804981C: .4byte 0x03006F40
_08049820: .4byte 0x00000000
_08049824:
	ldr r0, _08049840 @ =0x0000FFDF
	ldr r2, [sp, #4]
	ands r2, r0
	str r2, [sp, #4]
_0804982C:
	ldrb r0, [r5, #1]
	cmp r0, #6
	bls _08049834
	b _080499FC
_08049834:
	lsls r0, r0, #2
	ldr r1, _08049844 @ =_08049848
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08049840: .4byte 0x0000FFDF
_08049844: .4byte _08049848
_08049848: @ jump table
	.4byte _08049864 @ case 0
	.4byte _08049868 @ case 1
	.4byte _08049864 @ case 2
	.4byte _08049868 @ case 3
	.4byte _0804986C @ case 4
	.4byte _080498E4 @ case 5
	.4byte _0804996C @ case 6
_08049864:
	movs r0, #0x10
	b _080499FE
_08049868:
	movs r0, #0x10
	b _080499FE
_0804986C:
	ldr r3, _080498D4 @ =0x04000052
	ldrh r2, [r3]
	movs r1, #0x1f
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r5, #6]
	ldrh r2, [r3]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r2
	lsrs r0, r0, #8
	strb r0, [r5, #7]
	ldr r0, _080498D8 @ =0x04000054
	ldrh r0, [r0]
	ands r1, r0
	strb r1, [r5, #8]
	ldr r0, _080498DC @ =0x00000000
	str r0, [r5, #0xc]
	str r0, [r5, #0x10]
	ldrb r0, [r5, #6]
	movs r7, #0x10
	subs r0, r7, r0
	bl int_to_softfloat
	adds r6, r0, #0
	mov r0, sl
	lsls r4, r0, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	bl int_to_softfloat
	adds r2, r0, #0
	cmp r4, #0
	bge _080498B8
	ldr r1, _080498E0 @ =0x43800000
	bl softfloat_add_f32
	adds r2, r0, #0
_080498B8:
	adds r0, r6, #0
	adds r1, r2, #0
	bl softfloat_divide
	str r0, [r5, #0x18]
	ldrb r0, [r5, #7]
	subs r0, r7, r0
	bl int_to_softfloat
	adds r6, r0, #0
	ldr r1, [sp, #8]
	lsls r4, r1, #0x18
	b _080499CE
	.align 2, 0
_080498D4: .4byte 0x04000052
_080498D8: .4byte 0x04000054
_080498DC: .4byte 0x00000000
_080498E0: .4byte 0x43800000
_080498E4:
	strb r6, [r5, #6]
	mov r2, r8
	strb r2, [r5, #7]
	strb r3, [r5, #8]
	ldr r0, _0804995C @ =0x00000000
	str r0, [r5, #0xc]
	str r0, [r5, #0x10]
	movs r7, #0x10
	subs r0, r7, r6
	bl int_to_softfloat
	adds r6, r0, #0
	mov r0, sl
	lsls r4, r0, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	bl int_to_softfloat
	adds r2, r0, #0
	cmp r4, #0
	bge _08049916
	ldr r1, _08049960 @ =0x43800000
	bl softfloat_add_f32
	adds r2, r0, #0
_08049916:
	adds r0, r6, #0
	adds r1, r2, #0
	bl softfloat_divide
	str r0, [r5, #0x18]
	mov r1, r8
	subs r0, r7, r1
	bl int_to_softfloat
	adds r6, r0, #0
	ldr r2, [sp, #8]
	lsls r4, r2, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	bl int_to_softfloat
	adds r2, r0, #0
	cmp r4, #0
	bge _08049944
	ldr r1, _08049960 @ =0x43800000
	bl softfloat_add_f32
	adds r2, r0, #0
_08049944:
	adds r0, r6, #0
	adds r1, r2, #0
	bl softfloat_divide
	str r0, [r5, #0x1c]
	strb r7, [r5, #3]
	strb r7, [r5, #4]
	ldr r1, _08049964 @ =0x030017F0
	ldr r0, _08049968 @ =apply_blend_coefficients
	str r0, [r1]
	b _08049A00
	.align 2, 0
_0804995C: .4byte 0x00000000
_08049960: .4byte 0x43800000
_08049964: .4byte 0x030017F0
_08049968: .4byte apply_blend_coefficients
_0804996C:
	ldr r2, _080499F0 @ =0x04000052
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strb r0, [r5, #9]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	strb r0, [r5, #0xa]
	strb r6, [r5, #6]
	mov r4, r8
	strb r4, [r5, #7]
	strb r3, [r5, #8]
	ldr r0, _080499F4 @ =0x00000000
	str r0, [r5, #0xc]
	str r0, [r5, #0x10]
	ldrb r0, [r5, #9]
	subs r0, r0, r6
	bl int_to_softfloat
	adds r6, r0, #0
	mov r7, sl
	lsls r4, r7, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	bl int_to_softfloat
	adds r2, r0, #0
	cmp r4, #0
	bge _080499B4
	ldr r1, _080499F8 @ =0x43800000
	bl softfloat_add_f32
	adds r2, r0, #0
_080499B4:
	adds r0, r6, #0
	adds r1, r2, #0
	bl softfloat_divide
	str r0, [r5, #0x18]
	ldrb r0, [r5, #0xa]
	mov r1, r8
	subs r0, r0, r1
	bl int_to_softfloat
	adds r6, r0, #0
	ldr r2, [sp, #8]
	lsls r4, r2, #0x18
_080499CE:
	asrs r4, r4, #0x18
	adds r0, r4, #0
	bl int_to_softfloat
	adds r2, r0, #0
	cmp r4, #0
	bge _080499E4
	ldr r1, _080499F8 @ =0x43800000
	bl softfloat_add_f32
	adds r2, r0, #0
_080499E4:
	adds r0, r6, #0
	adds r1, r2, #0
	bl softfloat_divide
	str r0, [r5, #0x1c]
	b _08049A00
	.align 2, 0
_080499F0: .4byte 0x04000052
_080499F4: .4byte 0x00000000
_080499F8: .4byte 0x43800000
_080499FC:
	movs r0, #0
_080499FE:
	strb r0, [r5, #5]
_08049A00:
	ldr r0, _08049A1C @ =0x04000050
	ldr r4, [sp, #4]
	ldr r7, [sp]
	orrs r4, r7
	strh r4, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08049A1C: .4byte 0x04000050
	.syntax divided
