	.syntax unified

	thumb_func_start sub_08065618
sub_08065618: @ 0x08065618
	push {r4, r5, lr}
	bl sub_08074B68
	ldr r4, _08065644 @ =0x03006F74
	ldr r1, [r4]
	adds r1, #0x7f
	movs r5, #0
	strb r0, [r1]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r0, [r4]
	str r5, [r0, #8]
	ldr r1, _08065648 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065644: .4byte 0x03006F74
_08065648: .4byte 0x0300137C
	.syntax divided
