	.syntax unified

	thumb_func_start sub_08069078
sub_08069078: @ 0x08069078
	push {lr}
	bl update_battle_icon_rotation
	bl battle_update_action_counters
	bl update_battle_bot_entry_animations
	bl update_battle_bot_death_animations
	bl update_battle_bot_damage_animations
	bl update_battle_bot_turn_order_tiles
	bl update_sprite_animations_tick_0806AF40
	bl update_sprite_animations_0806B334
	bl sub_0806A584
	cmp r0, #0
	beq _080690B4
	ldr r1, _080690B8 @ =0x03006F88
	movs r0, #0
	str r0, [r1]
	ldr r1, _080690BC @ =0x03006F80
	movs r0, #0xa
	str r0, [r1]
	ldr r1, _080690C0 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_080690B4:
	pop {r0}
	bx r0
	.align 2, 0
_080690B8: .4byte 0x03006F88
_080690BC: .4byte 0x03006F80
_080690C0: .4byte 0x0300137C
	.syntax divided
