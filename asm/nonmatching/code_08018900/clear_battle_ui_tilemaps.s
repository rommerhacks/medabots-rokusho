	.syntax unified

	thumb_func_start clear_battle_ui_tilemaps
	.global clear_battle_ui_tilemaps
clear_battle_ui_tilemaps: @ 0x0801AEF4
	push {r4, r5, lr}
	sub sp, #8
	ldr r5, _0801AF68 @ =0x0400000A
	ldrh r0, [r5]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0xc
	movs r1, #7
	movs r2, #0
	movs r3, #0xd
	bl vram_fill_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xc
	movs r1, #7
	movs r2, #0x12
	movs r3, #0xd
	bl vram_fill_tilemap_rect
	subs r5, #2
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xc
	movs r1, #7
	movs r2, #0
	movs r3, #0xd
	bl vram_fill_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xc
	movs r1, #7
	movs r2, #0x12
	movs r3, #0xd
	bl vram_fill_tilemap_rect
	movs r0, #0x3c
	movs r1, #0xa
	bl clear_battle_sprite_slot
	movs r0, #0x78
	movs r1, #8
	bl clear_battle_sprite_slot
	movs r0, #0xa
	movs r1, #0x17
	bl clear_battle_sprite_slot
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801AF68: .4byte 0x0400000A
	.syntax divided
