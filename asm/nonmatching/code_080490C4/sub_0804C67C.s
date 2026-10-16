	.syntax unified

	thumb_func_start sub_0804C67C
sub_0804C67C: @ 0x0804C67C
	push {lr}
	movs r0, #3
	bl read_map_script_bytes
	ldr r0, _0804C694 @ =0x030057E0
	ldr r1, _0804C698 @ =0x00000C89
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0804C694: .4byte 0x030057E0
_0804C698: .4byte 0x00000C89
	.syntax divided
