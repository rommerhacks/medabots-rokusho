	.syntax unified

	thumb_func_start update_3d_entity_projections
update_3d_entity_projections: @ 0x08053FC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r7, _080541D0 @ =0x03005350
	movs r0, #0xf0
	str r0, [r7]
	movs r0, #0xa0
	str r0, [r7, #4]
	ldr r4, _080541D4 @ =0xC2F10000
	ldr r5, _080541D8 @ =0x42F10000
	ldr r6, _080541DC @ =0xC2A10000
	ldr r0, _080541E0 @ =0x42A10000
	mov r8, r0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl affine_set_destination_and_compute_transform
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl affine_set_source_and_compute_transform
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	bl double_to_int
	adds r4, r0, #0
	adds r0, r7, #0
	adds r0, #0xac
	ldr r1, [r0, #4]
	ldr r0, [r0]
	bl double_to_int
	adds r1, r0, #0
	adds r0, r4, #0
	bl init_affine_transform_viewport
	movs r1, #0
	str r1, [sp]
	mov sl, r7
_08054028:
	ldr r0, _080541E4 @ =0x03006D30
	ldr r2, [r0]
	ldr r3, [sp]
	lsls r1, r3, #1
	adds r0, r1, r3
	lsls r0, r0, #8
	adds r2, r0, r2
	ldr r0, [r2]
	str r1, [sp, #8]
	adds r3, #1
	str r3, [sp, #0xc]
	cmp r0, #0
	bne _08054044
	b _080541B4
_08054044:
	ldr r1, [r2, #4]
	ldr r0, [r2, #8]
	cmp r1, r0
	bge _0805404E
	b _080541B4
_0805404E:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r2, r6
	ldr r0, [r0]
	cmp r0, #0
	bne _0805405C
	b _080541B4
_0805405C:
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bge _08054072
	b _080541B4
_08054072:
	ldr r1, _080541E8 @ =0x083D2DB0
	mov r2, sl
	adds r2, #0xf8
	ldr r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r6, [sp]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #4]
	adds r1, r0, #0
	ldm r1!, {r0}
	ldr r3, _080541EC @ =0x03005520
	str r0, [r3]
	subs r2, #0x38
	movs r7, #3
_08054096:
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [r1, #0x10]
	str r0, [r2, #0x10]
	ldr r0, [r1, #0x20]
	str r0, [r2, #0x20]
	adds r1, #4
	adds r2, #4
	subs r7, #1
	cmp r7, #0
	bge _08054096
	movs r6, #0x90
	add r6, sl
	mov r8, r6
	ldr r0, _080541E4 @ =0x03006D30
	ldr r1, [r0]
	ldr r2, [sp, #8]
	ldr r3, [sp]
	adds r0, r2, r3
	lsls r0, r0, #8
	adds r4, r0, r1
	adds r1, r4, #0
	adds r1, #0xf8
	ldr r0, [r6]
	ldr r1, [r1]
	bl softfloat_add_f32
	adds r6, r0, #0
	mov r0, sl
	adds r0, #0x94
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r0, [r0]
	ldr r1, [r1]
	bl softfloat_add_f32
	adds r5, r0, #0
	mov r0, sl
	adds r0, #0x9c
	ldr r0, [r0]
	bl int_to_softfloat
	adds r4, r0, #0
	ldr r3, _080541F0 @ =0x030053F0
	ldr r0, [r3]
	bl int_to_softfloat
	adds r3, r0, #0
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl set_state_float_field
	movs r7, #0
	movs r6, #0x90
	rsbs r6, r6, #0
	add r8, r6
_0805410A:
	lsls r4, r7, #2
	ldr r0, _080541F4 @ =0x030053B0
	adds r5, r4, r0
	mov r0, r8
	adds r0, #0xc0
	adds r0, r4, r0
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _080541E4 @ =0x03006D30
	ldr r2, [r1]
	ldr r3, [sp, #8]
	ldr r6, [sp]
	adds r1, r3, r6
	lsls r1, r1, #8
	adds r6, r1, r2
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r1, [r1]
	bl softfloat_multiply
	ldr r1, [r6, #0x10]
	bl softfloat_add_f32
	str r0, [r5]
	ldr r3, _080541F8 @ =0x030053C0
	adds r5, r4, r3
	mov r0, r8
	adds r0, #0xd0
	adds r0, r4, r0
	ldr r0, [r0]
	bl int_to_softfloat
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r1, [r1]
	bl softfloat_multiply
	ldr r1, [r6, #0x58]
	bl softfloat_add_f32
	str r0, [r5]
	movs r3, #0x80
	add r3, r8
	mov sb, r3
	adds r5, r4, r3
	ldr r0, _080541FC @ =0x03005430
	adds r4, r4, r0
	ldr r0, [r4]
	bl int_to_softfloat
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r1, [r1]
	bl softfloat_multiply
	adds r1, r6, #0
	adds r1, #0xa0
	ldr r1, [r1]
	bl softfloat_add_f32
	str r0, [r5]
	adds r7, #1
	cmp r7, #3
	ble _0805410A
	mov r4, sl
	adds r4, #0x98
	ldr r3, [sp, #4]
	ldr r0, [r3, #4]
	bl int_to_softfloat
	str r0, [r4]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sl
	ldr r6, [sp]
	str r6, [r0]
	ldr r0, _080541F4 @ =0x030053B0
	ldr r1, _080541F8 @ =0x030053C0
	mov r2, sb
	bl compute_distance_to_state_position
_080541B4:
	ldr r0, [sp, #0xc]
	str r0, [sp]
	cmp r0, #0xf
	bgt _080541BE
	b _08054028
_080541BE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080541D0: .4byte 0x03005350
_080541D4: .4byte 0xC2F10000
_080541D8: .4byte 0x42F10000
_080541DC: .4byte 0xC2A10000
_080541E0: .4byte 0x42A10000
_080541E4: .4byte 0x03006D30
_080541E8: .4byte 0x083D2DB0
_080541EC: .4byte 0x03005520
_080541F0: .4byte 0x030053F0
_080541F4: .4byte 0x030053B0
_080541F8: .4byte 0x030053C0
_080541FC: .4byte 0x03005430
	.syntax divided
