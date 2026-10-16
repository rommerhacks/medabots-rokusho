	.syntax unified

	thumb_func_start sub_080531D0
	.global sub_080531D0
sub_080531D0: @ 0x080531D0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _080531E2
	bl sub_0805311C
	b _080531E6
_080531E2:
	bl sub_08053154
_080531E6:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
