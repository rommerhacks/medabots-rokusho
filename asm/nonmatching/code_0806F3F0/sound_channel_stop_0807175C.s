	.syntax unified

	thumb_func_start sound_channel_stop_0807175C
sound_channel_stop_0807175C: @ 0x0807175C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	subs r2, #0x16
	movs r3, #0x80
	lsls r3, r3, #0x11
	lsls r3, r2
	lsrs r3, r3, #0x18
	ldr r4, _0807178C @ =0x03007010
	ldrb r2, [r4]
	bics r2, r3
	strb r2, [r4]
	ldr r2, _08071790 @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r2
	adds r3, r0, #0
	adds r3, #0x23
	movs r2, #0
	strb r2, [r3]
	strh r1, [r0, #6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807178C: .4byte 0x03007010
_08071790: .4byte 0x03002C30
	.syntax divided
