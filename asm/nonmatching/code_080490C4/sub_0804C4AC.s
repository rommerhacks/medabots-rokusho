	.syntax unified

	thumb_func_start sub_0804C4AC
sub_0804C4AC: @ 0x0804C4AC
	push {r4, lr}
	ldr r4, _0804C4DC @ =0x030057E0
	ldr r1, _0804C4E0 @ =0x00000C8A
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0804C4E4 @ =0x00000C8C
	adds r0, r4, r2
	strh r1, [r0]
	bl read_map_script_byte
	ldr r2, _0804C4E8 @ =0x00000C94
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _0804C4EC @ =0x00000CB5
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	subs r2, #0xb
	adds r4, r4, r2
	strb r1, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C4DC: .4byte 0x030057E0
_0804C4E0: .4byte 0x00000C8A
_0804C4E4: .4byte 0x00000C8C
_0804C4E8: .4byte 0x00000C94
_0804C4EC: .4byte 0x00000CB5
	.syntax divided
