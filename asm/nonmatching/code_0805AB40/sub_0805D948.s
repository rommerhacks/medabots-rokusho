	.syntax unified

	thumb_func_start sub_0805D948
sub_0805D948: @ 0x0805D948
	push {lr}
	ldr r0, _0805D964 @ =0x08485788
	ldr r0, [r0, #0x24]
	bl run_message
	cmp r0, #0
	beq _0805D95E
	ldr r1, _0805D968 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805D95E:
	pop {r0}
	bx r0
	.align 2, 0
_0805D964: .4byte 0x08485788
_0805D968: .4byte 0x0300137C
	.syntax divided
