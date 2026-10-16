	.syntax unified

	thumb_func_start load_bot_part_sprite
	.global load_bot_part_sprite
load_bot_part_sprite: @ 0x080158D0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, _080158F4 @ =0x03001864
	adds r1, r4, #0
	bl get_bot_part_effective_values
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	str r5, [sp]
	bl decompress_sprite_to_vram_08042D94
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080158F4: .4byte 0x03001864
	.syntax divided
