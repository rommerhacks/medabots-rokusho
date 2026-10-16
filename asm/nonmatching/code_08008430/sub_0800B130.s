	.syntax unified

	thumb_func_start sub_0800B130
sub_0800B130: @ 0x0800B130
	push {r4, r5, lr}
	ldr r5, _0800B170 @ =0x03000440
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4]
	adds r1, r0, #1
	strh r1, [r4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb4
	bls _0800B16A
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0800B16A
	bl sub_0800B0F8
	adds r1, r5, #0
	adds r1, #0x3f
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _0800B16A
	movs r0, #0
	strh r0, [r4]
	strb r0, [r1]
_0800B16A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800B170: .4byte 0x03000440
	.syntax divided
