	.syntax unified

	thumb_func_start sub_08057024
sub_08057024: @ 0x08057024
	push {lr}
	ldr r1, _0805703C @ =0x083D5E08
	ldr r0, _08057040 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0805703C: .4byte 0x083D5E08
_08057040: .4byte 0x0300137C
	.syntax divided
