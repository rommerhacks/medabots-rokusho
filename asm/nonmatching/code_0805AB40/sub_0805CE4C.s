	.syntax unified

	thumb_func_start sub_0805CE4C
sub_0805CE4C: @ 0x0805CE4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #5
	mov r8, r0
	ldr r4, _0805CEA0 @ =0x03001780
	ldrb r1, [r4]
	movs r0, #0x53
	movs r2, #0x54
	bl sub_08041C14
	ldr r0, _0805CEA4 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	subs r0, #1
	movs r1, #5
	bl sub_0807CBBC
	cmp r0, #0
	beq _0805CECA
	ldr r0, [r4]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805CEAC
	ldr r2, _0805CEA8 @ =0x03002C30
	movs r1, #0xa2
	lsls r1, r1, #5
	adds r3, r2, r1
	ldrh r0, [r3]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xa4
	lsls r0, r0, #5
	adds r2, r2, r0
	ldrh r0, [r2]
	orrs r1, r0
	b _0805CEC8
	.align 2, 0
_0805CEA0: .4byte 0x03001780
_0805CEA4: .4byte 0x03006F74
_0805CEA8: .4byte 0x03002C30
_0805CEAC:
	ldr r2, _0805CF18 @ =0x03002C30
	movs r1, #0xa2
	lsls r1, r1, #5
	adds r4, r2, r1
	ldrh r3, [r4]
	ldr r1, _0805CF1C @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r3
	strh r0, [r4]
	movs r4, #0xa4
	lsls r4, r4, #5
	adds r2, r2, r4
	ldrh r0, [r2]
	ands r1, r0
_0805CEC8:
	strh r1, [r2]
