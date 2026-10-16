	.syntax unified

	thumb_func_start sub_08045A40
sub_08045A40: @ 0x08045A40
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0x40
	rsbs r0, r0, #0
	cmp r2, r0
	ble _08045A5C
	adds r0, #0x20
	cmp r1, r0
	ble _08045A5C
	cmp r2, #0x9f
	bgt _08045A5C
	cmp r1, #0xef
	bgt _08045A5C
	movs r3, #1
_08045A5C:
	adds r0, r3, #0
	bx lr
	.syntax divided
