	.syntax unified

	thumb_func_start dispatch_substate_handler
dispatch_substate_handler: @ 0x08062874
	push {r4, lr}
	sub sp, #0x1c
	mov r1, sp
	ldr r0, _080628A0 @ =0x080AFA20
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _080628A4 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	add sp, #0x1c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080628A0: .4byte 0x080AFA20
_080628A4: .4byte 0x0300137C
	.syntax divided
