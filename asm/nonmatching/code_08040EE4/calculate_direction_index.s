	.syntax unified

	thumb_func_start calculate_direction_index
	.global calculate_direction_index
calculate_direction_index: @ 0x080442B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r1, #0
	adds r4, r3, #0
	cmp r0, r2
	bgt _080442CA
	movs r1, #0
	mov r8, r1
	subs r0, r2, r0
	b _080442D0
_080442CA:
	movs r1, #1
	mov r8, r1
	subs r0, r0, r2
_080442D0:
	bl int_to_softfloat
	adds r5, r0, #0
	cmp r6, r4
	bgt _080442E0
	movs r7, #0
	subs r0, r4, r6
	b _080442E4
_080442E0:
	movs r7, #1
	subs r0, r6, r4
_080442E4:
	bl int_to_softfloat
	adds r4, r0, #0
	mov r1, r8
	cmp r1, #0
	beq _080442F2
	b _08044468
_080442F2:
	cmp r7, #0
	bne _080443AC
	ldr r6, _08044324 @ =0x00000000
	adds r0, r5, #0
	adds r1, r6, #0
	bl soft_float_eq
	cmp r0, #0
	bne _08044306
	b _0804453E
_08044306:
	adds r0, r4, #0
	adds r1, r6, #0
	bl soft_float_eq
	cmp r0, #0
	beq _080443CA
	adds r0, r5, #0
	adds r1, r4, #0
	bl soft_float_eq
	cmp r0, #0
	bne _08044328
	movs r0, #0xc
	b _080445E2
	.align 2, 0
_08044324: .4byte 0x00000000
_08044328:
	adds r0, r5, #0
	adds r1, r4, #0
	bl softfloat_compare_eq
	cmp r0, #0
	ble _08044370
	ldr r1, _08044368 @ =0x3F000000
	adds r0, r4, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r1, r4, #0
	bl softfloat_divide
	bl float_to_int
	adds r1, r0, #0
	cmp r1, #4
	ble _08044362
	ldr r0, _0804436C @ =0x03001780
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08044362
	movs r1, #4
_08044362:
	movs r0, #0xc
	subs r0, r0, r1
	b _080445E2
	.align 2, 0
_08044368: .4byte 0x3F000000
_0804436C: .4byte 0x03001780
_08044370:
	ldr r1, _080443A4 @ =0x3F000000
	adds r0, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r1, r5, #0
	bl softfloat_divide
	bl float_to_int
	adds r1, r0, #0
	cmp r1, #4
	ble _0804439E
	ldr r0, _080443A8 @ =0x03001780
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0804439E
	movs r1, #4
_0804439E:
	adds r0, r1, #0
	adds r0, #0xc
	b _080445E2
	.align 2, 0
_080443A4: .4byte 0x3F000000
_080443A8: .4byte 0x03001780
_080443AC:
	cmp r7, #1
	bne _08044468
	ldr r6, _080443D0 @ =0x00000000
	adds r0, r5, #0
	adds r1, r6, #0
	bl soft_float_eq
	cmp r0, #0
	beq _08044482
	adds r0, r4, #0
	adds r1, r6, #0
	bl soft_float_eq
	cmp r0, #0
	bne _080443D4
_080443CA:
	movs r0, #8
	b _080445E2
	.align 2, 0
_080443D0: .4byte 0x00000000
_080443D4:
	adds r0, r5, #0
	adds r1, r4, #0
	bl soft_float_eq
	cmp r0, #0
	bne _080443E4
	movs r0, #4
	b _080445E2
_080443E4:
	adds r0, r5, #0
	adds r1, r4, #0
	bl softfloat_compare_eq
	cmp r0, #0
	ble _0804442C
	ldr r1, _08044424 @ =0x3F000000
	adds r0, r4, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r1, r4, #0
	bl softfloat_divide
	bl float_to_int
	adds r1, r0, #0
	cmp r1, #4
	ble _0804441E
	ldr r0, _08044428 @ =0x03001780
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0804441E
	movs r1, #4
_0804441E:
	adds r0, r1, #4
	b _080445E2
	.align 2, 0
_08044424: .4byte 0x3F000000
_08044428: .4byte 0x03001780
_0804442C:
	ldr r1, _08044460 @ =0x3F000000
	adds r0, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r1, r5, #0
	bl softfloat_divide
	bl float_to_int
	adds r1, r0, #0
	cmp r1, #4
	ble _0804445A
	ldr r0, _08044464 @ =0x03001780
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0804445A
	movs r1, #4
