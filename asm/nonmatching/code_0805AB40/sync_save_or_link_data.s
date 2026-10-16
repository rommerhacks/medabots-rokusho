	.syntax unified

	thumb_func_start sync_save_or_link_data
sync_save_or_link_data: @ 0x0805E0E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xe6
	lsls r0, r0, #2
	mov r8, r0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _0805E124
	movs r6, #0
	mov r4, sp
_0805E0FA:
	ldrh r0, [r5]
	strh r0, [r4]
	adds r5, #2
	ldrh r0, [r5]
	strh r0, [r4, #2]
	adds r5, #2
	ldrh r0, [r5]
	strh r0, [r4, #4]
	adds r5, #2
	ldrh r0, [r5]
	strh r0, [r4, #6]
	adds r5, #2
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl ProgramEepromDwordEx
	adds r6, #1
	cmp r6, r8
	blt _0805E0FA
	b _0805E160
_0805E124:
	movs r6, #0
_0805E126:
	lsls r4, r6, #0x10
	lsrs r0, r4, #0x10
	mov r1, sp
	bl ReadEepromDword
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r3, #0
	adds r6, #1
	mov r2, sp
_0805E13A:
	ldrh r1, [r5]
	ldrh r0, [r2]
	cmp r0, r1
	beq _0805E146
	strh r1, [r2]
	movs r7, #1
_0805E146:
	adds r5, #2
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	bls _0805E13A
	cmp r7, #0
	beq _0805E15C
	lsrs r0, r4, #0x10
	mov r1, sp
	bl ProgramEepromDwordEx
_0805E15C:
	cmp r6, r8
	blt _0805E126
_0805E160:
	movs r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
