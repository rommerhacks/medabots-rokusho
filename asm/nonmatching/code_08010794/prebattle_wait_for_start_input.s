	.syntax unified

	thumb_func_start prebattle_wait_for_start_input
prebattle_wait_for_start_input: @ 0x08010860
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _0801089C @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080108AC
	movs r0, #0x32
	bl get_item_quantity_by_id
	cmp r0, #0
	beq _080108AC
	ldr r0, _080108A0 @ =0x030057E0
	ldr r1, _080108A4 @ =0x00000C2D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080108AC
	movs r0, #4
	bl play_sound_effect
	ldr r1, _080108A8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080108C2
	.align 2, 0
_0801089C: .4byte 0x0300058C
_080108A0: .4byte 0x030057E0
_080108A4: .4byte 0x00000C2D
_080108A8: .4byte 0x0300137C
_080108AC:
	ldr r0, _080108C8 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080108C4
	movs r0, #4
	bl play_sound_effect
	ldr r1, _080108CC @ =0x0300137C
	movs r0, #0x20
_080108C2:
	str r0, [r1]
_080108C4:
	pop {r0}
	bx r0
	.align 2, 0
_080108C8: .4byte 0x0300058C
_080108CC: .4byte 0x0300137C
	.syntax divided
