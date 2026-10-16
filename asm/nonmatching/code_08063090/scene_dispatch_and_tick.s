	.syntax unified

	thumb_func_start scene_dispatch_and_tick
scene_dispatch_and_tick: @ 0x08064844
	push {r4, lr}
	sub sp, #0x10
	mov r1, sp
	ldr r0, _08064880 @ =0x080AFAD0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08064884 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _08064888 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08064876
	ldr r1, _0806488C @ =0x03001C04
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08064876:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064880: .4byte 0x080AFAD0
_08064884: .4byte 0x0300137C
_08064888: .4byte 0x03001780
_0806488C: .4byte 0x03001C04
	.syntax divided
