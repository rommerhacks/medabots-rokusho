	.syntax unified

	thumb_func_start sub_0804BD8C
sub_0804BD8C: @ 0x0804BD8C
	push {r4, r5, r6, r7, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r5, _0804BDE8 @ =0x03006D20
	ldr r4, _0804BDEC @ =0x030057E0
	ldr r0, _0804BDF0 @ =0x00000CB4
	adds r3, r4, r0
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	adds r0, #0x31
	movs r6, #0
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0xa]
	ldr r2, _0804BDF4 @ =0x00000C94
	adds r1, r4, r2
	ldrb r2, [r1]
	movs r1, #0xf
	ands r1, r2
	ldrb r2, [r3]
	lsls r2, r2, #3
	ldr r7, _0804BDF8 @ =0x000005DC
	adds r3, r4, r7
	adds r2, r2, r3
	bl set_sprite_anim_and_store
	strb r6, [r5]
	ldr r1, _0804BDFC @ =0x00000C95
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r5, #2]
	ldr r2, _0804BE00 @ =0x00000C89
	adds r4, r4, r2
	movs r0, #1
	strb r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804BDE8: .4byte 0x03006D20
_0804BDEC: .4byte 0x030057E0
_0804BDF0: .4byte 0x00000CB4
_0804BDF4: .4byte 0x00000C94
_0804BDF8: .4byte 0x000005DC
_0804BDFC: .4byte 0x00000C95
_0804BE00: .4byte 0x00000C89
	.syntax divided
