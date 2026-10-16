	.syntax unified

	thumb_func_start sub_080039E0
sub_080039E0: @ 0x080039E0
	push {lr}
	sub sp, #4
	bl sub_0803EED8
	cmp r0, #0
	bne _08003A1A
	ldr r0, _08003A20 @ =0x03000430
	ldr r0, [r0]
	cmp r0, #2
	bne _08003A0A
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	ldr r0, _08003A24 @ =0x03002414
	ldr r1, [r0]
	ldr r0, _08003A28 @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _08003A2C @ =0x01000100
	mov r0, sp
	bl CpuFastSet
_08003A0A:
	ldr r1, _08003A30 @ =0x083AC320
	ldr r0, _08003A34 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_08003A1A:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08003A20: .4byte 0x03000430
_08003A24: .4byte 0x03002414
_08003A28: .4byte 0x00000B84
_08003A2C: .4byte 0x01000100
_08003A30: .4byte 0x083AC320
_08003A34: .4byte 0x0300137C
	.syntax divided
