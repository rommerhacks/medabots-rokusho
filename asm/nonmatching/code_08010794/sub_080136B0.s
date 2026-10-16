	.syntax unified

	thumb_func_start sub_080136B0
sub_080136B0: @ 0x080136B0
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _080136E0 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _080136DA
	ldr r1, _080136E4 @ =0x0300137C
	movs r0, #0xb
	str r0, [r1]
_080136DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080136E0: .4byte 0x03001800
_080136E4: .4byte 0x0300137C
	.syntax divided
