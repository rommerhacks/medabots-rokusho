	.syntax unified

	thumb_func_start decompress_sprite_from_game_state
	.global decompress_sprite_from_game_state
decompress_sprite_from_game_state: @ 0x08006414
	push {r4, lr}
	sub sp, #4
	ldr r3, _08006440 @ =0x03000440
	adds r0, r3, #0
	adds r0, #0x98
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x99
	ldrb r1, [r1]
	adds r2, r3, #0
	adds r2, #0x9a
	ldrb r2, [r2]
	adds r3, #0x9b
	ldrb r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl decompress_sprite_to_vram_08042D94
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08006440: .4byte 0x03000440
	.syntax divided
