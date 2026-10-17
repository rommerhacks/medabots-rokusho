	.syntax unified

	thumb_func_start truncate_to_digit_count
truncate_to_digit_count: @ 0x0804889C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	mov r8, r7
	movs r4, #0
	b _080488E2
_080488B2:
	movs r5, #1
	movs r6, #0
	adds r4, #1
	b _080488C2
_080488BA:
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r5, r0, #1
	adds r6, #1
_080488C2:
	adds r0, r7, #0
	bl count_decimal_digits
	subs r0, r0, r4
	cmp r6, r0
	blt _080488BA
	mov r0, r8
	adds r1, r5, #0
	bl sub_0807CBBC
	adds r6, r0, #0
	adds r0, r5, #0
	muls r0, r6, r0
	mov r1, r8
	subs r1, r1, r0
	mov r8, r1
_080488E2:
	adds r0, r7, #0
	bl count_decimal_digits
	mov r1, sb
	subs r0, r0, r1
	cmp r4, r0
	bge _080488FC
	adds r0, r7, #0
	bl count_decimal_digits
	subs r0, #1
	cmp r4, r0
	bne _080488B2
_080488FC:
	mov r0, sb
	cmp r0, #0
	bne _08048906
	mov r0, r8
	b _08048908
_08048906:
	adds r0, r6, #0
_08048908:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
