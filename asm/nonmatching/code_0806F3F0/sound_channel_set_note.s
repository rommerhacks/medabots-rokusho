	.syntax unified

	thumb_func_start sound_channel_set_note
sound_channel_set_note: @ 0x08071720
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r0, #0
	subs r4, #0x16
	movs r3, #0x80
	lsls r3, r3, #0x11
	lsls r3, r4
	lsrs r3, r3, #0x18
	ldr r5, _08071754 @ =0x03007010
	ldrb r4, [r5]
	orrs r3, r4
	strb r3, [r5]
	ldr r3, _08071758 @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r3, r0, #0
	adds r3, #0x23
	strb r2, [r3]
	strh r1, [r0, #0x30]
	strh r1, [r0, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08071754: .4byte 0x03007010
_08071758: .4byte 0x03002C30
	.syntax divided
