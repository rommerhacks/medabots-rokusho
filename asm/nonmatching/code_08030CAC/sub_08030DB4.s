	.syntax unified

	thumb_func_start sub_08030DB4
sub_08030DB4: @ 0x08030DB4
	push {lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	movs r0, #0x51
	bl play_sound_effect
	ldr r1, _08030DE4 @ =0x03000590
	ldr r2, _08030DE8 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xc0
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08030DEC
	adds r1, r2, #0
	adds r1, #0x51
	movs r0, #0x50
	b _08030DF2
	.align 2, 0
_08030DE4: .4byte 0x03000590
_08030DE8: .4byte 0x03001800
_08030DEC:
	adds r1, r2, #0
	adds r1, #0x51
	movs r0, #0x28
_08030DF2:
	strb r0, [r1]
	ldr r0, _08030E0C @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_0801B004
	ldr r1, _08030E10 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08030E0C: .4byte 0x03001800
_08030E10: .4byte 0x0300137C
	.syntax divided
