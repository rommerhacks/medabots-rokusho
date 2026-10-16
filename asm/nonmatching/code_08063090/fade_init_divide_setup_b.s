	.syntax unified

	thumb_func_start fade_init_divide_setup_b
fade_init_divide_setup_b: @ 0x08066B78
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r7, #0
	ldr r0, _08066BF0 @ =0x03006F74
	mov sb, r0
	ldr r3, _08066BF4 @ =0x080AE77C
_08066B90:
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r7, #4
	adds r6, r1, r0
	adds r4, r6, #0
	adds r4, #0xd0
	movs r0, #0
	ldrsh r5, [r4, r0]
	lsls r0, r7, #8
	movs r1, #0x12
	str r3, [sp]
	bl sub_0807CBBC
	add r0, r8
	movs r1, #0xff
	ands r0, r1
	lsls r1, r0, #1
	ldr r3, [sp]
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r5, r1
	asrs r1, r1, #8
	adds r2, r6, #0
	adds r2, #0xd8
	strh r1, [r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	adds r1, r6, #0
	adds r1, #0xda
	strh r0, [r1]
	adds r7, #1
	cmp r7, #0x11
	ble _08066B90
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066BF0: .4byte 0x03006F74
_08066BF4: .4byte 0x080AE77C
	.syntax divided
