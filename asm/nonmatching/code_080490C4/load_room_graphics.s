	.syntax unified

	thumb_func_start load_room_graphics
	.global load_room_graphics
load_room_graphics: @ 0x0804B264
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r1, _0804B3D0 @ =0x0400000A
	ldr r2, _0804B3D4 @ =0x0000C609
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _0804B3D8 @ =0x0000EA0A
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r4, _0804B3DC @ =0x0000EE0B
	adds r0, r4, #0
	strh r0, [r1]
	ldr r4, _0804B3E0 @ =0x030057E0
	ldr r5, _0804B3E4 @ =0x000007FE
	adds r7, r4, r5
	ldrb r0, [r7]
	bl field_load_area_tiles
	ldrb r0, [r7]
	movs r1, #0
	bl sub_08052960
	movs r1, #0x80
	lsls r1, r1, #4
	adds r6, r4, r1
	strh r0, [r6]
	ldrb r0, [r7]
	movs r1, #1
	bl sub_08052960
	ldr r2, _0804B3E8 @ =0x00000802
	adds r5, r4, r2
	strh r0, [r5]
	ldrb r0, [r7]
	movs r1, #0
	bl sub_08052990
	ldr r3, _0804B3EC @ =0x00000804
	adds r3, r3, r4
	mov sl, r3
	strh r0, [r3]
	ldrb r0, [r7]
	movs r1, #1
	bl sub_08052990
	ldr r1, _0804B3F0 @ =0x00000806
	adds r1, r1, r4
	mov sb, r1
	strh r0, [r1]
	bl clear_vram_bg2_tiles
	movs r2, #0x81
	lsls r2, r2, #4
	adds r4, r4, r2
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, #0
	bl sub_080496C8
	ldr r1, _0804B3F4 @ =0x084045A8
	ldrb r0, [r7]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r2, [r5]
	lsrs r2, r2, #1
	ldrh r1, [r6]
	lsrs r1, r1, #1
	muls r2, r1, r2
	adds r1, r4, #0
	bl memcpy_u8
	ldr r3, _0804B3F8 @ =0x083F92F4
	mov r8, r3
	ldrb r2, [r7]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _0804B316
	b _0804B41C
_0804B316:
	ldr r1, _0804B3FC @ =0x083F8CF4
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804B41C
	ldr r1, _0804B400 @ =0x06009000
	bl LZ77UnCompVram
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r5, _0804B404 @ =0x03006D14
	ldr r1, [r5]
	bl LZ77UnCompVram
	ldr r0, [r5]
	adds r0, #0x10
	ldr r1, _0804B408 @ =0x06003000
	mov r4, sb
	ldrh r2, [r4]
	mov r4, sl
	ldrh r3, [r4]
	movs r4, #0x40
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x80
	str r6, [sp, #8]
	bl copy_tilemap_with_offset_08048CA4
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r5]
	bl LZ77UnCompVram
	ldr r0, [r5]
	adds r0, #0x10
	ldr r1, _0804B40C @ =0x06005000
	mov r3, sb
	ldrh r2, [r3]
	mov r3, sl
	ldrh r3, [r3]
	mov ip, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	bl copy_tilemap_with_offset_08048CA4
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r5]
	bl LZ77UnCompVram
	ldr r0, [r5]
	adds r0, #0x10
	ldr r1, _0804B410 @ =0x06007000
	mov r5, sb
	ldrh r2, [r5]
	mov r5, sl
	ldrh r3, [r5]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	bl copy_tilemap_with_offset_08048CA4
	ldr r1, _0804B414 @ =0x083F8FF4
	ldrb r0, [r7]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _0804B3C2
	b _0804B52E
_0804B3C2:
	ldr r0, _0804B418 @ =0x030057DC
	ldr r1, [r0]
	adds r0, r4, #0
	bl LZ77UnCompVram
	b _0804B52E
	.align 2, 0
