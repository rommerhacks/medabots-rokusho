	.syntax unified

	thumb_func_start sub_0804AE34
sub_0804AE34: @ 0x0804AE34
	push {r4, lr}
	ldr r4, _0804AE6C @ =0x030057E0
	ldr r0, _0804AE70 @ =0x00000C5C
	adds r1, r4, r0
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #0
	bl load_battle_palette_via_dma
	movs r0, #9
	movs r1, #0
	bl dispatch_jump_table_29
	ldr r1, _0804AE74 @ =0x00000C52
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r0, _0804AE78 @ =0x00000C54
	adds r4, r4, r0
	ldrh r2, [r4]
	movs r0, #0xe
	movs r3, #0
	bl init_sprite_affine_matrices_and_state
	bl sub_0804A1C4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804AE6C: .4byte 0x030057E0
_0804AE70: .4byte 0x00000C5C
_0804AE74: .4byte 0x00000C52
_0804AE78: .4byte 0x00000C54
	.syntax divided
