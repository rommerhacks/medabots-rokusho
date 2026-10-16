	.syntax unified

	thumb_func_start init_battle_sprites
	.global init_battle_sprites
init_battle_sprites: @ 0x08050C48
	push {r4, lr}
	ldr r0, _08050C70 @ =0x03002C30
	movs r1, #0xa0
	lsls r1, r1, #4
	bl sub_080496C8
	bl sub_080492CC
	movs r4, #0
_08050C5A:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl calculate_oam_affine_matrix
	adds r4, #1
	cmp r4, #0x1f
	ble _08050C5A
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08050C70: .4byte 0x03002C30
	.syntax divided
