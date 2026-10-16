	.syntax unified

	thumb_func_start sub_0801C188
sub_0801C188: @ 0x0801C188
	push {lr}
	ldr r0, _0801C1AC @ =0x084C8AC4
	ldr r1, _0801C1B0 @ =0x06014E00
	bl lz_decompress_dispatch
	ldr r0, _0801C1B4 @ =0x084E3078
	ldr r1, _0801C1B8 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0801C1BC @ =0x03001800
	adds r1, #0x9c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801C1AC: .4byte 0x084C8AC4
_0801C1B0: .4byte 0x06014E00
_0801C1B4: .4byte 0x084E3078
_0801C1B8: .4byte 0x050002C0
_0801C1BC: .4byte 0x03001800
	.syntax divided
