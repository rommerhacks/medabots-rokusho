	.syntax unified

	thumb_func_start sub_0803DA90
sub_0803DA90: @ 0x0803DA90
	push {r4, lr}
	sub sp, #8
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl set_blend_effect_mode
	ldr r0, _0803DAE0 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _0803DAE4 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r1, _0803DAE8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803DAE0: .4byte 0x04000008
_0803DAE4: .4byte 0x0400000A
_0803DAE8: .4byte 0x0300137C
	.syntax divided
