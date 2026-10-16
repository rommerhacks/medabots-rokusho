	.syntax unified

	thumb_func_start sub_0800DF4C
sub_0800DF4C: @ 0x0800DF4C
	push {lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r1, _0800DF6C @ =0x03000430
	movs r0, #0
	str r0, [r1]
	ldr r1, _0800DF70 @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _0800DF74 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800DF6C: .4byte 0x03000430
_0800DF70: .4byte 0x03002B8C
_0800DF74: .4byte 0x0300137C
	.syntax divided
