	.syntax unified

	thumb_func_start audio_unlink_channel_node
audio_unlink_channel_node: @ 0x08074840
	push {r4, lr}
	adds r2, r0, #0
	ldr r4, [r2, #4]
	cmp r4, #0
	bne _08074850
	ldr r0, [r2]
	cmp r0, #0
	beq _08074886
_08074850:
	ldr r0, _08074864 @ =0x03007014
	ldr r0, [r0]
	ldr r1, _08074868 @ =0x000005E4
	adds r3, r0, r1
	ldr r1, [r3]
	ldr r0, [r1, #4]
	cmp r0, r1
	bne _0807486C
	movs r0, #0
	b _0807487E
	.align 2, 0
_08074864: .4byte 0x03007014
_08074868: .4byte 0x000005E4
_0807486C:
	ldr r0, [r2]
	str r4, [r0, #4]
	ldr r1, [r2, #4]
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, [r3]
	cmp r0, r2
	bne _08074880
	ldr r0, [r2, #4]
_0807487E:
	str r0, [r3]
_08074880:
	movs r0, #0
	str r0, [r2, #4]
	str r0, [r2]
_08074886:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
