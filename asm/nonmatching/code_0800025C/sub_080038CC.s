	.syntax unified

	thumb_func_start sub_080038CC
sub_080038CC: @ 0x080038CC
	push {lr}
	bl sub_080039BC
	bl update_blend_effect
	cmp r0, #0
	beq _080038E6
	bl sub_0800393C
	ldr r1, _080038EC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080038E6:
	pop {r0}
	bx r0
	.align 2, 0
_080038EC: .4byte 0x0300137C
	.syntax divided
