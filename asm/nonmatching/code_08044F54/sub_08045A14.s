	.syntax unified

	thumb_func_start sub_08045A14
	.global sub_08045A14
sub_08045A14: @ 0x08045A14
	adds r2, r0, #0
	movs r3, #0x1f
_08045A18:
	ldrh r0, [r1]
	strh r0, [r2, #6]
	adds r1, #2
	adds r2, #8
	ldrh r0, [r1]
	strh r0, [r2, #6]
	adds r1, #2
	adds r2, #8
	ldrh r0, [r1]
	strh r0, [r2, #6]
	adds r1, #2
	adds r2, #8
	ldrh r0, [r1]
	strh r0, [r2, #6]
	adds r1, #2
	adds r2, #8
	subs r3, #1
	cmp r3, #0
	bge _08045A18
	bx lr
	.syntax divided
