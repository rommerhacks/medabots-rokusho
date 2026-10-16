	.syntax unified

	thumb_func_start setup_palette_fade_to_color
	.global setup_palette_fade_to_color
setup_palette_fade_to_color: @ 0x08049CCC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	bl float_to_double
	adds r2, r1, #0
	adds r1, r0, #0
	adds r0, r4, #0
	bl palette_blend_to_color_080013A8
	ldr r4, _08049D40 @ =0x03006F40
	str r5, [r4, #0x24]
	str r5, [r4, #0x28]
	str r6, [r4, #0x2c]
	adds r0, r5, #0
	adds r1, r6, #0
	bl softfloat_subtract
	mov r1, r8
	bl softfloat_divide
	str r0, [r4, #0x30]
	movs r4, #0xbc
	lsls r4, r4, #6
	mov r0, r8
	bl float_clamp_to_int
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	movs r0, #0xa
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #0x40
	adds r1, r4, #0
	movs r2, #5
	bl setup_blend_effect
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08049D40: .4byte 0x03006F40
	.syntax divided
