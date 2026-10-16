	.syntax unified

	thumb_func_start dispatch_battle_end_substate
dispatch_battle_end_substate: @ 0x0806826C
	push {r4, lr}
	sub sp, #0x1c
	mov r1, sp
	ldr r0, _080682A0 @ =0x080AFEC4
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _080682A4 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	ldr r1, _080682A8 @ =0x0300057C
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	add sp, #0x1c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080682A0: .4byte 0x080AFEC4
_080682A4: .4byte 0x0300137C
_080682A8: .4byte 0x0300057C
	.syntax divided
