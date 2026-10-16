	.syntax unified

	thumb_func_start render_battle_medapart_list
	.global render_battle_medapart_list
render_battle_medapart_list: @ 0x0805B0E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	add r7, sp, #0x10
	str r0, [r7]
	mov r1, sp
	adds r0, r1, #0
	str r0, [r7, #0x10]
	sub sp, #4
	mov r2, sp
	adds r2, #0x10
	str r2, [r7, #4]
	sub sp, #4
	mov r0, sp
	adds r0, #0x10
	str r0, [r7, #8]
	sub sp, #4
	add r1, sp, #0x10
	mov sl, r1
	sub sp, #0x10
	add r2, sp, #0x10
	mov sb, r2
	ldr r0, _0805B298 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #0x19]
	str r0, [r7, #0xc]
	ldr r0, _0805B29C @ =0x02023078
	ldrb r1, [r0]
	movs r4, #0
	mov r3, sb
	lsls r1, r1, #3
	movs r0, #0x81
	lsls r0, r0, #0x12
	adds r2, r1, r0
_0805B12A:
	ldr r0, [r7, #4]
	adds r1, r0, r4
	ldrh r0, [r2]
	strb r0, [r1]
	ldr r0, [r7, #8]
	adds r1, r0, r4
	ldrb r0, [r2, #2]
	strb r0, [r1]
	mov r0, sl
	adds r1, r0, r4
	ldrb r0, [r2, #3]
	strb r0, [r1]
	ldr r0, [r2, #4]
	str r0, [r3]
	ldr r1, [r7]
	cmp r1, #0
	beq _0805B150
	lsrs r0, r0, #1
	str r0, [r3]
_0805B150:
	adds r2, #8
	adds r3, #4
	adds r4, #1
	cmp r4, #4
	blt _0805B12A
	movs r2, #4
	cmp r2, #0
	beq _0805B1B2
	movs r0, #0x8a
	lsls r0, r0, #0x17
	mov r8, r0
	movs r1, #0xb
	str r1, [r7, #0x24]
	movs r6, #0xa
	movs r5, #0xd0
	lsls r5, r5, #0x14
	movs r4, #4
_0805B172:
	lsrs r0, r5, #0x18
	movs r1, #0xe
	bl clear_sprite_table_mask
	movs r0, #0xc
	adds r1, r6, #0
	movs r2, #3
	bl sub_0805B3E4
	movs r0, #0xc
	ldr r1, [r7, #0x24]
	movs r2, #3
	bl sub_0805B3E4
	mov r2, r8
	lsrs r0, r2, #0x18
	movs r1, #7
	bl clear_sprite_table_mask
	movs r0, #0xe0
	lsls r0, r0, #0x13
	add r8, r0
	ldr r1, [r7, #0x24]
	adds r1, #2
	str r1, [r7, #0x24]
	adds r6, #2
	movs r2, #0xe0
	lsls r2, r2, #0x14
	adds r5, r5, r2
	subs r4, #1
	cmp r4, #0
	bne _0805B172
_0805B1B2:
	movs r4, #0
	cmp r4, #4
	blt _0805B1BA
	b _0805B394
_0805B1BA:
	ldr r0, _0805B2A0 @ =0x03002C30
	movs r1, #0x8a
	lsls r1, r1, #0x17
	str r1, [r7, #0x14]
	ldr r5, [r7, #4]
	movs r2, #0xdc
	lsls r2, r2, #5
	adds r2, r0, r2
	str r2, [r7, #0x18]
	mov r8, sl
	movs r1, #0xd4
	lsls r1, r1, #5
	adds r6, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #0x14
	str r2, [r7, #0x1c]
	movs r0, #0xa
	mov sl, r0
	movs r1, #0xd0
	lsls r1, r1, #0x14
	str r1, [r7, #0x20]
	ldr r2, [r7, #8]
	str r2, [r7, #0x24]
_0805B1E8:
	ldr r0, [r7]
	cmp r0, #0
	bne _0805B2B0
	ldr r0, _0805B298 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, r4
	bgt _0805B1FC
	b _0805B394
_0805B1FC:
	ldrb r0, [r5]
	lsls r0, r0, #2
	ldr r1, [r7, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _0805B2A4 @ =0x083BB9CC
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r2, [r7, #0x20]
	lsrs r1, r2, #0x18
	movs r2, #0xe
	str r2, [sp]
	movs r2, #0xd
	str r2, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #2
	mov r3, sl
	bl render_text_sprites_08040DB8
	ldr r1, [r7, #0x24]
	ldrb r0, [r1]
	ldr r2, [r7, #0x1c]
	lsrs r3, r2, #0x18
	movs r1, #5
	str r1, [sp]
	ldr r1, _0805B2A8 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0xd
	bl draw_tilemap_bar
	ldrh r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #7
	orrs r0, r1
	strh r0, [r6]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, #0x1b
	strh r0, [r6, #6]
	ldr r1, [r7, #0x18]
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #7
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r5]
	ldr r1, [r7, #0xc]
	adds r2, r4, #0
	bl load_battle_sprite_tiles
	mov r0, sb
	ldr r1, [r0]
	ldr r0, _0805B2AC @ =0x030004DE
	bl divide_by_10000
	ldr r2, [r7, #0x14]
	lsrs r1, r2, #0x18
	movs r0, #7
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	ldr r0, _0805B2AC @ =0x030004DE
	movs r2, #0x12
	mov r3, sl
	bl render_text_sprites_08040DB8
	b _0805B352
	.align 2, 0
_0805B298: .4byte 0x03006F74
_0805B29C: .4byte 0x02023078
_0805B2A0: .4byte 0x03002C30
_0805B2A4: .4byte 0x083BB9CC
_0805B2A8: .4byte 0x0400000A
_0805B2AC: .4byte 0x030004DE
_0805B2B0:
	ldr r1, [r7, #0x24]
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805B394
	ldrb r0, [r5]
	lsls r0, r0, #2
	ldr r2, [r7, #0xc]
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r1, _0805B3D4 @ =0x083BB9CC
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [r7, #0x20]
	lsrs r1, r2, #0x18
	movs r2, #0xe
	str r2, [sp]
	movs r2, #0xd
	str r2, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #2
	mov r3, sl
	bl render_text_sprites_08040DB8
	ldr r1, [r7, #0x24]
	ldrb r0, [r1]
	ldr r2, [r7, #0x1c]
	lsrs r3, r2, #0x18
	movs r1, #5
	str r1, [sp]
	ldr r1, _0805B3D8 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0xd
	bl draw_tilemap_bar
	ldrh r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #7
	orrs r0, r1
	strh r0, [r6]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, #0x1b
	strh r0, [r6, #6]
	ldr r1, [r7, #0x18]
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #7
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r5]
	ldr r1, [r7, #0xc]
	adds r2, r4, #0
	bl load_battle_sprite_tiles
	mov r0, sb
	ldr r1, [r0]
	ldr r0, _0805B3DC @ =0x030004DE
	bl divide_by_10000
	ldr r2, [r7, #0x14]
	lsrs r1, r2, #0x18
	movs r0, #7
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	ldr r0, _0805B3DC @ =0x030004DE
	movs r2, #0x12
	mov r3, sl
	bl render_text_sprites_08040DB8
_0805B352:
	ldr r0, [r7, #0x14]
	movs r1, #0xe0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	str r0, [r7, #0x14]
	movs r2, #4
	add sb, r2
	adds r5, #1
	ldr r0, [r7, #0x18]
	adds r0, #0x40
	str r0, [r7, #0x18]
	movs r1, #1
	add r8, r1
	adds r6, #0x40
	ldr r2, [r7, #0x1c]
	movs r0, #0x80
	lsls r0, r0, #0x12
	adds r2, r2, r0
	str r2, [r7, #0x1c]
	movs r1, #2
	add sl, r1
	ldr r2, [r7, #0x20]
	movs r0, #0xe0
	lsls r0, r0, #0x14
	adds r2, r2, r0
	str r2, [r7, #0x20]
	ldr r1, [r7, #0x24]
	adds r1, #1
	str r1, [r7, #0x24]
	adds r4, #1
	cmp r4, #4
	bge _0805B394
	b _0805B1E8
_0805B394:
	ldr r4, _0805B3DC @ =0x030004DE
	ldr r0, _0805B3E0 @ =0x03006F74
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	adds r0, r4, #0
	bl divide_by_10000
	movs r0, #7
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x61
	movs r2, #0x13
	movs r3, #5
	bl render_text_sprites_08040DB8
	ldr r2, [r7, #0x10]
	mov sp, r2
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805B3D4: .4byte 0x083BB9CC
_0805B3D8: .4byte 0x0400000A
_0805B3DC: .4byte 0x030004DE
_0805B3E0: .4byte 0x03006F74
	.syntax divided
