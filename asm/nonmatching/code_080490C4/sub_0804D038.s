	.syntax unified

	thumb_func_start sub_0804D038
sub_0804D038: @ 0x0804D038
	push {lr}
	bl init_battle_sprites
	pop {r0}
	bx r0
	.align 2, 0

	.syntax divided
