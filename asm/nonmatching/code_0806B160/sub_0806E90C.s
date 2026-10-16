	.syntax unified

	thumb_func_start sub_0806E90C
sub_0806E90C: @ 0x0806E90C
	push {lr}
	bl sub_0806E854
	ldr r1, _0806E92C @ =0x08485F68
	ldr r0, _0806E930 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	bl sub_0806E8C8
	pop {r0}
	bx r0
	.align 2, 0
_0806E92C: .4byte 0x08485F68
_0806E930: .4byte 0x0300137C
	.syntax divided
