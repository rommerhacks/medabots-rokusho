	.syntax unified

	thumb_func_start sub_08013DE4
sub_08013DE4: @ 0x08013DE4
	push {r4, lr}
	bl sub_080182D0
	bl animate_bg_window_blink
	bl setup_scene_bg_from_game_state
	bl setup_battle_bot_display
	ldr r0, _08013E28 @ =0x03001780
	ldrb r4, [r0]
	bl sub_0801827C
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #8
	adds r1, r4, #0
	bl sub_08041C14
	bl sub_080182AC
	bl update_blend_effect
	cmp r0, #0
	beq _08013E20
	ldr r1, _08013E2C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08013E20:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013E28: .4byte 0x03001780
_08013E2C: .4byte 0x0300137C
	.syntax divided
