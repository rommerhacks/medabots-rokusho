	.syntax unified

	thumb_func_start sub_08034170
sub_08034170: @ 0x08034170
	push {r4, lr}
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	ldr r4, _080341B8 @ =0x03001800
	ldr r2, _080341BC @ =0x0000015F
	adds r1, r4, r2
	strb r0, [r1]
	bl battle_advance_action_text
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0xec
	movs r3, #0
	ldrsh r2, [r2, r3]
	bl battle_set_damage_vs_armor
	bl sub_08034F08
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080341B8: .4byte 0x03001800
_080341BC: .4byte 0x0000015F
	.syntax divided
