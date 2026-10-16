	.syntax unified

	thumb_func_start sub_08008BE0
sub_08008BE0: @ 0x08008BE0
	push {lr}
	bl sub_080093F8
	ldr r0, _08008C18 @ =0x083B5F80
	ldr r0, [r0, #0xc]
	movs r1, #6
	bl process_sprite_anim_commands
	ldr r0, _08008C1C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08008C24
	ldr r2, _08008C20 @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x44
	ldrb r0, [r1]
	cmp r0, #0
	bne _08008C12
	adds r0, r2, #0
	adds r0, #0x45
	ldrb r0, [r0]
_08008C12:
	subs r0, #1
	strb r0, [r1]
	b _08008C4C
	.align 2, 0
_08008C18: .4byte 0x083B5F80
_08008C1C: .4byte 0x03001798
_08008C20: .4byte 0x03000440
_08008C24:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08008C58
	ldr r0, _08008C44 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x44
	ldrb r1, [r2]
	adds r0, #0x45
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _08008C48
	strb r3, [r2]
	b _08008C4C
	.align 2, 0
_08008C44: .4byte 0x03000440
_08008C48:
	adds r0, r1, #1
	strb r0, [r2]
_08008C4C:
	movs r0, #2
	bl play_sound_effect
	bl sub_0800AAC0
	b _08008C98
_08008C58:
	ldr r0, _08008C7C @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08008C84
	movs r0, #4
	bl play_sound_effect
	bl sub_0800AA1C
	bl sub_0803FB0C
	ldr r1, _08008C80 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08008C96
	.align 2, 0
_08008C7C: .4byte 0x0300058C
_08008C80: .4byte 0x0300137C
_08008C84:
	movs r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08008C98
	movs r0, #5
	bl play_sound_effect
	ldr r1, _08008C9C @ =0x0300137C
	movs r0, #0x4e
_08008C96:
	str r0, [r1]
_08008C98:
	pop {r0}
	bx r0
	.align 2, 0
_08008C9C: .4byte 0x0300137C
	.syntax divided
