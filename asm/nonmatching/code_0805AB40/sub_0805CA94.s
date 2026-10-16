	.syntax unified

	thumb_func_start sub_0805CA94
sub_0805CA94: @ 0x0805CA94
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r0, _0805CAC8 @ =0x03006F74
	ldr r1, [r0]
	ldr r2, _0805CACC @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	bl sub_080415BC
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _0805CAD0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0805CAC8: .4byte 0x03006F74
_0805CACC: .4byte 0x01000100
_0805CAD0: .4byte 0x0300137C
	.syntax divided
