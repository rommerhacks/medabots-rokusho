	.syntax unified

	thumb_func_start update_all_battle_status_sprites
	.global update_all_battle_status_sprites
update_all_battle_status_sprites: @ 0x080195C0
	push {r4, r5, lr}
	movs r0, #0x46
	movs r1, #0x12
	bl clear_sprite_table_mask
	movs r4, #0
	ldr r0, _080195FC @ =0x03000590
	adds r5, r0, #0
	adds r5, #0x40
_080195D2:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080195EA
	adds r0, r4, #0
	bl battle_bot_status_sprite_update
	adds r0, r4, #0
	bl battle_update_status_effect_sprite
	adds r0, r4, #0
	bl update_battle_status_effect_sprite
_080195EA:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _080195D2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080195FC: .4byte 0x03000590
	.syntax divided
