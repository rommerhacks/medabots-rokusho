	.syntax unified

	thumb_func_start sub_0800EDA0
sub_0800EDA0: @ 0x0800EDA0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r5, #0
	ldr r0, _0800EDF4 @ =0x03004C40
	mov sb, r0
	ldr r6, _0800EDF8 @ =0x03000440
	movs r2, #0x3f
	adds r2, r2, r6
	mov r8, r2
	movs r4, #5
	ldr r7, _0800EDFC @ =0x0400000A
_0800EDBC:
	adds r0, r6, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r1, r1, r0
	lsls r0, r5, #1
	adds r1, r1, r0
	adds r1, #1
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800EE04
	ldrh r1, [r7]
	str r1, [sp]
	ldr r1, _0800EE00 @ =0x00006360
	str r1, [sp, #4]
	movs r1, #0x19
	adds r2, r4, #0
	movs r3, #1
	bl sub_08042950
	b _0800EE18
	.align 2, 0
_0800EDF4: .4byte 0x03004C40
_0800EDF8: .4byte 0x03000440
_0800EDFC: .4byte 0x0400000A
_0800EE00: .4byte 0x00006360
_0800EE04:
	ldrh r0, [r7]
	str r0, [sp]
	ldr r0, _0800EE30 @ =0x00006360
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0x19
	adds r2, r4, #0
	movs r3, #1
	bl sub_08042950
_0800EE18:
	adds r4, #2
	adds r5, #1
	cmp r5, #3
	bls _0800EDBC
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800EE30: .4byte 0x00006360
	.syntax divided
