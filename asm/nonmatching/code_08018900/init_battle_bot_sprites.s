	.syntax unified

	thumb_func_start init_battle_bot_sprites
	.global init_battle_bot_sprites
init_battle_bot_sprites: @ 0x0801BBC4
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r0, _0801BBE0 @ =0x03000590
	movs r6, #0xe4
	lsls r6, r6, #0x17
	adds r5, r0, #0
	adds r5, #0x40
_0801BBD2:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801BBE4
	adds r0, r4, #0
	bl init_battle_sprite_entry_0801BC04
	b _0801BBEC
	.align 2, 0
_0801BBE0: .4byte 0x03000590
_0801BBE4:
	lsrs r0, r6, #0x18
	movs r1, #1
	bl clear_sprite_table_mask
_0801BBEC:
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r6, r6, r0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _0801BBD2
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
