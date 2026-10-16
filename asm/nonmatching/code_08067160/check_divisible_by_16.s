	.syntax unified

	thumb_func_start check_divisible_by_16
check_divisible_by_16: @ 0x08068790
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080687CC @ =0x03000000
	mov r8, r0
	ldr r7, _080687D0 @ =0x03000005
	ldrb r6, [r7]
	ldr r5, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_0807CC88
	cmp r0, #0
	bne _080687BC
	ldr r4, _080687D4 @ =0x04000054
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_0807CBBC
	movs r1, #0x10
	subs r1, r1, r0
	strh r1, [r4]
_080687BC:
	ldrb r0, [r7]
	lsls r0, r0, #4
	mov r2, r8
	ldr r1, [r2]
	cmp r1, r0
	beq _080687D8
	movs r0, #0
	b _080687DA
	.align 2, 0
_080687CC: .4byte 0x03000000
_080687D0: .4byte 0x03000005
_080687D4: .4byte 0x04000054
_080687D8:
	movs r0, #1
_080687DA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
