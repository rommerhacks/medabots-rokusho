	.syntax unified

	thumb_func_start sub_080347BC
sub_080347BC: @ 0x080347BC
	push {r4, lr}
	movs r3, #0
	ldr r4, _080347F0 @ =0x030018EC
	ldr r1, _080347F4 @ =0x03000590
	adds r0, r4, #0
	subs r0, #0x65
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, #0x4c
	adds r2, r0, r1
_080347D0:
	ldrb r0, [r2]
	ldrb r1, [r2, #0xd]
	subs r0, r0, r1
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r2, #0x18
	adds r3, #1
	cmp r3, #3
	bls _080347D0
	bl sub_08034F08
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080347F0: .4byte 0x030018EC
_080347F4: .4byte 0x03000590
	.syntax divided
