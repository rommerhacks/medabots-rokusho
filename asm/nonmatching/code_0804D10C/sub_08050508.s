	.syntax unified

	thumb_func_start sub_08050508
	.global sub_08050508
sub_08050508: @ 0x08050508
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r7, #0xf
	ands r7, r0
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0
	beq _08050574
	ldr r6, _080505A4 @ =0x03002C30
	adds r5, r7, #0
	adds r0, r5, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r6
	ldr r0, [r0, #0xc]
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	bl sub_080526F0
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r6
	ldr r0, [r0, #0x10]
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	bl sub_08052714
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl find_map_event_by_coords
	cmp r0, #0
	beq _08050574
	ldr r1, _080505A8 @ =0x03006D38
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _08050574
	ldr r0, _080505AC @ =0x083D29E6
	ldrb r1, [r1, #3]
	adds r1, r1, r0
	ldrb r0, [r1]
	bl sub_08047BA8
_08050574:
	adds r4, r7, #0
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl clear_battle_sprite_entry
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x79
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl clear_battle_sprite_entry
	adds r0, r4, #0
	bl sub_0804DB68
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080505A4: .4byte 0x03002C30
_080505A8: .4byte 0x03006D38
_080505AC: .4byte 0x083D29E6
	.syntax divided
