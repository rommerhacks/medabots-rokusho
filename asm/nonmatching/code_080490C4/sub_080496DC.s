	.syntax unified

	thumb_func_start sub_080496DC
sub_080496DC: @ 0x080496DC
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #0
	cmp r3, r1
	bhs _080496F0
_080496E6:
	strb r2, [r0]
	adds r0, #1
	adds r3, #1
	cmp r3, r1
	blo _080496E6
_080496F0:
	bx lr
	.align 2, 0
	.syntax divided
