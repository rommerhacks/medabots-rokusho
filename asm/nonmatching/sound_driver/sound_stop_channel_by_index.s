	.syntax unified

	thumb_func_start sound_stop_channel_by_index
sound_stop_channel_by_index: @ 0x080744B4
	push {r4, r5, lr}
	ldr r5, _080744F8 @ =0x03007014
	ldr r1, [r5]
	movs r2, #0x74
	adds r4, r0, #0
	muls r4, r2, r4
	adds r1, #0x14
	adds r1, r1, r4
	ldr r0, [r1]
	cmp r0, #0
	beq _08074540
	bl sub_080743C8
	cmp r0, #0
	bne _08074540
	ldr r1, [r5]
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080744FC
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, #0x5f
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	movs r1, #0xcb
	lsls r1, r1, #2
	b _0807451C
	.align 2, 0
_080744F8: .4byte 0x03007014
_080744FC:
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _08074524
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, #0x5f
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	movs r1, #0xae
	lsls r1, r1, #1
_0807451C:
	adds r0, r0, r1
	bl sound_update_channel_3
	b _08074540
_08074524:
	adds r0, r1, r4
	adds r0, #0x66
	strb r2, [r0]
	ldr r1, [r5]
	adds r1, r1, r4
	adds r1, #0x50
	ldrb r2, [r1]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r4
	bl sound_update_channel_3
_08074540:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
