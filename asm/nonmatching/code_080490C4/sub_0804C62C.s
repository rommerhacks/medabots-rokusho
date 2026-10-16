	.syntax unified

	thumb_func_start sub_0804C62C
sub_0804C62C: @ 0x0804C62C
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804C650 @ =0x030057E0
	ldr r0, _0804C654 @ =0x00000C95
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0804C644
	movs r0, #1
	strb r0, [r2]
_0804C644:
	ldr r0, _0804C658 @ =0x00000C89
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804C650: .4byte 0x030057E0
_0804C654: .4byte 0x00000C95
_0804C658: .4byte 0x00000C89
	.syntax divided
