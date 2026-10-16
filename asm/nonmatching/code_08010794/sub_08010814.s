	.syntax unified

	thumb_func_start sub_08010814
sub_08010814: @ 0x08010814
	push {lr}
	bl update_scroll_movement_a
	ldr r1, _08010850 @ =0x083C2BBC
	ldr r0, _08010854 @ =0x03001800
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08010848
	bl update_all_battle_sprite_orbits
	ldr r0, _08010858 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x84
	movs r2, #8
	strb r2, [r1]
	adds r0, #0x85
	strb r2, [r0]
	ldr r1, _0801085C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08010848:
	bl update_all_battle_sprite_orbits
	pop {r0}
	bx r0
	.align 2, 0
_08010850: .4byte 0x083C2BBC
_08010854: .4byte 0x03001800
_08010858: .4byte 0x03000440
_0801085C: .4byte 0x0300137C
	.syntax divided
