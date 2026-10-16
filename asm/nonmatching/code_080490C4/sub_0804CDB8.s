	.syntax unified

	thumb_func_start sub_0804CDB8
sub_0804CDB8: @ 0x0804CDB8
	push {r4, r5, r6, lr}
	ldr r4, _0804CDE8 @ =0x030057E0
	ldr r0, _0804CDEC @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804CDF0 @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #1
	bl read_map_script_bytes
	bl sub_08047F50
	cmp r0, #2
	bgt _0804CDE2
	ldr r0, _0804CDF4 @ =0x00000C95
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804CDE2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CDE8: .4byte 0x030057E0
_0804CDEC: .4byte 0x00000C8A
_0804CDF0: .4byte 0x00000C8C
_0804CDF4: .4byte 0x00000C95
	.syntax divided
