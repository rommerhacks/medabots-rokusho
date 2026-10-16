	.syntax unified

	thumb_func_start sub_0804BCBC
sub_0804BCBC: @ 0x0804BCBC
	push {lr}
	movs r0, #3
	bl read_map_script_bytes
	ldr r2, _0804BCE8 @ =0x030057E0
	ldr r1, _0804BCEC @ =0x00000C94
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, r1, #8
	ldr r3, _0804BCF0 @ =0x00000C95
	adds r0, r2, r3
	ldrb r0, [r0]
	orrs r0, r1
	ldr r1, _0804BCF4 @ =0x00000C96
	adds r2, r2, r1
	ldrb r2, [r2]
	movs r1, #7
	ands r1, r2
	bl sub_080531EC
	pop {r0}
	bx r0
	.align 2, 0
_0804BCE8: .4byte 0x030057E0
_0804BCEC: .4byte 0x00000C94
_0804BCF0: .4byte 0x00000C95
_0804BCF4: .4byte 0x00000C96
	.syntax divided
