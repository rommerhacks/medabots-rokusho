	.syntax unified

	thumb_func_start sub_080358F0
sub_080358F0: @ 0x080358F0
	push {r4, lr}
	movs r2, #0
	ldr r1, _08035920 @ =0x03000590
	ldr r3, _08035924 @ =0x030018E8
	lsls r0, r0, #8
	adds r1, #0x49
	adds r1, r0, r1
_080358FE:
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _08035912
	ldrb r0, [r1]
	cmp r0, #0x35
	bne _08035912
	ldrh r0, [r3]
	ldrb r4, [r1, #4]
	adds r0, r0, r4
	strh r0, [r3]
_08035912:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #2
	bls _080358FE
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035920: .4byte 0x03000590
_08035924: .4byte 0x030018E8
	.syntax divided
