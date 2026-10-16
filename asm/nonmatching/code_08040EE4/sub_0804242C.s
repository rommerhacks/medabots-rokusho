	.syntax unified

	thumb_func_start sub_0804242C
	.global sub_0804242C
sub_0804242C: @ 0x0804242C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #1
	bls _080424A8
	subs r0, #1
	lsls r0, r0, #0x18
	b _080424A0
_08042444:
	movs r0, #0
	mov r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add r1, ip
	mov sb, r1
	cmp r8, ip
	bhs _0804249C
_08042454:
	mov r1, r8
	lsls r0, r1, #3
	ldr r1, _080424B4 @ =0x02023000
	adds r2, r0, r1
	adds r1, #8
	adds r3, r0, r1
	ldrh r7, [r3]
	ldrh r1, [r2]
	adds r0, r7, #0
	cmp r1, r0
	blo _08042478
	cmp r1, r0
	bne _08042494
	ldrh r1, [r2, #2]
	ldrh r0, [r3, #2]
	cmp r1, r0
	bhs _08042494
	ldrh r1, [r2]
_08042478:
	ldrh r4, [r2, #2]
	ldrh r5, [r2, #4]
	ldrh r6, [r2, #6]
	strh r7, [r2]
	ldrh r0, [r3, #2]
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	strh r0, [r2, #4]
	ldrh r0, [r3, #6]
	strh r0, [r2, #6]
	strh r1, [r3]
	strh r4, [r3, #2]
	strh r5, [r3, #4]
	strh r6, [r3, #6]
_08042494:
	movs r0, #1
	add r8, r0
	cmp r8, ip
	blo _08042454
_0804249C:
	mov r1, sb
	lsls r0, r1, #0x18
_080424A0:
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	bne _08042444
_080424A8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080424B4: .4byte 0x02023000
	.syntax divided
