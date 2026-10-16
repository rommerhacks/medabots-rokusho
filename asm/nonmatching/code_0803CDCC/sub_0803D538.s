	.syntax unified

	thumb_func_start sub_0803D538
sub_0803D538: @ 0x0803D538
	push {r4, lr}
	sub sp, #4
	ldr r4, _0803D588 @ =0x0300137C
	ldr r0, [r4]
	subs r0, #0x10
	cmp r0, #0xf
	bls _0803D54E
	bl sub_0803EED8
	cmp r0, #0
	bne _0803D57E
_0803D54E:
	ldr r0, _0803D58C @ =0x03000430
	ldr r0, [r0]
	cmp r0, #2
	bne _0803D56C
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	ldr r0, _0803D590 @ =0x03002414
	ldr r1, [r0]
	ldr r0, _0803D594 @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _0803D598 @ =0x01000100
	mov r0, sp
	bl CpuFastSet
_0803D56C:
	bl sub_0803E780
	ldr r0, _0803D59C @ =0x083AFAF8
	ldr r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_0803D57E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D588: .4byte 0x0300137C
_0803D58C: .4byte 0x03000430
_0803D590: .4byte 0x03002414
_0803D594: .4byte 0x00000B84
_0803D598: .4byte 0x01000100
_0803D59C: .4byte 0x083AFAF8
	.syntax divided
