	.syntax unified

	thumb_func_start sub_0806F094
sub_0806F094: @ 0x0806F094
	push {lr}
	bl battle_transition_fade_step
	cmp r0, #0
	beq _0806F0AC
	ldr r1, _0806F0B0 @ =0x03001800
	movs r0, #0
	str r0, [r1, #8]
	movs r0, #7
	strh r0, [r1, #4]
	movs r0, #0xc
	strh r0, [r1, #0xc]
_0806F0AC:
	pop {r0}
	bx r0
	.align 2, 0
_0806F0B0: .4byte 0x03001800
	.syntax divided
