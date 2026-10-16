	.syntax unified

	thumb_func_start run_message
	.global run_message
run_message: @ 0x0803FB3C
	push {r4, lr}
	ldr r4, _0803FB5C @ =0x03000440
	str r0, [r4, #8]
	ldr r1, _0803FB60 @ =0x083B279C
	ldrb r0, [r4, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r4, #4]
	cmp r0, #7
	bhi _0803FB64
	movs r0, #0
	b _0803FB66
	.align 2, 0
_0803FB5C: .4byte 0x03000440
_0803FB60: .4byte 0x083B279C
_0803FB64:
	movs r0, #1
_0803FB66:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
