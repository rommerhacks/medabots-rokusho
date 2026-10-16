	.syntax unified

	thumb_func_start divide_by_65536
	.global divide_by_65536
divide_by_65536: @ 0x08048B54
	push {lr}
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_0807CBBC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1
	.syntax divided
