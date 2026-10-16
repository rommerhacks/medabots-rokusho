	.syntax unified

	thumb_func_start sound_update_channel3_frequency
sound_update_channel3_frequency: @ 0x08073308
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r4, #0x50
	ldrb r0, [r4]
	movs r1, #0xef
	ands r1, r0
	strb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08073370
	ldr r0, _08073358 @ =0x04000084
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	movs r1, #0
	cmp r0, #0
	bne _08073334
	movs r1, #0x80
	lsls r1, r1, #8
_08073334:
	adds r3, r1, #0
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
	bge _0807335C
	movs r2, #0
	b _08073364
	.align 2, 0
_08073358: .4byte 0x04000084
_0807335C:
	ldr r1, _08073378 @ =0x000007FF
	cmp r0, r1
	ble _08073364
	adds r2, r1, #0
_08073364:
	orrs r3, r2
	strh r3, [r5]
	ldrb r1, [r4]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4]
_08073370:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073378: .4byte 0x000007FF
	.syntax divided
