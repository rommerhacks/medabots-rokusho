	.syntax unified

	thumb_func_start sub_0804C53C
sub_0804C53C: @ 0x0804C53C
	push {r4, lr}
	movs r0, #3
	bl read_map_script_bytes
	ldr r4, _0804C588 @ =0x030057E0
	ldr r1, _0804C58C @ =0x00000C94
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #8
	ldr r2, _0804C590 @ =0x00000C95
	adds r0, r4, r2
	ldrb r0, [r0]
	orrs r0, r1
	bl battle_find_entity_by_id
	adds r2, r0, #0
	cmp r2, #0
	beq _0804C580
	ldrb r1, [r2, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804C580
	lsls r0, r1, #0x1b
	lsrs r0, r0, #3
	movs r3, #0xc4
	lsls r3, r3, #0x16
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	ldr r3, _0804C594 @ =0x00000C96
	adds r1, r4, r3
	ldrb r1, [r1]
	bl set_sprite_anim_and_store
_0804C580:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C588: .4byte 0x030057E0
_0804C58C: .4byte 0x00000C94
_0804C590: .4byte 0x00000C95
_0804C594: .4byte 0x00000C96
	.syntax divided
