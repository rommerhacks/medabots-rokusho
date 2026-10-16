	.syntax unified

	thumb_func_start sub_0804C5FC
sub_0804C5FC: @ 0x0804C5FC
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804C620 @ =0x030057E0
	ldr r0, _0804C624 @ =0x00000C95
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0804C614
	movs r0, #1
	strb r0, [r2]
_0804C614:
	ldr r0, _0804C628 @ =0x00000C89
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804C620: .4byte 0x030057E0
_0804C624: .4byte 0x00000C95
_0804C628: .4byte 0x00000C89
	.syntax divided
