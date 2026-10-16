	.syntax unified

	thumb_func_start sub_080039BC
sub_080039BC: @ 0x080039BC
	ldr r0, _080039D8 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080039D6
	ldr r0, _080039DC @ =0x03001C04
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_080039D6:
	bx lr
	.align 2, 0
_080039D8: .4byte 0x03001780
_080039DC: .4byte 0x03001C04
	.syntax divided
