	.syntax unified

	thumb_func_start sub_0805DD60
sub_0805DD60: @ 0x0805DD60
	push {r4, r5, lr}
	movs r0, #4
	bl is_sound_playing_with_lock
	adds r1, r0, #0
	cmp r1, #0
	bne _0805DDA8
	movs r0, #0
	bl play_song
	movs r0, #0
	bl play_sound_effect
	ldr r0, _0805DD90 @ =0x03002B70
	movs r1, #0xfe
	movs r4, #0xf
	adds r0, #0x13
_0805DD82:
	strb r1, [r0]
	subs r0, #1
	subs r4, #1
	cmp r4, #0
	bge _0805DD82
	movs r4, #0
	b _0805DD96
	.align 2, 0
_0805DD90: .4byte 0x03002B70
_0805DD94:
	adds r4, #1
_0805DD96:
	cmp r4, #3
	bgt _0805DDA6
	movs r0, #1
	bl save_dispatch
	adds r5, r0, #0
	cmp r5, #0
	bne _0805DD94
_0805DDA6:
	adds r0, r5, #0
_0805DDA8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
