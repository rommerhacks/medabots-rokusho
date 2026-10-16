	.syntax unified

	thumb_func_start sub_0806098C
sub_0806098C: @ 0x0806098C
	push {lr}
	bl update_battle_sprite_animation
	bl update_animation_timer
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _080609B2
	bl copy_obj_palette_to_buffer
	ldr r0, _080609B8 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080609BC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080609B2:
	pop {r0}
	bx r0
	.align 2, 0
_080609B8: .4byte 0x03000440
_080609BC: .4byte 0x0300137C
	.syntax divided
