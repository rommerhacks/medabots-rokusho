	.syntax unified

	thumb_func_start sub_0800801C
sub_0800801C: @ 0x0800801C
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	ldr r0, _08008048 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #8
	bl sub_08041C14
	bl update_blend_effect
	cmp r0, #0
	beq _08008042
	ldr r1, _0800804C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08008042:
	pop {r0}
	bx r0
	.align 2, 0
_08008048: .4byte 0x03001780
_0800804C: .4byte 0x0300137C
	.syntax divided
