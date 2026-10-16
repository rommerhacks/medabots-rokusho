	.syntax unified

	thumb_func_start sub_08031438
sub_08031438: @ 0x08031438
	push {lr}
	movs r0, #0x21
	movs r1, #0
	bl advance_sprite_anim_frame
	cmp r0, #0
	beq _0803144E
	ldr r1, _08031454 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803144E:
	pop {r0}
	bx r0
	.align 2, 0
_08031454: .4byte 0x0300137C
	.syntax divided