_0805CECA:
	ldr r0, _0805CF20 @ =0x03006F74
	ldr r5, [r0]
	ldrb r1, [r5, #0x10]
	adds r6, r0, #0
	cmp r1, #1
	bhi _0805CED8
	b _0805CFFC
_0805CED8:
	ldr r0, _0805CF24 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0805CF32
	ldrb r0, [r5, #0xc]
	ldrb r1, [r5, #0x11]
	cmp r0, r1
	bne _0805CF2C
	ldrb r6, [r5, #0x11]
	adds r0, r6, #0
	mov r1, r8
	bl sub_0807CD58
	adds r4, r0, #0
	ldrb r7, [r5, #0x10]
	adds r0, r7, #0
	mov r1, r8
	bl sub_0807CD58
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	bne _0805CF28
	adds r0, r7, #0
	mov r1, r8
	bl sub_0807CDD0
	adds r0, r6, r0
	b _0805CF2C
	.align 2, 0
_0805CF18: .4byte 0x03002C30
_0805CF1C: .4byte 0x0000BFFF
_0805CF20: .4byte 0x03006F74
_0805CF24: .4byte 0x03001798
_0805CF28:
	mov r2, r8
	adds r0, r2, r6
_0805CF2C:
	subs r0, #1
	strb r0, [r5, #0xc]
	b _0805D304
_0805CF32:
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0805CF8E
	ldrb r6, [r5, #0x11]
	adds r0, r6, #0
	mov r1, r8
	bl sub_0807CD58
	adds r4, r0, #0
	ldrb r7, [r5, #0x10]
	adds r0, r7, #0
	mov r1, r8
	bl sub_0807CD58
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	bne _0805CF78
	ldrb r4, [r5, #0xc]
	adds r0, r7, #0
	mov r1, r8
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r6, r0
	subs r0, #1
	cmp r4, r0
	beq _0805CF84
	adds r0, r4, #1
	strb r0, [r5, #0xc]
	b _0805D304
_0805CF78:
	ldrb r1, [r5, #0xc]
	mov r4, r8
	adds r0, r6, r4
	subs r0, #1
	cmp r1, r0
	bne _0805CF88
_0805CF84:
	strb r6, [r5, #0xc]
	b _0805D304
_0805CF88:
	adds r0, r1, #1
	strb r0, [r5, #0xc]
	b _0805D304
_0805CF8E:
	ldrb r4, [r5, #0x10]
	mov r0, r8
	adds r0, #1
	cmp r4, r0
	blt _0805CFFC
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805CFAC
	ldrb r0, [r5, #0x11]
	add r0, r8
	cmp r0, r4
	blt _0805CFE2
	strb r2, [r5, #0x11]
	b _0805CFE4
_0805CFAC:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0805CFFC
	ldrb r0, [r5, #0x11]
	cmp r0, r8
	blo _0805CFC0
	mov r1, r8
	subs r0, r0, r1
	b _0805CFE2
_0805CFC0:
	adds r0, r4, #0
	mov r1, r8
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805CFD4
	mov r2, r8
	subs r0, r4, r2
	b _0805CFE2
_0805CFD4:
	adds r0, r4, #0
	mov r1, r8
	bl sub_0807CD58
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
_0805CFE2:
	strb r0, [r5, #0x11]
_0805CFE4:
	ldr r0, [r6]
	ldrb r1, [r0, #0x11]
	strb r1, [r0, #0xc]
	bl update_battle_medapart_icons
	ldr r0, _0805CFF8 @ =0x03004130
	bl sub_0805B470
	b _0805D304
	.align 2, 0
_0805CFF8: .4byte 0x03004130
_0805CFFC:
	adds r4, r6, #0
	ldr r2, [r4]
	ldrb r3, [r2, #0x12]
	cmp r3, #0
	beq _0805D07C
	ldr r0, _0805D034 @ =0x03001780
	ldr r0, [r0]
	bl sub_0805CA28
	ldr r0, _0805D038 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0805D044
	ldr r1, _0805D03C @ =0x03002C30
	movs r0, #0xa8
	lsls r0, r0, #5
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _0805D040 @ =0x0000BFFF
	ands r0, r2
	movs r2, #0
	strh r0, [r1]
	ldr r0, [r4]
	strb r2, [r0, #0x12]
	b _0805D304
	.align 2, 0
_0805D034: .4byte 0x03001780
_0805D038: .4byte 0x0300058C
_0805D03C: .4byte 0x03002C30
_0805D040: .4byte 0x0000BFFF
_0805D044:
	movs r0, #5
	ands r0, r1
	cmp r0, #0
	bne _0805D04E
	b _0805D322
_0805D04E:
	ldr r1, _0805D074 @ =0x03002C30
	movs r2, #0xa8
	lsls r2, r2, #5
	adds r1, r1, r2
	ldrh r2, [r1]
	ldr r0, _0805D078 @ =0x0000BFFF
	ands r0, r2
	movs r2, #0
	strh r0, [r1]
	ldr r0, [r6]
	strb r2, [r0, #0x12]
	bl swap_inventory_items
	bl unpack_item_inventory_to_buffer
	bl update_battle_medapart_icons
	b _0805D304
	.align 2, 0
_0805D074: .4byte 0x03002C30
_0805D078: .4byte 0x0000BFFF
_0805D07C:
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	bls _0805D09A
	ldr r0, _0805D0E8 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0805D09A
	strh r3, [r2, #2]
	movs r0, #2
	bl play_sound_effect
	bl init_fade_sprite_and_start_fade
_0805D09A:
	ldr r4, _0805D0EC @ =0x03006F74
	ldr r3, [r4]
	ldrb r0, [r3, #0x12]
	cmp r0, #0
	beq _0805D0A6
	b _0805D322
_0805D0A6:
	ldr r0, _0805D0E8 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0805D0B4
	b _0805D2D0
_0805D0B4:
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	bne _0805D0BC
	b _0805D2DC
_0805D0BC:
	ldr r2, _0805D0F0 @ =0x03006D38
	movs r1, #0x81
	lsls r1, r1, #0x12
	ldrb r0, [r3, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r2, #4]
	ldrb r0, [r3, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_08048914
	cmp r0, #1
	beq _0805D138
	cmp r0, #1
	bgt _0805D0F4
	cmp r0, #0
	bne _0805D0E6
	b _0805D2C8
_0805D0E6:
	b _0805D2D0
	.align 2, 0
_0805D0E8: .4byte 0x0300058C
_0805D0EC: .4byte 0x03006F74
_0805D0F0: .4byte 0x03006D38
_0805D0F4:
	cmp r0, #4
	ble _0805D0FA
	b _0805D2D0
_0805D0FA:
	bl sub_0803FB0C
	movs r0, #6
	bl play_sound_effect
	ldr r2, _0805D12C @ =0x03002C30
	movs r0, #0xa2
	lsls r0, r0, #5
	adds r4, r2, r0
	ldrh r3, [r4]
	ldr r1, _0805D130 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r3
	strh r0, [r4]
	movs r4, #0xa4
	lsls r4, r4, #5
	adds r2, r2, r4
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	ldr r1, _0805D134 @ =0x0300137C
	movs r0, #9
	str r0, [r1]
	b _0805D322
	.align 2, 0
_0805D12C: .4byte 0x03002C30
_0805D130: .4byte 0x0000BFFF
_0805D134: .4byte 0x0300137C
_0805D138:
	movs r0, #4
	bl play_sound_effect
	ldr r0, [r4]
	ldrb r0, [r0, #0xc]
	lsls r0, r0, #2
	movs r1, #0x81
	lsls r1, r1, #0x12
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x28
	bls _0805D152
	b _0805D2A8
_0805D152:
	lsls r0, r0, #2
	ldr r1, _0805D15C @ =_0805D160
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805D15C: .4byte _0805D160
_0805D160: @ jump table
	.4byte _0805D204 @ case 0
	.4byte _0805D21C @ case 1
	.4byte _0805D2A8 @ case 2
	.4byte _0805D2A8 @ case 3
	.4byte _0805D2A8 @ case 4
	.4byte _0805D230 @ case 5
	.4byte _0805D2A8 @ case 6
	.4byte _0805D2A8 @ case 7
	.4byte _0805D2A8 @ case 8
	.4byte _0805D2A8 @ case 9
	.4byte _0805D2A8 @ case 10
	.4byte _0805D2A8 @ case 11
	.4byte _0805D244 @ case 12
	.4byte _0805D258 @ case 13
	.4byte _0805D2A8 @ case 14
	.4byte _0805D2A8 @ case 15
	.4byte _0805D2A8 @ case 16
	.4byte _0805D2A8 @ case 17
	.4byte _0805D2A8 @ case 18
	.4byte _0805D26C @ case 19
	.4byte _0805D2A8 @ case 20
	.4byte _0805D2A8 @ case 21
	.4byte _0805D2A8 @ case 22
	.4byte _0805D2A8 @ case 23
	.4byte _0805D2A8 @ case 24
	.4byte _0805D2A8 @ case 25
	.4byte _0805D2A8 @ case 26
	.4byte _0805D2A8 @ case 27
	.4byte _0805D2A8 @ case 28
	.4byte _0805D2A8 @ case 29
	.4byte _0805D2A8 @ case 30
	.4byte _0805D2A8 @ case 31
	.4byte _0805D2A8 @ case 32
	.4byte _0805D2A8 @ case 33
	.4byte _0805D2A8 @ case 34
	.4byte _0805D2A8 @ case 35
	.4byte _0805D2A8 @ case 36
	.4byte _0805D2A8 @ case 37
	.4byte _0805D2A8 @ case 38
	.4byte _0805D280 @ case 39
	.4byte _0805D294 @ case 40
_0805D204:
	ldr r0, _0805D214 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0805D218 @ =0x0300137C
	movs r0, #0xb
	str r0, [r1]
	b _0805D322
	.align 2, 0
_0805D214: .4byte 0x03006F74
_0805D218: .4byte 0x0300137C
_0805D21C:
	ldr r0, _0805D228 @ =0x030057E0
	ldr r2, _0805D22C @ =0x00000C5C
	adds r0, r0, r2
	movs r1, #3
	strb r1, [r0]
	b _0805D2B0
	.align 2, 0
_0805D228: .4byte 0x030057E0
_0805D22C: .4byte 0x00000C5C
_0805D230:
	ldr r0, _0805D23C @ =0x030057E0
	ldr r4, _0805D240 @ =0x00000C5C
	adds r0, r0, r4
	movs r1, #4
	strb r1, [r0]
	b _0805D2B0
	.align 2, 0
_0805D23C: .4byte 0x030057E0
_0805D240: .4byte 0x00000C5C
_0805D244:
	ldr r0, _0805D250 @ =0x030057E0
	ldr r1, _0805D254 @ =0x00000C5C
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	b _0805D2B0
	.align 2, 0
_0805D250: .4byte 0x030057E0
_0805D254: .4byte 0x00000C5C
_0805D258:
	ldr r0, _0805D264 @ =0x030057E0
	ldr r2, _0805D268 @ =0x00000C5C
	adds r0, r0, r2
	movs r1, #8
	strb r1, [r0]
	b _0805D2B0
	.align 2, 0
_0805D264: .4byte 0x030057E0
_0805D268: .4byte 0x00000C5C
_0805D26C:
	ldr r0, _0805D278 @ =0x030057E0
	ldr r4, _0805D27C @ =0x00000C5C
	adds r0, r0, r4
	movs r1, #6
	strb r1, [r0]
	b _0805D2B0
	.align 2, 0
_0805D278: .4byte 0x030057E0
_0805D27C: .4byte 0x00000C5C
_0805D280:
	ldr r0, _0805D28C @ =0x030057E0
	ldr r1, _0805D290 @ =0x00000C5C
	adds r0, r0, r1
	movs r1, #7
	strb r1, [r0]
	b _0805D2B0
	.align 2, 0
_0805D28C: .4byte 0x030057E0
_0805D290: .4byte 0x00000C5C
_0805D294:
	ldr r0, _0805D2A0 @ =0x030057E0
	ldr r2, _0805D2A4 @ =0x00000C5C
	adds r0, r0, r2
	movs r1, #0xd
	strb r1, [r0]
	b _0805D2B0
	.align 2, 0
_0805D2A0: .4byte 0x030057E0
_0805D2A4: .4byte 0x00000C5C
_0805D2A8:
	movs r0, #4
	bl dispatch_by_index_0476e8
	b _0805D322
_0805D2B0:
	ldr r0, _0805D2C0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0805D2C4 @ =0x0300137C
	movs r0, #0xd
	str r0, [r1]
	b _0805D322
	.align 2, 0
_0805D2C0: .4byte 0x03000440
_0805D2C4: .4byte 0x0300137C
_0805D2C8:
	movs r0, #6
	bl play_sound_effect
	b _0805D322
_0805D2D0:
	ldr r0, _0805D2F8 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0805D322
_0805D2DC:
	movs r0, #5
	bl play_sound_effect
	bl copy_obj_palette_to_buffer
	ldr r0, _0805D2FC @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0805D300 @ =0x0300137C
	movs r0, #7
	str r0, [r1]
	b _0805D322
	.align 2, 0
_0805D2F8: .4byte 0x0300058C
_0805D2FC: .4byte 0x03000440
_0805D300: .4byte 0x0300137C
_0805D304:
	movs r0, #2
	bl play_sound_effect
	bl sub_0803FB0C
	ldr r0, _0805D32C @ =0x030040F0
	bl item_menu_set_cursor_pos
	ldr r1, _0805D330 @ =0x0300137C
	movs r0, #4
	str r0, [r1]
	ldr r0, _0805D334 @ =0x03001780
	ldr r0, [r0]
	bl sub_0805CA28
_0805D322:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805D32C: .4byte 0x030040F0
_0805D330: .4byte 0x0300137C
_0805D334: .4byte 0x03001780
	.syntax divided
