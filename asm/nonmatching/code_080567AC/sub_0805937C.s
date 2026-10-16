	.syntax unified

	thumb_func_start sub_0805937C
	.global sub_0805937C
sub_0805937C: @ 0x0805937C
	push {r4, r5, r6, lr}
	ldr r5, _08059390 @ =0x030057A0
	ldrb r1, [r5, #0x14]
	cmp r1, #3
	beq _0805939A
	cmp r1, #3
	bgt _08059394
	cmp r1, #0
	blt _0805940E
	b _080593E8
	.align 2, 0
_08059390: .4byte 0x030057A0
_08059394:
	cmp r1, #4
	bne _0805940E
	b _080593E8
_0805939A:
	bl battle_sequence_dispatch
	cmp r0, #4
	bne _0805940C
	ldr r6, _080593EC @ =0x030057E0
	ldr r0, _080593F0 @ =0x00000C5C
	adds r4, r6, r0
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r5, #0x12]
	cmp r0, #0xe
	beq _080593B6
	cmp r0, #0x12
	bne _080593E4
_080593B6:
	bl decompress_battle_tile_graphics
	ldr r2, _080593F4 @ =0x040000D4
	ldr r3, _080593F8 @ =0x083F8634
	ldr r1, _080593FC @ =0x083D29A6
	ldrb r0, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _08059400 @ =0x05000200
	str r0, [r2, #4]
	ldr r0, _08059404 @ =0x84000008
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r1, [r4]
	ldr r2, _08059408 @ =0x00000C28
	adds r0, r6, r2
	strb r1, [r0]
	bl load_battle_terrain_data
_080593E4:
	bl init_battle_sprites
_080593E8:
	movs r0, #1
	b _0805940E
	.align 2, 0
_080593EC: .4byte 0x030057E0
_080593F0: .4byte 0x00000C5C
_080593F4: .4byte 0x040000D4
_080593F8: .4byte 0x083F8634
_080593FC: .4byte 0x083D29A6
_08059400: .4byte 0x05000200
_08059404: .4byte 0x84000008
_08059408: .4byte 0x00000C28
_0805940C:
	movs r0, #0
_0805940E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
