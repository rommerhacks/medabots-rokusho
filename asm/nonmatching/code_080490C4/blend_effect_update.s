	.syntax unified

	thumb_func_start blend_effect_update
	.global blend_effect_update
blend_effect_update: @ 0x08049A20
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r0, _08049A38 @ =0x03006F40
	ldrb r2, [r0, #2]
	adds r6, r0, #0
	cmp r2, #2
	bne _08049A44
	movs r7, #1
	ldr r1, _08049A3C @ =0x030017F0
	ldr r0, _08049A40 @ =0x08000841
	str r0, [r1]
	b _08049C5E
	.align 2, 0
_08049A38: .4byte 0x03006F40
_08049A3C: .4byte 0x030017F0
_08049A40: .4byte 0x08000841
_08049A44:
	ldr r1, _08049A7C @ =0x030017F0
	cmp r2, #1
	beq _08049A4C
	b _08049C5E
_08049A4C:
	ldrb r0, [r6]
	cmp r0, #0x40
	beq _08049A94
	cmp r0, #0x40
	ble _08049A94
	cmp r0, #0x80
	beq _08049A5E
	cmp r0, #0xc0
	bne _08049A94
_08049A5E:
	ldr r4, [r6, #0x14]
	ldr r5, _08049A80 @ =0x43800000
	adds r0, r4, #0
	adds r1, r5, #0
	bl soft_float_ge
	cmp r0, #0
	bge _08049A84
	ldr r1, [r6, #0x20]
	adds r0, r4, #0
	bl softfloat_add_f32
	str r0, [r6, #0x14]
	b _08049A86
	.align 2, 0
_08049A7C: .4byte 0x030017F0
_08049A80: .4byte 0x43800000
_08049A84:
	str r5, [r6, #0x14]
_08049A86:
	ldr r0, [r6, #0x14]
	ldr r1, _08049AA8 @ =0x43800000
	bl softfloat_compare_ge
	cmp r0, #0
	blt _08049A94
	movs r7, #1
_08049A94:
	ldrb r0, [r6, #1]
	ldr r1, _08049AAC @ =0x030017F0
	cmp r0, #6
	bls _08049A9E
	b _08049C5E
_08049A9E:
	lsls r0, r0, #2
	ldr r1, _08049AB0 @ =_08049AB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08049AA8: .4byte 0x43800000
_08049AAC: .4byte 0x030017F0
_08049AB0: .4byte _08049AB4
_08049AB4: @ jump table
	.4byte _08049AD0 @ case 0
	.4byte _08049AFC @ case 1
	.4byte _08049AD0 @ case 2
	.4byte _08049AFC @ case 3
	.4byte _08049B54 @ case 4
	.4byte _08049BA0 @ case 5
	.4byte _08049BE8 @ case 6
_08049AD0:
	ldr r0, [r6, #0xc]
	ldr r4, _08049AF8 @ =0x3D800000
	adds r1, r4, #0
	bl softfloat_multiply
	bl float_clamp_to_int
	strb r0, [r6, #3]
	ldr r0, [r6, #0x10]
	adds r1, r4, #0
	bl softfloat_multiply
	bl float_clamp_to_int
	strb r0, [r6, #4]
	ldr r0, [r6, #0x14]
	adds r1, r4, #0
	bl softfloat_multiply
	b _08049B3C
	.align 2, 0
_08049AF8: .4byte 0x3D800000
_08049AFC:
	ldr r0, [r6, #0xc]
	ldr r5, _08049B48 @ =0x3D800000
	adds r1, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r4, _08049B4C @ =0x41800000
	adds r0, r4, #0
	bl softfloat_subtract
	bl float_clamp_to_int
	strb r0, [r6, #3]
	ldr r0, [r6, #0x10]
	adds r1, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_subtract
	bl float_clamp_to_int
	strb r0, [r6, #4]
	ldr r0, [r6, #0x14]
	adds r1, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_subtract
_08049B3C:
	bl float_clamp_to_int
	strb r0, [r6, #5]
	ldr r1, _08049B50 @ =0x030017F0
	b _08049C5E
	.align 2, 0
_08049B48: .4byte 0x3D800000
_08049B4C: .4byte 0x41800000
_08049B50: .4byte 0x030017F0
_08049B54:
	ldr r0, [r6, #0xc]
	ldr r1, [r6, #0x18]
	bl softfloat_add_f32
	str r0, [r6, #0xc]
	bl float_clamp_to_int
	ldrb r1, [r6, #6]
	adds r0, r0, r1
	strb r0, [r6, #3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _08049B76
	movs r0, #0x10
	strb r0, [r6, #3]
	movs r7, #1
_08049B76:
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x1c]
	bl softfloat_add_f32
	str r0, [r6, #0x10]
	bl float_clamp_to_int
	ldrb r1, [r6, #7]
	adds r0, r0, r1
	strb r0, [r6, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08049B9C @ =0x030017F0
	cmp r0, #0xf
	bls _08049C5E
	movs r0, #0x10
	strb r0, [r6, #4]
	b _08049C5C
	.align 2, 0
_08049B9C: .4byte 0x030017F0
_08049BA0:
	ldr r0, [r6, #0xc]
	ldr r1, [r6, #0x18]
	bl softfloat_add_f32
	str r0, [r6, #0xc]
	bl float_clamp_to_int
	movs r4, #0x10
	subs r0, r4, r0
	strb r0, [r6, #3]
	ldrb r1, [r6, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r1
	bhi _08049BC2
	strb r1, [r6, #3]
	movs r7, #1
_08049BC2:
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x1c]
	bl softfloat_add_f32
	str r0, [r6, #0x10]
	bl float_clamp_to_int
	subs r0, r4, r0
	strb r0, [r6, #4]
	ldrb r2, [r6, #7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08049BE4 @ =0x030017F0
	cmp r0, r2
	bhi _08049C5E
	strb r2, [r6, #4]
	b _08049C5C
	.align 2, 0
_08049BE4: .4byte 0x030017F0
_08049BE8:
	ldr r0, [r6, #0xc]
	ldr r1, [r6, #0x18]
	bl softfloat_add_f32
	str r0, [r6, #0xc]
	bl float_clamp_to_int
	ldrb r1, [r6, #9]
	subs r0, r1, r0
	strb r0, [r6, #3]
	ldrb r3, [r6, #6]
	adds r2, r3, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r2, r1
	beq _08049C12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r2
	blo _08049C1E
	b _08049C1A
_08049C12:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r2
	bhi _08049C1E
_08049C1A:
	strb r3, [r6, #3]
	movs r7, #1
_08049C1E:
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x1c]
	bl softfloat_add_f32
	str r0, [r6, #0x10]
	bl float_clamp_to_int
	ldrb r1, [r6, #0xa]
	subs r0, r1, r0
	strb r0, [r6, #4]
	ldrb r3, [r6, #7]
	adds r2, r3, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r2, r1
	beq _08049C50
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08049C4C @ =0x030017F0
	cmp r0, r2
	blo _08049C5E
	b _08049C5A
	.align 2, 0
_08049C4C: .4byte 0x030017F0
_08049C50:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08049C74 @ =0x030017F0
	cmp r0, r2
	bhi _08049C5E
_08049C5A:
	strb r3, [r6, #4]
_08049C5C:
	movs r7, #1
_08049C5E:
	ldr r0, _08049C78 @ =apply_blend_coefficients
	str r0, [r1]
	cmp r7, #0
	beq _08049C6C
	movs r7, #0
	movs r0, #2
	strb r0, [r6, #2]
_08049C6C:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08049C74: .4byte 0x030017F0
_08049C78: .4byte apply_blend_coefficients
	.syntax divided
