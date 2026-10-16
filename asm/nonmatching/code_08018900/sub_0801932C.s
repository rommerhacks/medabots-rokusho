	.syntax unified

	thumb_func_start sub_0801932C
sub_0801932C: @ 0x0801932C
	ldr r1, _08019344 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	cmp r0, #0x1f
	bls _08019340
	movs r0, #0x1f
	strb r0, [r1]
_08019340:
	bx lr
	.align 2, 0
_08019344: .4byte 0x03000590
	.syntax divided
