	.syntax unified

	thumb_func_start sub_0803431C
sub_0803431C: @ 0x0803431C
	push {r4, lr}
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	ldr r4, _08034354 @ =0x03001800
	ldr r2, _08034358 @ =0x0000015F
	adds r1, r4, r2
	strb r0, [r1]
	bl battle_advance_action_text
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	bl sub_080208C0
	adds r0, r4, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803434C
	bl sub_08034F08
_0803434C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034354: .4byte 0x03001800
_08034358: .4byte 0x0000015F
	.syntax divided
