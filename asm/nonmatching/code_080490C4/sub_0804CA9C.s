	.syntax unified

	thumb_func_start sub_0804CA9C
sub_0804CA9C: @ 0x0804CA9C
	push {r4, r5, r6, lr}
	ldr r4, _0804CAD4 @ =0x030057E0
	ldr r0, _0804CAD8 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804CADC @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804CAE0 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	bl sub_08047DB0
	cmp r0, #0
	bne _0804CACC
	ldr r0, _0804CAE4 @ =0x00000C95
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804CACC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CAD4: .4byte 0x030057E0
_0804CAD8: .4byte 0x00000C8A
_0804CADC: .4byte 0x00000C8C
_0804CAE0: .4byte 0x00000C94
_0804CAE4: .4byte 0x00000C95
	.syntax divided
