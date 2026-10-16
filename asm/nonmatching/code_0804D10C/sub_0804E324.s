	.syntax unified

	thumb_func_start sub_0804E324
sub_0804E324: @ 0x0804E324
	push {r4, r5, lr}
	ldr r1, _0804E368 @ =0x030057E0
	ldr r4, _0804E36C @ =0x083D2998
	ldr r0, _0804E370 @ =0x00000C94
	adds r3, r1, r0
	ldrb r0, [r3]
	adds r0, r0, r4
	ldrb r2, [r0]
	ldr r5, _0804E374 @ =0x00000C5C
	adds r0, r1, r5
	strb r2, [r0]
	adds r5, #0xd
	adds r0, r1, r5
	strb r2, [r0]
	ldrb r0, [r3]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r2, _0804E378 @ =0x00000C28
	adds r1, r1, r2
	strb r0, [r1]
	bl load_battle_terrain_data
	bl decompress_battle_tile_graphics
	ldr r0, _0804E37C @ =0x03006F40
	ldrb r0, [r0, #1]
	cmp r0, #3
	beq _0804E388
	cmp r0, #3
	bgt _0804E380
	cmp r0, #1
	beq _0804E388
	b _0804E38C
	.align 2, 0
_0804E368: .4byte 0x030057E0
_0804E36C: .4byte 0x083D2998
_0804E370: .4byte 0x00000C94
_0804E374: .4byte 0x00000C5C
_0804E378: .4byte 0x00000C28
_0804E37C: .4byte 0x03006F40
_0804E380:
	cmp r0, #6
	bgt _0804E38C
	cmp r0, #5
	blt _0804E38C
_0804E388:
	movs r4, #1
	b _0804E38E
_0804E38C:
	movs r4, #0
_0804E38E:
	movs r0, #0
	bl resolve_tile_from_battle_state
	adds r2, r0, #0
	ldr r3, _0804E3B8 @ =0x083F8634
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _0804E3A4
	movs r2, #1
_0804E3A4:
	cmp r4, #0
	beq _0804E3C4
	ldr r1, _0804E3BC @ =0x040000D4
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0804E3C0 @ =0x05000200
	b _0804E3D0
	.align 2, 0
_0804E3B8: .4byte 0x083F8634
_0804E3BC: .4byte 0x040000D4
_0804E3C0: .4byte 0x05000200
_0804E3C4:
	ldr r1, _0804E3E4 @ =0x040000D4
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0804E3E8 @ =0x0202F800
_0804E3D0:
	str r0, [r1, #4]
	ldr r0, _0804E3EC @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_08050244
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E3E4: .4byte 0x040000D4
_0804E3E8: .4byte 0x0202F800
_0804E3EC: .4byte 0x84000008
	.syntax divided
