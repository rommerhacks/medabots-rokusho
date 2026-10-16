	.syntax unified

	thumb_func_start sub_0801D434
sub_0801D434: @ 0x0801D434
	push {lr}
	ldr r0, _0801D450 @ =0x084E3038
	ldr r1, _0801D454 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0801D458 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801D450: .4byte 0x084E3038
_0801D454: .4byte 0x050002C0
_0801D458: .4byte 0x03001800
	.syntax divided
