	.syntax unified

	thumb_func_start sound_update_with_lock
sound_update_with_lock: @ 0x08074B28
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _08074B60 @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, _08074B64 @ =0x0000FFFE
	cmp r1, r0
	bhi _08074B42
	adds r0, r1, #1
	strh r0, [r2]
_08074B42:
	adds r0, r3, #0
	bl set_all_sound_channels_flag_0x40
	ldr r0, [r4]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08074B5A
	subs r0, #1
	strh r0, [r1]
_08074B5A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074B60: .4byte 0x03007014
_08074B64: .4byte 0x0000FFFE
	.syntax divided
