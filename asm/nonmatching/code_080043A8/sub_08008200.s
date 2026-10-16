	.syntax unified

	thumb_func_start sub_08008200
sub_08008200: @ 0x08008200
	push {lr}
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	bl sub_080093F8
	bl sub_0800A180
	ldr r0, _0800822C @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #8
	bl sub_08041C14
	ldr r1, _08008230 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800822C: .4byte 0x03001780
_08008230: .4byte 0x0300137C
	.syntax divided
