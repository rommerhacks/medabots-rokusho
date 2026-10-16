	.syntax unified

	thumb_func_start sub_0804CD58
sub_0804CD58: @ 0x0804CD58
	push {r4, lr}
	bl read_map_script_byte
	adds r1, r0, #0
	ldr r4, _0804CDA4 @ =0x030057E0
	ldr r0, _0804CDA8 @ =0x00000C94
	adds r4, r4, r0
	strb r1, [r4]
	ldr r0, _0804CDAC @ =0x03002C30
	ldr r3, _0804CDB0 @ =0x00000C21
	adds r2, r0, r3
	strb r1, [r2]
	subs r3, #1
	adds r2, r0, r3
	strb r1, [r2]
	ldr r2, _0804CDB4 @ =0x00000C2B
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
	ldrb r0, [r4]
	bl set_battle_state_byte_c83
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804CDA4: .4byte 0x030057E0
_0804CDA8: .4byte 0x00000C94
_0804CDAC: .4byte 0x03002C30
_0804CDB0: .4byte 0x00000C21
_0804CDB4: .4byte 0x00000C2B
	.syntax divided
