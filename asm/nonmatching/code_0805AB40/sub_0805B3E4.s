	.syntax unified

	thumb_func_start sub_0805B3E4
sub_0805B3E4: @ 0x0805B3E4
	lsls r0, r0, #1
	ldr r3, _0805B408 @ =0x0600B000
	adds r0, r0, r3
	lsls r1, r1, #6
	adds r1, r0, r1
	movs r0, #0
	cmp r0, r2
	bge _0805B404
	movs r3, #0
_0805B3F6:
	strh r3, [r1]
	adds r1, #2
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r2
	blt _0805B3F6
_0805B404:
	bx lr
	.align 2, 0
_0805B408: .4byte 0x0600B000
	.syntax divided
