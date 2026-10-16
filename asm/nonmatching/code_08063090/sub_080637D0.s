	.syntax unified

	thumb_func_start sub_080637D0
sub_080637D0: @ 0x080637D0
	push {lr}
	sub sp, #0x38
	ldr r1, _0806382C @ =0x080AFA6C
	mov r0, sp
	movs r2, #0x34
	bl memcpy_optimized
	ldr r0, _08063830 @ =0x03000430
	ldr r0, [r0]
	cmp r0, #2
	bne _080637FC
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x34]
	add r0, sp, #0x34
	ldr r1, _08063834 @ =0x03002414
	ldr r1, [r1]
	ldr r2, _08063838 @ =0x00000B84
	adds r1, r1, r2
	ldr r2, _0806383C @ =0x01000100
	bl CpuFastSet
_080637FC:
	ldr r0, _08063840 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _08063844 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08063824
	ldr r0, _08063848 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_08063824:
	add sp, #0x38
	pop {r0}
	bx r0
	.align 2, 0
_0806382C: .4byte 0x080AFA6C
_08063830: .4byte 0x03000430
_08063834: .4byte 0x03002414
_08063838: .4byte 0x00000B84
_0806383C: .4byte 0x01000100
_08063840: .4byte 0x0300137C
_08063844: .4byte 0x03001780
_08063848: .4byte 0x03001C04
	.syntax divided
