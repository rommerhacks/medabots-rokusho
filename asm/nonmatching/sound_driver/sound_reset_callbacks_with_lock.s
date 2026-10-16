	.syntax unified

	thumb_func_start sound_reset_callbacks_with_lock
sound_reset_callbacks_with_lock: @ 0x08074D94
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08074DCC @ =0x03007014
	ldr r0, [r5]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r3, r0, r2
	ldrh r2, [r3]
	ldr r0, _08074DD0 @ =0x0000FFFE
	cmp r2, r0
	bhi _08074DAE
	adds r0, r2, #1
	strh r0, [r3]
_08074DAE:
	adds r0, r4, #0
	bl sound_reset_channel_callbacks
	ldr r0, [r5]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08074DC6
	subs r0, #1
	strh r0, [r1]
_08074DC6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08074DCC: .4byte 0x03007014
_08074DD0: .4byte 0x0000FFFE
	.syntax divided
