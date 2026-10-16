	.syntax unified

	thumb_func_start sub_08002A2C
sub_08002A2C: @ 0x08002A2C
	push {r4, lr}
	ldr r0, _08002AC0 @ =0x083B5F80
	ldr r0, [r0]
	movs r1, #0
	bl process_sprite_anim_commands
	ldr r4, _08002AC4 @ =0x03001798
	ldrb r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08002A62
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08002AC8 @ =0x03000440
	adds r2, #0x8e
	ldrb r0, [r2]
	subs r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08002ACC @ =0x03002C30
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r1, #4]
_08002A62:
	ldrb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08002A8A
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08002AC8 @ =0x03000440
	adds r2, #0x8e
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08002ACC @ =0x03002C30
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r1, #4]
_08002A8A:
	ldr r0, _08002AD0 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08002AD8
	movs r0, #0x10
	bl sound_stop_all_with_fade_guard
	movs r0, #5
	bl play_sound_effect
	movs r0, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #0xa
	movs r1, #7
	bl clear_battle_sprite_slot
	ldr r0, _08002AC8 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08002AD4 @ =0x0300137C
	movs r0, #3
	b _08002AEA
	.align 2, 0
_08002AC0: .4byte 0x083B5F80
_08002AC4: .4byte 0x03001798
_08002AC8: .4byte 0x03000440
_08002ACC: .4byte 0x03002C30
_08002AD0: .4byte 0x0300058C
_08002AD4: .4byte 0x0300137C
_08002AD8:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08002AEC
	movs r0, #4
	bl play_sound_effect
	ldr r1, _08002AF4 @ =0x0300137C
	movs r0, #6
_08002AEA:
	str r0, [r1]
_08002AEC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08002AF4: .4byte 0x0300137C
	.syntax divided
