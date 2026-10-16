	.syntax unified

	thumb_func_start sub_08071614
sub_08071614: @ 0x08071614
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #0
	ldr r0, _08071658 @ =0x08486118
	mov r8, r0
_08071620:
	ldr r0, _0807165C @ =0x03002C30
	lsls r1, r6, #6
	adds r4, r1, r0
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r0, [r5]
	cmp r0, #0
	beq _08071676
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	movs r7, #0
	strh r0, [r4, #0x1a]
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	cmp r0, #1
	beq _08071676
	cmp r0, #1
	bgt _08071660
	cmp r0, #0
	beq _08071666
	b _08071676
	.align 2, 0
_08071658: .4byte 0x08486118
_0807165C: .4byte 0x03002C30
_08071660:
	cmp r0, #0xff
	beq _08071670
	b _08071676
_08071666:
	strb r7, [r5]
	adds r0, r4, #0
	adds r0, #0x21
	strb r7, [r0]
	b _08071676
_08071670:
	adds r0, r6, #0
	bl sub_0806B584
_08071676:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x19
	bls _08071620
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
