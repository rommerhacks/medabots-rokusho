	.syntax unified

	thumb_func_start sub_0805F8B0
sub_0805F8B0: @ 0x0805F8B0
	push {lr}
	ldr r0, _0805F8E4 @ =0x08485788
	ldr r0, [r0, #0x10]
	bl run_message
	cmp r0, #0
	beq _0805F8DE
	movs r0, #0
	bl play_song
	movs r0, #0
	bl play_sound_effect
	bl get_medal_count_or_status
	ldr r0, _0805F8E8 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #2]
	ldr r1, _0805F8EC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805F8DE:
	pop {r0}
	bx r0
	.align 2, 0
_0805F8E4: .4byte 0x08485788
_0805F8E8: .4byte 0x03006F74
_0805F8EC: .4byte 0x0300137C
	.syntax divided
