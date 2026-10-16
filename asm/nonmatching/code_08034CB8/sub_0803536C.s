	.syntax unified

	thumb_func_start sub_0803536C
	.global sub_0803536C
sub_0803536C: @ 0x0803536C
	adds r3, r0, #0
	movs r0, #6
	ands r0, r1
	lsrs r0, r0, #1
	cmp r0, #1
	beq _0803538C
	cmp r0, #3
	beq _0803539C
	ldr r1, _08035388 @ =0x03002C30
	lsls r0, r3, #6
	adds r0, r0, r1
	strh r2, [r0, #2]
	b _080353A6
	.align 2, 0
_08035388: .4byte 0x03002C30
_0803538C:
	ldr r0, _08035398 @ =0x03002C30
	lsls r1, r3, #6
	adds r1, r1, r0
	adds r0, r2, #1
	b _080353A4
	.align 2, 0
_08035398: .4byte 0x03002C30
_0803539C:
	ldr r0, _080353A8 @ =0x03002C30
	lsls r1, r3, #6
	adds r1, r1, r0
	subs r0, r2, #1
_080353A4:
	strh r0, [r1, #2]
_080353A6:
	bx lr
	.align 2, 0
_080353A8: .4byte 0x03002C30
	.syntax divided
