	.syntax unified

	thumb_func_start fixed_point_multiply_divide
	.global fixed_point_multiply_divide
fixed_point_multiply_divide: @ 0x08015DD0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	cmp r3, #0
	blt _08015DE2
	bl int_to_softfloat
	b _08015DF6
_08015DE2:
	movs r0, #1
	ands r0, r3
	lsrs r1, r3, #1
	orrs r0, r1
	bl int_to_softfloat
	adds r4, r0, #0
	adds r1, r4, #0
	bl softfloat_add_f32
_08015DF6:
	adds r4, r0, #0
	cmp r5, #0
	blt _08015E04
	adds r0, r5, #0
	bl int_to_softfloat
	b _08015E16
_08015E04:
	movs r0, #1
	ands r0, r5
	lsrs r1, r5, #1
	orrs r0, r1
	bl int_to_softfloat
	adds r1, r0, #0
	bl softfloat_add_f32
_08015E16:
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_divide
	adds r4, r0, #0
	cmp r6, #0
	blt _08015E2C
	adds r0, r6, #0
	bl int_to_softfloat
	b _08015E3E
_08015E2C:
	movs r0, #1
	ands r0, r6
	lsrs r1, r6, #1
	orrs r0, r1
	bl int_to_softfloat
	adds r1, r0, #0
	bl softfloat_add_f32
_08015E3E:
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_multiply
	bl float_clamp_to_int
	lsrs r1, r0, #3
	lsls r2, r1, #0x10
	movs r1, #7
	ands r1, r0
	orrs r2, r1
	cmp r6, #0
	beq _08015E5E
	cmp r2, #0
	bne _08015E5E
	movs r2, #1
_08015E5E:
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
