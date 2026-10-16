	.syntax unified

	thumb_func_start sub_08074E84
sub_08074E84: @ 0x08074E84
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r0, #0x40
	ldrh r0, [r0]
	subs r0, r5, r0
	adds r1, r6, #0
	bl sub_0807CBBC
	adds r1, r0, #0
	cmp r1, #0
	beq _08074EAA
	adds r0, r4, #0
	adds r0, #0x42
	strh r5, [r0]
	adds r0, #2
	strh r1, [r0]
	str r6, [r4, #0x3c]
_08074EAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
