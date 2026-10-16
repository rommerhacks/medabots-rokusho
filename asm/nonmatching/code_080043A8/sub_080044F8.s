	.syntax unified

	thumb_func_start sub_080044F8
sub_080044F8: @ 0x080044F8
	push {r4, r5, lr}
	bl sub_08004E74
	bl sub_08006764
	bl toggle_sprite_pair_visibility
	bl dispatch_game_substate_handler_08006824
	bl battle_update_medabot_display
	bl sub_08006F14
	ldr r5, _0800452C @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x50
	ldrb r4, [r0]
	cmp r4, #0
	bne _08004530
	bl copy_obj_palette_to_buffer
	adds r0, r5, #0
	adds r0, #0x84
	strb r4, [r0]
	b _0800453A
	.align 2, 0
_0800452C: .4byte 0x03000440
_08004530:
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
_0800453A:
	ldr r1, _08004548 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08004548: .4byte 0x0300137C
	.syntax divided
