	.syntax unified

	thumb_func_start sub_0800B0F8
sub_0800B0F8: @ 0x0800B0F8
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r6, _0800B124 @ =0x0300047F
	ldr r5, _0800B128 @ =0x06007A00
_0800B100:
	lsls r0, r4, #8
	ldrb r1, [r6]
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, _0800B12C @ =0x084C3B14
	adds r0, r0, r1
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	adds r5, #0x20
	adds r4, #1
	cmp r4, #4
	bls _0800B100
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800B124: .4byte 0x0300047F
_0800B128: .4byte 0x06007A00
_0800B12C: .4byte 0x084C3B14
	.syntax divided
