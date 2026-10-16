	.syntax unified

	thumb_func_start sub_0804BB7C
sub_0804BB7C: @ 0x0804BB7C
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r0, _0804BBA0 @ =0x030057E0
	ldr r2, _0804BBA4 @ =0x00000C94
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	orrs r0, r1
	bl sub_0805311C
	pop {r0}
	bx r0
	.align 2, 0
_0804BBA0: .4byte 0x030057E0
_0804BBA4: .4byte 0x00000C94
	.syntax divided
