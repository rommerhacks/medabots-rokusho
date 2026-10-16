	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_0807CBBC
	.global sub_0807CBBC
sub_0807CBBC: @ 0x0807CBBC
	cmp r1, #0
	beq _0807CC44
	push {r4}
	adds r4, r0, #0
	eors r4, r1
	mov ip, r4
	movs r3, #1
	movs r2, #0
	cmp r1, #0
	bpl _0807CBD2
	rsbs r1, r1, #0
_0807CBD2:
	cmp r0, #0
	bpl _0807CBD8
	rsbs r0, r0, #0
_0807CBD8:
	cmp r0, r1
	blo _0807CC36
	movs r4, #1
	lsls r4, r4, #0x1c
_0807CBE0:
	cmp r1, r4
	bhs _0807CBEE
	cmp r1, r0
	bhs _0807CBEE
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _0807CBE0
_0807CBEE:
	lsls r4, r4, #3
_0807CBF0:
	cmp r1, r4
	bhs _0807CBFE
	cmp r1, r0
	bhs _0807CBFE
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _0807CBF0
_0807CBFE:
	cmp r0, r1
	blo _0807CC06
	subs r0, r0, r1
	orrs r2, r3
_0807CC06:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _0807CC12
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
_0807CC12:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _0807CC1E
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
_0807CC1E:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _0807CC2A
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
_0807CC2A:
	cmp r0, #0
	beq _0807CC36
	lsrs r3, r3, #4
	beq _0807CC36
	lsrs r1, r1, #4
	b _0807CBFE
_0807CC36:
	adds r0, r2, #0
	mov r4, ip
	cmp r4, #0
	bpl _0807CC40
	rsbs r0, r0, #0
_0807CC40:
	pop {r4}
	mov pc, lr
_0807CC44:
	push {lr}
	bl sub_0807CC50
	movs r0, #0
	pop {pc}
	.align 2, 0

	thumb_func_start sub_0807CC50
sub_0807CC50: @ 0x0807CC50
	mov pc, lr
	.align 2, 0

	thumb_func_start float_clamp_to_int
	.global float_clamp_to_int
float_clamp_to_int: @ 0x0807CC54
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0807CC6C @ =0x4F000000
	bl softfloat_compare_ge
	cmp r0, #0
	bge _0807CC70
	adds r0, r4, #0
	bl float_to_int
	b _0807CC82
	.align 2, 0
_0807CC6C: .4byte 0x4F000000
_0807CC70:
	ldr r1, _0807CC84 @ =0xCF000000
	adds r0, r4, #0
	bl softfloat_add_f32
	bl float_to_int
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
_0807CC82:
	pop {r4, pc}
	.align 2, 0
_0807CC84: .4byte 0xCF000000

	thumb_func_start sub_0807CC88
	.global sub_0807CC88
sub_0807CC88: @ 0x0807CC88
	movs r3, #1
	cmp r1, #0
	beq _0807CD4C
	bpl _0807CC92
	rsbs r1, r1, #0
_0807CC92:
	push {r4}
	push {r0}
	cmp r0, #0
	bpl _0807CC9C
	rsbs r0, r0, #0
_0807CC9C:
	cmp r0, r1
	blo _0807CD40
	movs r4, #1
	lsls r4, r4, #0x1c
_0807CCA4:
	cmp r1, r4
	bhs _0807CCB2
	cmp r1, r0
	bhs _0807CCB2
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _0807CCA4
_0807CCB2:
	lsls r4, r4, #3
_0807CCB4:
	cmp r1, r4
	bhs _0807CCC2
	cmp r1, r0
	bhs _0807CCC2
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _0807CCB4
_0807CCC2:
	movs r2, #0
	cmp r0, r1
	blo _0807CCCA
	subs r0, r0, r1
_0807CCCA:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _0807CCDC
	subs r0, r0, r4
	mov ip, r3
	movs r4, #1
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_0807CCDC:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _0807CCEE
	subs r0, r0, r4
	mov ip, r3
	movs r4, #2
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_0807CCEE:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _0807CD00
	subs r0, r0, r4
	mov ip, r3
	movs r4, #3
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_0807CD00:
	mov ip, r3
	cmp r0, #0
	beq _0807CD0E
	lsrs r3, r3, #4
	beq _0807CD0E
	lsrs r1, r1, #4
	b _0807CCC2
_0807CD0E:
	movs r4, #0xe
	lsls r4, r4, #0x1c
	ands r2, r4
	beq _0807CD40
	mov r3, ip
	movs r4, #3
	rors r3, r4
	tst r2, r3
	beq _0807CD24
	lsrs r4, r1, #3
	adds r0, r0, r4
_0807CD24:
	mov r3, ip
	movs r4, #2
	rors r3, r4
	tst r2, r3
	beq _0807CD32
	lsrs r4, r1, #2
	adds r0, r0, r4
_0807CD32:
	mov r3, ip
	movs r4, #1
	rors r3, r4
	tst r2, r3
	beq _0807CD40
	lsrs r4, r1, #1
	adds r0, r0, r4
_0807CD40:
	pop {r4}
	cmp r4, #0
	bpl _0807CD48
	rsbs r0, r0, #0
_0807CD48:
	pop {r4}
	mov pc, lr
_0807CD4C:
	push {lr}
	bl sub_0807CC50
	movs r0, #0
	pop {pc}
	.align 2, 0

	thumb_func_start sub_0807CD58
	.global sub_0807CD58
sub_0807CD58: @ 0x0807CD58
	cmp r1, #0
	beq _0807CDC6
	movs r3, #1
	movs r2, #0
	push {r4}
	cmp r0, r1
	blo _0807CDC0
	movs r4, #1
	lsls r4, r4, #0x1c
_0807CD6A:
	cmp r1, r4
	bhs _0807CD78
	cmp r1, r0
	bhs _0807CD78
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _0807CD6A
_0807CD78:
	lsls r4, r4, #3
_0807CD7A:
	cmp r1, r4
	bhs _0807CD88
	cmp r1, r0
	bhs _0807CD88
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _0807CD7A
_0807CD88:
	cmp r0, r1
	blo _0807CD90
	subs r0, r0, r1
	orrs r2, r3
_0807CD90:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _0807CD9C
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
_0807CD9C:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _0807CDA8
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
_0807CDA8:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _0807CDB4
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
_0807CDB4:
	cmp r0, #0
	beq _0807CDC0
	lsrs r3, r3, #4
	beq _0807CDC0
	lsrs r1, r1, #4
	b _0807CD88
_0807CDC0:
	adds r0, r2, #0
	pop {r4}
	mov pc, lr
_0807CDC6:
	push {lr}
	bl sub_0807CC50
	movs r0, #0
	pop {pc}

	thumb_func_start sub_0807CDD0
	.global sub_0807CDD0
sub_0807CDD0: @ 0x0807CDD0
	cmp r1, #0
	beq _0807CE86
	movs r3, #1
	cmp r0, r1
	bhs _0807CDDC
	mov pc, lr
_0807CDDC:
	push {r4}
	movs r4, #1
	lsls r4, r4, #0x1c
_0807CDE2:
	cmp r1, r4
	bhs _0807CDF0
	cmp r1, r0
	bhs _0807CDF0
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _0807CDE2
_0807CDF0:
	lsls r4, r4, #3
_0807CDF2:
	cmp r1, r4
	bhs _0807CE00
	cmp r1, r0
	bhs _0807CE00
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _0807CDF2
_0807CE00:
	movs r2, #0
	cmp r0, r1
	blo _0807CE08
	subs r0, r0, r1
_0807CE08:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _0807CE1A
	subs r0, r0, r4
	mov ip, r3
	movs r4, #1
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_0807CE1A:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _0807CE2C
	subs r0, r0, r4
	mov ip, r3
	movs r4, #2
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_0807CE2C:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _0807CE3E
	subs r0, r0, r4
	mov ip, r3
	movs r4, #3
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_0807CE3E:
	mov ip, r3
	cmp r0, #0
	beq _0807CE4C
	lsrs r3, r3, #4
	beq _0807CE4C
	lsrs r1, r1, #4
	b _0807CE00
_0807CE4C:
	movs r4, #0xe
	lsls r4, r4, #0x1c
	ands r2, r4
	bne _0807CE58
	pop {r4}
	mov pc, lr
_0807CE58:
	mov r3, ip
	movs r4, #3
	rors r3, r4
	tst r2, r3
	beq _0807CE66
	lsrs r4, r1, #3
	adds r0, r0, r4
_0807CE66:
	mov r3, ip
	movs r4, #2
	rors r3, r4
	tst r2, r3
	beq _0807CE74
	lsrs r4, r1, #2
	adds r0, r0, r4
_0807CE74:
	mov r3, ip
	movs r4, #1
	rors r3, r4
	tst r2, r3
	beq _0807CE82
	lsrs r4, r1, #1
	adds r0, r0, r4
_0807CE82:
	pop {r4}
	mov pc, lr
_0807CE86:
	push {lr}
	bl sub_0807CC50
	movs r0, #0
	pop {pc}

	thumb_func_start softfloat_pack_double
