	.syntax unified

	thumb_func_start sound_channel_update_frequency
sound_channel_update_frequency: @ 0x0807328C
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	movs r3, #0
	adds r4, r2, #0
	adds r4, #0x50
	ldrb r1, [r4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080732AC
	movs r3, #0x80
	lsls r3, r3, #8
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4]
_080732AC:
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080732F4
	adds r1, r2, #0
	adds r1, #0x46
	adds r0, r2, #0
	adds r0, #0x55
	ldrb r0, [r0]
	ldrh r1, [r1]
	adds r1, r1, r0
	ldr r0, [r2, #0x38]
	asrs r0, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	bge _080732D8
	movs r2, #0
	b _080732E0
_080732D8:
	ldr r1, _080732F0 @ =0x000007FF
	cmp r0, r1
	ble _080732E0
	adds r2, r1, #0
_080732E0:
	orrs r3, r2
	strh r3, [r5]
	ldrb r1, [r4]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4]
	b _08073302
	.align 2, 0
_080732F0: .4byte 0x000007FF
_080732F4:
	cmp r3, #0
	beq _08073302
	adds r0, r2, #0
	adds r0, #0x46
	ldrh r0, [r0]
	orrs r3, r0
	strh r3, [r5]
_08073302:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
