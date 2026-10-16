	.syntax unified

	thumb_func_start sub_0807068C
sub_0807068C: @ 0x0807068C
	ldr r0, _080706A4 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080706A0
	ldr r1, _080706A8 @ =0x03001C04
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
_080706A0:
	bx lr
	.align 2, 0
_080706A4: .4byte 0x03001780
_080706A8: .4byte 0x03001C04
	.syntax divided
