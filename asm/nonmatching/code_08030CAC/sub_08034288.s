	.syntax unified

	thumb_func_start sub_08034288
sub_08034288: @ 0x08034288
	push {r4, lr}
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	ldr r4, _080342C0 @ =0x03001800
	ldr r2, _080342C4 @ =0x0000015F
	adds r1, r4, r2
	strb r0, [r1]
	bl battle_advance_action_text
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	bl sub_08020050
	adds r0, r4, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080342B8
	bl sub_08034F08
_080342B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080342C0: .4byte 0x03001800
_080342C4: .4byte 0x0000015F
	.syntax divided
