	.syntax unified

	thumb_func_start sub_0806DFC4
sub_0806DFC4: @ 0x0806DFC4
	push {lr}
	bl scene_transition_step_080686F4
	cmp r0, #0
	beq _0806DFE2
	ldr r2, _0806DFE8 @ =0x0300178C
	ldr r1, _0806DFEC @ =0x03001800
	ldrh r0, [r1]
	str r0, [r2]
	ldr r2, _0806DFF0 @ =0x03002B8C
	ldrh r0, [r1, #2]
	str r0, [r2]
	ldr r2, _0806DFF4 @ =0x0300137C
	ldrh r0, [r1, #4]
	str r0, [r2]
_0806DFE2:
	pop {r0}
	bx r0
	.align 2, 0
_0806DFE8: .4byte 0x0300178C
_0806DFEC: .4byte 0x03001800
_0806DFF0: .4byte 0x03002B8C
_0806DFF4: .4byte 0x0300137C
	.syntax divided
