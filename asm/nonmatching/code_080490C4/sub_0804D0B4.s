	.syntax unified

	thumb_func_start sub_0804D0B4
sub_0804D0B4: @ 0x0804D0B4
	push {r4, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r2, _0804D0F8 @ =0x030057E0
	ldr r1, _0804D0FC @ =0x00000CB4
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r3, _0804D100 @ =0x000005DC
	adds r1, r2, r3
	adds r4, r0, r1
	ldrh r0, [r4, #2]
	ldr r3, _0804D104 @ =0x00000FFF
	ands r3, r0
	ldr r1, _0804D108 @ =0x00000C94
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, #1
	adds r2, r2, r1
	ldrb r1, [r2]
	orrs r0, r1
	cmp r3, r0
	bne _0804D0F0
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	movs r2, #0
	bl set_tile_data
_0804D0F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D0F8: .4byte 0x030057E0
_0804D0FC: .4byte 0x00000CB4
_0804D100: .4byte 0x000005DC
_0804D104: .4byte 0x00000FFF
_0804D108: .4byte 0x00000C94
	.syntax divided
