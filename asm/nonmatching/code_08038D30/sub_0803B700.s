	.syntax unified

	thumb_func_start sub_0803B700
sub_0803B700: @ 0x0803B700
	push {r4, lr}
	sub sp, #8
	ldr r0, _0803B74C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _0803B750 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	movs r0, #4
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #0x23
	movs r1, #1
	bl clear_battle_sprite_slot
	bl battle_advance_sequence_counter
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B74C: .4byte 0x04000008
_0803B750: .4byte 0x0400000A
	.syntax divided
