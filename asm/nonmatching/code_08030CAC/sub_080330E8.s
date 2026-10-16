	.syntax unified

	thumb_func_start sub_080330E8
	.global sub_080330E8
sub_080330E8: @ 0x080330E8
	push {lr}
	bl get_random_battle_weight_entry
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
