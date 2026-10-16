	.syntax unified

	thumb_func_start sub_08034AA0
sub_08034AA0: @ 0x08034AA0
	push {r4, r5, r6, r7, lr}
	bl rng_next_080424B8
	ldr r7, _08034AE8 @ =0x03001800
	ldr r6, _08034AEC @ =0x083AF200
	movs r4, #0xf
	ands r0, r4
	adds r0, r0, r6
	ldrb r0, [r0]
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r5, r7, r1
	strb r0, [r5]
	bl rng_next_080424B8
	ands r0, r4
	adds r0, r0, r6
	ldrb r0, [r0]
	ldr r1, _08034AF0 @ =0x00000189
	adds r2, r7, r1
	strb r0, [r2]
	ldrb r1, [r5]
	ldrb r0, [r2]
	adds r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0xec
	strh r0, [r1]
	bl sub_08034F08
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034AE8: .4byte 0x03001800
_08034AEC: .4byte 0x083AF200
_08034AF0: .4byte 0x00000189
	.syntax divided
