	.syntax unified

	thumb_func_start sound_channel_request_stop
sound_channel_request_stop: @ 0x08073E20
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _08073E38
	adds r0, r4, #0
	bl sound_channel_stop_08073B0C
	ldr r0, [r4, #0xc]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0xc]
_08073E38:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073E40:
	.byte 0x3E, 0x30, 0x04, 0x21, 0x01, 0x70, 0x70, 0x47
	.syntax divided
