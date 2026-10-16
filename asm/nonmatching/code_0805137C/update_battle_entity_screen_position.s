	.syntax unified

	thumb_func_start update_battle_entity_screen_position
update_battle_entity_screen_position: @ 0x08053BC8
	push {r4, lr}
	sub sp, #0x14
	add r3, sp, #0xc
	str r3, [sp]
	add r3, sp, #0x10
	str r3, [sp, #4]
	add r3, sp, #8
	bl compute_3d_transform_vectors
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl update_entity_position_and_triggers
	ldr r3, _08053C24 @ =0x03002C30
	ldr r0, _08053C28 @ =0x03005350
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08053C2C @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r2
	movs r2, #0x83
	lsls r2, r2, #2
	adds r1, r0, r2
	adds r2, #0xd0
	adds r0, r0, r2
	ldr r1, [r1]
	adds r0, r0, r1
	ldrb r4, [r0]
	lsls r4, r4, #6
	adds r4, r4, r3
	ldr r0, [sp, #0x10]
	bl float_to_int
	lsls r0, r0, #8
	ldrb r1, [r4, #0x14]
	orrs r1, r0
	str r1, [r4, #0x14]
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053C24: .4byte 0x03002C30
_08053C28: .4byte 0x03005350
_08053C2C: .4byte 0x03006D30
	.syntax divided
