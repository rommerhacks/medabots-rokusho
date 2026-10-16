	.syntax unified

	thumb_func_start sub_08050310
sub_08050310: @ 0x08050310
	push {r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	movs r4, #0xf
	ands r4, r5
	movs r0, #0xf0
	ands r0, r5
	cmp r0, #0
	beq _08050350
	adds r0, r7, #0
	adds r1, r6, #0
	bl find_map_event_by_coords
	cmp r0, #0
	beq _08050350
	ldr r1, _080503A4 @ =0x03006D38
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _08050350
	ldr r0, _080503A8 @ =0x083D29E6
	ldrb r1, [r1, #3]
	adds r1, r1, r0
	ldrb r0, [r1]
	bl sub_08047BA8
_08050350:
	bl find_next_available_battle_sprite_slot
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_0804DB84
	adds r0, r4, #0
	bl sub_0804DBA4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, r8
	adds r2, r7, #0
	adds r3, r6, #0
	bl init_battle_medapart_sprite
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq _0805039A
	adds r0, r4, #0
	bl sub_0804DBA4
	ldr r1, _080503AC @ =0x03002C30
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r1
	ldr r3, [r0, #0x10]
	asrs r2, r3, #8
	adds r2, #5
	lsls r2, r2, #8
	movs r1, #0xff
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #0x10]
_0805039A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080503A4: .4byte 0x03006D38
_080503A8: .4byte 0x083D29E6
_080503AC: .4byte 0x03002C30
	.syntax divided
