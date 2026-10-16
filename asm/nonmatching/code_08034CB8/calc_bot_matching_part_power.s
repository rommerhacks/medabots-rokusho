	.syntax unified

	thumb_func_start calc_bot_matching_part_power
calc_bot_matching_part_power: @ 0x0803576C
	push {r4, r5, lr}
	movs r4, #0
	movs r3, #0
	ldr r1, _08035798 @ =0x03000590
	lsls r0, r0, #8
	adds r2, r0, r1
	ldrb r5, [r2, #4]
	adds r1, #0x48
	adds r1, r0, r1
_0803577E:
	ldrb r0, [r1]
	cmp r5, r0
	bne _08035788
	ldrb r0, [r2, #7]
	adds r4, r4, r0
_08035788:
	adds r1, #0x18
	adds r3, #1
	cmp r3, #3
	bls _0803577E
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08035798: .4byte 0x03000590
	.syntax divided
