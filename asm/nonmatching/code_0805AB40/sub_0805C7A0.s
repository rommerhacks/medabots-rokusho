	.syntax unified

	thumb_func_start sub_0805C7A0
sub_0805C7A0: @ 0x0805C7A0
	push {lr}
	movs r0, #0
	bl play_song
	movs r0, #0
	bl play_sound_effect
	bl get_medal_count_or_status
	movs r1, #0
	ldr r3, _0805C7DC @ =0x03002B74
	movs r2, #0xfe
_0805C7B8:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	adds r1, r0, r3
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	ble _0805C7B8
	ldr r1, _0805C7E0 @ =0x03002B8C
	movs r0, #0x1c
	str r0, [r1]
	ldr r1, _0805C7E4 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0805C7DC: .4byte 0x03002B74
_0805C7E0: .4byte 0x03002B8C
_0805C7E4: .4byte 0x0300137C
	.syntax divided
