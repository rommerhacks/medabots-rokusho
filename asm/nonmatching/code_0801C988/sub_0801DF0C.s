	.syntax unified

	thumb_func_start sub_0801DF0C
sub_0801DF0C: @ 0x0801DF0C
	push {r4, lr}
	sub sp, #8
	ldr r0, _0801DF48 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	str r1, [sp]
	ldr r1, _0801DF4C @ =0x05000120
	ldr r4, _0801DF50 @ =0x01000008
	mov r0, sp
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0801DF54 @ =0x11111111
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r1, _0801DF58 @ =0x06004120
	adds r2, r4, #0
	bl CpuFastSet
	ldr r1, _0801DF5C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DF48: .4byte 0x03000440
_0801DF4C: .4byte 0x05000120
_0801DF50: .4byte 0x01000008
_0801DF54: .4byte 0x11111111
_0801DF58: .4byte 0x06004120
_0801DF5C: .4byte 0x03001800
	.syntax divided
