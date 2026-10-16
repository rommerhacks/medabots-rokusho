	.syntax unified

	thumb_func_start update_cursor_tile_position
	.global update_cursor_tile_position
update_cursor_tile_position: @ 0x08053050
	push {r4, r5, lr}
	ldr r5, _080530A4 @ =0x030057E0
	ldr r1, _080530A8 @ =0x00000C76
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805309C
	ldr r2, _080530AC @ =0x00000C52
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r2, #0x1c
	adds r1, r5, r2
	strh r0, [r1]
	subs r2, #0x1a
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r2, #0x1c
	adds r4, r5, r2
	strh r0, [r4]
	ldrh r0, [r1]
	bl sub_080526F0
	ldr r2, _080530B0 @ =0x00000C72
	adds r1, r5, r2
	strb r0, [r1]
	ldrh r0, [r4]
	bl sub_08052714
	ldr r2, _080530B4 @ =0x00000C73
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _080530B8 @ =0x03002C30
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl set_battle_state_byte_c83
_0805309C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080530A4: .4byte 0x030057E0
_080530A8: .4byte 0x00000C76
_080530AC: .4byte 0x00000C52
_080530B0: .4byte 0x00000C72
_080530B4: .4byte 0x00000C73
_080530B8: .4byte 0x03002C30
	.syntax divided