_0804B3D0: .4byte 0x0400000A
_0804B3D4: .4byte 0x0000C609
_0804B3D8: .4byte 0x0000EA0A
_0804B3DC: .4byte 0x0000EE0B
_0804B3E0: .4byte 0x030057E0
_0804B3E4: .4byte 0x000007FE
_0804B3E8: .4byte 0x00000802
_0804B3EC: .4byte 0x00000804
_0804B3F0: .4byte 0x00000806
_0804B3F4: .4byte 0x084045A8
_0804B3F8: .4byte 0x083F92F4
_0804B3FC: .4byte 0x083F8CF4
_0804B400: .4byte 0x06009000
_0804B404: .4byte 0x03006D14
_0804B408: .4byte 0x06003000
_0804B40C: .4byte 0x06005000
_0804B410: .4byte 0x06007000
_0804B414: .4byte 0x083F8FF4
_0804B418: .4byte 0x030057DC
_0804B41C:
	ldr r0, _0804B548 @ =0x06009000
	movs r1, #0x80
	bl sub_080496C8
	ldr r0, _0804B54C @ =0x040000D4
	ldr r3, _0804B550 @ =0x080AC5D4
	str r3, [r0]
	ldr r1, _0804B554 @ =0x06009080
	str r1, [r0, #4]
	ldr r2, _0804B558 @ =0x80000040
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0804B55C @ =0x080AC674
	str r1, [r0]
	ldr r1, _0804B560 @ =0x06009100
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0804B564 @ =0x080AC714
	str r1, [r0]
	ldr r1, _0804B568 @ =0x06009180
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0804B56C @ =0x080AC7B4
	str r1, [r0]
	ldr r1, _0804B570 @ =0x06009200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _0804B574 @ =0x06009280
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _0804B578 @ =0x06009300
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _0804B57C @ =0x06009380
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0804B580 @ =0x080AC854
	str r1, [r0]
	ldr r1, _0804B584 @ =0x06009400
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0804B588 @ =0x080AC8F4
	str r1, [r0]
	ldr r1, _0804B58C @ =0x06009480
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, _0804B590 @ =0x03006D14
	mov r8, r0
	ldr r0, [r0]
	ldr r5, _0804B594 @ =0x030057E0
	ldr r1, _0804B598 @ =0x03005FE2
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r7, r5, r3
	ldrh r1, [r7]
	muls r1, r2, r1
	movs r2, #8
	bl sub_080496DC
	mov r4, r8
	ldr r0, [r4]
	ldr r1, _0804B59C @ =0x06003000
	ldr r3, _0804B598 @ =0x03005FE2
	ldrh r2, [r3]
	ldrh r3, [r7]
	movs r6, #0x40
	str r6, [sp]
	str r6, [sp, #4]
	ldr r4, _0804B5A0 @ =0x0300642A
	ldrh r4, [r4]
	lsrs r4, r4, #3
	str r4, [sp, #8]
	ldr r4, _0804B5A4 @ =0x00000C48
	adds r4, r4, r5
	mov sl, r4
	ldrh r4, [r4]
	lsrs r4, r4, #3
	str r4, [sp, #0xc]
	movs r4, #0x80
	mov sb, r4
	str r4, [sp, #0x10]
	bl copy_tiles_to_bg_tilemap
	mov r1, r8
	ldr r0, [r1]
	ldr r1, _0804B5A8 @ =0x06005000
	ldr r3, _0804B598 @ =0x03005FE2
	ldrh r2, [r3]
	ldrh r3, [r7]
	str r6, [sp]
	str r6, [sp, #4]
	ldr r4, _0804B5A0 @ =0x0300642A
	ldrh r4, [r4]
	lsrs r4, r4, #3
	str r4, [sp, #8]
	mov r4, sl
	ldrh r4, [r4]
	lsrs r4, r4, #3
	str r4, [sp, #0xc]
	mov r4, sb
	str r4, [sp, #0x10]
	bl copy_tiles_to_bg_tilemap
	movs r0, #0x81
	lsls r0, r0, #4
	adds r5, r5, r0
	ldr r1, _0804B5AC @ =0x06007000
	ldr r3, _0804B598 @ =0x03005FE2
	ldrh r2, [r3]
	ldrh r3, [r7]
	str r6, [sp]
	str r6, [sp, #4]
	ldr r4, _0804B5A0 @ =0x0300642A
	ldrh r0, [r4]
	lsrs r0, r0, #3
	str r0, [sp, #8]
	mov r4, sl
	ldrh r0, [r4]
	lsrs r0, r0, #3
	str r0, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	adds r0, r5, #0
	bl copy_tiles_to_bg_tilemap
_0804B52E:
	bl field_center_camera_on_player
	bl check_and_update_battlefield_palette
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B548: .4byte 0x06009000
_0804B54C: .4byte 0x040000D4
_0804B550: .4byte 0x080AC5D4
_0804B554: .4byte 0x06009080
_0804B558: .4byte 0x80000040
_0804B55C: .4byte 0x080AC674
_0804B560: .4byte 0x06009100
_0804B564: .4byte 0x080AC714
_0804B568: .4byte 0x06009180
_0804B56C: .4byte 0x080AC7B4
_0804B570: .4byte 0x06009200
_0804B574: .4byte 0x06009280
_0804B578: .4byte 0x06009300
_0804B57C: .4byte 0x06009380
_0804B580: .4byte 0x080AC854
_0804B584: .4byte 0x06009400
_0804B588: .4byte 0x080AC8F4
_0804B58C: .4byte 0x06009480
_0804B590: .4byte 0x03006D14
_0804B594: .4byte 0x030057E0
_0804B598: .4byte 0x03005FE2
_0804B59C: .4byte 0x06003000
_0804B5A0: .4byte 0x0300642A
_0804B5A4: .4byte 0x00000C48
_0804B5A8: .4byte 0x06005000
_0804B5AC: .4byte 0x06007000
	.syntax divided
