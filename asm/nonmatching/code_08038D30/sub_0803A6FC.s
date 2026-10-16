	.syntax unified

	thumb_func_start sub_0803A6FC
sub_0803A6FC: @ 0x0803A6FC
	push {r4, r5, lr}
	sub sp, #8
	ldr r5, _0803A754 @ =0x04000008
	ldrh r0, [r5]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl tilemap_fill_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0x20
	movs r3, #0
	bl tilemap_fill_rect
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r5]
	ldr r0, _0803A758 @ =0x03005000
	strh r4, [r0]
	ldr r0, _0803A75C @ =0x03004C30
	strh r4, [r0]
	movs r0, #4
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #0x23
	movs r1, #1
	bl clear_battle_sprite_slot
	bl battle_advance_sequence_counter
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803A754: .4byte 0x04000008
_0803A758: .4byte 0x03005000
_0803A75C: .4byte 0x03004C30
	.syntax divided
