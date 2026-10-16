	.syntax unified

	thumb_func_start sub_0804C900
sub_0804C900: @ 0x0804C900
	push {lr}
	bl read_map_script_byte
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_08047BA8
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
