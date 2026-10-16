	.syntax unified

	thumb_func_start sub_080492CC
	.global sub_080492CC
sub_080492CC: @ 0x080492CC
	ldr r1, _080492F0 @ =0x03005310
	movs r0, #0
	strh r0, [r1, #0x18]
	strh r0, [r1, #0x1a]
	movs r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _080492F4 @ =0x03006D40
	movs r1, #0x1f
_080492DE:
	strh r2, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #4]
	adds r0, #0x10
	subs r1, #1
	cmp r1, #0
	bge _080492DE
	bx lr
	.align 2, 0
_080492F0: .4byte 0x03005310
_080492F4: .4byte 0x03006D40
	.syntax divided
