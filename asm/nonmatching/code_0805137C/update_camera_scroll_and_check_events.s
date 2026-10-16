	.syntax unified

	thumb_func_start update_camera_scroll_and_check_events
	.global update_camera_scroll_and_check_events
update_camera_scroll_and_check_events: @ 0x0805193C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #1
	beq _080519D0
	cmp r0, #1
	bgt _08051952
	cmp r0, #0
	beq _0805195E
	b _08051B20
_08051952:
	cmp r1, #2
	beq _08051A4C
	cmp r1, #3
	bne _0805195C
	b _08051ABC
_0805195C:
	b _08051B20
_0805195E:
	ldr r5, _080519BC @ =0x030057E0
	ldr r0, _080519C0 @ =0x00000C54
	adds r4, r5, r0
	ldrh r0, [r4]
	ldr r1, _080519C4 @ =0x00000C4A
	adds r6, r5, r1
	ldrh r2, [r6]
	cmp r0, r2
	bne _08051972
	b _08051B20
_08051972:
	movs r0, #0x2f
	bl sub_080518F4
	ldrh r1, [r4]
	subs r1, r1, r0
	strh r1, [r4]
	movs r0, #0x2f
	bl advance_sprite_by_terrain_modifier
	bl sub_08052A18
	cmp r0, #0
	beq _0805198E
	b _08051B20
_0805198E:
	ldrh r1, [r4]
	ldrh r0, [r6]
	subs r1, r1, r0
	ldr r2, _080519C8 @ =0x00000802
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #3
	subs r0, #0x60
	cmp r1, r0
	blt _080519A4
	b _08051B20
_080519A4:
	ldr r0, _080519CC @ =0x03004C30
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080519B0
	b _08051B20
_080519B0:
	movs r0, #0x2f
	bl sub_080518F4
	rsbs r0, r0, #0
	b _08051A30
	.align 2, 0
_080519BC: .4byte 0x030057E0
_080519C0: .4byte 0x00000C54
_080519C4: .4byte 0x00000C4A
_080519C8: .4byte 0x00000802
_080519CC: .4byte 0x03004C30
_080519D0:
	ldr r2, _08051A3C @ =0x030057E0
	ldr r0, _08051A40 @ =0x00000C54
	adds r4, r2, r0
	ldrh r1, [r4]
	subs r0, #0xa
	adds r5, r2, r0
	ldrh r0, [r5]
	subs r1, r1, r0
	adds r1, #0x10
	ldr r0, _08051A44 @ =0x00000802
	adds r6, r2, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	cmp r1, r0
	blt _080519F0
	b _08051B20
_080519F0:
	movs r0, #0x2f
	bl sub_080518F4
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r0, #0x2f
	bl advance_sprite_by_terrain_modifier
	bl sub_08052A18
	cmp r0, #0
	beq _08051A0C
	b _08051B20
_08051A0C:
	ldrh r0, [r4]
	ldrh r1, [r5]
	subs r0, r0, r1
	adds r0, #0x10
	cmp r0, #0x50
	bgt _08051A1A
	b _08051B20
_08051A1A:
	ldr r0, _08051A48 @ =0x03004C30
	movs r2, #2
	ldrsh r1, [r0, r2]
	adds r1, #0xa0
	ldrh r0, [r6]
	lsls r0, r0, #3
	cmp r1, r0
	bge _08051B20
	movs r0, #0x2f
	bl sub_080518F4
_08051A30:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_08052AF8
	b _08051B20
	.align 2, 0
_08051A3C: .4byte 0x030057E0
_08051A40: .4byte 0x00000C54
_08051A44: .4byte 0x00000802
_08051A48: .4byte 0x03004C30
_08051A4C:
	ldr r5, _08051AAC @ =0x030057E0
	ldr r0, _08051AB0 @ =0x00000C52
	adds r4, r5, r0
	ldrh r0, [r4]
	ldr r1, _08051AB4 @ =0x00000C48
	adds r6, r5, r1
	ldrh r2, [r6]
	cmp r0, r2
	beq _08051B20
	movs r0, #0x2f
	bl sub_080518F4
	ldrh r1, [r4]
	subs r1, r1, r0
	strh r1, [r4]
	movs r0, #0x2f
	bl advance_sprite_by_terrain_modifier
	bl sub_08052A04
	cmp r0, #0
	bne _08051B20
	ldrh r1, [r4]
	ldrh r0, [r6]
	subs r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #3
	subs r0, #0x80
	cmp r1, r0
	bge _08051B20
	ldr r0, _08051AB8 @ =0x03004C30
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08051B20
	movs r0, #0x2f
	bl sub_080518F4
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_08052A2C
	b _08051B20
	.align 2, 0
