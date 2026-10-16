	.syntax unified

	thumb_func_start update_wave_channel_params
update_wave_channel_params: @ 0x080731D4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0x50
	ldrb r1, [r5]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080731FA
	adds r0, r4, #0
	adds r0, #0x67
	ldrb r0, [r0]
	bl load_wave_pattern
	ldrb r1, [r5]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5]
_080731FA:
	ldrb r1, [r5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08073236
	adds r0, r4, #0
	adds r0, #0x66
	ldrb r1, [r0]
	subs r0, #0x26
	ldrh r0, [r0]
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r2, _0807323C @ =0xFFFFF000
	adds r1, r2, #0
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x4a
	strh r0, [r1]
	ldr r1, _08073240 @ =0x083ABA62
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x1c
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #8
	strh r0, [r6]
	ldrb r1, [r5]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r5]
_08073236:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807323C: .4byte 0xFFFFF000
_08073240: .4byte 0x083ABA62
	.syntax divided
