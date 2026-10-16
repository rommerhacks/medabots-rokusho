	.syntax unified

	thumb_func_start sound_update_channel_at_6d8
	.global sound_update_channel_at_6d8
sound_update_channel_at_6d8: @ 0x08073F5C
	push {r4, lr}
	ldr r4, _08073F98 @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, _08073F9C @ =0x0000FFFE
	cmp r1, r0
	bhi _08073F74
	adds r0, r1, #1
	strh r0, [r2]
_08073F74:
	ldr r0, [r4]
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r0, r2
	bl sound_channel_update
	ldr r0, [r4]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08073F92
	subs r0, #1
	strh r0, [r1]
_08073F92:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073F98: .4byte 0x03007014
_08073F9C: .4byte 0x0000FFFE
	.syntax divided
