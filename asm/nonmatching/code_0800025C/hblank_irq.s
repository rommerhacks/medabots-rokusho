	.syntax unified

	thumb_func_start hblank_irq
hblank_irq: @ 0x08000824
	push {lr}
	ldr r0, _08000838 @ =0x03002C20
	ldr r0, [r0]
	bl _call_via_r0
	ldr r1, _0800083C @ =0x04000202
	movs r0, #2
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08000838: .4byte 0x03002C20
_0800083C: .4byte 0x04000202

	.syntax divided
