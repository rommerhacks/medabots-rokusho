	.syntax unified

	thumb_func_start sub_08035740
	.global sub_08035740
sub_08035740: @ 0x08035740
	adds r3, r0, #0
	ldrb r0, [r3]
	adds r0, r0, r1
	cmp r0, r2
	bls _0803574E
	strb r2, [r3]
	b _08035750
_0803574E:
	strb r0, [r3]
_08035750:
	bx lr
	.align 2, 0
	.syntax divided
