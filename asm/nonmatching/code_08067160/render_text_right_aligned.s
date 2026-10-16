	.syntax unified

	thumb_func_start render_text_right_aligned
render_text_right_aligned: @ 0x08067328
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	movs r5, #0
	b _08067338
_08067334:
	adds r3, #1
	adds r5, #1
_08067338:
	ldrb r0, [r3]
	cmp r0, #0
	bne _08067334
	subs r3, #1
	ldr r0, _08067374 @ =0x0400000A
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	lsls r1, r2, #6
	ldr r2, _08067378 @ =0x0600003A
	adds r1, r1, r2
	adds r1, r0, r1
	movs r2, #0
	movs r4, #0
	ldr r6, _0806737C @ =0x0600DD00
_0806735A:
	cmp r2, r5
	bge _08067380
	ldrb r0, [r3]
	subs r3, #1
	cmp r0, #0x20
	beq _08067380
	subs r0, #0x41
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	b _08067382
	.align 2, 0
_08067374: .4byte 0x0400000A
_08067378: .4byte 0x0600003A
_0806737C: .4byte 0x0600DD00
_08067380:
	strh r4, [r1]
_08067382:
	subs r1, #2
	adds r2, #1
	cmp r2, #0x13
	ble _0806735A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
