	.syntax unified

	thumb_func_start sound_update_channel1_with_fallback
sound_update_channel1_with_fallback: @ 0x080745D4
	push {r4, lr}
	ldr r4, _08074604 @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r0, r1
	bl sound_channel1_update
	bl sub_080743C8
	cmp r0, #0
	bne _080745FE
	ldr r1, [r4]
	adds r1, #0x50
	ldrb r2, [r1]
	movs r0, #0x5f
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	bl sound_channel1_update
_080745FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074604: .4byte 0x03007014
	.syntax divided
