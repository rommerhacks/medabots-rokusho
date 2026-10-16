	.syntax unified

	thumb_func_start blend_fade_step_08065598
	.global blend_fade_step_08065598
blend_fade_step_08065598: @ 0x08065598
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0
	movs r0, #5
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bne _080655AA
	movs r4, #1
	b _08065602
_080655AA:
	ldr r2, _0806560C @ =0x04000050
	ldrh r0, [r3]
	movs r1, #0x3f
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08065610 @ =0x04000052
	movs r2, #0
	strh r4, [r0]
	ldr r1, _08065614 @ =0x04000054
	ldrb r0, [r3, #2]
	strh r0, [r1]
	ldrb r0, [r3, #4]
	adds r0, #1
	strb r0, [r3, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r3, #3]
	cmp r0, r1
	blo _08065602
	strb r2, [r3, #4]
	movs r0, #5
	ldrsb r0, [r3, r0]
	cmp r0, #0
	ble _080655E4
	ldrb r0, [r3, #2]
	cmp r0, #0xf
	bls _080655E4
	strb r2, [r3, #5]
	movs r4, #1
_080655E4:
	movs r0, #5
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _080655F6
	ldrb r0, [r3, #2]
	cmp r0, #0
	bne _080655F6
	strb r0, [r3, #5]
	movs r4, #1
_080655F6:
	cmp r4, #0
	bne _08065602
	ldrb r0, [r3, #5]
	ldrb r1, [r3, #2]
	adds r0, r0, r1
	strb r0, [r3, #2]
_08065602:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0806560C: .4byte 0x04000050
_08065610: .4byte 0x04000052
_08065614: .4byte 0x04000054
	.syntax divided
