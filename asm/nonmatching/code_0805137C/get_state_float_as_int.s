	.syntax unified

	thumb_func_start get_state_float_as_int
get_state_float_as_int: @ 0x08053D2C
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r6, r0, #0
	mov sb, r1
	mov r8, r2
	mov sl, r3
	ldr r5, _08053D90 @ =0x03005350
	ldr r0, [r5, #0x30]
	bl float_to_int
	adds r4, r0, #0
	adds r0, r6, #0
	bl float_to_int
	muls r4, r0, r4
	ldr r0, [r5, #0x38]
	bl float_to_int
	adds r4, r4, r0
	ldr r0, [r5, #8]
	adds r4, r4, r0
	mov r0, r8
	str r4, [r0]
	ldr r0, [r5, #0x34]
	bl float_to_int
	adds r4, r0, #0
	mov r0, sb
	bl float_to_int
	muls r4, r0, r4
	ldr r0, [r5, #0x3c]
	bl float_to_int
	adds r4, r4, r0
	ldr r0, [r5, #0xc]
	subs r0, r0, r4
	mov r1, sl
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053D90: .4byte 0x03005350
	.syntax divided
