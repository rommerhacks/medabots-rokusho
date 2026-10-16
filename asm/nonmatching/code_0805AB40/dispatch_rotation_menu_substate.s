	.syntax unified

	thumb_func_start dispatch_rotation_menu_substate
dispatch_rotation_menu_substate: @ 0x0805C9B8
	push {r4, lr}
	sub sp, #0x18
	mov r1, sp
	ldr r0, _0805C9E0 @ =0x080AF7A8
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, _0805C9E4 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	add sp, #0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C9E0: .4byte 0x080AF7A8
_0805C9E4: .4byte 0x0300137C
	.syntax divided
