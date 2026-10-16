	.syntax unified

	thumb_func_start sub_0803E9BC
sub_0803E9BC: @ 0x0803E9BC
	push {lr}
	movs r0, #4
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r3, _0803EA0C @ =0x03002C30
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #0
	movs r0, #0xc4
	lsls r0, r0, #8
	strh r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x9a
	strh r0, [r1]
	adds r0, #0x6a
	adds r1, r3, r0
	movs r0, #0x58
	strh r0, [r1]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r3, r1
	strb r2, [r0]
	ldr r0, _0803EA10 @ =0x0000010B
	adds r1, r3, r0
	movs r0, #0x80
	strb r0, [r1]
	ldr r0, _0803EA14 @ =0x083B5F80
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #4
	bl init_battle_sprite_entry_08040B90
	pop {r0}
	bx r0
	.align 2, 0
_0803EA0C: .4byte 0x03002C30
_0803EA10: .4byte 0x0000010B
_0803EA14: .4byte 0x083B5F80
	.syntax divided
