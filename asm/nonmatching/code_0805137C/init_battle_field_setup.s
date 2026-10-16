	.syntax unified

	thumb_func_start init_battle_field_setup
	.global init_battle_field_setup
init_battle_field_setup: @ 0x080517A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r4, _08051880 @ =0x030057E0
	ldr r0, _08051884 @ =0x00000C58
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08051888 @ =0x00000C5C
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _0805188C @ =0x00000C28
	adds r0, r4, r2
	strb r1, [r0]
	bl load_battle_terrain_data
	ldr r0, _08051890 @ =0x00000C52
	adds r0, r0, r4
	mov r8, r0
	ldrh r0, [r0]
	bl sub_080526F0
	ldr r2, _08051894 @ =0x00000C56
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08051898 @ =0x00000C54
	adds r6, r4, r0
	ldrh r0, [r6]
	bl sub_08052714
	ldr r2, _0805189C @ =0x00000C57
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _080518A0 @ =0x0000C804
	mov sb, r0
	movs r5, #1
	str r5, [sp]
	movs r0, #0x2f
	mov r1, sb
	movs r2, #3
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	ldr r1, _080518A4 @ =0x00000C67
	adds r0, r4, r1
	ldrb r0, [r0]
	bl field_set_player_facing
	movs r0, #3
	bl update_battle_direction_indicator
	ldr r7, _080518A8 @ =0x03002C30
	ldr r2, _080518AC @ =0x00000BCB
	adds r1, r7, r2
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _080518B0 @ =0x085FA104
	ldr r1, _080518B4 @ =0x06017FC0
	bl LZ77UnCompVram
	ldr r1, _080518B8 @ =0x0000CC0C
	str r5, [sp]
	movs r0, #0x59
	movs r2, #0x90
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	mov r0, r8
	ldrh r1, [r0]
	ldr r0, _080518BC @ =0x0000164C
	adds r2, r7, r0
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldrh r1, [r6]
	subs r1, #5
	ldr r0, _080518C0 @ =0x00001650
	adds r2, r7, r0
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080518C4 @ =0x00000BC2
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _080518C8 @ =0x00001642
	adds r0, r7, r2
	strh r1, [r0]
	ldr r1, _080518CC @ =0x00000BC4
	adds r0, r7, r1
	ldrh r0, [r0]
	subs r0, #5
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldr r0, _080518D0 @ =0x00000C5B
	adds r4, r4, r0
	ldrb r3, [r4]
	cmp r3, #0
	beq _080518D4
	movs r1, #0xbc
	lsls r1, r1, #4
	adds r0, r7, r1
	mov r2, sb
	strh r2, [r0]
	b _080518E4
	.align 2, 0
_08051880: .4byte 0x030057E0
_08051884: .4byte 0x00000C58
_08051888: .4byte 0x00000C5C
_0805188C: .4byte 0x00000C28
_08051890: .4byte 0x00000C52
_08051894: .4byte 0x00000C56
_08051898: .4byte 0x00000C54
_0805189C: .4byte 0x00000C57
_080518A0: .4byte 0x0000C804
_080518A4: .4byte 0x00000C67
_080518A8: .4byte 0x03002C30
_080518AC: .4byte 0x00000BCB
_080518B0: .4byte 0x085FA104
_080518B4: .4byte 0x06017FC0
_080518B8: .4byte 0x0000CC0C
_080518BC: .4byte 0x0000164C
_080518C0: .4byte 0x00001650
_080518C4: .4byte 0x00000BC2
_080518C8: .4byte 0x00001642
_080518CC: .4byte 0x00000BC4
_080518D0: .4byte 0x00000C5B
_080518D4:
	movs r1, #0xbc
	lsls r1, r1, #4
	adds r0, r7, r1
	strh r3, [r0]
	movs r2, #0xb2
	lsls r2, r2, #5
	adds r0, r7, r2
	strh r3, [r0]
_080518E4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
