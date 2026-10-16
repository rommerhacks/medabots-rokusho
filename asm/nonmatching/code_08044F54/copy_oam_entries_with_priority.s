	.syntax unified

	thumb_func_start copy_oam_entries_with_priority
copy_oam_entries_with_priority: @ 0x080455E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	mov sl, r1
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov ip, r3
	movs r6, #0
	ldrb r1, [r5, #0xa]
	ldrb r0, [r5, #0xb]
	muls r1, r0, r1
	cmp r6, r1
	bge _08045670
	cmp r4, ip
	bhs _08045670
	ldrh r7, [r5, #8]
	adds r3, r7, #0
	movs r0, #0xd
	rsbs r0, r0, #0
	mov r8, r0
	ldr r5, [r5]
	mov sb, r5
	adds r5, r1, #0
_08045618:
	lsls r0, r4, #3
	mov r1, sl
	adds r2, r0, r1
	lsls r0, r6, #3
	add r0, sb
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	strh r7, [r2, #6]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r3, r0
	bls _0804563E
	ldrb r0, [r2, #5]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #5]
	b _0804565C
_0804563E:
	cmp r3, #0xc8
	bls _0804564C
	ldrb r0, [r2, #5]
	mov r1, r8
	ands r1, r0
	movs r0, #8
	b _08045658
_0804564C:
	cmp r3, #0x64
	bls _0804565C
	ldrb r0, [r2, #5]
	mov r1, r8
	ands r1, r0
	movs r0, #4
_08045658:
	orrs r1, r0
	strb r1, [r2, #5]
_0804565C:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r6, r5
	bge _08045670
	cmp r4, ip
	blo _08045618
_08045670:
	adds r0, r4, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
