	.syntax unified

	thumb_func_start sub_0804C988
sub_0804C988: @ 0x0804C988
	push {r4, r5, r6, lr}
	ldr r4, _0804C9C4 @ =0x030057E0
	ldr r0, _0804C9C8 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804C9CC @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #2
	bl read_map_script_bytes
	ldr r2, _0804C9D0 @ =0x00000C94
	adds r1, r4, r2
	ldr r0, _0804C9D4 @ =0x03002C30
	subs r2, #0xb3
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _0804C9BC
	ldr r0, _0804C9D8 @ =0x00000C95
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804C9BC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804C9C4: .4byte 0x030057E0
_0804C9C8: .4byte 0x00000C8A
_0804C9CC: .4byte 0x00000C8C
_0804C9D0: .4byte 0x00000C94
_0804C9D4: .4byte 0x03002C30
_0804C9D8: .4byte 0x00000C95
	.syntax divided
