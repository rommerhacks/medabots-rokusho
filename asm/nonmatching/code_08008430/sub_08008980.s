	.syntax unified

	thumb_func_start sub_08008980
sub_08008980: @ 0x08008980
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	bl sub_0800B130
	bl update_blend_effect
	cmp r0, #0
	beq _0800899E
	ldr r1, _080089A4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800899E:
	pop {r0}
	bx r0
	.align 2, 0
_080089A4: .4byte 0x0300137C
	.syntax divided
