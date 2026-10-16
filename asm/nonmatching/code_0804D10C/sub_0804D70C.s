	.syntax unified

	thumb_func_start sub_0804D70C
sub_0804D70C: @ 0x0804D70C
	push {lr}
	movs r0, #1
	bl read_map_script_bytes
	ldr r0, _0804D724 @ =0x030057E0
	ldr r1, _0804D728 @ =0x00000C89
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0804D724: .4byte 0x030057E0
_0804D728: .4byte 0x00000C89
	.syntax divided
