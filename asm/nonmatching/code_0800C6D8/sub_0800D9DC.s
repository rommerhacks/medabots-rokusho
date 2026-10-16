	.syntax unified

	thumb_func_start sub_0800D9DC
sub_0800D9DC: @ 0x0800D9DC
	push {lr}
	sub sp, #4
	bl sub_0803EED8
	cmp r0, #0
	bne _0800DA16
	ldr r0, _0800DA1C @ =0x03000430
	ldr r0, [r0]
	cmp r0, #2
	bne _0800DA06
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	ldr r0, _0800DA20 @ =0x03002414
	ldr r1, [r0]
	ldr r0, _0800DA24 @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _0800DA28 @ =0x01000100
	mov r0, sp
	bl CpuFastSet
_0800DA06:
	ldr r1, _0800DA2C @ =0x083ACB54
	ldr r0, _0800DA30 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0800DA16:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0800DA1C: .4byte 0x03000430
_0800DA20: .4byte 0x03002414
_0800DA24: .4byte 0x00000B84
_0800DA28: .4byte 0x01000100
_0800DA2C: .4byte 0x083ACB54
_0800DA30: .4byte 0x0300137C
	.syntax divided
