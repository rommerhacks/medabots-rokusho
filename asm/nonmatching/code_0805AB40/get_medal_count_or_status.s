	.syntax unified

	thumb_func_start get_medal_count_or_status
	.global get_medal_count_or_status
get_medal_count_or_status: @ 0x0805DD48
	push {lr}
	ldr r1, _0805DD5C @ =0x03000BCC
	movs r0, #2
	bl sub_0807C7A8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.align 2, 0
_0805DD5C: .4byte 0x03000BCC
	.syntax divided
