	.syntax unified

	thumb_func_start battle_advance_action_text
	.global battle_advance_action_text
battle_advance_action_text: @ 0x08036218
	push {r4, r5, lr}
	ldr r4, _08036260 @ =0x03001800
	ldr r0, _08036264 @ =0x00000113
	adds r5, r4, r0
	ldrb r1, [r5]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08036268
	adds r0, r4, #0
	adds r0, #0xff
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08036268
	movs r0, #1
	bl get_active_bot_part_index_and_load_values
	ldrb r1, [r5]
	adds r0, r4, #0
	adds r0, #0x67
	ldrb r2, [r0]
	movs r0, #1
	bl advance_text_display
	adds r2, r0, #0
	cmp r2, #0
	beq _0803625A
	ldrb r1, [r5]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r5]
_0803625A:
	adds r0, r2, #0
	b _0803626A
	.align 2, 0
_08036260: .4byte 0x03001800
_08036264: .4byte 0x00000113
_08036268:
	movs r0, #1
_0803626A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
