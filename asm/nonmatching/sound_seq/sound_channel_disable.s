	.syntax unified

	thumb_func_start sound_channel_disable
sound_channel_disable: @ 0x08072BB0
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x62
	movs r0, #0
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #2
	bgt _08072BD0
	cmp r0, #0
	blt _08072BD0
	adds r0, r1, #0
	bl sound_channel_handle_end
_08072BD0:
	pop {r0}
	bx r0
	.syntax divided
