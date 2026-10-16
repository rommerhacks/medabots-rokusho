	.syntax unified

	thumb_func_start sub_0807255C
sub_0807255C: @ 0x0807255C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0x56
	ldrb r0, [r0]
	adds r1, r7, #0
	adds r1, #0x59
	movs r6, #0
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x57
	ldrb r0, [r0]
	lsrs r0, r0, #1
	movs r1, #0x5a
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	adds r5, r7, #0
	adds r5, #0x48
	ldrh r0, [r5]
	adds r0, #2
	bl sub_08073140
	adds r4, r0, #0
	ldrh r0, [r5]
	bl sub_08073140
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r4, r4, r0
	adds r0, r7, #0
	adds r0, #0x58
	ldrb r0, [r0]
	muls r0, r4, r0
	mov r2, r8
	ldrb r1, [r2]
	bl sub_0807CD58
	str r0, [r7, #0x34]
	str r6, [r7, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
