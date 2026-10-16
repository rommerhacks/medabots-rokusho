	.syntax unified

	thumb_func_start update_blend_effect
	.global update_blend_effect
update_blend_effect: @ 0x080425DC
	push {r4, r5, r6, lr}
	ldr r2, _08042608 @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x94
	adds r0, r2, #0
	adds r0, #0x92
	ldrh r0, [r0]
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x90
	ldrb r0, [r0]
	subs r0, #1
	mov ip, r2
	cmp r0, #5
	bhi _08042646
	lsls r0, r0, #2
	ldr r1, _0804260C @ =_08042610
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08042608: .4byte 0x03000440
_0804260C: .4byte _08042610
_08042610: @ jump table
	.4byte _08042628 @ case 0
	.4byte _0804263A @ case 1
	.4byte _08042628 @ case 2
	.4byte _0804263A @ case 3
	.4byte _08042628 @ case 4
	.4byte _0804263A @ case 5
_08042628:
	mov r0, ip
	adds r0, #0x94
	ldrh r1, [r0]
	lsrs r1, r1, #4
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b _08042642
_0804263A:
	mov r0, ip
	adds r0, #0x94
	ldrh r0, [r0]
	lsrs r3, r0, #4
_08042642:
	adds r4, r3, #0
	adds r5, r3, #0
_08042646:
	ldr r2, _08042668 @ =0x04000052
	movs r1, #0x1f
	ands r4, r1
	lsls r0, r4, #8
	ands r3, r1
	orrs r0, r3
	strh r0, [r2]
	ldr r0, _0804266C @ =0x04000054
	ands r5, r1
	strh r5, [r0]
	mov r0, ip
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0xff
	bhi _08042670
	movs r0, #0
	b _08042672
	.align 2, 0
_08042668: .4byte 0x04000052
_0804266C: .4byte 0x04000054
_08042670:
	movs r0, #1
_08042672:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
