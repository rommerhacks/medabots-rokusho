	.syntax unified

	thumb_func_start sound_channel_update
sound_channel_update: @ 0x08073FA0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	bne _08073FB2
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
	b _08074070
_08073FB2:
	ldr r5, [r4, #0xc]
	movs r6, #1
	ands r5, r6
	cmp r5, #0
	bne _08074070
	adds r0, r4, #0
	bl sub_08073EAC
	ldr r0, [r4, #8]
	adds r0, #0x10
	str r0, [r4, #8]
	ldrh r0, [r4, #0x38]
	cmp r0, #0
	beq _08073FD6
	ldrh r1, [r4, #0x36]
	adds r0, r0, r1
	strh r0, [r4, #0x36]
	strh r5, [r4, #0x38]
_08073FD6:
	ldr r2, [r4]
	ldr r1, [r2]
	ldr r0, [r4, #8]
	cmp r1, r0
	bhi _08074004
	ldr r0, [r2, #8]
	ands r0, r6
	cmp r0, #0
	beq _0807400C
	adds r5, r4, #0
	adds r5, #0x3a
	ldrb r0, [r5]
	bl sound_stop_fifo_dma
	ldr r1, [r4]
	ldr r0, [r1, #0xc]
	str r0, [r4, #8]
	ldrb r0, [r5]
	ldr r2, [r1, #0xc]
	adds r2, #0x10
	adds r1, r1, r2
	bl sound_start_fifo_dma
_08074004:
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x36]
	cmp r0, r1
	bhi _08074014
_0807400C:
	adds r0, r4, #0
	bl sound_restart_channel
	b _08074070
_08074014:
	ldr r0, [r4, #0xc]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08074056
	ldr r1, [r4, #4]
	ldr r0, [r4, #0x14]
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x11
	bl sub_0807CD58
	movs r1, #0x80
	lsls r1, r1, #9
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x10
	orrs r1, r0
	str r1, [r4, #0x10]
	ldr r2, _08074078 @ =0x084873C0
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r1, [r0]
	ldr r0, [r4, #0xc]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0xc]
_08074056:
	ldr r0, [r4, #0xc]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08074070
	adds r0, r4, #0
	bl sound_configure_mixing_channel
	ldr r0, [r4, #0xc]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0xc]
_08074070:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08074078: .4byte 0x084873C0
	.syntax divided
