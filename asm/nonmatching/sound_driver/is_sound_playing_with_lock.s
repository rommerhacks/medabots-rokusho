	.syntax unified

	thumb_func_start is_sound_playing_with_lock
	.global is_sound_playing_with_lock
is_sound_playing_with_lock: @ 0x08074E2C
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _08074E68 @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, _08074E6C @ =0x0000FFFE
	cmp r1, r0
	bhi _08074E46
	adds r0, r1, #1
	strh r0, [r2]
_08074E46:
	adds r0, r3, #0
	bl is_sound_playing_at_position
	adds r2, r0, #0
	ldr r0, [r4]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _08074E60
	subs r0, #1
	strh r0, [r1]
_08074E60:
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08074E68: .4byte 0x03007014
_08074E6C: .4byte 0x0000FFFE
	.syntax divided
