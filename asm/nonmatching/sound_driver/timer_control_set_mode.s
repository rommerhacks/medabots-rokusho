	.syntax unified

	thumb_func_start timer_control_set_mode
timer_control_set_mode: @ 0x080739B4
	push {r4, lr}
	ldr r1, _080739E4 @ =0x084873C8
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldrh r2, [r3]
	ldr r1, _080739E8 @ =0x0000499F
	adds r0, r1, #0
	ands r0, r2
	ldr r4, _080739EC @ =0x00008440
	adds r2, r4, #0
	orrs r0, r2
	strh r0, [r3]
	ldrh r0, [r3]
	ands r1, r0
	movs r2, #0x88
	lsls r2, r2, #3
	adds r0, r2, #0
	orrs r1, r0
	strh r1, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080739E4: .4byte 0x084873C8
_080739E8: .4byte 0x0000499F
_080739EC: .4byte 0x00008440
	.syntax divided
