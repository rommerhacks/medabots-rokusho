	.syntax unified

	thumb_func_start sub_0806F78C
sub_0806F78C: @ 0x0806F78C
	push {lr}
	bl battle_transition_fade_step
	cmp r0, #0
	beq _0806F7A4
	ldr r1, _0806F7A8 @ =0x03001800
	movs r0, #0
	str r0, [r1, #8]
	movs r0, #0xa
	strh r0, [r1, #4]
	movs r0, #0x11
	strh r0, [r1, #0xc]
_0806F7A4:
	pop {r0}
	bx r0
	.align 2, 0
_0806F7A8: .4byte 0x03001800
	.syntax divided
