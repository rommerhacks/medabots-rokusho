	.syntax unified

	thumb_func_start setup_all_battle_bot_sprite_positions
	.global setup_all_battle_bot_sprite_positions
setup_all_battle_bot_sprite_positions: @ 0x080159BC
	push {r4, r5, lr}
	movs r4, #0
_080159C0:
	ldr r0, _080159FC @ =0x03000590
	lsls r1, r4, #8
	adds r1, r1, r0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #0
	beq _080159EE
	movs r5, #0xc8
	cmp r4, #2
	bhi _080159D6
	movs r5, #0x28
_080159D6:
	adds r0, r4, #0
	movs r1, #3
	bl sub_0807CDD0
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #3
	adds r2, #0x24
	adds r0, r4, #0
	adds r1, r5, #0
	bl setup_battle_bot_sprites_08015960
_080159EE:
	adds r4, #1
	cmp r4, #5
	bls _080159C0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080159FC: .4byte 0x03000590
	.syntax divided
