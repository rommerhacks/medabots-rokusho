	.syntax unified

	thumb_func_start sub_08003620
sub_08003620: @ 0x08003620
	push {lr}
	bl sub_080039BC
	movs r0, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	bl copy_obj_palette_to_buffer
	ldr r0, _0800364C @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	ldr r1, _08003650 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800364C: .4byte 0x03000440
_08003650: .4byte 0x0300137C
	.syntax divided
