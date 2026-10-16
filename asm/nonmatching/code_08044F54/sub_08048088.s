	.syntax unified

	thumb_func_start sub_08048088
	.global sub_08048088
sub_08048088: @ 0x08048088
	ldr r1, _08048094 @ =0x08484444
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08048094: .4byte 0x08484444
	.syntax divided
