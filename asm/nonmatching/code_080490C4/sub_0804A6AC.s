	.syntax unified

	thumb_func_start sub_0804A6AC
sub_0804A6AC: @ 0x0804A6AC
	push {lr}
	bl sub_0804B1FC
	bl init_battle_medapart_sprites_all
	movs r0, #5
	movs r1, #0
	bl dispatch_jump_table_29
	ldr r1, _0804A6D0 @ =0x03005310
	movs r0, #0
	strb r0, [r1, #1]
	ldr r1, _0804A6D4 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804A6D0: .4byte 0x03005310
_0804A6D4: .4byte 0x0300137C
	.syntax divided
