	.syntax unified

	thumb_func_start update_blend_effect_from_input
update_blend_effect_from_input: @ 0x0804B5B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r5, _0804B680 @ =0x0300058C
	ldrb r1, [r5]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804B5EA
	ldr r4, _0804B684 @ =0x03006F40
	ldr r0, [r4, #0x14]
	ldr r1, _0804B688 @ =0x3F800000
	bl softfloat_add_f32
	str r0, [r4, #0x14]
	bl float_clamp_to_int
	adds r1, r0, #0
	movs r0, #0xf
	ands r0, r1
	bl int_to_softfloat
	str r0, [r4, #0x14]
	ldr r4, _0804B68C @ =0x04000054
	bl float_clamp_to_int
	movs r1, #0x3f
	ands r1, r0
	strh r1, [r4]
_0804B5EA:
	ldrb r7, [r5, #1]
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq _0804B632
	ldr r4, _0804B684 @ =0x03006F40
	ldr r0, [r4, #0xc]
	ldr r1, _0804B688 @ =0x3F800000
	bl softfloat_add_f32
	str r0, [r4, #0xc]
	bl float_clamp_to_int
	adds r1, r0, #0
	movs r0, #0xf
	ands r0, r1
	bl int_to_softfloat
	adds r6, r0, #0
	str r6, [r4, #0xc]
	ldr r0, _0804B690 @ =0x04000052
	mov r8, r0
	ldr r0, [r4, #0x10]
	bl float_clamp_to_int
	adds r4, r0, #0
	movs r5, #0x3f
	ands r4, r5
	lsls r4, r4, #8
	adds r0, r6, #0
	bl float_clamp_to_int
	ands r0, r5
	orrs r4, r0
	mov r1, r8
	strh r4, [r1]
_0804B632:
	movs r0, #2
	ands r0, r7
	cmp r0, #0
	beq _0804B674
	ldr r6, _0804B684 @ =0x03006F40
	ldr r0, [r6, #0x10]
	ldr r1, _0804B688 @ =0x3F800000
	bl softfloat_add_f32
	str r0, [r6, #0x10]
	bl float_clamp_to_int
	adds r1, r0, #0
	movs r0, #0xf
	ands r0, r1
	bl int_to_softfloat
	str r0, [r6, #0x10]
	ldr r1, _0804B690 @ =0x04000052
	mov r8, r1
	bl float_clamp_to_int
	adds r4, r0, #0
	movs r5, #0x3f
	ands r4, r5
	lsls r4, r4, #8
	ldr r0, [r6, #0xc]
	bl float_clamp_to_int
	ands r0, r5
	orrs r4, r0
	mov r0, r8
	strh r4, [r0]
_0804B674:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B680: .4byte 0x0300058C
_0804B684: .4byte 0x03006F40
_0804B688: .4byte 0x3F800000
_0804B68C: .4byte 0x04000054
_0804B690: .4byte 0x04000052
	.syntax divided
