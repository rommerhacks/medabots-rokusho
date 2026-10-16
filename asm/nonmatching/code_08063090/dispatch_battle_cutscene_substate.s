	.syntax unified

	thumb_func_start dispatch_battle_cutscene_substate
dispatch_battle_cutscene_substate: @ 0x08065B7C
	push {r4, lr}
	sub sp, #0x20
	mov r1, sp
	ldr r0, _08065BA8 @ =0x080AFB10
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	ldr r0, _08065BAC @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08065BA8: .4byte 0x080AFB10
_08065BAC: .4byte 0x0300137C
	.syntax divided
