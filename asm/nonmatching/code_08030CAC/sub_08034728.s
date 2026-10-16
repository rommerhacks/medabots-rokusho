	.syntax unified

	thumb_func_start sub_08034728
sub_08034728: @ 0x08034728
	push {r4, lr}
	movs r3, #0
	ldr r2, _08034764 @ =0x03000590
	ldr r1, _08034768 @ =0x03001887
	ldrb r0, [r1]
	adds r1, #0x65
	lsls r0, r0, #8
	adds r2, #0x4a
	adds r2, r0, r2
_0803473A:
	ldrb r0, [r2, #0xf]
	cmp r0, #0
	beq _08034752
	ldrb r0, [r2]
	cmp r0, #2
	beq _0803474A
	cmp r0, #3
	bne _08034752
_0803474A:
	ldrh r0, [r1]
	ldrb r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r1]
_08034752:
	adds r2, #0x18
	adds r3, #1
	cmp r3, #2
	bls _0803473A
	bl sub_08034F08
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034764: .4byte 0x03000590
_08034768: .4byte 0x03001887
	.syntax divided
