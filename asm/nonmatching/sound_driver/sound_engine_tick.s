	.syntax unified

	thumb_func_start sound_engine_tick
	.global sound_engine_tick
sound_engine_tick: @ 0x080730FC
	push {r4, lr}
	ldr r4, _08073138 @ =0x03007014
	ldr r1, [r4]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08073132
	adds r2, r1, r2
	ldrh r1, [r2]
	ldr r0, _0807313C @ =0x0000FFFE
	cmp r1, r0
	bhi _0807311C
	adds r0, r1, #1
	strh r0, [r2]
_0807311C:
	bl sound_engine_update_all_channels
	ldr r0, [r4]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08073132
	subs r0, #1
	strh r0, [r1]
_08073132:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073138: .4byte 0x03007014
_0807313C: .4byte 0x0000FFFE
	.syntax divided
