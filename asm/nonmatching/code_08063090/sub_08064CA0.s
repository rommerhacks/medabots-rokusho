	.syntax unified

	thumb_func_start sub_08064CA0
sub_08064CA0: @ 0x08064CA0
	push {r4, r5, r6, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _08064D04 @ =0x01006000
	mov r0, sp
	bl CpuFastSet
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	movs r0, #0xa0
	lsls r0, r0, #0x13
	strh r4, [r0]
	movs r3, #0
	movs r2, #0
	movs r6, #0x80
	ldr r4, _08064D08 @ =0x03000BE0
	ldr r5, _08064D0C @ =0x03006F74
_08064CCC:
	ldrb r1, [r4]
	adds r0, r6, #0
	ands r0, r1
	ldr r1, _08064D0C @ =0x03006F74
	cmp r0, #0
	beq _08064CE2
	ldr r0, [r5]
	adds r0, #0xb0
	adds r0, r0, r3
	strb r2, [r0]
	adds r3, #1
_08064CE2:
	adds r4, #0x40
	adds r2, #1
	cmp r2, #0x1d
	ble _08064CCC
	ldr r0, [r1]
	adds r0, #0x30
	strb r3, [r0]
	ldr r0, _08064D10 @ =0x03000584
	ldrb r0, [r0]
	cmp r0, #2
	beq _08064D1C
	ldr r1, _08064D14 @ =0x03002B8C
	movs r0, #6
	str r0, [r1]
	ldr r1, _08064D18 @ =0x0300137C
	movs r0, #0
	b _08064D2E
	.align 2, 0
_08064D04: .4byte 0x01006000
_08064D08: .4byte 0x03000BE0
_08064D0C: .4byte 0x03006F74
_08064D10: .4byte 0x03000584
_08064D14: .4byte 0x03002B8C
_08064D18: .4byte 0x0300137C
_08064D1C:
	bl sub_080415BC
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	ldr r1, _08064D38 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_08064D2E:
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064D38: .4byte 0x0300137C
	.syntax divided
