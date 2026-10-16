	.syntax unified

	thumb_func_start init_window_params
init_window_params: @ 0x08041624
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r6, r0, #0
	mov r8, r1
	mov sb, r2
	adds r5, r3, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	mov r0, sb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r4, _08041670 @ =0x03000468
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0
	bl sub_0803F624
	strb r6, [r4, #2]
	strb r5, [r4, #3]
	mov r0, r8
	strb r0, [r4, #4]
	mov r0, sb
	strb r0, [r4, #5]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08041670: .4byte 0x03000468
	.syntax divided
