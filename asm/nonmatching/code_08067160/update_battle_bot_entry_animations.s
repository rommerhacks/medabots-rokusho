	.syntax unified

	thumb_func_start update_battle_bot_entry_animations
update_battle_bot_entry_animations: @ 0x0806A910
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r0, #0
	mov sb, r0
_0806A920:
	ldr r0, _0806A9F8 @ =0x03006F8C
	mov r1, sb
	adds r4, r1, r0
	ldrb r0, [r4]
	movs r2, #1
	add r2, sb
	mov r8, r2
	cmp r0, #2
	bls _0806A934
	b _0806ABF4
_0806A934:
	ldr r5, _0806A9FC @ =0x03002C30
	ldr r7, _0806AA00 @ =0x08485CC4
	lsls r2, r1, #1
	adds r6, r2, r1
	adds r0, r0, r6
	adds r0, r0, r7
	ldrb r3, [r0]
	lsls r0, r3, #6
	adds r0, r0, r5
	ldrh r1, [r0, #0x1a]
	ldr r0, _0806AA04 @ =0x000002AF
	str r2, [sp, #4]
	cmp r1, r0
	bhi _0806A952
	b _0806AA58
_0806A952:
	subs r0, r3, #3
	movs r1, #4
	bl battle_sprite_set_palette_index
	ldrb r0, [r4]
	adds r0, r0, r6
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x2a
	movs r1, #0
	mov sl, r1
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0806AA32
	mov r2, r8
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sprite_animation_dispatch
	ldr r1, _0806AA08 @ =0x03006F94
	ldrb r0, [r1]
	cmp r0, #0
	bne _0806AA14
	mov r0, r8
	strb r0, [r1]
	movs r6, #0
	ldr r1, _0806AA0C @ =0x083F7FF4
	mov sl, r1
	movs r2, #3
	mov sb, r2
	ldr r0, _0806A9FC @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #1
	adds r7, r0, r1
_0806A9AC:
	ldr r0, _0806AA10 @ =0x03001780
	ldr r0, [r0]
	adds r0, r0, r6
	movs r1, #0xff
	ands r0, r1
	add r0, sl
	ldrb r5, [r0]
	mov r2, sb
	ands r5, r2
	adds r4, r6, #4
	movs r0, #0x86
	lsls r0, r0, #1
	adds r2, r5, r0
	mov r1, sb
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r3, #0xb
	bl init_battle_sprite_entry_08048818
	movs r0, #0x64
	strb r0, [r7, #0xb]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r3, r6, #4
	movs r0, #0x7f
	ands r3, r0
	adds r0, r4, #0
	movs r1, #8
	adds r2, r5, #0
	bl sprite_animation_dispatch
	adds r7, #0x40
	adds r6, #1
	cmp r6, #0xf
	ble _0806A9AC
	b _0806AA2A
	.align 2, 0
_0806A9F8: .4byte 0x03006F8C
_0806A9FC: .4byte 0x03002C30
_0806AA00: .4byte 0x08485CC4
_0806AA04: .4byte 0x000002AF
_0806AA08: .4byte 0x03006F94
_0806AA0C: .4byte 0x083F7FF4
_0806AA10: .4byte 0x03001780
_0806AA14:
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _0806AA20
	mov r2, r8
	strb r2, [r1, #1]
	b _0806AA2A
_0806AA20:
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _0806AA2A
	mov r0, r8
	strb r0, [r1, #2]
_0806AA2A:
	movs r0, #0x43
	bl play_sound_effect
	b _0806ABF4
_0806AA32:
	movs r0, #0x44
	bl play_sound_effect
	ldrb r0, [r4]
	adds r0, r0, r6
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r5
	movs r2, #0
	mov r1, sl
	strh r1, [r0, #0x1a]
	ldr r0, _0806AB28 @ =0x03006FEC
	add r0, sb
	movs r1, #0x20
	strb r1, [r0]
	ldr r0, _0806AB2C @ =0x03006FF0
	add r0, sb
	strb r2, [r0]
_0806AA58:
	ldr r5, _0806AB30 @ =0x03002C30
	ldr r7, _0806AB34 @ =0x08485CC4
	ldr r0, _0806AB38 @ =0x03006F8C
	mov r2, sb
	adds r4, r2, r0
	ldrb r0, [r4]
	ldr r6, [sp, #4]
	add r6, sb
	adds r3, r0, r6
	adds r0, r3, r7
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r1, r0, r5
	ldrh r0, [r1, #0x3a]
	ldr r2, _0806AB3C @ =0x00000157
	cmp r0, r2
	bhi _0806AAF2
	ldrh r0, [r1, #0x1a]
	cmp r0, r2
	bls _0806AAF2
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl divide_by_3
	ldrb r0, [r4]
	adds r0, r0, r6
	adds r0, r0, r7
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrb r1, [r0, #0xb]
	subs r1, #4
	strb r1, [r0, #0xb]
	ldrb r0, [r4]
	adds r0, r0, r6
	adds r0, r0, r7
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrb r1, [r0, #0xb]
	subs r1, #4
	strb r1, [r0, #0xb]
	ldrb r0, [r4]
	adds r0, r0, r6
	adds r0, r0, r7
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrb r1, [r0, #0xb]
	subs r1, #4
	strb r1, [r0, #0xb]
	ldrb r0, [r4]
	adds r0, r0, r6
	adds r0, r0, r7
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r5
	ldrb r0, [r1, #0xb]
	subs r0, #4
	strb r0, [r1, #0xb]
	ldrb r0, [r4]
	cmp r0, #1
	bhi _0806AAF2
	adds r0, r6, #1
	ldrb r4, [r4]
	adds r0, r0, r4
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x2a
	movs r1, #2
	strb r1, [r0]
_0806AAF2:
	ldr r5, _0806AB30 @ =0x03002C30
	ldr r7, _0806AB34 @ =0x08485CC4
	ldr r0, _0806AB38 @ =0x03006F8C
	mov r1, sb
	adds r6, r1, r0
	ldrb r0, [r6]
	ldr r2, [sp, #4]
	add r2, sb
	adds r0, r0, r2
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r3, r0, r5
	ldrh r1, [r3, #0x1a]
	lsls r4, r1, #0x10
	movs r0, #0xac
	lsls r0, r0, #1
	cmp r1, r0
	bls _0806AB44
	ldrh r1, [r3, #0x1a]
	ldr r2, _0806AB40 @ =0xFFFFFEA8
	adds r1, r1, r2
	asrs r1, r1, #1
	movs r0, #0xd8
	subs r0, r0, r1
	strh r0, [r3, #2]
	b _0806AB88
	.align 2, 0
_0806AB28: .4byte 0x03006FEC
_0806AB2C: .4byte 0x03006FF0
_0806AB30: .4byte 0x03002C30
_0806AB34: .4byte 0x08485CC4
_0806AB38: .4byte 0x03006F8C
_0806AB3C: .4byte 0x00000157
_0806AB40: .4byte 0xFFFFFEA8
_0806AB44:
	lsrs r0, r4, #0x11
	adds r0, #0x2c
	strh r0, [r3, #2]
	ldrb r3, [r6]
	adds r0, r3, r2
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r1, r0, r5
	ldrh r0, [r1, #0x3a]
	cmp r0, #0x97
	bhi _0806AB88
	ldrh r0, [r1, #0x1a]
	cmp r0, #0x97
	bls _0806AB88
	cmp r3, #1
	bhi _0806AB88
	adds r2, #1
	adds r0, r3, r2
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r2
	adds r0, r0, r7
	ldrb r0, [r0]
	subs r0, #3
	movs r1, #4
	bl battle_sprite_set_palette_index
_0806AB88:
	ldr r4, _0806AC10 @ =0x03006F8C
	add r4, sb
	ldrb r0, [r4]
	ldr r5, [sp, #4]
	add r5, sb
	adds r0, r0, r5
	ldr r1, _0806AC14 @ =0x08485CC4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r2, _0806AC18 @ =0x03002C30
	adds r0, r0, r2
	ldrh r1, [r0, #0x1a]
	strh r1, [r0, #0x3a]
	ldrb r0, [r4]
	adds r0, r0, r5
	ldr r1, _0806AC14 @ =0x08485CC4
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrh r0, [r1, #0x1a]
	adds r0, #1
	strh r0, [r1, #0x1a]
	ldrb r1, [r4]
	adds r0, r1, r5
	ldr r2, _0806AC14 @ =0x08485CC4
	adds r0, r0, r2
	ldrb r0, [r0]
	subs r0, #3
	subs r1, #2
	subs r1, r5, r1
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldrb r0, [r4]
	adds r1, r0, #0
	adds r1, #0x14
	adds r1, r5, r1
	lsls r1, r1, #6
	ldr r2, _0806AC18 @ =0x03002C30
	adds r1, r1, r2
	adds r0, r0, r5
	ldr r2, _0806AC14 @ =0x08485CC4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r2, _0806AC18 @ =0x03002C30
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	movs r0, #1
	add r0, sb
	mov r8, r0
_0806ABF4:
	mov sb, r8
	mov r1, sb
	cmp r1, #2
	bgt _0806ABFE
	b _0806A920
_0806ABFE:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806AC10: .4byte 0x03006F8C
_0806AC14: .4byte 0x08485CC4
_0806AC18: .4byte 0x03002C30
	.syntax divided
