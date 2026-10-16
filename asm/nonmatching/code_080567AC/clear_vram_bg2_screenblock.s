	.syntax unified

	thumb_func_start clear_vram_bg2_screenblock
clear_vram_bg2_screenblock: @ 0x08059DCC
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, _08059DFC @ =0x06008400
	ldr r2, _08059E00 @ =0x01000F00
	mov r0, sp
	bl CpuFastSet
	ldr r1, _08059E04 @ =0x0400000C
	ldr r0, _08059E08 @ =0x00001608
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08059DFC: .4byte 0x06008400
_08059E00: .4byte 0x01000F00
_08059E04: .4byte 0x0400000C
_08059E08: .4byte 0x00001608
	.syntax divided
