	.syntax unified

	thumb_func_start init_all_sound_channels
	.global init_all_sound_channels
init_all_sound_channels: @ 0x0807488C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r0, _080748F4 @ =0x03007014
	ldr r4, [r0]
	movs r7, #0
	adds r5, r4, #0
	adds r5, #0x50
_0807489A:
	ldr r0, _080748F8 @ =0x083ABBE0
	adds r3, r7, r0
	movs r2, #0
	strb r6, [r5, #1]
	ldr r0, [r3]
	str r0, [r4, #0xc]
	ldr r0, [r3, #4]
	str r0, [r4, #0x10]
	ldrb r0, [r3, #8]
	strb r0, [r5, #0x14]
	ldrb r1, [r5]
	movs r0, #0x5f
	orrs r0, r1
	strb r0, [r5]
	str r2, [r4, #4]
	str r2, [r4]
	ldrb r0, [r3, #9]
	cmp r0, #0xff
	beq _080748D8
	ldr r2, _080748F4 @ =0x03007014
	adds r1, r0, #0
	movs r0, #0x34
	muls r1, r0, r1
	ldr r0, _080748FC @ =0x000005EC
	adds r1, r1, r0
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r4, #8]
	adds r0, r4, #0
	bl clear_sound_channel_wave_data
_080748D8:
	adds r0, r4, #0
	movs r1, #0
	bl init_sound_channel
	adds r7, #0xc
	adds r6, #1
	adds r5, #0x74
	adds r4, #0x74
	cmp r6, #0xc
	ble _0807489A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080748F4: .4byte 0x03007014
_080748F8: .4byte 0x083ABBE0
_080748FC: .4byte 0x000005EC
	.syntax divided
