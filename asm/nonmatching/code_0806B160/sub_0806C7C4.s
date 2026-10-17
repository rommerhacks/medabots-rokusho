	.syntax unified

	thumb_func_start sub_0806C7C4
sub_0806C7C4: @ 0x0806C7C4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _0806C7DC @ =0x03002C30
	adds r5, r0, #0
	adds r5, #0x20
	ldrb r4, [r5]
	adds r6, r0, #0
	cmp r4, #0
	beq _0806C7E0
	cmp r4, #1
	beq _0806C88C
	b _0806C980
	.align 2, 0
_0806C7DC: .4byte 0x03002C30
_0806C7E0:
	movs r1, #0xc0
	lsls r1, r1, #8
	movs r7, #3
	str r7, [sp]
	movs r0, #0
	movs r2, #0x34
	movs r3, #0xd
	bl init_battle_sprite_entry_08048818
	movs r0, #0x78
	strh r0, [r6, #2]
	ldr r0, _0806C83C @ =0x0000FFF0
	strh r0, [r6, #4]
	strh r4, [r6, #0x1a]
	adds r1, r6, #0
	adds r1, #0x21
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r0, _0806C840 @ =0x03001800
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x23
	ble _0806C84C
	movs r1, #0xc8
	lsls r1, r1, #8
	str r7, [sp]
	movs r0, #0x2e
	movs r2, #0x10
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806C844 @ =0x0000CC08
	str r7, [sp]
	movs r0, #0x36
	movs r2, #0x12
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r0, _0806C848 @ =0x00000D84
	adds r1, r6, r0
	b _0806C97C
	.align 2, 0
_0806C83C: .4byte 0x0000FFF0
_0806C840: .4byte 0x03001800
_0806C844: .4byte 0x0000CC08
_0806C848: .4byte 0x00000D84
_0806C84C:
	cmp r0, #0
	bgt _0806C852
	b _0806C980
_0806C852:
	ldr r1, _0806C87C @ =0x0000CC08
	str r7, [sp]
	movs r0, #0x21
	movs r2, #0x12
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806C880 @ =0x00000802
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _0806C884 @ =0x00000842
	adds r0, r6, r2
	strh r1, [r0]
	ldr r1, _0806C888 @ =0x00000804
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #8
	adds r2, #2
	adds r1, r6, r2
	b _0806C97E
	.align 2, 0
_0806C87C: .4byte 0x0000CC08
_0806C880: .4byte 0x00000802
_0806C884: .4byte 0x00000842
_0806C888: .4byte 0x00000804
_0806C88C:
	ldrh r0, [r6, #0x1a]
	cmp r0, #0x90
	bhi _0806C91A
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0806C91A
	movs r1, #0
	ldr r4, _0806C8E0 @ =0x083F7FF4
	ldr r0, _0806C8E4 @ =0x00000A02
	adds r2, r6, r0
_0806C8A2:
	ldrb r3, [r2, #0x1e]
	cmp r3, #0
	bne _0806C8F0
	movs r0, #3
	strb r0, [r2, #0x1e]
	ldr r0, _0806C8E8 @ =0x03001780
	ldr r0, [r0]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	adds r0, #0x58
	strh r0, [r2]
	ldr r1, _0806C8EC @ =0x00000E44
	adds r0, r6, r1
	ldrh r0, [r0]
	subs r0, #0x10
	strh r0, [r2, #2]
	strh r3, [r2, #0x18]
	ldrh r0, [r6, #0x1a]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0806C8F8
	movs r0, #0x3d
	bl play_sound_effect
	b _0806C8F8
	.align 2, 0
_0806C8E0: .4byte 0x083F7FF4
_0806C8E4: .4byte 0x00000A02
_0806C8E8: .4byte 0x03001780
_0806C8EC: .4byte 0x00000E44
_0806C8F0:
	adds r2, #0x40
	adds r1, #1
	cmp r1, #5
	ble _0806C8A2
_0806C8F8:
	ldr r2, _0806C93C @ =0x03002C30
	ldrh r1, [r2, #0x1a]
	movs r0, #4
	ands r0, r1
	movs r1, #0x76
	adds r6, r2, #0
	cmp r0, #0
	beq _0806C90A
	movs r1, #0x7a
_0806C90A:
	ldr r2, _0806C940 @ =0x00000E42
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _0806C944 @ =0x00000E44
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0806C91A:
	ldrh r2, [r6, #0x1a]
	cmp r2, #0xeb
	bhi _0806C92C
	ldr r0, _0806C948 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0806C94C
_0806C92C:
	movs r0, #0
	bl clear_sprite_entry
	movs r0, #0x39
	bl clear_sprite_entry
	movs r0, #1
	b _0806C982
	.align 2, 0
_0806C93C: .4byte 0x03002C30
_0806C940: .4byte 0x00000E42
_0806C944: .4byte 0x00000E44
_0806C948: .4byte 0x0300058C
_0806C94C:
	adds r0, r2, #1
	strh r0, [r6, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bne _0806C980
	movs r1, #0xc8
	lsls r1, r1, #8
	movs r4, #3
	str r4, [sp]
	movs r0, #0x2f
	movs r2, #0x10
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806C98C @ =0x0000CC08
	str r4, [sp]
	movs r0, #0x37
	movs r2, #0x12
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806C990 @ =0x00000DC4
	adds r1, r6, r2
_0806C97C:
	movs r0, #0x1e
_0806C97E:
	strh r0, [r1]
_0806C980:
	movs r0, #0
_0806C982:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806C98C: .4byte 0x0000CC08
_0806C990: .4byte 0x00000DC4
	.syntax divided
