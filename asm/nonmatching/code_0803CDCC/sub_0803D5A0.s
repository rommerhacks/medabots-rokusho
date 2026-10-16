	.syntax unified

	thumb_func_start sub_0803D5A0
sub_0803D5A0: @ 0x0803D5A0
	push {r4, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	ldr r1, _0803D5D0 @ =0x03001800
	ldr r2, _0803D5D4 @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	ldr r0, _0803D5D8 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x86
	movs r1, #0
	strh r4, [r2]
	adds r0, #0x84
	strb r1, [r0]
	ldr r1, _0803D5DC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D5D0: .4byte 0x03001800
_0803D5D4: .4byte 0x01000100
_0803D5D8: .4byte 0x03000440
_0803D5DC: .4byte 0x0300137C
	.syntax divided
