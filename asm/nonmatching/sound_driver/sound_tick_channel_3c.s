	.syntax unified

	thumb_func_start sound_tick_channel_3c
sound_tick_channel_3c: @ 0x08074770
	push {lr}
	ldr r0, _08074790 @ =0x03007014
	ldr r1, [r0]
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _0807478C
	movs r2, #0xae
	lsls r2, r2, #3
	adds r0, r1, r2
	bl sound_update_channel_3
_0807478C:
	pop {r0}
	bx r0
	.align 2, 0
_08074790: .4byte 0x03007014
	.syntax divided
