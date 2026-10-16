	.syntax unified

	thumb_func_start sub_08031518
sub_08031518: @ 0x08031518
	push {lr}
	movs r0, #0x22
	movs r1, #0
	bl medal_update_exp_progress
	cmp r0, #0
	beq _0803152E
	ldr r1, _08031534 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803152E:
	pop {r0}
	bx r0
	.align 2, 0
_08031534: .4byte 0x0300137C
	.syntax divided
