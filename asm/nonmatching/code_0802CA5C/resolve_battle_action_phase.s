	.syntax unified

	thumb_func_start resolve_battle_action_phase
resolve_battle_action_phase: @ 0x08030A24
	push {r4, r5, r6, r7, lr}
	ldr r5, _08030A50 @ =0x03001800
	adds r4, r5, #0
	adds r4, #0x87
	ldrb r0, [r4]
	bl sub_0801B67C
	ldr r6, _08030A54 @ =0x03000590
	ldrb r0, [r4]
	lsls r3, r0, #8
	adds r2, r3, r6
	adds r0, r2, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08030A58
	adds r1, r5, #0
	adds r1, #0xa6
	movs r0, #4
	b _08030C36
	.align 2, 0
_08030A50: .4byte 0x03001800
_08030A54: .4byte 0x03000590
_08030A58:
	adds r1, r2, #0
	adds r1, #0xdd
	ldrb r0, [r1]
	cmp r0, #3
	bhi _08030A7E
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r3
	adds r1, r1, r6
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	bne _08030A7E
	adds r1, r5, #0
	adds r1, #0xa6
	movs r0, #5
	b _08030C36
_08030A7E:
	ldr r0, _08030AB4 @ =0x03000590
	ldr r3, _08030AB8 @ =0x03001800
	adds r1, r3, #0
	adds r1, #0x87
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r2, r1, r0
	adds r1, r2, #0
	adds r1, #0xc9
	ldrb r1, [r1]
	adds r4, r3, #0
	adds r7, r0, #0
	cmp r1, #0x2b
	bne _08030ABC
	adds r0, r2, #0
	adds r0, #0xca
	adds r1, r2, #0
	adds r1, #0xdd
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08030ABC
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #6
	b _08030C36
	.align 2, 0
_08030AB4: .4byte 0x03000590
_08030AB8: .4byte 0x03001800
_08030ABC:
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #3
	bls _08030AE4
	subs r1, r0, #4
	adds r0, r4, #0
	adds r0, #0xa7
	strb r1, [r0]
	ldr r1, _08030AE0 @ =0x0300137C
	movs r0, #0x30
	str r0, [r1]
	b _08030C86
	.align 2, 0
_08030AE0: .4byte 0x0300137C
_08030AE4:
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r5]
	bl select_next_bot_and_action
	ldrb r0, [r5]
	lsls r1, r0, #8
	adds r1, r1, r7
	adds r1, #0xdd
	ldrb r1, [r1]
	subs r1, #1
	bl sub_08016E5C
	cmp r0, #0
	beq _08030B10
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #7
	b _08030C36
_08030B10:
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r1, r0, r7
	adds r0, r1, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #1
	bne _08030B40
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _08030B40
	adds r1, #0x58
	ldrb r0, [r1]
	cmp r0, #0
	bne _08030B3C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #8
	b _08030C36
_08030B3C:
	subs r0, #1
	strb r0, [r1]
_08030B40:
	ldr r0, _08030B90 @ =0x03000590
	ldr r3, _08030B94 @ =0x03001800
	adds r1, r3, #0
	adds r1, #0x87
	ldrb r1, [r1]
	lsls r6, r1, #8
	adds r5, r6, r0
	adds r2, r5, #0
	adds r2, #0xe0
	ldrb r1, [r2]
	adds r4, r3, #0
	adds r7, r0, #0
	cmp r1, #0
	beq _08030BB0
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r0, r0, r7
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _08030B98
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030BB0
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #9
	b _08030C36
	.align 2, 0
_08030B90: .4byte 0x03000590
_08030B94: .4byte 0x03001800
_08030B98:
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _08030BB0
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0xa
	b _08030C36
_08030BB0:
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r5, r0, #8
	adds r3, r5, r7
	adds r2, r3, #0
	adds r2, #0xe1
	ldrb r0, [r2]
	cmp r0, #0
	beq _08030C44
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, r0, r7
	adds r0, #0x49
	ldrb r5, [r0]
	cmp r5, #0x20
	bne _08030C10
	ldrb r0, [r2]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r0, r3, #0
	adds r0, #0xe0
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r7
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	beq _08030C44
	adds r0, r4, #0
	adds r0, #0xa6
	movs r1, #0xb
	strb r1, [r0]
	ldr r0, _08030C0C @ =0x0300137C
	str r5, [r0]
	b _08030C86
	.align 2, 0
_08030C0C: .4byte 0x0300137C
_08030C10:
	ldrb r0, [r2]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r0, r3, #0
	adds r0, #0xe0
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r7
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	bne _08030C44
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0xc
_08030C36:
	strb r0, [r1]
	ldr r1, _08030C40 @ =0x0300137C
	movs r0, #0x20
	str r0, [r1]
	b _08030C86
	.align 2, 0
_08030C40: .4byte 0x0300137C
_08030C44:
	adds r3, r4, #0
	adds r3, #0x87
	ldrb r2, [r3]
	lsls r2, r2, #8
	adds r0, r2, r7
	adds r0, #0xdd
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r7
	adds r0, #0x49
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xa8
	movs r2, #0
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xdd
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0xa7
	strb r0, [r1]
	ldr r1, _08030C8C @ =0x03002B8C
	movs r0, #9
	str r0, [r1]
	ldr r0, _08030C90 @ =0x0300137C
	str r2, [r0]
_08030C86:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030C8C: .4byte 0x03002B8C
_08030C90: .4byte 0x0300137C
_08030C94:
	.byte 0x01, 0x49, 0x40, 0x20, 0x08, 0x60, 0x70, 0x47, 0x7C, 0x13, 0x00, 0x03
	.byte 0x01, 0x49, 0x50, 0x20, 0x08, 0x60, 0x70, 0x47, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
