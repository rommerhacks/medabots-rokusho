	.syntax unified

	thumb_func_start sub_0804C468
sub_0804C468: @ 0x0804C468
	push {r4, r5, lr}
	ldr r4, _0804C498 @ =0x030057E0
	ldr r1, _0804C49C @ =0x00000C8A
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0804C4A0 @ =0x00000C8C
	adds r0, r4, r2
	movs r5, #0
	strh r1, [r0]
	bl read_map_script_byte
	ldr r2, _0804C4A4 @ =0x00000C94
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _0804C4A8 @ =0x00000CB5
	adds r0, r4, r1
	strb r5, [r0]
	subs r2, #0xb
	adds r4, r4, r2
	movs r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804C498: .4byte 0x030057E0
_0804C49C: .4byte 0x00000C8A
_0804C4A0: .4byte 0x00000C8C
_0804C4A4: .4byte 0x00000C94
_0804C4A8: .4byte 0x00000CB5
	.syntax divided