_08051AAC: .4byte 0x030057E0
_08051AB0: .4byte 0x00000C52
_08051AB4: .4byte 0x00000C48
_08051AB8: .4byte 0x03004C30
_08051ABC:
	ldr r2, _08051BAC @ =0x030057E0
	ldr r0, _08051BB0 @ =0x00000C52
	adds r4, r2, r0
	ldrh r1, [r4]
	subs r0, #0xa
	adds r5, r2, r0
	ldrh r0, [r5]
	subs r1, r1, r0
	adds r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #4
	adds r6, r2, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	cmp r1, r0
	bge _08051B20
	movs r0, #0x2f
	bl sub_080518F4
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r0, #0x2f
	bl advance_sprite_by_terrain_modifier
	bl sub_08052A04
	cmp r0, #0
	bne _08051B20
	ldrh r0, [r4]
	ldrh r1, [r5]
	subs r0, r0, r1
	adds r0, #0x10
	cmp r0, #0x80
	ble _08051B20
	ldr r0, _08051BB4 @ =0x03004C30
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r1, #0xf0
	ldrh r0, [r6]
	lsls r0, r0, #3
	cmp r1, r0
	bge _08051B20
	movs r0, #0x2f
	bl sub_080518F4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_08052A2C
_08051B20:
	ldr r4, _08051BAC @ =0x030057E0
	ldr r0, _08051BB8 @ =0x00000C58
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051C12
	ldr r1, _08051BBC @ =0x03002C30
	ldr r2, _08051BC0 @ =0x083D2908
	ldr r0, _08051BC4 @ =0x00000C5C
	adds r7, r4, r0
	ldrb r0, [r7]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r2, _08051BC8 @ =0x00000BEA
	adds r1, r1, r2
	strb r0, [r1]
	ldr r1, _08051BB0 @ =0x00000C52
	adds r0, r4, r1
	ldrh r0, [r0]
	bl sub_080526F0
	ldr r2, _08051BCC @ =0x00000C56
	adds r6, r4, r2
	strb r0, [r6]
	ldr r1, _08051BD0 @ =0x00000C54
	adds r0, r4, r1
	ldrh r0, [r0]
	bl sub_08052714
	ldr r2, _08051BD4 @ =0x00000C57
	adds r5, r4, r2
	strb r0, [r5]
	ldr r1, _08051BD8 @ =0x00000C88
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08051C12
	bl find_npc_event_match
	cmp r0, #0
	bne _08051C12
	ldrb r0, [r6]
	ldrb r1, [r5]
	bl find_map_event_by_coords
	cmp r0, #0
	beq _08051BF8
	ldr r0, _08051BDC @ =0x03005310
	movs r1, #3
	strb r1, [r0, #1]
	ldr r1, _08051BE0 @ =0x03006D38
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _08051B9E
	ldr r0, _08051BE4 @ =0x083D29E6
	ldrb r1, [r1, #3]
	adds r1, r1, r0
	ldrb r0, [r1]
	bl sub_08047BA8
_08051B9E:
	ldr r0, _08051BE8 @ =0x00007FFF
	ldr r1, _08051BEC @ =0x00000000
	ldr r2, _08051BF0 @ =0x42000000
	ldr r3, _08051BF4 @ =0x41000000
	bl setup_palette_fade_to_color_with_obj
	b _08051C12
	.align 2, 0
_08051BAC: .4byte 0x030057E0
_08051BB0: .4byte 0x00000C52
_08051BB4: .4byte 0x03004C30
_08051BB8: .4byte 0x00000C58
_08051BBC: .4byte 0x03002C30
_08051BC0: .4byte 0x083D2908
_08051BC4: .4byte 0x00000C5C
_08051BC8: .4byte 0x00000BEA
_08051BCC: .4byte 0x00000C56
_08051BD0: .4byte 0x00000C54
_08051BD4: .4byte 0x00000C57
_08051BD8: .4byte 0x00000C88
_08051BDC: .4byte 0x03005310
_08051BE0: .4byte 0x03006D38
_08051BE4: .4byte 0x083D29E6
_08051BE8: .4byte 0x00007FFF
_08051BEC: .4byte 0x00000000
_08051BF0: .4byte 0x42000000
_08051BF4: .4byte 0x41000000
_08051BF8:
	ldrb r0, [r7]
	cmp r0, #1
	beq _08051C12
	bl check_random_encounter
	cmp r0, #0
	beq _08051C12
	bl populate_battle_entity_tile_positions
	movs r0, #0x21
	movs r1, #0
	bl sub_08047878
_08051C12:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
