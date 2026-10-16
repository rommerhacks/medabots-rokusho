	.syntax unified

	thumb_func_start sub_0801C32C
sub_0801C32C: @ 0x0801C32C
	push {r4, lr}
	ldr r0, _0801C354 @ =0x084E2EF8
	ldr r1, _0801C358 @ =0x05000300
	movs r2, #8
	bl CpuFastSet
	ldr r4, _0801C35C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08016370
	adds r4, #0x9c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C354: .4byte 0x084E2EF8
_0801C358: .4byte 0x05000300
_0801C35C: .4byte 0x03001800
	.syntax divided
