	.syntax unified

	thumb_func_start sub_0801E8DC
sub_0801E8DC: @ 0x0801E8DC
	push {lr}
	ldr r0, _0801E908 @ =0x0850E338
	ldr r1, _0801E90C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0xa
	bl sub_0803684C
	cmp r0, #0
	beq _0801E904
	ldr r0, _0801E910 @ =0x03000440
	adds r0, #0x86
	movs r1, #0xa
	strh r1, [r0]
	ldr r1, _0801E914 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801E904:
	pop {r0}
	bx r0
	.align 2, 0
_0801E908: .4byte 0x0850E338
_0801E90C: .4byte 0x050003C0
_0801E910: .4byte 0x03000440
_0801E914: .4byte 0x03001800
	.syntax divided
