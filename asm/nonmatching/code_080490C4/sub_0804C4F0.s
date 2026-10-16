	.syntax unified

	thumb_func_start sub_0804C4F0
sub_0804C4F0: @ 0x0804C4F0
	push {r4, lr}
	bl read_map_script_byte
	ldr r4, _0804C528 @ =0x030057E0
	ldr r2, _0804C52C @ =0x00000C2A
	adds r1, r4, r2
	strb r0, [r1]
	bl read_map_script_byte
	ldr r2, _0804C530 @ =0x00000C2F
	adds r1, r4, r2
	strb r0, [r1]
	bl read_map_script_byte
	ldr r2, _0804C534 @ =0x00000C2E
	adds r1, r4, r2
	strb r0, [r1]
	bl sub_0804B6EC
	cmp r0, #0
	bne _0804C522
	ldr r0, _0804C538 @ =0x00000C89
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0804C522:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C528: .4byte 0x030057E0
_0804C52C: .4byte 0x00000C2A
_0804C530: .4byte 0x00000C2F
_0804C534: .4byte 0x00000C2E
_0804C538: .4byte 0x00000C89
	.syntax divided
