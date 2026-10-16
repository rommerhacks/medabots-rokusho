	.syntax unified

	thumb_func_start sub_08002EC4
sub_08002EC4: @ 0x08002EC4
	push {r4, r5, lr}
	ldr r5, _08002EDC @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r4, [r0]
	cmp r4, #1
	beq _08002F08
	cmp r4, #1
	bgt _08002EE0
	cmp r4, #0
	beq _08002EE6
	b _08002F38
	.align 2, 0
_08002EDC: .4byte 0x03000440
_08002EE0:
	cmp r4, #2
	beq _08002F30
	b _08002F38
_08002EE6:
	movs r0, #7
	bl play_song
	adds r0, r5, #0
	adds r0, #0x8f
	strb r4, [r0]
	ldr r1, _08002F00 @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r0, _08002F04 @ =0x0300137C
	str r4, [r0]
	b _08002F1A
	.align 2, 0
_08002F00: .4byte 0x03002B8C
_08002F04: .4byte 0x0300137C
_08002F08:
	ldr r1, _08002F24 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08002F28 @ =0x03002B8C
	movs r0, #4
	str r0, [r1]
	ldr r1, _08002F2C @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_08002F1A:
	movs r0, #0x28
	movs r1, #0x57
	bl clear_battle_sprite_slot
	b _08002F58
	.align 2, 0
_08002F24: .4byte 0x0300178C
_08002F28: .4byte 0x03002B8C
_08002F2C: .4byte 0x0300137C
_08002F30:
	movs r0, #1
	bl sub_0804765C
	b _08002F58
_08002F38:
	ldr r1, _08002F60 @ =0x03000588
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08002F64 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08002F68 @ =0x03002B8C
	movs r0, #5
	str r0, [r1]
	ldr r1, _08002F6C @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	movs r0, #0x28
	movs r1, #0x57
	bl clear_battle_sprite_slot
_08002F58:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08002F60: .4byte 0x03000588
_08002F64: .4byte 0x0300178C
_08002F68: .4byte 0x03002B8C
_08002F6C: .4byte 0x0300137C
	.syntax divided
