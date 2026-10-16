	.syntax unified

	thumb_func_start prebattle_intro_state_handler
prebattle_intro_state_handler: @ 0x08010264
	push {lr}
	sub sp, #4
	ldr r0, _080102A4 @ =0x03000430
	ldr r0, [r0]
	cmp r0, #2
	bne _0801028C
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	ldr r1, _080102A8 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _080102AC @ =0x03002414
	ldr r0, [r0]
	ldr r2, _080102B0 @ =0x00000B84
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _080102B4 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0801028C:
	ldr r1, _080102B8 @ =0x083ACCA4
	ldr r0, _080102BC @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080102A4: .4byte 0x03000430
_080102A8: .4byte 0x040000D4
_080102AC: .4byte 0x03002414
_080102B0: .4byte 0x00000B84
_080102B4: .4byte 0x85000100
_080102B8: .4byte 0x083ACCA4
_080102BC: .4byte 0x0300137C
	.syntax divided
