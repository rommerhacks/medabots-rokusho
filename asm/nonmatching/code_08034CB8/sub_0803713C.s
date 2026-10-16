	.syntax unified

	thumb_func_start sub_0803713C
	.global sub_0803713C
sub_0803713C: @ 0x0803713C
	push {r4, r5, lr}
	ldr r2, _080371BC @ =0x03000590
	ldr r4, _080371C0 @ =0x03001800
	adds r3, r4, #0
	adds r3, #0x87
	ldrb r1, [r3]
	lsls r0, r1, #8
	adds r0, r0, r2
	adds r1, #1
	adds r0, #0xe0
	movs r5, #0
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa7
	ldrb r1, [r1]
	adds r1, #1
	adds r0, #0xe1
	strb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0803717E
	strb r5, [r1]
_0803717E:
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	ldr r2, _080371C4 @ =0x00000161
	adds r1, r4, r2
	strb r0, [r1]
	ldrb r0, [r3]
	bl sub_080355C4
	adds r2, r4, #0
	adds r2, #0xf8
	ldrb r0, [r2]
	movs r1, #2
	eors r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xb7
	strb r5, [r1]
	subs r2, #2
	movs r1, #2
	strb r1, [r2]
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080371C8
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r3, [r0]
	b _080371DE
	.align 2, 0
_080371BC: .4byte 0x03000590
_080371C0: .4byte 0x03001800
_080371C4: .4byte 0x00000161
_080371C8:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0x28
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xff
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
_080371DE:
	ldr r2, _08037204 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803720C
	ldr r0, _08037208 @ =0x00000115
	adds r1, r2, r0
	movs r0, #0x28
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0xff
	ldrb r1, [r3]
	movs r0, #2
	orrs r0, r1
	strb r0, [r3]
	b _08037214
	.align 2, 0
_08037204: .4byte 0x03001800
_08037208: .4byte 0x00000115
_0803720C:
	ldr r0, _0803722C @ =0x00000115
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
_08037214:
	adds r1, r2, #0
	adds r1, #0xb8
	movs r0, #0
	strb r0, [r1]
	bl select_ai_action_type
	bl determine_battle_target_mode
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803722C: .4byte 0x00000115
	.syntax divided