_0804445A:
	movs r0, #4
	subs r0, r0, r1
	b _080445E2
	.align 2, 0
_08044460: .4byte 0x3F000000
_08044464: .4byte 0x03001780
_08044468:
	mov r1, r8
	cmp r1, #1
	beq _08044470
	b _080445E2
_08044470:
	cmp r7, #1
	bne _0804452C
	ldr r6, _08044488 @ =0x00000000
	adds r0, r5, #0
	adds r1, r6, #0
	bl soft_float_eq
	cmp r0, #0
	bne _0804448C
_08044482:
	movs r0, #0
	b _080445E2
	.align 2, 0
_08044488: .4byte 0x00000000
_0804448C:
	adds r0, r4, #0
	adds r1, r6, #0
	bl soft_float_eq
	cmp r0, #0
	beq _08044554
	adds r0, r5, #0
	adds r1, r4, #0
	bl soft_float_eq
	cmp r0, #0
	bne _080444A8
	movs r0, #0x1c
	b _080445E2
_080444A8:
	adds r0, r5, #0
	adds r1, r4, #0
	bl softfloat_compare_eq
	cmp r0, #0
	ble _080444F0
	ldr r1, _080444E8 @ =0x3F000000
	adds r0, r4, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r1, r4, #0
	bl softfloat_divide
	bl float_to_int
	adds r1, r0, #0
	cmp r1, #4
	ble _080444E2
	ldr r0, _080444EC @ =0x03001780
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080444E2
	movs r1, #4
_080444E2:
	movs r0, #0x1c
	subs r0, r0, r1
	b _080445E2
	.align 2, 0
_080444E8: .4byte 0x3F000000
_080444EC: .4byte 0x03001780
_080444F0:
	ldr r1, _08044524 @ =0x3F000000
	adds r0, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r1, r5, #0
	bl softfloat_divide
	bl float_to_int
	adds r1, r0, #0
	cmp r1, #4
	ble _0804451E
	ldr r0, _08044528 @ =0x03001780
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0804451E
	movs r1, #4
_0804451E:
	adds r0, r1, #0
	adds r0, #0x1c
	b _080445E2
	.align 2, 0
_08044524: .4byte 0x3F000000
_08044528: .4byte 0x03001780
_0804452C:
	cmp r7, #0
	bne _080445E2
	ldr r6, _08044544 @ =0x00000000
	adds r0, r5, #0
	adds r1, r6, #0
	bl soft_float_eq
	cmp r0, #0
	bne _08044548
_0804453E:
	movs r0, #0x10
	b _080445E2
	.align 2, 0
_08044544: .4byte 0x00000000
_08044548:
	adds r0, r4, #0
	adds r1, r6, #0
	bl soft_float_eq
	cmp r0, #0
	bne _08044558
_08044554:
	movs r0, #0x18
	b _080445E2
_08044558:
	adds r0, r5, #0
	adds r1, r4, #0
	bl soft_float_eq
	cmp r0, #0
	bne _08044568
	movs r0, #0x14
	b _080445E2
_08044568:
	adds r0, r5, #0
	adds r1, r4, #0
	bl softfloat_compare_eq
	cmp r0, #0
	ble _080445B0
	ldr r1, _080445A8 @ =0x3F000000
	adds r0, r4, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r1, r4, #0
	bl softfloat_divide
	bl float_to_int
	adds r1, r0, #0
	cmp r1, #4
	ble _080445A2
	ldr r0, _080445AC @ =0x03001780
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080445A2
	movs r1, #4
_080445A2:
	adds r0, r1, #0
	adds r0, #0x14
	b _080445E2
	.align 2, 0
_080445A8: .4byte 0x3F000000
_080445AC: .4byte 0x03001780
_080445B0:
	ldr r1, _080445EC @ =0x3F000000
	adds r0, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r1, r5, #0
	bl softfloat_divide
	bl float_to_int
	adds r1, r0, #0
	cmp r1, #4
	ble _080445DE
	ldr r0, _080445F0 @ =0x03001780
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080445DE
	movs r1, #4
_080445DE:
	movs r0, #0x14
	subs r0, r0, r1
_080445E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080445EC: .4byte 0x3F000000
_080445F0: .4byte 0x03001780
	.syntax divided
