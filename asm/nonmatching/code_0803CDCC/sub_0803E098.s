	.syntax unified

	thumb_func_start sub_0803E098
sub_0803E098: @ 0x0803E098
	push {lr}
	bl sub_0803E894
	bl sub_0803EC98
	cmp r0, #0
	beq _0803E0B6
	bl sub_0803ECF0
	bl sub_0803ED10
	ldr r1, _0803E0BC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E0B6:
	pop {r0}
	bx r0
	.align 2, 0
_0803E0BC: .4byte 0x0300137C
	.syntax divided
