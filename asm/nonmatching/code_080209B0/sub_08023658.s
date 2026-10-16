	.syntax unified

	thumb_func_start sub_08023658
sub_08023658: @ 0x08023658
	push {r4, r5, r6, lr}
	ldr r4, _0802369C @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x84
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r6, _080236A0 @ =0x03001800
	adds r5, r6, #0
	adds r5, #0x87
	ldrb r0, [r5]
	ldrb r1, [r1]
	movs r2, #2
	bl sub_08037330
	adds r4, #0x89
	ldrb r0, [r4]
	cmp r0, #0
	bne _080236A8
	ldr r0, _080236A4 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080236A8
	ldrb r0, [r5]
	bl sub_080373D4
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080236D4
	.align 2, 0
_0802369C: .4byte 0x03000440
_080236A0: .4byte 0x03001800
_080236A4: .4byte 0x03001798
_080236A8:
	ldr r0, _080236BC @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0
	beq _080236C0
	subs r0, #1
	strh r0, [r1]
	b _080236D4
	.align 2, 0
_080236BC: .4byte 0x03000440
_080236C0:
	ldr r4, _080236DC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_080373D4
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080236D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080236DC: .4byte 0x03001800
	.syntax divided
