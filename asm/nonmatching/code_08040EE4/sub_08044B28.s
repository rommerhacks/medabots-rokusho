	.syntax unified

	thumb_func_start sub_08044B28
	.global sub_08044B28
sub_08044B28: @ 0x08044B28
	push {lr}
	bl lz_decompress_dispatch
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
