	.syntax unified

	thumb_func_start sub_0804C3F8
sub_0804C3F8: @ 0x0804C3F8
	push {r4, r5, lr}
	ldr r0, _0804C424 @ =0x030057E0
	ldr r1, _0804C428 @ =0x00000C8A
	adds r4, r0, r1
	ldrh r5, [r4]
	adds r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_08053288
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	bl read_map_script_byte
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r5, r5, r0
	strh r5, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804C424: .4byte 0x030057E0
_0804C428: .4byte 0x00000C8A
	.syntax divided
