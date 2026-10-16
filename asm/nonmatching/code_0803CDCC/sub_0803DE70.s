	.syntax unified

	thumb_func_start sub_0803DE70
sub_0803DE70: @ 0x0803DE70
	push {lr}
	bl sub_0803E894
	bl update_blend_effect
	cmp r0, #0
	beq _0803DE86
	ldr r1, _0803DE8C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DE86:
	pop {r0}
	bx r0
	.align 2, 0
_0803DE8C: .4byte 0x0300137C
	.syntax divided
