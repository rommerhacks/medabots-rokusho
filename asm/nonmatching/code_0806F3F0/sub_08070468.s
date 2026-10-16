	.syntax unified

	thumb_func_start sub_08070468
sub_08070468: @ 0x08070468
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08070488 @ =0x03002C30
	lsls r1, r4, #6
	adds r2, r1, r0
	ldrb r3, [r2, #8]
	adds r5, r0, #0
	cmp r3, #0x3f
	bls _0807048C
	ldrb r0, [r2, #9]
	cmp r0, #0x3f
	bls _08070492
	movs r0, #0
	b _080704C8
	.align 2, 0
_08070488: .4byte 0x03002C30
_0807048C:
	ldrb r0, [r2, #9]
	cmp r0, #0x3f
	bhi _080704AA
_08070492:
	lsls r1, r4, #6
	adds r2, r1, r5
	ldrb r0, [r2, #9]
	adds r0, #8
	strb r0, [r2, #9]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _080704BC
	movs r0, #0x40
	strb r0, [r2, #9]
	b _080704BC
_080704AA:
	adds r0, r3, #0
	adds r0, #8
	strb r0, [r2, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _080704BC
	movs r0, #0x40
	strb r0, [r2, #8]
_080704BC:
	adds r1, r1, r5
	adds r1, #0x21
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
_080704C8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
