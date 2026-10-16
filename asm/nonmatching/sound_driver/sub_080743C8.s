	.syntax unified

	thumb_func_start sub_080743C8
	.global sub_080743C8
sub_080743C8: @ 0x080743C8
	ldr r0, _080743DC @ =0x03007014
	ldr r0, [r0]
	ldr r1, _080743E0 @ =0x0000072C
	adds r0, r0, r1
	ldrb r0, [r0]
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	bx lr
	.align 2, 0
_080743DC: .4byte 0x03007014
_080743E0: .4byte 0x0000072C
	.syntax divided
