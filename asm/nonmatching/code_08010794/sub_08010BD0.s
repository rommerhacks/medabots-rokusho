	.syntax unified

	thumb_func_start sub_08010BD0
sub_08010BD0: @ 0x08010BD0
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r1, _08010C14 @ =0x083C3984
	ldr r0, _08010C18 @ =0x03001800
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08010C0E
	ldr r0, _08010C1C @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08010C0E
	ldr r1, _08010C20 @ =0x03000440
	movs r0, #0
	strb r0, [r1, #0x1b]
	movs r0, #0xd
	bl play_sound_effect
	ldr r1, _08010C24 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08010C0E:
	pop {r0}
	bx r0
	.align 2, 0
_08010C14: .4byte 0x083C3984
_08010C18: .4byte 0x03001800
_08010C1C: .4byte 0x0300058C
_08010C20: .4byte 0x03000440
_08010C24: .4byte 0x0300137C
	.syntax divided
