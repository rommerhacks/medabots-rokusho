	.syntax unified

	thumb_func_start sub_08057988
sub_08057988: @ 0x08057988
	push {lr}
	sub sp, #4
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _080579B0
	ldr r1, _080579B8 @ =0x0000C004
	ldr r2, _080579BC @ =0x00000307
	movs r0, #0
	str r0, [sp]
	movs r0, #0x7f
	movs r3, #0xc
	bl init_battle_sprite_entry_08048818
	bl update_cursor_sprite_position
	ldr r1, _080579C0 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_080579B0:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080579B8: .4byte 0x0000C004
_080579BC: .4byte 0x00000307
_080579C0: .4byte 0x0300137C
	.syntax divided
