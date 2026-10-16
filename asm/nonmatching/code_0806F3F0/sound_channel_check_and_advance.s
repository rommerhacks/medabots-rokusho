	.syntax unified

	thumb_func_start sound_channel_check_and_advance
sound_channel_check_and_advance: @ 0x08072338
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x5d
	ldrb r1, [r0]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	bhs _0807234A
	movs r0, #0
	b _08072358
_0807234A:
	adds r0, r4, #0
	bl sound_channel_parse_note_param
	adds r0, r4, #0
	bl sound_channel_tick_decay
	movs r0, #1
_08072358:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
