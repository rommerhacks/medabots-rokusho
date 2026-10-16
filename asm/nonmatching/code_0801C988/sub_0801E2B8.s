	.syntax unified

	thumb_func_start sub_0801E2B8
sub_0801E2B8: @ 0x0801E2B8
	push {lr}
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	bl battle_advance_action_text
	ldr r0, _0801E2D4 @ =0x03001800
	adds r0, #0xb5
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0801E2D4: .4byte 0x03001800
	.syntax divided
