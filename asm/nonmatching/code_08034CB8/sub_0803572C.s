	.syntax unified

	thumb_func_start sub_0803572C
	.global sub_0803572C
sub_0803572C: @ 0x0803572C
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, r1
	bge _08035738
	movs r0, #0
	b _0803573A
_08035738:
	subs r0, r0, r1
_0803573A:
	strb r0, [r2]
	bx lr
	.align 2, 0
	.syntax divided
