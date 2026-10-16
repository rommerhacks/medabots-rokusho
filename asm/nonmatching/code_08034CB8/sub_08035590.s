	.syntax unified

	thumb_func_start sub_08035590
sub_08035590: @ 0x08035590
	ldr r1, _080355C0 @ =0x03000590
	lsls r0, r0, #8
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0x71
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r2, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #0
	beq _080355AE
	adds r1, #3
_080355AE:
	adds r0, r2, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080355BA
	adds r1, #5
_080355BA:
	adds r0, r1, #0
	bx lr
	.align 2, 0
_080355C0: .4byte 0x03000590
	.syntax divided
