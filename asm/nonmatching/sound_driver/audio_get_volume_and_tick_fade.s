	.syntax unified

	thumb_func_start audio_get_volume_and_tick_fade
audio_get_volume_and_tick_fade: @ 0x08075018
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r3, _0807505C @ =0x03007014
	ldr r0, [r3]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, _08075060 @ =0x0000FFFE
	cmp r1, r0
	bhi _08075034
	adds r0, r1, #1
	strh r0, [r2]
_08075034:
	ldr r0, [r3]
	ldr r2, _08075064 @ =0x0000072D
	adds r1, r0, r2
	ldrb r1, [r1]
	str r1, [r4]
	ldr r1, _08075068 @ =0x0000072E
	adds r0, r0, r1
	ldrb r0, [r0]
	str r0, [r5]
	ldr r0, [r3]
	adds r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08075056
	subs r0, #1
	strh r0, [r1]
_08075056:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807505C: .4byte 0x03007014
_08075060: .4byte 0x0000FFFE
_08075064: .4byte 0x0000072D
_08075068: .4byte 0x0000072E
	.syntax divided
