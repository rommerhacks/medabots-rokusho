	.syntax unified

	thumb_func_start sub_0804BCF8
sub_0804BCF8: @ 0x0804BCF8
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r0, _0804BD1C @ =0x030057E0
	ldr r2, _0804BD20 @ =0x00000C94
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	orrs r0, r1
	bl sub_08053234
	pop {r0}
	bx r0
	.align 2, 0
_0804BD1C: .4byte 0x030057E0
_0804BD20: .4byte 0x00000C94
	.syntax divided
