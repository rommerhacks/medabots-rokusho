	.syntax unified

	thumb_func_start check_divisible_by_16_b
check_divisible_by_16_b: @ 0x080689E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08068A18 @ =0x03000000
	mov r8, r0
	ldr r7, _08068A1C @ =0x03000005
	ldrb r6, [r7]
	ldr r5, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_0807CC88
	cmp r0, #0
	bne _08068A08
	ldr r4, _08068A20 @ =0x04000054
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_0807CBBC
	strh r0, [r4]
_08068A08:
	ldrb r0, [r7]
	lsls r0, r0, #4
	mov r2, r8
	ldr r1, [r2]
	cmp r1, r0
	beq _08068A24
	movs r0, #0
	b _08068A26
	.align 2, 0
_08068A18: .4byte 0x03000000
_08068A1C: .4byte 0x03000005
_08068A20: .4byte 0x04000054
_08068A24:
	movs r0, #1
_08068A26:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
