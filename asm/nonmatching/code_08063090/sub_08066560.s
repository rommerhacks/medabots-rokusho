	.syntax unified

	thumb_func_start sub_08066560
sub_08066560: @ 0x08066560
	push {lr}
	bl poll_choice_menu
	cmp r0, #0
	beq _08066576
	ldr r1, _0806657C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bl sub_0803FB0C
_08066576:
	pop {r0}
	bx r0
	.align 2, 0
_0806657C: .4byte 0x0300137C
	.syntax divided
