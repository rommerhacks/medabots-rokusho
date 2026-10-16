	.syntax unified

	thumb_func_start dispatch_scene_substate_and_scroll
dispatch_scene_substate_and_scroll: @ 0x08067A08
	push {r4, lr}
	sub sp, #0x1c
	mov r1, sp
	ldr r0, _08067A3C @ =0x080AFEA8
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08067A40 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	ldr r1, _08067A44 @ =0x0300057C
	ldrh r0, [r1, #2]
	subs r0, #1
	strh r0, [r1, #2]
	add sp, #0x1c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08067A3C: .4byte 0x080AFEA8
_08067A40: .4byte 0x0300137C
_08067A44: .4byte 0x0300057C
	.syntax divided
