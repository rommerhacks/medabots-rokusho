	.syntax unified

	thumb_func_start sub_0804C11C
sub_0804C11C: @ 0x0804C11C
	push {r4, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r4, _0804C144 @ =0x030057E0
	ldr r1, _0804C148 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	bl sub_0804DBA4
	ldr r1, _0804C14C @ =0x03006D20
	adds r0, #0x4f
	strb r0, [r1, #0xa]
	ldr r0, _0804C150 @ =0x00000C89
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C144: .4byte 0x030057E0
_0804C148: .4byte 0x00000C94
_0804C14C: .4byte 0x03006D20
_0804C150: .4byte 0x00000C89
	.syntax divided
