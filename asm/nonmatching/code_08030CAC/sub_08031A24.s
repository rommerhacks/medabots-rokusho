	.syntax unified

	thumb_func_start sub_08031A24
sub_08031A24: @ 0x08031A24
	push {lr}
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	ldr r1, _08031A38 @ =0x0300137C
	movs r0, #0x51
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08031A38: .4byte 0x0300137C
	.syntax divided
