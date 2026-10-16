	.syntax unified

	thumb_func_start sub_08053BB4
sub_08053BB4: @ 0x08053BB4
	push {lr}
	ldr r2, _08053BC4 @ =0x03005404
	adds r3, r2, #4
	bl get_state_float_as_int
	pop {r0}
	bx r0
	.align 2, 0
_08053BC4: .4byte 0x03005404
	.syntax divided
