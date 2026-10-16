	.syntax unified

	thumb_func_start battle_advance_dialogue_text
	.global battle_advance_dialogue_text
battle_advance_dialogue_text: @ 0x080361C4
	push {r4, r5, lr}
	ldr r4, _0803620C @ =0x03001800
	movs r0, #0x89
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrb r1, [r5]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08036210
	adds r0, r4, #0
	adds r0, #0xff
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08036210
	movs r0, #0
	bl get_active_bot_part_index_and_load_values
	ldrb r1, [r5]
	adds r0, r4, #0
	adds r0, #0x67
	ldrb r2, [r0]
	movs r0, #0
	bl advance_text_display
	adds r2, r0, #0
	cmp r2, #0
	beq _08036208
	ldrb r1, [r5]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r5]
_08036208:
	adds r0, r2, #0
	b _08036212
	.align 2, 0
_0803620C: .4byte 0x03001800
_08036210:
	movs r0, #1
_08036212:
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
