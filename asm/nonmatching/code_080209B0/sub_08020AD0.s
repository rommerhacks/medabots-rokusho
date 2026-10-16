	.syntax unified

	thumb_func_start sub_08020AD0
sub_08020AD0: @ 0x08020AD0
	push {r4, r5, r6, lr}
	ldr r4, _08020B34 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x88
	ldrb r0, [r5]
	bl sub_080351E8
	ldr r2, _08020B38 @ =0x03000590
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x87
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08020B3C
	adds r6, r4, #0
	adds r6, #0xca
	ldrh r0, [r6]
	cmp r0, #0
	beq _08020B3C
	ldrb r0, [r5]
	bl find_random_available_part_slot
	cmp r0, #0
	beq _08020B3C
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0xd0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x8b
	strb r0, [r2]
	ldrb r0, [r5]
	ldrb r1, [r1]
	ldrh r2, [r6]
	bl battle_set_damage_display
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0xf
	b _08020B44
	.align 2, 0
_08020B34: .4byte 0x03001800
_08020B38: .4byte 0x03000590
_08020B3C:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_08020B44:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
