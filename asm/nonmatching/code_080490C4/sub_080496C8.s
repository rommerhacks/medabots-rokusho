	.syntax unified

	thumb_func_start sub_080496C8
	.global sub_080496C8
sub_080496C8: @ 0x080496C8
	movs r2, #0
	cmp r2, r1
	bhs _080496DA
	movs r3, #0
_080496D0:
	strb r3, [r0]
	adds r0, #1
	adds r2, #1
	cmp r2, r1
	blo _080496D0
_080496DA:
	bx lr
	.syntax divided
