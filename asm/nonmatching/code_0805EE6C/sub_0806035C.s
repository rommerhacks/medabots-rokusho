	.syntax unified

	thumb_func_start sub_0806035C
sub_0806035C: @ 0x0806035C
	push {lr}
	bl sub_080600E0
	ldr r2, _0806037C @ =0x03006F74
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #0x20
	beq _08060384
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08060380 @ =0x04000054
	ldr r0, [r2]
	ldrb r0, [r0]
	lsrs r0, r0, #1
	strh r0, [r1]
	b _08060398
	.align 2, 0
_0806037C: .4byte 0x03006F74
_08060380: .4byte 0x04000054
_08060384:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0806039C @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080603A0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08060398:
	pop {r0}
	bx r0
	.align 2, 0
_0806039C: .4byte 0x0000FDFF
_080603A0: .4byte 0x0300137C
	.syntax divided
