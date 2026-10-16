	.syntax unified

	thumb_func_start play_song
	.global play_song
play_song: @ 0x08074A10
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _08074A4C @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, _08074A50 @ =0x0000FFFE
	cmp r1, r0
	bhi _08074A2A
	adds r0, r1, #1
	strh r0, [r2]
_08074A2A:
	adds r0, r3, #0
	movs r1, #0
	bl load_song_channels
	ldr r0, [r4]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08074A44
	subs r0, #1
	strh r0, [r1]
_08074A44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074A4C: .4byte 0x03007014
_08074A50: .4byte 0x0000FFFE
	.syntax divided
