	.syntax unified

	thumb_func_start init_battle_entities_and_labels
	.global init_battle_entities_and_labels
init_battle_entities_and_labels: @ 0x080150C0
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, _080150F8 @ =0x03001800
	adds r0, #0x5b
	ldrb r1, [r0]
	cmp r4, r1
	bhs _080150E0
	adds r5, r0, #0
_080150D0:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl init_enemy_bot_medal
	adds r4, #1
	ldrb r0, [r5]
	cmp r4, r0
	blo _080150D0
_080150E0:
	bl init_enemy_bot_loadouts
	ldr r0, _080150F8 @ =0x03001800
	adds r0, #0x5b
	ldrb r1, [r0]
	movs r0, #3
	bl setup_bot_render_label
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080150F8: .4byte 0x03001800
	.syntax divided
