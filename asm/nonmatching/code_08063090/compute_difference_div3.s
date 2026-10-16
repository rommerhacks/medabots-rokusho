	.syntax unified

	thumb_func_start compute_difference_div3
compute_difference_div3: @ 0x080666DC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, [r6]
	ldr r4, [r5]
	subs r0, r0, r4
	movs r1, #3
	bl sub_0807CBBC
	adds r0, r0, r4
	mov r1, r8
	str r0, [r1]
	ldr r0, [r6, #4]
	ldr r5, [r5, #4]
	subs r0, r0, r5
	movs r1, #3
	bl sub_0807CBBC
	adds r0, r0, r5
	mov r1, r8
	str r0, [r1, #4]
	ldr r0, [r6]
	subs r0, r0, r4
	lsls r0, r0, #1
	movs r1, #3
	bl sub_0807CBBC
	adds r0, r0, r4
	mov r1, sb
	str r0, [r1]
	ldr r0, [r6, #4]
	subs r0, r0, r5
	lsls r0, r0, #1
	movs r1, #3
	bl sub_0807CBBC
	adds r0, r0, r5
	mov r1, sb
	str r0, [r1, #4]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
