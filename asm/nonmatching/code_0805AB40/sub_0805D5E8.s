	.syntax unified

	thumb_func_start sub_0805D5E8
sub_0805D5E8: @ 0x0805D5E8
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r0, _0805D61C @ =0x03006F74
	ldr r1, [r0]
	ldr r2, _0805D620 @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	bl sub_080415BC
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _0805D624 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0805D61C: .4byte 0x03006F74
_0805D620: .4byte 0x01000100
_0805D624: .4byte 0x0300137C
	.syntax divided
