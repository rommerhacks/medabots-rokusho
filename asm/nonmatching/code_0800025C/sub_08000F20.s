	.syntax unified

	thumb_func_start sub_08000F20
sub_08000F20: @ 0x08000F20
	push {r7}
	adds r4, r2, #0
	movs r2, #0xc0
	lsls r2, r2, #8
	ands r2, r3
	lsrs r2, r2, #0xe
	adds r7, r2, #3
	lsrs r3, r3, #8
	movs r2, #0x1f
	ands r3, r2
	lsls r3, r3, #0xb
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r0, r0, r2
	adds r3, r3, r0
	lsls r1, r7
	adds r3, r3, r1
	mov r8, r3
	adds r6, r4, #0
	adds r6, #0x10
	movs r5, #0
	b _08000F66
_08000F4C:
	adds r1, r5, #0
	lsls r1, r7
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r4]
	lsls r2, r2, #0xa
	lsrs r2, r2, #0xb
	adds r0, r6, #0
	bl CpuSet
	ldr r0, [r4]
	adds r6, r6, r0
	adds r5, #1
_08000F66:
	ldr r0, [r4, #4]
	cmp r5, r0
	blo _08000F4C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
