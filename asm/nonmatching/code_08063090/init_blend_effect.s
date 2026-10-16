	.syntax unified

	thumb_func_start init_blend_effect
	.global init_blend_effect
init_blend_effect: @ 0x08065564
	push {r4, r5, lr}
	ldr r4, [sp, #0xc]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r5, #0
	strh r4, [r0]
	strb r1, [r0, #2]
	strb r2, [r0, #3]
	strb r3, [r0, #5]
	ldr r2, _08065590 @ =0x04000050
	movs r1, #0x3f
	orrs r4, r1
	strh r4, [r2]
	ldr r1, _08065594 @ =0x04000052
	strh r5, [r1]
	adds r1, #2
	ldrb r0, [r0, #2]
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065590: .4byte 0x04000050
_08065594: .4byte 0x04000052
	.syntax divided
