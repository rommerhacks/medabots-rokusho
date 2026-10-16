	.syntax unified

	thumb_func_start populate_battle_entity_tile_positions
	.global populate_battle_entity_tile_positions
populate_battle_entity_tile_positions: @ 0x080505B0
	push {r4, r5, r6, lr}
	ldr r0, _08050654 @ =0x03005FBC
	movs r1, #0x20
	bl sub_080496C8
	movs r6, #0
_080505BC:
	ldr r0, _08050658 @ =0x030055A0
	adds r2, r6, #0
	adds r2, #0x4f
	lsls r1, r2, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08050648
	ldr r1, _0805065C @ =0x03002C30
	lsls r0, r2, #6
	adds r5, r0, r1
	ldr r0, [r5, #0xc]
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	bl sub_080526F0
	ldr r1, _08050660 @ =0x030057E0
	lsls r4, r6, #2
	adds r4, r4, r1
	ldr r2, _08050664 @ =0x000007DC
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, [r5, #0x10]
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	bl sub_08052714
	ldr r3, _08050668 @ =0x000007DD
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #4
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r2, [r0]
	movs r0, #3
	ands r0, r2
	orrs r1, r0
	ldr r2, _0805066C @ =0x000007DF
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #1
	adds r4, r4, r3
	movs r0, #0x1f
	adds r1, r6, #0
	ands r1, r0
	ldrb r2, [r4]
	movs r3, #0x20
	rsbs r3, r3, #0
	adds r0, r3, #0
	ands r2, r0
	orrs r2, r1
	strb r2, [r4]
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #6
	subs r3, #0x21
	adds r0, r3, #0
	ands r2, r0
	orrs r2, r1
	movs r0, #0x80
	orrs r2, r0
	strb r2, [r4]
_08050648:
	adds r6, #1
	cmp r6, #5
	ble _080505BC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08050654: .4byte 0x03005FBC
_08050658: .4byte 0x030055A0
_0805065C: .4byte 0x03002C30
_08050660: .4byte 0x030057E0
_08050664: .4byte 0x000007DC
_08050668: .4byte 0x000007DD
_0805066C: .4byte 0x000007DF
	.syntax divided
