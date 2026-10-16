	.syntax unified

	thumb_func_start sound_channel_stop_08073B0C
sound_channel_stop_08073B0C: @ 0x08073B0C
	push {r4, r5, lr}
	ldr r5, _08073B58 @ =0x084873C0
	adds r4, r0, #0
	adds r4, #0x3a
	ldrb r2, [r4]
	subs r0, r2, #1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08073B52
	adds r0, r2, #0
	bl timer_control_set_mode
	ldrb r0, [r4]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1]
	ldr r2, _08073B5C @ =0x04000082
	ldr r1, _08073B60 @ =0x083ABAAE
	ldrb r0, [r4]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_08073B52:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073B58: .4byte 0x084873C0
_08073B5C: .4byte 0x04000082
_08073B60: .4byte 0x083ABAAE
	.syntax divided
