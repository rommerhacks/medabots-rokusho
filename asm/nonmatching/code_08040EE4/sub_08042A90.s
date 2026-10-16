	.syntax unified

	thumb_func_start sub_08042A90
	.global sub_08042A90
sub_08042A90: @ 0x08042A90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov sl, r1
	adds r6, r2, #0
	mov r8, r3
	ldr r4, [sp, #0x2c]
	ldr r0, [sp, #0x30]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r5, sp
	mov r0, sb
	movs r1, #0xa
	bl sub_0807CD58
	strb r0, [r5]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r0, sb
	subs r1, r0, r1
	mov r0, sp
	strb r1, [r0, #1]
	add r5, sp, #4
	mov r0, sl
	movs r1, #0xa
	bl sub_0807CD58
	strb r0, [r5]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r0, sl
	subs r1, r0, r1
	strb r1, [r5, #1]
	lsrs r4, r4, #8
	movs r0, #0x1f
	ands r4, r0
	lsls r4, r4, #0xb
	lsls r6, r6, #1
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r6, r6, r0
	adds r4, r4, r6
	mov r0, r8
	lsls r0, r0, #6
	mov r8, r0
	add r4, r8
	movs r2, #0
	mov r3, sp
	adds r3, #1
_08042AFE:
	mov r0, sp
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _08042B10
	cmp r2, #1
	bne _08042B18
	ldrb r0, [r3]
	b _08042B12
_08042B10:
	ldrb r0, [r1]
_08042B12:
	adds r0, r7, r0
	strh r0, [r4]
	adds r4, #2
_08042B18:
	adds r2, #1
	cmp r2, #1
	bls _08042AFE
	ldr r0, [sp, #0x28]
	strh r0, [r4]
	adds r4, #2
	movs r2, #0
	mov r3, sp
	adds r3, #5
_08042B2A:
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _08042B3A
	cmp r2, #1
	bne _08042B42
	ldrb r0, [r3]
	b _08042B3C
_08042B3A:
	ldrb r0, [r1]
_08042B3C:
	adds r0, r7, r0
	strh r0, [r4]
	adds r4, #2
_08042B42:
	adds r2, #1
	cmp r2, #1
	bls _08042B2A
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
