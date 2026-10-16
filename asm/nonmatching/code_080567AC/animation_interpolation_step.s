	.syntax unified

	thumb_func_start animation_interpolation_step
	.global animation_interpolation_step
animation_interpolation_step: @ 0x08056DDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	movs r2, #1
	mov sb, r2
	ldr r7, [r5, #0xc]
	cmp r7, #0
	bne _08056DF8
	b _0805700E
_08056DF8:
	ldr r4, [r5, #0x20]
	adds r0, r4, #0
	bl int_to_softfloat
	ldr r6, [r5, #0x1c]
	adds r1, r6, #0
	bl soft_float_gt
	mov r8, r6
	cmp r0, #0
	ble _08056E10
	b _08057004
_08056E10:
	adds r0, r7, #0
	subs r0, #0x10
	cmp r0, #7
	bls _08056E1A
	b _08056FC6
_08056E1A:
	lsls r0, r0, #2
	ldr r1, _08056E24 @ =_08056E28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08056E24: .4byte _08056E28
_08056E28: @ jump table
	.4byte _08056E48 @ case 0
	.4byte _08056E48 @ case 1
	.4byte _08056E68 @ case 2
	.4byte _08056E68 @ case 3
	.4byte _08056F02 @ case 4
	.4byte _08056F02 @ case 5
	.4byte _08056FC6 @ case 6
	.4byte _08056F84 @ case 7
_08056E48:
	adds r0, r4, #0
	bl int_to_softfloat
	ldr r1, [r5, #0x2c]
	bl softfloat_add_f32
	adds r1, r0, #0
	mov r0, r8
	bl soft_float_ge
	cmp r0, #0
	blt _08056E62
	b _08056FC6
_08056E62:
	ldr r0, [r5]
	ldr r1, [r5, #0x3c]
	b _08056FC0
_08056E68:
	adds r0, r4, #0
	bl int_to_softfloat
	ldr r1, [r5, #0x2c]
	bl softfloat_add_f32
	adds r1, r0, #0
	mov r0, r8
	bl soft_float_ge
	cmp r0, #0
	bge _08056EFC
	mov r0, sb
	bl int_to_softfloat
	adds r6, r0, #0
	ldr r0, [r5, #0x3c]
	adds r1, r6, #0
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [r5, #0x14]
	bl softfloat_add_f32
	str r0, [r5, #0x14]
	ldr r4, _08056EE8 @ =0x42800000
	adds r1, r4, #0
	bl softfloat_compare_ge
	cmp r0, #0
	blt _08056EA8
	str r4, [r5, #0x14]
_08056EA8:
	ldr r4, _08056EEC @ =0x080AE77C
	ldr r0, [r5, #0x14]
	ldr r1, _08056EF0 @ =0x43400000
	bl softfloat_add_f32
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	ldr r1, _08056EF4 @ =0x43800000
	bl softfloat_add_f32
	adds r1, r0, #0
	ldr r0, [r5, #0x40]
	bl softfloat_multiply
	ldr r1, _08056EF8 @ =0x3B800000
	bl softfloat_multiply
	adds r1, r6, #0
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [r5]
	b _08056FC0
	.align 2, 0
_08056EE8: .4byte 0x42800000
_08056EEC: .4byte 0x080AE77C
_08056EF0: .4byte 0x43400000
_08056EF4: .4byte 0x43800000
_08056EF8: .4byte 0x3B800000
_08056EFC:
	ldr r0, [r5]
	ldr r1, [r5, #0x40]
	b _08056FC0
_08056F02:
	adds r0, r4, #0
	bl int_to_softfloat
	ldr r1, [r5, #0x2c]
	bl softfloat_add_f32
	adds r1, r0, #0
	mov r0, r8
	bl soft_float_ge
	cmp r0, #0
	bge _08056F20
	ldr r0, [r5]
	ldr r1, [r5, #0x3c]
	b _08056FC0
_08056F20:
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x40]
	bl softfloat_add_f32
	str r0, [r5, #0x14]
	ldr r4, _08056F78 @ =0x42800000
	adds r1, r4, #0
	bl softfloat_compare_ge
	cmp r0, #0
	blt _08056F38
	str r4, [r5, #0x14]
_08056F38:
	ldr r4, _08056F7C @ =0x080AE77C
	ldr r0, [r5, #0x14]
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	adds r1, #0x40
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	adds r1, r0, #0
	ldr r0, [r5, #0x3c]
	bl softfloat_multiply
	ldr r1, _08056F80 @ =0x3B800000
	bl softfloat_multiply
	adds r4, r0, #0
	mov r0, sb
	bl int_to_softfloat
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [r5]
	b _08056FC0
	.align 2, 0
_08056F78: .4byte 0x42800000
_08056F7C: .4byte 0x080AE77C
_08056F80: .4byte 0x3B800000
_08056F84:
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x3c]
	bl softfloat_add_f32
	str r0, [r5, #0x14]
	ldr r4, _08056FF8 @ =0x080AE77C
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	adds r1, r0, #0
	ldr r0, [r5, #0x40]
	bl softfloat_multiply
	adds r4, r0, #0
	mov r0, sb
	bl int_to_softfloat
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [r5, #4]
_08056FC0:
	bl softfloat_add_f32
	str r0, [r5]
_08056FC6:
	ldr r1, _08056FFC @ =0x3F800000
	mov r0, r8
	bl softfloat_add_f32
	adds r4, r0, #0
	str r4, [r5, #0x1c]
	ldr r1, [r5, #0x24]
	ldr r0, _08057000 @ =0x0000FFFF
	cmp r1, r0
	beq _0805700E
	adds r0, r1, #0
	bl int_to_softfloat
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_compare_ge
	cmp r0, #0
	blt _0805700E
	movs r0, #0
	str r0, [r5, #0xc]
	movs r0, #1
	mov sl, r0
	b _0805700E
	.align 2, 0
_08056FF8: .4byte 0x080AE77C
_08056FFC: .4byte 0x3F800000
_08057000: .4byte 0x0000FFFF
_08057004:
	ldr r1, _08057020 @ =0x3F800000
	adds r0, r6, #0
	bl softfloat_add_f32
	str r0, [r5, #0x1c]
_0805700E:
	mov r0, sl
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057020: .4byte 0x3F800000
	.syntax divided
