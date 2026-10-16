	.syntax unified

	thumb_func_start sub_0806F3F0
sub_0806F3F0: @ 0x0806F3F0
	push {lr}
	bl battle_transition_fade_step
	cmp r0, #0
	beq _0806F410
	bl sub_0806FF50
	bl sub_0806FF90
	ldr r1, _0806F414 @ =0x03001800
	movs r0, #0
	str r0, [r1, #8]
	movs r0, #7
	strh r0, [r1, #4]
	movs r0, #0xe
	strh r0, [r1, #0xc]
_0806F410:
	pop {r0}
	bx r0
	.align 2, 0
_0806F414: .4byte 0x03001800
	.syntax divided