softfloat_pack_double: @ 0x0807CE90
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r1, r0, #0
	ldr r4, [r1, #0xc]
	ldr r5, [r1, #0x10]
	ldr r7, [r1, #4]
	movs r6, #0
	movs r2, #0
	ldr r0, [r1]
	cmp r0, #1
	bhi _0807CEA8
	movs r2, #1
_0807CEA8:
	cmp r2, #0
	beq _0807CEC8
	ldr r6, _0807CEBC @ =0x000007FF
	ldr r2, _0807CEC0 @ =0x00000000
	ldr r3, _0807CEC4 @ =0x00080000
	adds r0, r4, #0
	adds r1, r5, #0
	orrs r1, r3
	b _0807CF80
	.align 2, 0
_0807CEBC: .4byte 0x000007FF
_0807CEC0: .4byte 0x00000000
_0807CEC4: .4byte 0x00080000
_0807CEC8:
	movs r2, #0
	cmp r0, #4
	bne _0807CED0
	movs r2, #1
_0807CED0:
	cmp r2, #0
	bne _0807CF1C
	movs r2, #0
	cmp r0, #2
	bne _0807CEDC
	movs r2, #1
_0807CEDC:
	cmp r2, #0
	beq _0807CEE6
	movs r4, #0
	movs r5, #0
	b _0807CF84
_0807CEE6:
	adds r0, r5, #0
	orrs r0, r4
	cmp r0, #0
	beq _0807CF84
	ldr r2, [r1, #8]
	ldr r0, _0807CF04 @ =0xFFFFFC02
	cmp r2, r0
	bge _0807CF16
	subs r2, r0, r2
	cmp r2, #0x38
	ble _0807CF08
	movs r4, #0
	movs r5, #0
	b _0807CF76
	.align 2, 0
_0807CF04: .4byte 0xFFFFFC02
_0807CF08:
	adds r1, r5, #0
	adds r0, r4, #0
	bl lsr64
	adds r5, r1, #0
	adds r4, r0, #0
	b _0807CF76
_0807CF16:
	ldr r0, _0807CF24 @ =0x000003FF
	cmp r2, r0
	ble _0807CF2C
_0807CF1C:
	ldr r6, _0807CF28 @ =0x000007FF
	movs r4, #0
	movs r5, #0
	b _0807CF84
	.align 2, 0
_0807CF24: .4byte 0x000003FF
_0807CF28: .4byte 0x000007FF
_0807CF2C:
	ldr r0, _0807CF54 @ =0x000003FF
	adds r6, r2, r0
	movs r0, #0xff
	adds r1, r4, #0
	ands r1, r0
	movs r2, #0
	cmp r1, #0x80
	bne _0807CF58
	cmp r2, #0
	bne _0807CF58
	adds r0, #1
	adds r1, r4, #0
	ands r1, r0
	adds r0, r2, #0
	orrs r0, r1
	cmp r0, #0
	beq _0807CF60
	movs r0, #0x80
	movs r1, #0
	b _0807CF5C
	.align 2, 0
_0807CF54: .4byte 0x000003FF
_0807CF58:
	movs r0, #0x7f
	movs r1, #0
_0807CF5C:
	adds r4, r4, r0
	adcs r5, r1
_0807CF60:
	ldr r0, _0807CFC4 @ =0x1FFFFFFF
	cmp r5, r0
	bls _0807CF76
	lsls r3, r5, #0x1f
	lsrs r2, r4, #1
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r5, #1
	adds r5, r1, #0
	adds r4, r0, #0
	adds r6, #1
_0807CF76:
	lsls r3, r5, #0x18
	lsrs r2, r4, #8
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r5, #8
_0807CF80:
	adds r5, r1, #0
	adds r4, r0, #0
_0807CF84:
	str r4, [sp]
	ldr r2, _0807CFC8 @ =0x000FFFFF
	ands r2, r5
	ldr r0, [sp, #4]
	ldr r1, _0807CFCC @ =0xFFF00000
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	mov r2, sp
	ldr r1, _0807CFD0 @ =0x000007FF
	adds r0, r1, #0
	ands r6, r0
	lsls r1, r6, #4
	ldr r0, _0807CFD4 @ =0xFFFF800F
	ldrh r3, [r2, #6]
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #6]
	lsls r1, r7, #7
	movs r0, #0x7f
	ldrb r3, [r2, #7]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #7]
	ldr r1, [sp]
	ldr r0, [sp, #4]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	add sp, #8
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0807CFC4: .4byte 0x1FFFFFFF
_0807CFC8: .4byte 0x000FFFFF
_0807CFCC: .4byte 0xFFF00000
_0807CFD0: .4byte 0x000007FF
_0807CFD4: .4byte 0xFFFF800F

	thumb_func_start double_decompose
double_decompose: @ 0x0807CFD8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r6, r1, #0
	ldr r1, [r2, #4]
	str r1, [sp]
	ldr r0, [r2]
	str r0, [sp, #4]
	mov r2, sp
	adds r4, r1, #0
	lsls r0, r0, #0xc
	lsrs r5, r0, #0xc
	ldrh r3, [r2, #6]
	lsls r0, r3, #0x11
	lsrs r3, r0, #0x15
	ldrb r2, [r2, #7]
	lsrs r0, r2, #7
	str r0, [r6, #4]
	cmp r3, #0
	bne _0807D04C
	orrs r1, r5
	cmp r1, #0
	bne _0807D00C
	movs r0, #2
	str r0, [r6]
	b _0807D0A0
_0807D00C:
	ldr r0, _0807D044 @ =0xFFFFFC02
	str r0, [r6, #8]
	lsrs r3, r4, #0x18
	lsls r2, r5, #8
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #8
	adds r5, r1, #0
	adds r4, r0, #0
	movs r0, #3
	str r0, [r6]
	ldr r0, _0807D048 @ =0x0FFFFFFF
	cmp r5, r0
	bhi _0807D07C
	adds r7, r0, #0
_0807D02A:
	lsrs r3, r4, #0x1f
	lsls r2, r5, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #1
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [r6, #8]
	subs r0, #1
	str r0, [r6, #8]
	cmp r5, r7
	bls _0807D02A
	b _0807D07C
	.align 2, 0
_0807D044: .4byte 0xFFFFFC02
_0807D048: .4byte 0x0FFFFFFF
_0807D04C:
	ldr r0, _0807D060 @ =0x000007FF
	cmp r3, r0
	bne _0807D082
	orrs r1, r5
	cmp r1, #0
	bne _0807D064
	movs r0, #4
	str r0, [r6]
	b _0807D0A0
	.align 2, 0
_0807D060: .4byte 0x000007FF
_0807D064:
	movs r2, #0x80
	lsls r2, r2, #0xc
	movs r0, #0
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	cmp r1, #0
	beq _0807D07A
	movs r0, #1
	str r0, [r6]
	b _0807D07C
_0807D07A:
	str r1, [r6]
_0807D07C:
	str r4, [r6, #0xc]
	str r5, [r6, #0x10]
	b _0807D0A0
_0807D082:
	ldr r1, _0807D0A4 @ =0xFFFFFC01
	adds r0, r3, r1
	str r0, [r6, #8]
	movs r0, #3
	str r0, [r6]
	lsrs r3, r4, #0x18
	lsls r2, r5, #8
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #8
	ldr r2, _0807D0A8 @ =0x00000000
	ldr r3, _0807D0AC @ =0x10000000
	orrs r1, r3
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
_0807D0A0:
	add sp, #8
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0807D0A4: .4byte 0xFFFFFC01
_0807D0A8: .4byte 0x00000000
_0807D0AC: .4byte 0x10000000

	thumb_func_start softfloat_add_0807D0B0
softfloat_add_0807D0B0: @ 0x0807D0B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r3, r0, #0
	adds r4, r1, #0
	mov sl, r2
	movs r0, #0
	ldr r2, [r3]
	cmp r2, #1
	bhi _0807D0CC
	movs r0, #1
_0807D0CC:
	cmp r0, #0
	beq _0807D0D4
_0807D0D0:
	adds r0, r3, #0
	b _0807D30C
_0807D0D4:
	movs r1, #0
	ldr r0, [r4]
	cmp r0, #1
	bhi _0807D0DE
	movs r1, #1
_0807D0DE:
	cmp r1, #0
	bne _0807D156
	movs r1, #0
	cmp r2, #4
	bne _0807D0EA
	movs r1, #1
_0807D0EA:
	cmp r1, #0
	beq _0807D10C
	movs r1, #0
	cmp r0, #4
	bne _0807D0F6
	movs r1, #1
_0807D0F6:
	cmp r1, #0
	beq _0807D0D0
	ldr r1, [r3, #4]
	ldr r0, [r4, #4]
	cmp r1, r0
	beq _0807D0D0
	ldr r0, _0807D108 @ =0x03000408
	b _0807D30C
	.align 2, 0
_0807D108: .4byte 0x03000408
_0807D10C:
	movs r1, #0
	cmp r0, #4
	bne _0807D114
	movs r1, #1
_0807D114:
	cmp r1, #0
	bne _0807D156
	movs r1, #0
	cmp r0, #2
	bne _0807D120
	movs r1, #1
_0807D120:
	cmp r1, #0
	beq _0807D148
	movs r0, #0
	cmp r2, #2
	bne _0807D12C
	movs r0, #1
_0807D12C:
	cmp r0, #0
	beq _0807D0D0
	mov r1, sl
	adds r0, r3, #0
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
	ldm r0!, {r2, r5}
	stm r1!, {r2, r5}
	ldr r0, [r3, #4]
	ldr r1, [r4, #4]
	ands r0, r1
	mov r6, sl
	str r0, [r6, #4]
	b _0807D30A
_0807D148:
	movs r1, #0
	ldr r0, [r3]
	cmp r0, #2
	bne _0807D152
	movs r1, #1
_0807D152:
	cmp r1, #0
	beq _0807D15A
_0807D156:
	adds r0, r4, #0
	b _0807D30C
_0807D15A:
	ldr r0, [r3, #8]
	mov sb, r0
	ldr r1, [r4, #8]
	mov r8, r1
	ldr r6, [r3, #0xc]
	ldr r7, [r3, #0x10]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, sb
	mov r2, r8
	subs r0, r1, r2
	cmp r0, #0
	bge _0807D17A
	rsbs r0, r0, #0
_0807D17A:
	cmp r0, #0x3f
	bgt _0807D1F8
	ldr r3, [r3, #4]
	mov ip, r3
	ldr r4, [r4, #4]
	str r4, [sp, #8]
	cmp sb, r8
	ble _0807D1C4
	mov r3, sb
	mov r4, r8
	subs r3, r3, r4
	mov r8, r3
_0807D192:
	movs r5, #1
	rsbs r5, r5, #0
	add r8, r5
	ldr r2, [sp]
	movs r0, #1
	ands r2, r0
	movs r3, #0
	ldr r1, [sp, #4]
	lsls r5, r1, #0x1f
	ldr r0, [sp]
	lsrs r4, r0, #1
	adds r0, r5, #0
	orrs r0, r4
	adds r4, r1, #0
	lsrs r1, r4, #1
	adds r5, r2, #0
	orrs r5, r0
	str r5, [sp]
	adds r4, r3, #0
	orrs r4, r1
	str r4, [sp, #4]
	mov r5, r8
	cmp r5, #0
	bne _0807D192
	mov r8, sb
_0807D1C4:
	cmp r8, sb
	ble _0807D214
	mov r0, r8
	mov r1, sb
	subs r0, r0, r1
	mov sb, r0
_0807D1D0:
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	movs r2, #1
	ands r2, r6
	movs r3, #0
	lsls r5, r7, #0x1f
	lsrs r4, r6, #1
	adds r0, r5, #0
	orrs r0, r4
	lsrs r1, r7, #1
	adds r6, r2, #0
	orrs r6, r0
	adds r7, r3, #0
	orrs r7, r1
	mov r3, sb
	cmp r3, #0
	bne _0807D1D0
	mov sb, r8
	b _0807D214
_0807D1F8:
	cmp sb, r8
	ble _0807D206
	movs r0, #0
	movs r1, #0
	str r0, [sp]
	str r1, [sp, #4]
	b _0807D20C
_0807D206:
	mov sb, r8
	movs r6, #0
	movs r7, #0
_0807D20C:
	ldr r3, [r3, #4]
	mov ip, r3
	ldr r4, [r4, #4]
	str r4, [sp, #8]
_0807D214:
	ldr r1, [sp, #8]
	cmp ip, r1
	beq _0807D2BC
	mov r2, ip
	cmp r2, #0
	beq _0807D236
	adds r1, r7, #0
	adds r0, r6, #0
	bl negate_64bit
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r4, [sp]
	ldr r5, [sp, #4]
	adds r2, r2, r4
	adcs r3, r5
	b _0807D242
_0807D236:
	adds r3, r7, #0
	adds r2, r6, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	subs r2, r2, r0
	sbcs r3, r1
_0807D242:
	cmp r3, #0
	blt _0807D258
	movs r0, #0
	mov r1, sl
	str r0, [r1, #4]
	mov r4, sb
	str r4, [r1, #8]
	mov r5, sl
	str r2, [r5, #0xc]
	str r3, [r5, #0x10]
	b _0807D270
_0807D258:
	movs r0, #1
	mov r6, sl
	str r0, [r6, #4]
	mov r0, sb
	str r0, [r6, #8]
	adds r1, r3, #0
	adds r0, r2, #0
	bl negate_64bit
	mov r2, sl
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
_0807D270:
	mov r4, sl
	ldr r2, [r4, #0xc]
	ldr r3, [r4, #0x10]
	movs r0, #1
	rsbs r0, r0, #0
	asrs r1, r0, #0x1f
_0807D27C:
	adds r2, r2, r0
	adcs r3, r1
	ldr r0, _0807D2B8 @ =0x0FFFFFFF
	cmp r3, r0
	bhi _0807D2D4
	cmp r3, r0
	bne _0807D292
	movs r0, #2
	rsbs r0, r0, #0
	cmp r2, r0
	bhi _0807D2D4
_0807D292:
	mov r5, sl
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x10]
	lsrs r3, r0, #0x1f
	lsls r2, r1, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r0, #1
	mov r6, sl
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	ldr r2, [r6, #8]
	subs r2, #1
	str r2, [r6, #8]
	movs r2, #1
	rsbs r2, r2, #0
	asrs r3, r2, #0x1f
	b _0807D27C
	.align 2, 0
_0807D2B8: .4byte 0x0FFFFFFF
_0807D2BC:
	mov r0, ip
	mov r1, sl
	str r0, [r1, #4]
	mov r2, sb
	str r2, [r1, #8]
	ldr r3, [sp]
	ldr r4, [sp, #4]
	adds r6, r6, r3
	adcs r7, r4
	mov r4, sl
	str r6, [r4, #0xc]
	str r7, [r4, #0x10]
_0807D2D4:
	movs r0, #3
	mov r5, sl
	str r0, [r5]
	ldr r1, [r5, #0x10]
	ldr r0, _0807D318 @ =0x1FFFFFFF
	cmp r1, r0
	bls _0807D30A
	ldr r4, [r5, #0xc]
	ldr r5, [r5, #0x10]
	movs r2, #1
	adds r0, r4, #0
	ands r0, r2
	movs r1, #0
	lsls r6, r5, #0x1f
	mov r8, r6
	lsrs r6, r4, #1
	mov r2, r8
	orrs r2, r6
	lsrs r3, r5, #1
	orrs r0, r2
	orrs r1, r3
	mov r2, sl
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
_0807D30A:
	mov r0, sl
_0807D30C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0807D318: .4byte 0x1FFFFFFF

	thumb_func_start softfloat_double_add
softfloat_double_add: @ 0x0807D31C
	push {r4, lr}
	sub sp, #0x4c
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	str r3, [sp, #0x48]
	add r0, sp, #0x3c
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	add r2, sp, #0x28
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_add_0807D0B0
	bl softfloat_pack_double
	add sp, #0x4c
	pop {r4, pc}

	thumb_func_start softfloat_subtract_double
softfloat_subtract_double: @ 0x0807D34C
	push {r4, lr}
	sub sp, #0x4c
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	str r3, [sp, #0x48]
	add r0, sp, #0x3c
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	ldr r0, [r4, #4]
	movs r1, #1
	eors r0, r1
	str r0, [r4, #4]
	add r2, sp, #0x28
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_add_0807D0B0
	bl softfloat_pack_double
	add sp, #0x4c
	pop {r4, pc}

	thumb_func_start soft_double_multiply
soft_double_multiply: @ 0x0807D384
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x74
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	str r3, [sp, #0x48]
	add r0, sp, #0x3c
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	mov r8, sp
	add r0, sp, #0x28
	mov sl, r0
	movs r0, #0
	ldr r1, [sp]
	cmp r1, #1
	bhi _0807D3BA
	movs r0, #1
_0807D3BA:
	cmp r0, #0
	bne _0807D41E
	movs r2, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi _0807D3C8
	movs r2, #1
_0807D3C8:
	cmp r2, #0
	beq _0807D3D0
	ldr r0, [sp, #4]
	b _0807D440
_0807D3D0:
	movs r2, #0
	cmp r1, #4
	bne _0807D3D8
	movs r2, #1
_0807D3D8:
	cmp r2, #0
	beq _0807D3EA
	movs r1, #0
	cmp r0, #2
	bne _0807D3E4
	movs r1, #1
_0807D3E4:
	cmp r1, #0
	bne _0807D402
	b _0807D41E
_0807D3EA:
	movs r2, #0
	cmp r0, #4
	bne _0807D3F2
	movs r2, #1
_0807D3F2:
	cmp r2, #0
	beq _0807D412
	movs r0, #0
	cmp r1, #2
	bne _0807D3FE
	movs r0, #1
_0807D3FE:
	cmp r0, #0
	beq _0807D40C
_0807D402:
	ldr r0, _0807D408 @ =0x03000408
	b _0807D60A
	.align 2, 0
_0807D408: .4byte 0x03000408
_0807D40C:
	mov r1, r8
	ldr r0, [r1, #4]
	b _0807D440
_0807D412:
	movs r2, #0
	cmp r1, #2
	bne _0807D41A
	movs r2, #1
_0807D41A:
	cmp r2, #0
	beq _0807D430
_0807D41E:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x18]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	str r1, [sp, #4]
	mov r0, sp
	b _0807D60A
_0807D430:
	movs r1, #0
	cmp r0, #2
	bne _0807D438
	movs r1, #1
_0807D438:
	cmp r1, #0
	beq _0807D450
	mov r2, r8
	ldr r0, [r2, #4]
_0807D440:
	ldr r1, [sp, #0x18]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	str r1, [sp, #0x18]
	adds r0, r4, #0
	b _0807D60A
_0807D450:
	mov r4, r8
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	adds r6, r0, #0
	movs r7, #0
	str r1, [sp, #0x4c]
	movs r5, #0
	str r5, [sp, #0x50]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	adds r4, r0, #0
	str r1, [sp, #0x54]
	movs r0, #0
	str r0, [sp, #0x58]
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r7, #0
	adds r2, r6, #0
	bl umul64
	str r0, [sp, #0x5c]
	str r1, [sp, #0x60]
	ldr r0, [sp, #0x54]
	ldr r1, [sp, #0x58]
	adds r3, r7, #0
	adds r2, r6, #0
	bl umul64
	adds r7, r1, #0
	adds r6, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x4c]
	ldr r3, [sp, #0x50]
	bl umul64
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x54]
	ldr r1, [sp, #0x58]
	ldr r2, [sp, #0x4c]
	ldr r3, [sp, #0x50]
	bl umul64
	str r0, [sp, #0x64]
	str r1, [sp, #0x68]
	movs r1, #0
	movs r2, #0
	str r1, [sp, #0x6c]
	str r2, [sp, #0x70]
	adds r3, r7, #0
	adds r2, r6, #0
	adds r2, r2, r4
	adcs r3, r5
	cmp r7, r3
	bhi _0807D4C8
	cmp r7, r3
	bne _0807D4D0
	cmp r6, r2
	bls _0807D4D0
_0807D4C8:
	ldr r5, _0807D620 @ =0x00000001
	ldr r4, _0807D61C @ =0x00000000
	str r4, [sp, #0x6c]
	str r5, [sp, #0x70]
_0807D4D0:
	adds r1, r2, #0
	movs r6, #0
	adds r7, r1, #0
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x60]
	adds r6, r6, r0
	adcs r7, r1
	cmp r1, r7
	bhi _0807D4EC
	ldr r1, [sp, #0x60]
	cmp r1, r7
	bne _0807D4FC
	cmp r0, r6
	bls _0807D4FC
_0807D4EC:
	movs r0, #1
	movs r1, #0
	ldr r4, [sp, #0x6c]
	ldr r5, [sp, #0x70]
	adds r4, r4, r0
	adcs r5, r1
	str r4, [sp, #0x6c]
	str r5, [sp, #0x70]
_0807D4FC:
	adds r0, r3, #0
	adds r2, r0, #0
	movs r3, #0
	adds r5, r3, #0
	adds r4, r2, #0
	ldr r0, [sp, #0x64]
	ldr r1, [sp, #0x68]
	adds r4, r4, r0
	adcs r5, r1
	ldr r1, [sp, #0x6c]
	ldr r2, [sp, #0x70]
	adds r4, r4, r1
	adcs r5, r2
	mov r0, r8
	ldr r2, [r0, #8]
	ldr r0, [sp, #0x1c]
	adds r2, r2, r0
	str r2, [sp, #0x30]
	mov r0, r8
	ldr r1, [r0, #4]
	ldr r0, [sp, #0x18]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	str r0, [sp, #0x2c]
	adds r2, #4
	str r2, [sp, #0x30]
	ldr r0, _0807D624 @ =0x1FFFFFFF
	cmp r5, r0
	bls _0807D57E
	movs r1, #1
	mov sb, r1
	mov r8, r0
	mov ip, r2
_0807D542:
	movs r2, #1
	add ip, r2
	mov r0, sb
	ands r0, r4
	cmp r0, #0
	beq _0807D568
	lsls r3, r7, #0x1f
	lsrs r2, r6, #1
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r7, #1
	adds r7, r1, #0
	adds r6, r0, #0
	adds r0, r6, #0
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r1, r7
	adds r7, r1, #0
	adds r6, r0, #0
_0807D568:
	lsls r3, r5, #0x1f
	lsrs r2, r4, #1
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r5, #1
	adds r5, r1, #0
	adds r4, r0, #0
	cmp r5, r8
	bhi _0807D542
	mov r0, ip
	str r0, [sp, #0x30]
_0807D57E:
	ldr r0, _0807D628 @ =0x0FFFFFFF
	cmp r5, r0
	bhi _0807D5D0
	movs r1, #0x80
	lsls r1, r1, #0x18
	mov sb, r1
	mov r8, r0
	ldr r2, [sp, #0x30]
	mov ip, r2
_0807D590:
	movs r0, #1
	rsbs r0, r0, #0
	add ip, r0
	lsrs r3, r4, #0x1f
	lsls r2, r5, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #1
	adds r5, r1, #0
	adds r4, r0, #0
	movs r0, #0
	mov r1, sb
	ands r1, r7
	orrs r0, r1
	cmp r0, #0
	beq _0807D5BA
	movs r0, #1
	orrs r0, r4
	adds r1, r5, #0
	adds r5, r1, #0
	adds r4, r0, #0
_0807D5BA:
	lsrs r3, r6, #0x1f
	lsls r2, r7, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r6, #1
	adds r7, r1, #0
	adds r6, r0, #0
	cmp r5, r8
	bls _0807D590
	mov r1, ip
	str r1, [sp, #0x30]
_0807D5D0:
	movs r0, #0xff
	adds r1, r4, #0
	ands r1, r0
	movs r2, #0
	cmp r1, #0x80
	bne _0807D5FE
	cmp r2, #0
	bne _0807D5FE
	adds r0, #1
	adds r1, r4, #0
	ands r1, r0
	adds r0, r2, #0
	orrs r0, r1
	cmp r0, #0
	bne _0807D5F6
	adds r0, r7, #0
	orrs r0, r6
	cmp r0, #0
	beq _0807D5FE
_0807D5F6:
	movs r0, #0x80
	movs r1, #0
	adds r4, r4, r0
	adcs r5, r1
_0807D5FE:
	str r4, [sp, #0x34]
	str r5, [sp, #0x38]
	movs r0, #3
	mov r2, sl
	str r0, [r2]
	add r0, sp, #0x28
_0807D60A:
	bl softfloat_pack_double
	add sp, #0x74
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0807D61C: .4byte 0x00000000
_0807D620: .4byte 0x00000001
_0807D624: .4byte 0x1FFFFFFF
_0807D628: .4byte 0x0FFFFFFF

	thumb_func_start softfloat_divide_double
softfloat_divide_double: @ 0x0807D62C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x48
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	mov ip, sp
	movs r0, #0
	ldr r3, [sp]
	cmp r3, #1
	bhi _0807D656
	movs r0, #1
_0807D656:
	cmp r0, #0
	beq _0807D65E
	mov r1, sp
	b _0807D7A0
_0807D65E:
	movs r0, #0
	ldr r2, [sp, #0x14]
	adds r5, r2, #0
	cmp r2, #1
	bhi _0807D66A
	movs r0, #1
_0807D66A:
	cmp r0, #0
	beq _0807D672
	adds r1, r4, #0
	b _0807D7A0
_0807D672:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x18]
	eors r0, r1
	str r0, [sp, #4]
	movs r0, #0
	cmp r3, #4
	bne _0807D682
	movs r0, #1
_0807D682:
	cmp r0, #0
	bne _0807D692
	movs r4, #0
	cmp r3, #2
	bne _0807D68E
	movs r4, #1
_0807D68E:
	cmp r4, #0
	beq _0807D6A4
_0807D692:
	mov r1, ip
	ldr r0, [r1]
	cmp r0, r5
	beq _0807D69C
	b _0807D7A0
_0807D69C:
	ldr r1, _0807D6A0 @ =0x03000408
	b _0807D7A0
	.align 2, 0
_0807D6A0: .4byte 0x03000408
_0807D6A4:
	movs r0, #0
	cmp r2, #4
	bne _0807D6AC
	movs r0, #1
_0807D6AC:
	cmp r0, #0
	beq _0807D6BE
	movs r0, #0
	movs r1, #0
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r4, [sp, #8]
	mov r1, sp
	b _0807D7A0
_0807D6BE:
	movs r0, #0
	cmp r2, #2
	bne _0807D6C6
	movs r0, #1
_0807D6C6:
	cmp r0, #0
	beq _0807D6D2
	movs r0, #4
	mov r2, ip
	str r0, [r2]
	b _0807D79E
_0807D6D2:
	mov r3, ip
	ldr r1, [r3, #8]
	ldr r0, [sp, #0x1c]
	subs r6, r1, r0
	str r6, [r3, #8]
	ldr r4, [r3, #0xc]
	ldr r5, [r3, #0x10]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	str r0, [sp, #0x38]
	str r1, [sp, #0x3c]
	cmp r1, r5
	bhi _0807D6F6
	ldr r1, [sp, #0x3c]
	cmp r1, r5
	bne _0807D70A
	cmp r0, r4
	bls _0807D70A
_0807D6F6:
	lsrs r3, r4, #0x1f
	lsls r2, r5, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #1
	adds r5, r1, #0
	adds r4, r0, #0
	subs r0, r6, #1
	mov r2, ip
	str r0, [r2, #8]
_0807D70A:
	ldr r7, _0807D7B0 @ =0x10000000
	ldr r6, _0807D7AC @ =0x00000000
	movs r0, #0
	movs r1, #0
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
_0807D716:
	ldr r1, [sp, #0x3c]
	cmp r1, r5
	bhi _0807D73A
	cmp r1, r5
	bne _0807D726
	ldr r2, [sp, #0x38]
	cmp r2, r4
	bhi _0807D73A
_0807D726:
	ldr r0, [sp, #0x40]
	orrs r0, r6
	ldr r1, [sp, #0x44]
	orrs r1, r7
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	subs r4, r4, r0
	sbcs r5, r1
_0807D73A:
	lsls r3, r7, #0x1f
	lsrs r2, r6, #1
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r7, #1
	adds r7, r1, #0
	adds r6, r0, #0
	lsrs r3, r4, #0x1f
	lsls r2, r5, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #1
	adds r5, r1, #0
	adds r4, r0, #0
	adds r0, r7, #0
	orrs r0, r6
	cmp r0, #0
	bne _0807D716
	movs r0, #0xff
	ldr r1, [sp, #0x40]
	ands r1, r0
	movs r2, #0
	cmp r1, #0x80
	bne _0807D794
	cmp r2, #0
	bne _0807D794
	adds r0, #1
	ldr r1, [sp, #0x40]
	ands r1, r0
	adds r0, r2, #0
	orrs r0, r1
	cmp r0, #0
	bne _0807D784
	adds r0, r5, #0
	orrs r0, r4
	cmp r0, #0
	beq _0807D794
_0807D784:
	movs r0, #0x80
	movs r1, #0
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	adds r2, r2, r0
	adcs r3, r1
	str r2, [sp, #0x40]
	str r3, [sp, #0x44]
_0807D794:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	mov r2, ip
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
_0807D79E:
	mov r1, ip
_0807D7A0:
	adds r0, r1, #0
	bl softfloat_pack_double
	add sp, #0x48
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0807D7AC: .4byte 0x00000000
_0807D7B0: .4byte 0x10000000

	thumb_func_start soft_float_compare
soft_float_compare: @ 0x0807D7B4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0
	ldr r1, [r5]
	cmp r1, #1
	bhi _0807D7C4
	movs r0, #1
_0807D7C4:
	cmp r0, #0
	bne _0807D7D6
	movs r0, #0
	ldr r2, [r6]
	cmp r2, #1
	bhi _0807D7D2
	movs r0, #1
_0807D7D2:
	cmp r0, #0
	beq _0807D7DA
_0807D7D6:
	movs r0, #1
	b _0807D8B0
_0807D7DA:
	movs r0, #0
	cmp r1, #4
	bne _0807D7E2
	movs r0, #1
_0807D7E2:
	cmp r0, #0
	beq _0807D7FA
	movs r0, #0
	cmp r2, #4
	bne _0807D7EE
	movs r0, #1
_0807D7EE:
	cmp r0, #0
	beq _0807D7FA
	ldr r0, [r6, #4]
	ldr r1, [r5, #4]
	subs r0, r0, r1
	b _0807D8B0
_0807D7FA:
	movs r1, #0
	ldr r0, [r5]
	cmp r0, #4
	bne _0807D804
	movs r1, #1
_0807D804:
	cmp r1, #0
	bne _0807D852
	movs r1, #0
	cmp r2, #4
	bne _0807D810
	movs r1, #1
_0807D810:
	cmp r1, #0
	beq _0807D822
_0807D814:
	ldr r0, [r6, #4]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _0807D85C
	movs r1, #1
	b _0807D85C
_0807D822:
	movs r1, #0
	cmp r0, #2
	bne _0807D82A
	movs r1, #1
_0807D82A:
	cmp r1, #0
	beq _0807D83A
	movs r1, #0
	cmp r2, #2
	bne _0807D836
	movs r1, #1
_0807D836:
	cmp r1, #0
	bne _0807D8AE
_0807D83A:
	movs r1, #0
	cmp r0, #2
	bne _0807D842
	movs r1, #1
_0807D842:
	cmp r1, #0
	bne _0807D814
	movs r0, #0
	cmp r2, #2
	bne _0807D84E
	movs r0, #1
_0807D84E:
	cmp r0, #0
	beq _0807D860
_0807D852:
	ldr r0, [r5, #4]
	movs r1, #1
	cmp r0, #0
	beq _0807D85C
	subs r1, #2
_0807D85C:
	adds r0, r1, #0
	b _0807D8B0
_0807D860:
	ldr r0, [r6, #4]
	ldr r4, [r5, #4]
	cmp r4, r0
	beq _0807D872
_0807D868:
	movs r0, #1
	cmp r4, #0
	beq _0807D8B0
	subs r0, #2
	b _0807D8B0
_0807D872:
	ldr r1, [r5, #8]
	ldr r0, [r6, #8]
	cmp r1, r0
	bgt _0807D868
	cmp r1, r0
	bge _0807D88A
_0807D87E:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, #0
	beq _0807D8B0
	movs r0, #1
	b _0807D8B0
_0807D88A:
	ldr r3, [r5, #0x10]
	ldr r2, [r6, #0x10]
	cmp r3, r2
	bhi _0807D868
	cmp r3, r2
	bne _0807D89E
	ldr r1, [r5, #0xc]
	ldr r0, [r6, #0xc]
	cmp r1, r0
	bhi _0807D868
_0807D89E:
	cmp r2, r3
	bhi _0807D87E
	cmp r2, r3
	bne _0807D8AE
	ldr r1, [r6, #0xc]
	ldr r0, [r5, #0xc]
	cmp r1, r0
	bhi _0807D87E
_0807D8AE:
	movs r0, #0
_0807D8B0:
	pop {r4, r5, r6, pc}
	.align 2, 0

	thumb_func_start soft_double_compare_wrapper
soft_double_compare_wrapper: @ 0x0807D8B4
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	mov r0, sp
	adds r1, r4, #0
	bl soft_float_compare
	add sp, #0x38
	pop {r4, pc}
	.align 2, 0

	thumb_func_start soft_float_double_compare
soft_float_double_compare: @ 0x0807D8E0
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807D908
	movs r1, #1
_0807D908:
	cmp r1, #0
	bne _0807D91A
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi _0807D916
	movs r1, #1
_0807D916:
	cmp r1, #0
	beq _0807D91E
_0807D91A:
	movs r0, #1
	b _0807D926
_0807D91E:
	mov r0, sp
	adds r1, r4, #0
	bl soft_float_compare
_0807D926:
	add sp, #0x38
	pop {r4, pc}
	.align 2, 0

	thumb_func_start soft_double_compare_unordered_a
soft_double_compare_unordered_a: @ 0x0807D92C
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807D954
	movs r1, #1
_0807D954:
	cmp r1, #0
	bne _0807D966
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi _0807D962
	movs r1, #1
_0807D962:
	cmp r1, #0
	beq _0807D96A
_0807D966:
	movs r0, #1
	b _0807D972
_0807D96A:
	mov r0, sp
	adds r1, r4, #0
	bl soft_float_compare
_0807D972:
	add sp, #0x38
	pop {r4, pc}
	.align 2, 0

	thumb_func_start soft_double_compare_ge
soft_double_compare_ge: @ 0x0807D978
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807D9A0
	movs r1, #1
_0807D9A0:
	cmp r1, #0
	bne _0807D9B2
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi _0807D9AE
	movs r1, #1
_0807D9AE:
	cmp r1, #0
	beq _0807D9B8
_0807D9B2:
	movs r0, #1
	rsbs r0, r0, #0
	b _0807D9C0
_0807D9B8:
	mov r0, sp
	adds r1, r4, #0
	bl soft_float_compare
_0807D9C0:
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start soft_double_compare_gt
soft_double_compare_gt: @ 0x0807D9C4
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807D9EC
	movs r1, #1
_0807D9EC:
	cmp r1, #0
	bne _0807D9FE
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi _0807D9FA
	movs r1, #1
_0807D9FA:
	cmp r1, #0
	beq _0807DA04
_0807D9FE:
	movs r0, #1
	rsbs r0, r0, #0
	b _0807DA0C
_0807DA04:
	mov r0, sp
	adds r1, r4, #0
	bl soft_float_compare
_0807DA0C:
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start soft_double_compare_unordered_b
soft_double_compare_unordered_b: @ 0x0807DA10
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807DA38
	movs r1, #1
_0807DA38:
	cmp r1, #0
	bne _0807DA4A
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi _0807DA46
	movs r1, #1
_0807DA46:
	cmp r1, #0
	beq _0807DA4E
_0807DA4A:
	movs r0, #1
	b _0807DA56
_0807DA4E:
	mov r0, sp
	adds r1, r4, #0
	bl soft_float_compare
_0807DA56:
	add sp, #0x38
	pop {r4, pc}
	.align 2, 0

	thumb_func_start soft_double_compare_unordered_c
soft_double_compare_unordered_c: @ 0x0807DA5C
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl double_decompose
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl double_decompose
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807DA84
	movs r1, #1
_0807DA84:
	cmp r1, #0
	bne _0807DA96
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi _0807DA92
	movs r1, #1
_0807DA92:
	cmp r1, #0
	beq _0807DA9A
_0807DA96:
	movs r0, #1
	b _0807DAA2
_0807DA9A:
	mov r0, sp
	adds r1, r4, #0
	bl soft_float_compare
_0807DAA2:
	add sp, #0x38
	pop {r4, pc}
	.align 2, 0

	thumb_func_start softfloat_int_to_double
	.global softfloat_int_to_double
softfloat_int_to_double: @ 0x0807DAA8
	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, r0, #0
	movs r0, #3
	str r0, [sp]
	lsrs r1, r2, #0x1f
	str r1, [sp, #4]
	cmp r2, #0
	bne _0807DAC0
	movs r0, #2
	str r0, [sp]
	b _0807DB16
_0807DAC0:
	movs r0, #0x3c
	str r0, [sp, #8]
	cmp r1, #0
	beq _0807DAE6
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r2, r0
	bne _0807DAE0
	ldr r1, _0807DADC @ =0x00000000
	ldr r0, _0807DAD8 @ =0xC1E00000
	b _0807DB1C
	.align 2, 0
_0807DAD8: .4byte 0xC1E00000
_0807DADC: .4byte 0x00000000
_0807DAE0:
	rsbs r0, r2, #0
	asrs r1, r0, #0x1f
	b _0807DAEA
_0807DAE6:
	adds r0, r2, #0
	asrs r1, r2, #0x1f
_0807DAEA:
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x10]
	ldr r1, _0807DB20 @ =0x0FFFFFFF
	cmp r0, r1
	bhi _0807DB16
	adds r5, r1, #0
	ldr r4, [sp, #8]
_0807DAFA:
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	lsrs r3, r0, #0x1f
	lsls r2, r1, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r0, #1
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	subs r4, #1
	ldr r0, [sp, #0x10]
	cmp r0, r5
	bls _0807DAFA
	str r4, [sp, #8]
_0807DB16:
	mov r0, sp
	bl softfloat_pack_double
_0807DB1C:
	add sp, #0x14
	pop {r4, r5, pc}
	.align 2, 0
_0807DB20: .4byte 0x0FFFFFFF

	thumb_func_start double_to_int
	.global double_to_int
double_to_int: @ 0x0807DB24
	push {lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl double_decompose
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #2
	bne _0807DB3E
	movs r1, #1
_0807DB3E:
	cmp r1, #0
	bne _0807DB72
	movs r1, #0
	cmp r0, #1
	bhi _0807DB4A
	movs r1, #1
_0807DB4A:
	cmp r1, #0
	bne _0807DB72
	movs r1, #0
	cmp r0, #4
	bne _0807DB56
	movs r1, #1
_0807DB56:
	cmp r1, #0
	beq _0807DB6C
_0807DB5A:
	ldr r0, [sp, #4]
	ldr r1, _0807DB68 @ =0x7FFFFFFF
	cmp r0, #0
	beq _0807DB90
	adds r1, #1
	b _0807DB90
	.align 2, 0
_0807DB68: .4byte 0x7FFFFFFF
_0807DB6C:
	ldr r0, [sp, #8]
	cmp r0, #0
	bge _0807DB76
_0807DB72:
	movs r0, #0
	b _0807DB92
_0807DB76:
	cmp r0, #0x1e
	bgt _0807DB5A
	movs r2, #0x3c
	subs r2, r2, r0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	bl lsr64
	adds r1, r0, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _0807DB90
	rsbs r1, r1, #0
_0807DB90:
	adds r0, r1, #0
_0807DB92:
	add sp, #0x1c
	pop {pc}
	.align 2, 0

	thumb_func_start double_is_zero_to_float
double_is_zero_to_float: @ 0x0807DB98
	push {lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl double_decompose
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0807DBB2
	movs r1, #1
_0807DBB2:
	str r1, [sp, #4]
	mov r0, sp
	bl softfloat_pack_double
	add sp, #0x1c
	pop {pc}
	.align 2, 0

	thumb_func_start sub_0807DBC0
sub_0807DBC0: @ 0x0807DBC0
	sub sp, #4
	push {r4, lr}
	sub sp, #0x14
	str r3, [sp, #0x1c]
	ldr r3, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	str r4, [sp, #0x10]
	mov r0, sp
	bl softfloat_pack_double
	add sp, #0x14
	pop {r4}
	pop {r3}
	add sp, #4
	bx r3
	.align 2, 0

	thumb_func_start softfloat_double_round
	.global softfloat_double_round
softfloat_double_round: @ 0x0807DBE8
	push {r4, r5, lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl double_decompose
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	lsls r5, r3, #2
	lsrs r4, r2, #0x1e
	adds r0, r5, #0
	orrs r0, r4
	adds r5, r0, #0
	ldr r4, _0807DC28 @ =0x3FFFFFFF
	adds r0, r2, #0
	ands r0, r4
	movs r1, #0
	orrs r0, r1
	cmp r0, #0
	beq _0807DC18
	movs r0, #1
	orrs r5, r0
_0807DC18:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	adds r3, r5, #0
	bl softfloat_pack_from_params
	add sp, #0x1c
	pop {r4, r5, pc}
	.align 2, 0
_0807DC28: .4byte 0x3FFFFFFF

	thumb_func_start softfloat_pack_ieee754
softfloat_pack_ieee754: @ 0x0807DC2C
	push {r4, r5, r6, lr}
	ldr r2, [r0, #0xc]
	ldr r6, [r0, #4]
	movs r5, #0
	movs r1, #0
	ldr r3, [r0]
	cmp r3, #1
	bhi _0807DC3E
	movs r1, #1
_0807DC3E:
	cmp r1, #0
	beq _0807DC4C
	movs r5, #0xff
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r2, r0
	b _0807DCB2
_0807DC4C:
	movs r1, #0
	cmp r3, #4
	bne _0807DC54
	movs r1, #1
_0807DC54:
	cmp r1, #0
	bne _0807DC88
	movs r1, #0
	cmp r3, #2
	bne _0807DC60
	movs r1, #1
_0807DC60:
	cmp r1, #0
	beq _0807DC68
	movs r2, #0
	b _0807DCB2
_0807DC68:
	cmp r2, #0
	beq _0807DCB2
	ldr r0, [r0, #8]
	movs r3, #0x7e
	rsbs r3, r3, #0
	cmp r0, r3
	bge _0807DC84
	subs r0, r3, r0
	cmp r0, #0x19
	ble _0807DC80
	movs r2, #0
	b _0807DCB0
_0807DC80:
	lsrs r2, r0
	b _0807DCB0
_0807DC84:
	cmp r0, #0x7f
	ble _0807DC8E
_0807DC88:
	movs r5, #0xff
	movs r2, #0
	b _0807DCB2
_0807DC8E:
	adds r5, r0, #0
	adds r5, #0x7f
	movs r0, #0x7f
	ands r0, r2
	cmp r0, #0x40
	bne _0807DCA6
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _0807DCA8
	adds r2, #0x40
	b _0807DCA8
_0807DCA6:
	adds r2, #0x3f
_0807DCA8:
	cmp r2, #0
	bge _0807DCB0
	lsrs r2, r2, #1
	adds r5, #1
_0807DCB0:
	lsrs r2, r2, #7
_0807DCB2:
	ldr r0, _0807DCD4 @ =0x007FFFFF
	ands r2, r0
	ldr r0, _0807DCD8 @ =0xFF800000
	ands r4, r0
	orrs r4, r2
	movs r0, #0xff
	ands r5, r0
	lsls r1, r5, #0x17
	ldr r0, _0807DCDC @ =0x807FFFFF
	ands r4, r0
	orrs r4, r1
	lsls r1, r6, #0x1f
	ldr r0, _0807DCE0 @ =0x7FFFFFFF
	ands r4, r0
	orrs r4, r1
	adds r0, r4, #0
	pop {r4, r5, r6, pc}
	.align 2, 0
_0807DCD4: .4byte 0x007FFFFF
_0807DCD8: .4byte 0xFF800000
_0807DCDC: .4byte 0x807FFFFF
_0807DCE0: .4byte 0x7FFFFFFF

	thumb_func_start float_decompose_ieee754
float_decompose_ieee754: @ 0x0807DCE4
	push {r4, lr}
	adds r3, r1, #0
	ldr r0, [r0]
	lsls r1, r0, #9
	lsrs r2, r1, #9
	lsls r1, r0, #1
	lsrs r1, r1, #0x18
	lsrs r0, r0, #0x1f
	str r0, [r3, #4]
	cmp r1, #0
	bne _0807DD28
	cmp r2, #0
	bne _0807DD04
	movs r0, #2
	str r0, [r3]
	b _0807DD5C
_0807DD04:
	adds r4, r1, #0
	subs r4, #0x7e
	str r4, [r3, #8]
	lsls r2, r2, #7
	movs r0, #3
	str r0, [r3]
	ldr r1, _0807DD24 @ =0x3FFFFFFF
	cmp r2, r1
	bhi _0807DD44
	adds r0, r4, #0
_0807DD18:
	lsls r2, r2, #1
	subs r0, #1
	cmp r2, r1
	bls _0807DD18
	str r0, [r3, #8]
	b _0807DD44
	.align 2, 0
_0807DD24: .4byte 0x3FFFFFFF
_0807DD28:
	cmp r1, #0xff
	bne _0807DD48
	cmp r2, #0
	bne _0807DD36
	movs r0, #4
	str r0, [r3]
	b _0807DD5C
_0807DD36:
	movs r0, #0x80
	lsls r0, r0, #0xd
	ands r0, r2
	cmp r0, #0
	beq _0807DD42
	movs r0, #1
_0807DD42:
	str r0, [r3]
_0807DD44:
	str r2, [r3, #0xc]
	b _0807DD5C
_0807DD48:
	adds r0, r1, #0
	subs r0, #0x7f
	str r0, [r3, #8]
	movs r0, #3
	str r0, [r3]
	lsls r0, r2, #7
	movs r1, #0x80
	lsls r1, r1, #0x17
	orrs r0, r1
	str r0, [r3, #0xc]
_0807DD5C:
	pop {r4, pc}
	.align 2, 0

	thumb_func_start softfloat_add_0807DD60
softfloat_add_0807DD60: @ 0x0807DD60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r0, #0
	ldr r2, [r6]
	cmp r2, #1
	bhi _0807DD76
	movs r0, #1
_0807DD76:
	cmp r0, #0
	beq _0807DD7E
_0807DD7A:
	adds r0, r6, #0
	b _0807DED4
_0807DD7E:
	movs r1, #0
	ldr r0, [r7]
	cmp r0, #1
	bhi _0807DD88
	movs r1, #1
_0807DD88:
	cmp r1, #0
	bne _0807DDFC
	movs r1, #0
	cmp r2, #4
	bne _0807DD94
	movs r1, #1
_0807DD94:
	cmp r1, #0
	beq _0807DDB4
	movs r1, #0
	cmp r0, #4
	bne _0807DDA0
	movs r1, #1
_0807DDA0:
	cmp r1, #0
	beq _0807DD7A
	ldr r1, [r6, #4]
	ldr r0, [r7, #4]
	cmp r1, r0
	beq _0807DD7A
	ldr r0, _0807DDB0 @ =0x03000420
	b _0807DED4
	.align 2, 0
_0807DDB0: .4byte 0x03000420
_0807DDB4:
	movs r1, #0
	cmp r0, #4
	bne _0807DDBC
	movs r1, #1
_0807DDBC:
	cmp r1, #0
	bne _0807DDFC
	movs r1, #0
	cmp r0, #2
	bne _0807DDC8
	movs r1, #1
_0807DDC8:
	cmp r1, #0
	beq _0807DDEE
	movs r0, #0
	cmp r2, #2
	bne _0807DDD4
	movs r0, #1
_0807DDD4:
	cmp r0, #0
	beq _0807DD7A
	adds r1, r5, #0
	adds r0, r6, #0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r6, #4]
	ldr r1, [r7, #4]
	ands r0, r1
	str r0, [r5, #4]
	b _0807DED2
_0807DDEE:
	movs r1, #0
	ldr r0, [r6]
	cmp r0, #2
	bne _0807DDF8
	movs r1, #1
_0807DDF8:
	cmp r1, #0
	beq _0807DE00
_0807DDFC:
	adds r0, r7, #0
	b _0807DED4
_0807DE00:
	ldr r1, [r6, #8]
	ldr r3, [r7, #8]
	ldr r2, [r6, #0xc]
	ldr r4, [r7, #0xc]
	subs r0, r1, r3
	cmp r0, #0
	bge _0807DE10
	rsbs r0, r0, #0
_0807DE10:
	cmp r0, #0x1f
	bgt _0807DE54
	ldr r6, [r6, #4]
	ldr r7, [r7, #4]
	mov r8, r7
	cmp r1, r3
	ble _0807DE36
	movs r7, #1
	mov ip, r7
	subs r3, r1, r3
_0807DE24:
	subs r3, #1
	adds r0, r4, #0
	mov r7, ip
	ands r0, r7
	lsrs r4, r4, #1
	orrs r4, r0
	cmp r3, #0
	bne _0807DE24
	adds r3, r1, #0
_0807DE36:
	cmp r3, r1
	ble _0807DE66
	movs r0, #1
	mov ip, r0
	subs r1, r3, r1
_0807DE40:
	subs r1, #1
	adds r0, r2, #0
	mov r7, ip
	ands r0, r7
	lsrs r2, r2, #1
	orrs r2, r0
	cmp r1, #0
	bne _0807DE40
	adds r1, r3, #0
	b _0807DE66
_0807DE54:
	cmp r1, r3
	ble _0807DE5C
	movs r4, #0
	b _0807DE60
_0807DE5C:
	adds r1, r3, #0
	movs r2, #0
_0807DE60:
	ldr r6, [r6, #4]
	ldr r7, [r7, #4]
	mov r8, r7
_0807DE66:
	cmp r6, r8
	beq _0807DEB0
	cmp r6, #0
	beq _0807DE72
	subs r3, r4, r2
	b _0807DE74
_0807DE72:
	subs r3, r2, r4
_0807DE74:
	cmp r3, #0
	blt _0807DE82
	movs r0, #0
	str r0, [r5, #4]
	str r1, [r5, #8]
	str r3, [r5, #0xc]
	b _0807DE8C
_0807DE82:
	movs r0, #1
	str r0, [r5, #4]
	str r1, [r5, #8]
	rsbs r0, r3, #0
	str r0, [r5, #0xc]
_0807DE8C:
	ldr r1, [r5, #0xc]
	subs r0, r1, #1
	ldr r2, _0807DEAC @ =0x3FFFFFFE
	cmp r0, r2
	bhi _0807DEB8
_0807DE96:
	lsls r0, r1, #1
	str r0, [r5, #0xc]
	ldr r1, [r5, #8]
	subs r1, #1
	str r1, [r5, #8]
	adds r1, r0, #0
	subs r0, r1, #1
	cmp r0, r2
	bls _0807DE96
	b _0807DEB8
	.align 2, 0
_0807DEAC: .4byte 0x3FFFFFFE
_0807DEB0:
	str r6, [r5, #4]
	str r1, [r5, #8]
	adds r0, r2, r4
	str r0, [r5, #0xc]
_0807DEB8:
	movs r0, #3
	str r0, [r5]
	ldr r1, [r5, #0xc]
	cmp r1, #0
	bge _0807DED2
	movs r0, #1
	ands r0, r1
	lsrs r1, r1, #1
	orrs r0, r1
	str r0, [r5, #0xc]
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
_0807DED2:
	adds r0, r5, #0
_0807DED4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0

	thumb_func_start softfloat_add_f32
	.global softfloat_add_f32
softfloat_add_f32: @ 0x0807DEDC
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	add r2, sp, #0x20
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_add_0807DD60
	bl softfloat_pack_ieee754
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start softfloat_subtract
	.global softfloat_subtract
softfloat_subtract: @ 0x0807DF08
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	ldr r0, [r4, #4]
	movs r1, #1
	eors r0, r1
	str r0, [r4, #4]
	add r2, sp, #0x20
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_add_0807DD60
	bl softfloat_pack_ieee754
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start softfloat_multiply
	.global softfloat_multiply
softfloat_multiply: @ 0x0807DF3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	mov r7, sp
	add r0, sp, #0x20
	mov r8, r0
	movs r0, #0
	ldr r1, [sp]
	mov sb, r8
	cmp r1, #1
	bhi _0807DF6E
	movs r0, #1
_0807DF6E:
	cmp r0, #0
	bne _0807DFCC
	movs r2, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi _0807DF7C
	movs r2, #1
_0807DF7C:
	cmp r2, #0
	beq _0807DF84
	ldr r0, [sp, #4]
	b _0807DFEC
_0807DF84:
	movs r2, #0
	cmp r1, #4
	bne _0807DF8C
	movs r2, #1
_0807DF8C:
	cmp r2, #0
	beq _0807DF9E
	movs r1, #0
	cmp r0, #2
	bne _0807DF98
	movs r1, #1
_0807DF98:
	cmp r1, #0
	bne _0807DFB6
	b _0807DFCC
_0807DF9E:
	movs r2, #0
	cmp r0, #4
	bne _0807DFA6
	movs r2, #1
_0807DFA6:
	cmp r2, #0
	beq _0807DFC0
	movs r0, #0
	cmp r1, #2
	bne _0807DFB2
	movs r0, #1
_0807DFB2:
	cmp r0, #0
	beq _0807DFEA
_0807DFB6:
	ldr r0, _0807DFBC @ =0x03000420
	b _0807E08E
	.align 2, 0
_0807DFBC: .4byte 0x03000420
_0807DFC0:
	movs r2, #0
	cmp r1, #2
	bne _0807DFC8
	movs r2, #1
_0807DFC8:
	cmp r2, #0
	beq _0807DFDE
_0807DFCC:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x14]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	str r1, [sp, #4]
	mov r0, sp
	b _0807E08E
_0807DFDE:
	movs r1, #0
	cmp r0, #2
	bne _0807DFE6
	movs r1, #1
_0807DFE6:
	cmp r1, #0
	beq _0807DFFC
_0807DFEA:
	ldr r0, [r7, #4]
_0807DFEC:
	ldr r1, [sp, #0x14]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	str r1, [sp, #0x14]
	adds r0, r4, #0
	b _0807E08E
_0807DFFC:
	ldr r0, [r7, #0xc]
	movs r1, #0
	ldr r2, [sp, #0x1c]
	movs r3, #0
	bl umul64
	adds r2, r1, #0
	adds r5, r2, #0
	adds r6, r0, #0
	ldr r4, [r7, #8]
	ldr r0, [sp, #0x18]
	adds r4, r4, r0
	str r4, [sp, #0x28]
	ldr r1, [r7, #4]
	ldr r0, [sp, #0x14]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	str r0, [sp, #0x24]
	adds r4, #2
	str r4, [sp, #0x28]
	cmp r2, #0
	bge _0807E048
	movs r2, #1
	movs r1, #0x80
	lsls r1, r1, #0x18
_0807E032:
	adds r4, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0807E040
	lsrs r6, r6, #1
	orrs r6, r1
_0807E040:
	lsrs r5, r5, #1
	cmp r5, #0
	blt _0807E032
	str r4, [sp, #0x28]
_0807E048:
	ldr r0, _0807E09C @ =0x3FFFFFFF
	cmp r5, r0
	bhi _0807E06E
	movs r4, #0x80
	lsls r4, r4, #0x18
	movs r3, #1
	adds r2, r0, #0
	ldr r1, [sp, #0x28]
_0807E058:
	subs r1, #1
	lsls r5, r5, #1
	adds r0, r6, #0
	ands r0, r4
	cmp r0, #0
	beq _0807E066
	orrs r5, r3
_0807E066:
	lsls r6, r6, #1
	cmp r5, r2
	bls _0807E058
	str r1, [sp, #0x28]
_0807E06E:
	movs r0, #0x7f
	ands r0, r5
	cmp r0, #0x40
	bne _0807E084
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	bne _0807E082
	cmp r6, #0
	beq _0807E084
_0807E082:
	adds r5, #0x40
_0807E084:
	str r5, [sp, #0x2c]
	movs r0, #3
	mov r1, r8
	str r0, [r1]
	mov r0, sb
_0807E08E:
	bl softfloat_pack_ieee754
	add sp, #0x38
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0807E09C: .4byte 0x3FFFFFFF

	thumb_func_start softfloat_divide
	.global softfloat_divide
softfloat_divide: @ 0x0807E0A0
	push {r4, r5, r6, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x24
	add r5, sp, #0x10
	adds r1, r5, #0
	bl float_decompose_ieee754
	mov r4, sp
	movs r0, #0
	ldr r3, [sp]
	cmp r3, #1
	bhi _0807E0C6
	movs r0, #1
_0807E0C6:
	cmp r0, #0
	beq _0807E0CE
	mov r1, sp
	b _0807E180
_0807E0CE:
	movs r0, #0
	ldr r2, [sp, #0x10]
	adds r6, r2, #0
	cmp r2, #1
	bhi _0807E0DA
	movs r0, #1
_0807E0DA:
	cmp r0, #0
	beq _0807E0E2
	adds r1, r5, #0
	b _0807E180
_0807E0E2:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x14]
	eors r0, r1
	str r0, [sp, #4]
	movs r0, #0
	cmp r3, #4
	bne _0807E0F2
	movs r0, #1
_0807E0F2:
	cmp r0, #0
	bne _0807E102
	movs r0, #0
	cmp r3, #2
	bne _0807E0FE
	movs r0, #1
_0807E0FE:
	cmp r0, #0
	beq _0807E114
_0807E102:
	ldr r0, [r4]
	adds r1, r4, #0
	cmp r0, r6
	bne _0807E180
	ldr r1, _0807E110 @ =0x03000420
	b _0807E180
	.align 2, 0
_0807E110: .4byte 0x03000420
_0807E114:
	movs r1, #0
	cmp r2, #4
	bne _0807E11C
	movs r1, #1
_0807E11C:
	cmp r1, #0
	beq _0807E128
	str r0, [sp, #0xc]
	str r0, [sp, #8]
	mov r1, sp
	b _0807E180
_0807E128:
	movs r0, #0
	cmp r2, #2
	bne _0807E130
	movs r0, #1
_0807E130:
	cmp r0, #0
	beq _0807E13A
	movs r0, #4
	str r0, [r4]
	b _0807E17E
_0807E13A:
	ldr r1, [r4, #8]
	ldr r0, [sp, #0x18]
	subs r0, r1, r0
	str r0, [r4, #8]
	ldr r2, [r4, #0xc]
	ldr r3, [sp, #0x1c]
	cmp r2, r3
	bhs _0807E150
	lsls r2, r2, #1
	subs r0, #1
	str r0, [r4, #8]
_0807E150:
	movs r0, #0x80
	lsls r0, r0, #0x17
	movs r1, #0
_0807E156:
	cmp r2, r3
	blo _0807E15E
	orrs r1, r0
	subs r2, r2, r3
_0807E15E:
	lsrs r0, r0, #1
	lsls r2, r2, #1
	cmp r0, #0
	bne _0807E156
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x40
	bne _0807E17C
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807E17A
	cmp r2, #0
	beq _0807E17C
_0807E17A:
	adds r1, #0x40
_0807E17C:
	str r1, [r4, #0xc]
_0807E17E:
	adds r1, r4, #0
_0807E180:
	adds r0, r1, #0
	bl softfloat_pack_ieee754
	add sp, #0x28
	pop {r4, r5, r6, pc}
	.align 2, 0

	thumb_func_start softfloat_compare
softfloat_compare: @ 0x0807E18C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	ldr r2, [r4]
	cmp r2, #1
	bhi _0807E19A
	movs r0, #1
_0807E19A:
	cmp r0, #0
	bne _0807E1AC
	movs r0, #0
	ldr r3, [r1]
	cmp r3, #1
	bhi _0807E1A8
	movs r0, #1
_0807E1A8:
	cmp r0, #0
	beq _0807E1B0
_0807E1AC:
	movs r0, #1
	b _0807E26E
_0807E1B0:
	movs r0, #0
	cmp r2, #4
	bne _0807E1B8
	movs r0, #1
_0807E1B8:
	cmp r0, #0
	beq _0807E1D0
	movs r0, #0
	cmp r3, #4
	bne _0807E1C4
	movs r0, #1
_0807E1C4:
	cmp r0, #0
	beq _0807E1D0
	ldr r0, [r1, #4]
	ldr r1, [r4, #4]
	subs r0, r0, r1
	b _0807E26E
_0807E1D0:
	movs r2, #0
	ldr r0, [r4]
	cmp r0, #4
	bne _0807E1DA
	movs r2, #1
_0807E1DA:
	cmp r2, #0
	bne _0807E228
	movs r2, #0
	cmp r3, #4
	bne _0807E1E6
	movs r2, #1
_0807E1E6:
	cmp r2, #0
	beq _0807E1F8
_0807E1EA:
	ldr r0, [r1, #4]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _0807E232
	movs r1, #1
	b _0807E232
_0807E1F8:
	movs r2, #0
	cmp r0, #2
	bne _0807E200
	movs r2, #1
_0807E200:
	cmp r2, #0
	beq _0807E210
	movs r2, #0
	cmp r3, #2
	bne _0807E20C
	movs r2, #1
_0807E20C:
	cmp r2, #0
	bne _0807E26C
_0807E210:
	movs r2, #0
	cmp r0, #2
	bne _0807E218
	movs r2, #1
_0807E218:
	cmp r2, #0
	bne _0807E1EA
	movs r0, #0
	cmp r3, #2
	bne _0807E224
	movs r0, #1
_0807E224:
	cmp r0, #0
	beq _0807E236
_0807E228:
	ldr r0, [r4, #4]
	movs r1, #1
	cmp r0, #0
	beq _0807E232
	subs r1, #2
_0807E232:
	adds r0, r1, #0
	b _0807E26E
_0807E236:
	ldr r3, [r4, #4]
	ldr r0, [r1, #4]
	cmp r3, r0
	beq _0807E248
_0807E23E:
	movs r0, #1
	cmp r3, #0
	beq _0807E26E
	subs r0, #2
	b _0807E26E
_0807E248:
	ldr r2, [r4, #8]
	ldr r0, [r1, #8]
	cmp r2, r0
	bgt _0807E23E
	cmp r2, r0
	bge _0807E260
_0807E254:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, #0
	beq _0807E26E
	movs r0, #1
	b _0807E26E
_0807E260:
	ldr r0, [r4, #0xc]
	ldr r1, [r1, #0xc]
	cmp r0, r1
	bhi _0807E23E
	cmp r0, r1
	blo _0807E254
_0807E26C:
	movs r0, #0
_0807E26E:
	pop {r4, pc}

	thumb_func_start softfloat_compare_wrapper
softfloat_compare_wrapper: @ 0x0807E270
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_compare
	add sp, #0x28
	pop {r4, pc}
	.align 2, 0

	thumb_func_start soft_float_eq
	.global soft_float_eq
soft_float_eq: @ 0x0807E298
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807E2BC
	movs r1, #1
_0807E2BC:
	cmp r1, #0
	bne _0807E2CE
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi _0807E2CA
	movs r1, #1
_0807E2CA:
	cmp r1, #0
	beq _0807E2D2
_0807E2CE:
	movs r0, #1
	b _0807E2DA
_0807E2D2:
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_compare
_0807E2DA:
	add sp, #0x28
	pop {r4, pc}
	.align 2, 0

	thumb_func_start soft_float_le
soft_float_le: @ 0x0807E2E0
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807E304
	movs r1, #1
_0807E304:
	cmp r1, #0
	bne _0807E316
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi _0807E312
	movs r1, #1
_0807E312:
	cmp r1, #0
	beq _0807E31A
_0807E316:
	movs r0, #1
	b _0807E322
_0807E31A:
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_compare
_0807E322:
	add sp, #0x28
	pop {r4, pc}
	.align 2, 0

	thumb_func_start softfloat_compare_eq
	.global softfloat_compare_eq
softfloat_compare_eq: @ 0x0807E328
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807E34C
	movs r1, #1
_0807E34C:
	cmp r1, #0
	bne _0807E35E
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi _0807E35A
	movs r1, #1
_0807E35A:
	cmp r1, #0
	beq _0807E364
_0807E35E:
	movs r0, #1
	rsbs r0, r0, #0
	b _0807E36C
_0807E364:
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_compare
_0807E36C:
	add sp, #0x28
	pop {r4, pc}

	thumb_func_start softfloat_compare_ge
	.global softfloat_compare_ge
softfloat_compare_ge: @ 0x0807E370
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807E394
	movs r1, #1
_0807E394:
	cmp r1, #0
	bne _0807E3A6
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi _0807E3A2
	movs r1, #1
_0807E3A2:
	cmp r1, #0
	beq _0807E3AC
_0807E3A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _0807E3B4
_0807E3AC:
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_compare
_0807E3B4:
	add sp, #0x28
	pop {r4, pc}

	thumb_func_start soft_float_ge
	.global soft_float_ge
soft_float_ge: @ 0x0807E3B8
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807E3DC
	movs r1, #1
_0807E3DC:
	cmp r1, #0
	bne _0807E3EE
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi _0807E3EA
	movs r1, #1
_0807E3EA:
	cmp r1, #0
	beq _0807E3F2
_0807E3EE:
	movs r0, #1
	b _0807E3FA
_0807E3F2:
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_compare
_0807E3FA:
	add sp, #0x28
	pop {r4, pc}
	.align 2, 0

	thumb_func_start soft_float_gt
	.global soft_float_gt
soft_float_gt: @ 0x0807E400
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl float_decompose_ieee754
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl float_decompose_ieee754
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi _0807E424
	movs r1, #1
_0807E424:
	cmp r1, #0
	bne _0807E436
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi _0807E432
	movs r1, #1
_0807E432:
	cmp r1, #0
	beq _0807E43A
_0807E436:
	movs r0, #1
	b _0807E442
_0807E43A:
	mov r0, sp
	adds r1, r4, #0
	bl softfloat_compare
_0807E442:
	add sp, #0x28
	pop {r4, pc}
	.align 2, 0

	thumb_func_start int_to_softfloat
	.global int_to_softfloat
int_to_softfloat: @ 0x0807E448
	push {lr}
	sub sp, #0x10
	adds r1, r0, #0
	movs r0, #3
	str r0, [sp]
	lsrs r2, r1, #0x1f
	str r2, [sp, #4]
	cmp r1, #0
	bne _0807E460
	movs r0, #2
	str r0, [sp]
	b _0807E498
_0807E460:
	movs r0, #0x1e
	str r0, [sp, #8]
	cmp r2, #0
	beq _0807E47E
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	bne _0807E478
	ldr r0, _0807E474 @ =0xCF000000
	b _0807E49E
	.align 2, 0
_0807E474: .4byte 0xCF000000
_0807E478:
	rsbs r0, r1, #0
	str r0, [sp, #0xc]
	b _0807E480
_0807E47E:
	str r1, [sp, #0xc]
_0807E480:
	ldr r2, [sp, #0xc]
	ldr r3, _0807E4A4 @ =0x3FFFFFFF
	cmp r2, r3
	bhi _0807E498
	ldr r1, [sp, #8]
_0807E48A:
	lsls r0, r2, #1
	subs r1, #1
	adds r2, r0, #0
	cmp r0, r3
	bls _0807E48A
	str r1, [sp, #8]
	str r0, [sp, #0xc]
_0807E498:
	mov r0, sp
	bl softfloat_pack_ieee754
_0807E49E:
	add sp, #0x10
	pop {pc}
	.align 2, 0
_0807E4A4: .4byte 0x3FFFFFFF

	thumb_func_start float_to_int
	.global float_to_int
float_to_int: @ 0x0807E4A8
	push {lr}
	sub sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, sp
	bl float_decompose_ieee754
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #2
	bne _0807E4C0
	movs r1, #1
_0807E4C0:
	cmp r1, #0
	bne _0807E4F2
	movs r1, #0
	cmp r0, #1
	bhi _0807E4CC
	movs r1, #1
_0807E4CC:
	cmp r1, #0
	bne _0807E4F2
	movs r1, #0
	cmp r0, #4
	bne _0807E4D8
	movs r1, #1
_0807E4D8:
	cmp r1, #0
	beq _0807E4EC
_0807E4DC:
	ldr r0, [sp, #4]
	ldr r1, _0807E4E8 @ =0x7FFFFFFF
	cmp r0, #0
	beq _0807E50A
	adds r1, #1
	b _0807E50A
	.align 2, 0
_0807E4E8: .4byte 0x7FFFFFFF
_0807E4EC:
	ldr r1, [sp, #8]
	cmp r1, #0
	bge _0807E4F6
_0807E4F2:
	movs r0, #0
	b _0807E50C
_0807E4F6:
	cmp r1, #0x1e
	bgt _0807E4DC
	movs r0, #0x1e
	subs r0, r0, r1
	ldr r1, [sp, #0xc]
	lsrs r1, r0
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _0807E50A
	rsbs r1, r1, #0
_0807E50A:
	adds r0, r1, #0
_0807E50C:
	add sp, #0x14
	pop {pc}

	thumb_func_start float_is_zero
	.global float_is_zero
float_is_zero: @ 0x0807E510
	push {lr}
	sub sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, sp
	bl float_decompose_ieee754
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0807E528
	movs r1, #1
_0807E528:
	str r1, [sp, #4]
	mov r0, sp
	bl softfloat_pack_ieee754
	add sp, #0x14
	pop {pc}

	thumb_func_start softfloat_pack_from_params
softfloat_pack_from_params: @ 0x0807E534
	push {lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	mov r0, sp
	bl softfloat_pack_ieee754
	add sp, #0x10
	pop {pc}
	.align 2, 0

	thumb_func_start float_to_double
	.global float_to_double
float_to_double: @ 0x0807E54C
	push {r4, r5, r6, lr}
	sub sp, #0x18
	str r0, [sp, #0x14]
	add r0, sp, #0x14
	add r1, sp, #4
	bl float_decompose_ieee754
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	movs r4, #0
	lsrs r6, r3, #2
	lsls r5, r4, #0x1e
	adds r4, r6, #0
	orrs r4, r5
	lsls r3, r3, #0x1e
	str r4, [sp]
	bl sub_0807DBC0
	add sp, #0x18
	pop {r4, r5, r6, pc}

	thumb_func_start lsr64
lsr64: @ 0x0807E578
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r5, r0, #0
	cmp r2, #0
	beq _0807E5A8
	movs r0, #0x20
	subs r0, r0, r2
	cmp r0, #0
	bgt _0807E594
	movs r4, #0
	rsbs r0, r0, #0
	adds r3, r6, #0
	lsrs r3, r0
	b _0807E5A4
_0807E594:
	adds r1, r6, #0
	lsls r1, r0
	adds r4, r6, #0
	lsrs r4, r2
	adds r0, r5, #0
	lsrs r0, r2
	adds r3, r0, #0
	orrs r3, r1
_0807E5A4:
	adds r1, r4, #0
	adds r0, r3, #0
_0807E5A8:
	pop {r4, r5, r6, pc}
	.align 2, 0

	thumb_func_start umul64
umul64: @ 0x0807E5AC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r3, [sp]
	ldr r0, _0807E618 @ =0x0000FFFF
	mov ip, r0
	adds r2, r3, #0
	ands r2, r0
	lsrs r3, r3, #0x10
	ldr r1, [sp, #8]
	adds r0, r1, #0
	mov r4, ip
	ands r0, r4
	lsrs r1, r1, #0x10
	adds r5, r2, #0
	muls r5, r0, r5
	adds r4, r2, #0
	muls r4, r1, r4
	adds r2, r3, #0
	muls r2, r0, r2
	muls r3, r1, r3
	lsrs r0, r5, #0x10
	adds r4, r4, r0
	adds r4, r4, r2
	cmp r4, r2
	bhs _0807E5EC
	movs r0, #0x80
	lsls r0, r0, #9
	adds r3, r3, r0
_0807E5EC:
	lsrs r0, r4, #0x10
	adds r7, r3, r0
	mov r1, ip
	ands r4, r1
	lsls r0, r4, #0x10
	ands r5, r1
	adds r6, r0, #0
	orrs r6, r5
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r3, [sp]
	ldr r4, [sp, #0xc]
	adds r2, r3, #0
	muls r2, r4, r2
	ldr r5, [sp, #4]
	ldr r4, [sp, #8]
	adds r3, r5, #0
	muls r3, r4, r3
	adds r2, r2, r3
	adds r1, r7, r2
	add sp, #0x10
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0807E618: .4byte 0x0000FFFF

	thumb_func_start negate_64bit
negate_64bit: @ 0x0807E61C
	push {r4, lr}
	rsbs r2, r0, #0
	adds r3, r2, #0
	rsbs r1, r1, #0
	cmp r2, #0
	beq _0807E62A
	subs r1, #1
_0807E62A:
	adds r4, r1, #0
	adds r1, r4, #0
	adds r0, r3, #0
	pop {r4, pc}
	.align 2, 0

	thumb_func_start memcpy_optimized
	.global memcpy_optimized
memcpy_optimized: @ 0x0807E634
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r3, r1, #0
	cmp r2, #0xf
	bls _0807E674
	adds r0, r3, #0
	orrs r0, r5
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0807E674
	adds r1, r5, #0
_0807E64E:
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #0x10
	cmp r2, #0xf
	bhi _0807E64E
	cmp r2, #3
	bls _0807E672
_0807E668:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #4
	cmp r2, #3
	bhi _0807E668
_0807E672:
	adds r4, r1, #0
_0807E674:
	subs r2, #1
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq _0807E68E
	adds r1, r0, #0
_0807E680:
	ldrb r0, [r3]
	strb r0, [r4]
	adds r3, #1
	adds r4, #1
	subs r2, #1
	cmp r2, r1
	bne _0807E680
_0807E68E:
	adds r0, r5, #0
	pop {r4, r5, pc}
	.align 2, 0

	thumb_func_start custom_memset
	.global custom_memset
custom_memset: @ 0x0807E694
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r5, #0
	cmp r2, #3
	bls _0807E6DA
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	bne _0807E6DA
	adds r1, r5, #0
	movs r0, #0xff
	ands r4, r0
	lsls r3, r4, #8
	orrs r3, r4
	lsls r0, r3, #0x10
	orrs r3, r0
	cmp r2, #0xf
	bls _0807E6CE
_0807E6BA:
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	subs r2, #0x10
	cmp r2, #0xf
	bhi _0807E6BA
	b _0807E6CE
_0807E6CA:
	stm r1!, {r3}
	subs r2, #4
_0807E6CE:
	cmp r2, #3
	bhi _0807E6CA
	adds r3, r1, #0
	b _0807E6DA
_0807E6D6:
	strb r4, [r3]
	adds r3, #1
_0807E6DA:
	adds r0, r2, #0
	subs r2, #1
	cmp r0, #0
	bne _0807E6D6
	adds r0, r5, #0
	pop {r4, r5, pc}

	.incbin "baserom.gba", 0x7E6E6, 0xA
