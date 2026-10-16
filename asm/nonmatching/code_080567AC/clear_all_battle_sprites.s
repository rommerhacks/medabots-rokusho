	.syntax unified

	thumb_func_start clear_all_battle_sprites
clear_all_battle_sprites: @ 0x08059414
	push {r4, lr}
	movs r4, #0
_08059418:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl clear_battle_sprite_entry
	adds r4, #1
	cmp r4, #0x27
	ble _08059418
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
