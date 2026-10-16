	.syntax unified

	thumb_func_start sub_0804AD1C
sub_0804AD1C: @ 0x0804AD1C
	push {r4, lr}
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804AD50
	ldr r4, _0804AD58 @ =0x030057E0
	ldr r0, _0804AD5C @ =0x00000C5C
	adds r1, r4, r0
	movs r0, #0xb
	strb r0, [r1]
	movs r0, #0
	bl load_battle_palette_via_dma
	ldr r1, _0804AD60 @ =0x00000C52
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r0, _0804AD64 @ =0x00000C54
	adds r4, r4, r0
	ldrh r2, [r4]
	movs r0, #0x12
	movs r3, #0
	bl init_sprite_affine_matrices_and_state
	bl sub_0804A1C4
_0804AD50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804AD58: .4byte 0x030057E0
_0804AD5C: .4byte 0x00000C5C
_0804AD60: .4byte 0x00000C52
_0804AD64: .4byte 0x00000C54
	.syntax divided
