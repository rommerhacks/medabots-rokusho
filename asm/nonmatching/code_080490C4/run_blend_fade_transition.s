	.syntax unified

	thumb_func_start run_blend_fade_transition
	.global run_blend_fade_transition
run_blend_fade_transition: @ 0x08049DBC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #0
	mov r8, r0
	bl blend_effect_update
	ldr r4, _08049E30 @ =0x03005350
	ldr r0, _08049E34 @ =0x0000020A
	adds r6, r4, r0
	ldr r0, _08049E38 @ =0x0000FFFF
	strh r0, [r6]
	movs r0, #0x83
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r0, _08049E3C @ =0x0000BFFF
	strh r0, [r4]
	ldr r7, _08049E40 @ =0x03006F40
	ldr r0, [r7, #0x24]
	bl float_clamp_to_int
	adds r1, r0, #0
	ldrh r2, [r6]
	adds r0, r5, #0
	bl sub_08049E74
	ldr r0, [r7, #0x24]
	bl float_clamp_to_int
	adds r1, r0, #0
	ldrh r2, [r4]
	adds r0, r5, #0
	bl sub_08049E88
	ldr r0, [r7, #0x24]
	ldr r4, [r7, #0x30]
	adds r1, r4, #0
	bl softfloat_subtract
	adds r5, r0, #0
	str r5, [r7, #0x24]
	ldr r1, _08049E44 @ =0x00000000
	adds r0, r4, #0
	bl softfloat_compare_eq
	cmp r0, #0
	ble _08049E48
	ldr r1, [r7, #0x2c]
	adds r0, r5, #0
	bl soft_float_ge
	cmp r0, #0
	bge _08049E5E
	b _08049E54
	.align 2, 0
_08049E30: .4byte 0x03005350
_08049E34: .4byte 0x0000020A
_08049E38: .4byte 0x0000FFFF
_08049E3C: .4byte 0x0000BFFF
_08049E40: .4byte 0x03006F40
_08049E44: .4byte 0x00000000
_08049E48:
	ldr r1, [r7, #0x2c]
	adds r0, r5, #0
	bl softfloat_compare_eq
	cmp r0, #0
	ble _08049E5E
_08049E54:
	ldr r1, _08049E6C @ =0x030017F0
	ldr r0, _08049E70 @ =0x08000841
	str r0, [r1]
	movs r0, #1
	mov r8, r0
_08049E5E:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08049E6C: .4byte 0x030017F0
_08049E70: .4byte 0x08000841
	.syntax divided
