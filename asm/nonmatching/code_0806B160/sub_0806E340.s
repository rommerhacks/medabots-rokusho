	.syntax unified

	thumb_func_start sub_0806E340
sub_0806E340: @ 0x0806E340
	push {lr}
	bl blend_fade_step_0806E2F8
	cmp r0, #0
	beq _0806E362
	ldr r1, _0806E368 @ =0x03001800
	movs r0, #0
	str r0, [r1, #8]
	ldr r2, _0806E36C @ =0x0300178C
	ldrh r0, [r1]
	str r0, [r2]
	ldr r2, _0806E370 @ =0x03002B8C
	ldrh r0, [r1, #2]
	str r0, [r2]
	ldr r2, _0806E374 @ =0x0300137C
	ldrh r0, [r1, #4]
	str r0, [r2]
_0806E362:
	pop {r0}
	bx r0
	.align 2, 0
_0806E368: .4byte 0x03001800
_0806E36C: .4byte 0x0300178C
_0806E370: .4byte 0x03002B8C
_0806E374: .4byte 0x0300137C
	.syntax divided
