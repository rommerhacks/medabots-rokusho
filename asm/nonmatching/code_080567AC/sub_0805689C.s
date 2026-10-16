	.syntax unified

	thumb_func_start sub_0805689C
	.global sub_0805689C
sub_0805689C: @ 0x0805689C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r7, [r5]
	str r7, [r6, #0xc]
	ldr r0, [r5, #4]
	cmp r0, #0
	bge _080568B6
	adds r0, #0xff
_080568B6:
	asrs r0, r0, #8
	bl int_to_softfloat
	str r0, [r6, #0x10]
	ldr r0, [r5, #8]
	bl int_to_softfloat
	str r0, [r6, #0x14]
	ldr r0, [r5, #0xc]
	bl int_to_softfloat
	ldr r4, _0805694C @ =0x3B800000
	adds r1, r4, #0
	bl softfloat_multiply
	str r0, [r6, #0x18]
	ldr r0, [r5, #0x10]
	bl int_to_softfloat
	str r0, [r6, #0x1c]
	ldr r0, [r5, #0x14]
	str r0, [r6, #0x20]
	ldr r0, [r5, #0x18]
	str r0, [r6, #0x24]
	ldr r0, [r5, #0x1c]
	bl int_to_softfloat
	str r0, [r6, #0x28]
	ldr r0, [r5, #0x20]
	bl int_to_softfloat
	str r0, [r6, #0x2c]
	ldr r0, [r5, #0x24]
	bl int_to_softfloat
	str r0, [r6, #0x30]
	ldr r0, [r5, #0x28]
	bl int_to_softfloat
	str r0, [r6, #0x34]
	ldr r0, [r5, #0x2c]
	bl int_to_softfloat
	str r0, [r6, #0x38]
	ldr r0, [r5, #0x30]
	bl int_to_softfloat
	adds r1, r4, #0
	bl softfloat_multiply
	str r0, [r6, #0x3c]
	ldr r0, [r5, #0x34]
	bl int_to_softfloat
	adds r1, r4, #0
	bl softfloat_multiply
	str r0, [r6, #0x40]
	ldr r0, [r5, #0x38]
	str r0, [r6, #0x44]
	cmp r7, #1
	ble _08056936
	ldr r0, [r6]
	str r0, [r6, #4]
_08056936:
	ldr r0, [r6, #0xc]
	subs r0, #0x10
	cmp r0, #7
	bls _08056940
	b _08056DC8
_08056940:
	lsls r0, r0, #2
	ldr r1, _08056950 @ =_08056954
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805694C: .4byte 0x3B800000
_08056950: .4byte _08056954
_08056954: @ jump table
	.4byte _08056974 @ case 0
	.4byte _080569B8 @ case 1
	.4byte _080569F2 @ case 2
	.4byte _08056AF8 @ case 3
	.4byte _08056BC8 @ case 4
	.4byte _08056CB4 @ case 5
	.4byte _08056DC8 @ case 6
	.4byte _08056D88 @ case 7
_08056974:
	ldr r0, [r6, #0x3c]
	bl float_abs_if_negative
	bl float_default_to_one_if_zero
	adds r1, r0, #0
	ldr r0, [r6, #0x34]
	bl softfloat_divide
	adds r4, r0, #0
	str r4, [r6, #0x2c]
	ldr r0, [r6, #0x20]
	bl int_to_softfloat
	adds r1, r4, #0
	bl softfloat_add_f32
	bl float_to_int
	str r0, [r6, #0x24]
	ldr r0, [r6, #0x44]
	cmp r0, #0
	bne _080569A4
	b _08056DC8
_080569A4:
	ldr r0, [r6, #0x3c]
	bl float_sign
	adds r4, r0, #0
	ldr r0, [r6, #0x34]
	bl float_abs_if_negative
	adds r1, r0, #0
	adds r0, r4, #0
	b _08056D68
_080569B8:
	ldr r0, [r6, #0x20]
	bl int_to_softfloat
	ldr r1, [r6, #0x28]
	bl softfloat_add_f32
	bl float_to_int
	str r0, [r6, #0x24]
	ldr r4, [r6, #0x3c]
	ldr r1, [r6, #0x2c]
	adds r0, r4, #0
	bl softfloat_multiply
	str r0, [r6, #0x34]
	ldr r0, [r6, #0x44]
	cmp r0, #0
	bne _080569DE
	b _08056DC8
_080569DE:
	adds r0, r4, #0
	bl float_sign
	adds r4, r0, #0
	ldr r0, [r6, #0x34]
	bl float_abs_if_negative
	adds r1, r0, #0
	adds r0, r4, #0
	b _08056D68
_080569F2:
	ldr r0, [r6, #0x34]
	ldr r1, _08056A0C @ =0x3C800000
	bl softfloat_multiply
	str r0, [r6, #0x3c]
	ldr r5, [r6, #0x14]
	ldr r7, _08056A10 @ =0x00000000
	movs r0, #0
	mov r8, r0
	ldr r2, _08056A14 @ =0x080AE77C
	mov sb, r2
	b _08056A7C
	.align 2, 0
_08056A0C: .4byte 0x3C800000
_08056A10: .4byte 0x00000000
_08056A14: .4byte 0x080AE77C
_08056A18:
	adds r0, r5, #0
	adds r1, r4, #0
	bl softfloat_add_f32
	adds r5, r0, #0
	ldr r4, _08056AE4 @ =0x42800000
	adds r1, r4, #0
	bl softfloat_compare_ge
	cmp r0, #0
	blt _08056A30
	adds r5, r4, #0
_08056A30:
	adds r0, r5, #0
	ldr r1, _08056AE8 @ =0x43400000
	bl softfloat_add_f32
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	add r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	ldr r1, _08056AEC @ =0x43800000
	bl softfloat_add_f32
	adds r1, r0, #0
	ldr r0, [r6, #0x40]
	bl softfloat_multiply
	ldr r1, _08056AF0 @ =0x3B800000
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r7, #0
	bl softfloat_add_f32
	adds r7, r0, #0
	bl float_abs_if_negative
	ldr r1, [r6, #0x34]
	bl softfloat_compare_ge
	cmp r0, #0
	bge _08056A8A
	movs r0, #1
	add r8, r0
_08056A7C:
	ldr r4, [r6, #0x3c]
	adds r0, r4, #0
	ldr r1, _08056AF4 @ =0x00000000
	bl soft_float_eq
	cmp r0, #0
	bne _08056A18
_08056A8A:
	mov r0, r8
	bl int_to_softfloat
	str r0, [r6, #0x2c]
	ldr r0, [r6, #0x40]
	bl float_abs_if_negative
	bl float_default_to_one_if_zero
	adds r1, r0, #0
	ldr r0, [r6, #0x38]
	bl softfloat_divide
	adds r4, r0, #0
	str r4, [r6, #0x30]
	ldr r0, [r6, #0x20]
	bl int_to_softfloat
	ldr r1, [r6, #0x2c]
	bl softfloat_add_f32
	adds r1, r4, #0
	bl softfloat_add_f32
	bl float_to_int
	str r0, [r6, #0x24]
	adds r0, r7, #0
	bl float_abs_if_negative
	adds r1, r0, #0
	ldr r0, [r6, #0x34]
	bl softfloat_subtract
	adds r1, r0, #0
	ldr r0, [r6, #0x38]
	bl softfloat_add_f32
	str r0, [r6, #0x38]
	ldr r0, [r6, #0x44]
	cmp r0, #0
	bne _08056AE0
	b _08056DC8
_08056AE0:
	ldr r0, [r6, #0x40]
	b _08056D48
	.align 2, 0
_08056AE4: .4byte 0x42800000
_08056AE8: .4byte 0x43400000
_08056AEC: .4byte 0x43800000
_08056AF0: .4byte 0x3B800000
_08056AF4: .4byte 0x00000000
_08056AF8:
	ldr r0, [r6, #0x20]
	bl int_to_softfloat
	ldr r5, [r6, #0x28]
	adds r1, r5, #0
	bl softfloat_add_f32
	bl float_to_int
	str r0, [r6, #0x24]
	ldr r4, [r6, #0x2c]
	adds r0, r5, #0
	adds r1, r4, #0
	bl softfloat_subtract
	str r0, [r6, #0x30]
	adds r0, r4, #0
	bl float_default_to_one_if_zero
	adds r1, r0, #0
	ldr r0, _08056B40 @ =0x42800000
	bl softfloat_divide
	adds r4, r0, #0
	str r4, [r6, #0x3c]
	ldr r0, [r6, #0x40]
	ldr r1, [r6, #0x30]
	bl softfloat_multiply
	str r0, [r6, #0x38]
	ldr r5, [r6, #0x14]
	ldr r0, _08056B44 @ =0x00000000
	str r0, [r6, #0x34]
	ldr r7, _08056B48 @ =0x080AE77C
	b _08056B9A
	.align 2, 0
_08056B40: .4byte 0x42800000
_08056B44: .4byte 0x00000000
_08056B48: .4byte 0x080AE77C
_08056B4C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl softfloat_add_f32
	adds r5, r0, #0
	ldr r1, _08056BB4 @ =0x43400000
	bl softfloat_add_f32
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r7
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	ldr r1, _08056BB8 @ =0x43800000
	bl softfloat_add_f32
	adds r1, r0, #0
	ldr r0, [r6, #0x40]
	bl softfloat_multiply
	ldr r1, _08056BBC @ =0x3B800000
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [r6, #0x34]
	bl softfloat_add_f32
	str r0, [r6, #0x34]
	adds r0, r5, #0
	ldr r1, _08056BC0 @ =0x42800000
	bl softfloat_compare_ge
	cmp r0, #0
	bge _08056BA6
_08056B9A:
	adds r0, r4, #0
	ldr r1, _08056BC4 @ =0x00000000
	bl soft_float_eq
	cmp r0, #0
	bne _08056B4C
_08056BA6:
	ldr r0, [r6, #0x44]
	cmp r0, #0
	bne _08056BAE
	b _08056DC8
_08056BAE:
	ldr r0, [r6, #0x40]
	b _08056D48
	.align 2, 0
_08056BB4: .4byte 0x43400000
_08056BB8: .4byte 0x43800000
_08056BBC: .4byte 0x3B800000
_08056BC0: .4byte 0x42800000
_08056BC4: .4byte 0x00000000
_08056BC8:
	ldr r1, [r6, #0x38]
	ldr r0, _08056BE4 @ =0x42800000
	bl softfloat_divide
	str r0, [r6, #0x40]
	ldr r5, [r6, #0x14]
	ldr r0, _08056BE8 @ =0x00000000
	mov sb, r0
	movs r2, #0
	mov r8, r2
	ldr r7, [r6, #0x3c]
	ldr r0, _08056BEC @ =0x080AE77C
	mov sl, r0
	b _08056BF4
	.align 2, 0
_08056BE4: .4byte 0x42800000
_08056BE8: .4byte 0x00000000
_08056BEC: .4byte 0x080AE77C
_08056BF0:
	movs r2, #1
	add r8, r2
_08056BF4:
	ldr r1, [r6, #0x40]
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r5, r0, #0
	ldr r4, _08056CAC @ =0x42800000
	adds r1, r4, #0
	bl softfloat_compare_ge
	cmp r0, #0
	blt _08056C0C
	adds r5, r4, #0
_08056C0C:
	adds r0, r5, #0
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	adds r1, #0x40
	lsls r1, r1, #1
	add r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	adds r1, r0, #0
	adds r0, r7, #0
	bl softfloat_multiply
	ldr r1, _08056CB0 @ =0x3B800000
	bl softfloat_multiply
	adds r1, r0, #0
	mov r0, sb
	bl softfloat_add_f32
	mov sb, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl soft_float_eq
	cmp r0, #0
	bne _08056BF0
	mov r0, r8
	bl int_to_softfloat
	str r0, [r6, #0x30]
	mov r0, sb
	bl float_abs_if_negative
	adds r1, r0, #0
	ldr r0, [r6, #0x38]
	bl softfloat_subtract
	adds r1, r0, #0
	ldr r0, [r6, #0x34]
	bl softfloat_add_f32
	str r0, [r6, #0x34]
	mov r0, sb
	bl float_abs_if_negative
	str r0, [r6, #0x38]
	ldr r0, [r6, #0x3c]
	bl float_abs_if_negative
	bl float_default_to_one_if_zero
	adds r1, r0, #0
	ldr r0, [r6, #0x34]
	bl softfloat_divide
	adds r4, r0, #0
	str r4, [r6, #0x2c]
	ldr r0, [r6, #0x20]
	bl int_to_softfloat
	adds r1, r4, #0
	bl softfloat_add_f32
	ldr r1, [r6, #0x30]
	bl softfloat_add_f32
	bl float_to_int
	str r0, [r6, #0x24]
	ldr r0, [r6, #0x44]
	cmp r0, #0
	bne _08056CA6
	b _08056DC8
_08056CA6:
	ldr r0, [r6, #0x3c]
	b _08056D48
	.align 2, 0
_08056CAC: .4byte 0x42800000
_08056CB0: .4byte 0x3B800000
_08056CB4:
	ldr r0, [r6, #0x20]
	bl int_to_softfloat
	ldr r4, [r6, #0x28]
	adds r1, r4, #0
	bl softfloat_add_f32
	bl float_to_int
	str r0, [r6, #0x24]
	ldr r5, [r6, #0x30]
	adds r0, r4, #0
	adds r1, r5, #0
	bl softfloat_subtract
	adds r1, r0, #0
	str r1, [r6, #0x2c]
	ldr r0, [r6, #0x3c]
	bl softfloat_multiply
	str r0, [r6, #0x34]
	adds r0, r5, #0
	bl float_default_to_one_if_zero
	adds r1, r0, #0
	ldr r0, _08056D78 @ =0x42800000
	bl softfloat_divide
	str r0, [r6, #0x40]
	ldr r5, [r6, #0x14]
	ldr r0, _08056D7C @ =0x00000000
	str r0, [r6, #0x38]
	ldr r0, _08056D80 @ =0x080AE77C
	mov r8, r0
_08056CF8:
	ldr r1, [r6, #0x40]
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r5, r0, #0
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	adds r1, #0x40
	lsls r1, r1, #1
	add r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	adds r1, r0, #0
	ldr r4, [r6, #0x3c]
	adds r0, r4, #0
	bl softfloat_multiply
	ldr r1, _08056D84 @ =0x3B800000
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [r6, #0x38]
	bl softfloat_add_f32
	str r0, [r6, #0x38]
	adds r0, r5, #0
	ldr r1, _08056D78 @ =0x42800000
	bl softfloat_compare_ge
	adds r7, r4, #0
	cmp r0, #0
	blt _08056CF8
	ldr r0, [r6, #0x44]
	cmp r0, #0
	beq _08056DC8
	adds r0, r7, #0
_08056D48:
	bl float_sign
	adds r5, r0, #0
	ldr r0, [r6, #0x34]
	bl float_abs_if_negative
	adds r4, r0, #0
	ldr r0, [r6, #0x38]
	bl float_abs_if_negative
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r1, r0, #0
	adds r0, r5, #0
_08056D68:
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [r6]
	bl softfloat_subtract
	str r0, [r6]
	b _08056DC8
	.align 2, 0
_08056D78: .4byte 0x42800000
_08056D7C: .4byte 0x00000000
_08056D80: .4byte 0x080AE77C
_08056D84: .4byte 0x3B800000
_08056D88:
	ldr r0, [r6, #0x20]
	bl int_to_softfloat
	ldr r1, [r6, #0x28]
	bl softfloat_add_f32
	bl float_to_int
	str r0, [r6, #0x24]
	ldr r4, _08056DD8 @ =0x080AE77C
	ldr r5, [r6, #0x2c]
	adds r0, r5, #0
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	adds r1, r0, #0
	ldr r0, [r6, #0x40]
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [r6, #4]
	bl softfloat_add_f32
	str r0, [r6]
	str r5, [r6, #0x14]
_08056DC8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08056DD8: .4byte 0x080AE77C
	.syntax divided
