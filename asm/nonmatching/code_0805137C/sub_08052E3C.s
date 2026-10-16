	.syntax unified

	thumb_func_start sub_08052E3C
	.global sub_08052E3C
sub_08052E3C: @ 0x08052E3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r2, #0
	ldr r3, _08052EF4 @ =0x030057E0
	ldr r1, _08052EF8 @ =0x000007FE
	adds r0, r3, r1
	ldrb r0, [r0]
	ldr r1, _08052EFC @ =0x08413114
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _08052EE2
	adds r5, r3, #0
	ldr r3, _08052F00 @ =0x00000C56
	adds r3, r3, r5
	mov sb, r3
	ldr r6, _08052F04 @ =0x00000C52
	adds r6, r6, r5
	mov r8, r6
	ldr r0, _08052F08 @ =0x00000C54
	adds r7, r5, r0
	adds r4, r1, #0
_08052E70:
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	mov r3, sb
	ldrb r3, [r3]
	cmp r0, r3
	bne _08052ED6
	ldr r0, _08052F0C @ =0x00000C57
	adds r6, r5, r0
	ldrb r3, [r6]
	cmp r1, r3
	bne _08052ED6
	ldrb r1, [r4, #2]
	ldr r2, _08052EF8 @ =0x000007FE
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r0, [r0]
	bl load_npc_sprite_and_calc_camera_offset
	ldrb r1, [r4, #3]
	movs r0, #7
	ands r0, r1
	bl set_battle_entity_animation_attack
	ldrb r0, [r4, #6]
	ldr r3, _08052F10 @ =0x00000C48
	adds r1, r5, r3
	lsls r0, r0, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1]
	ldrb r0, [r4, #7]
	ldr r2, _08052F14 @ =0x00000C4A
	adds r1, r5, r2
	lsls r0, r0, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r7]
	mov r3, r8
	ldrh r0, [r3]
	bl sub_080526F0
	mov r1, sb
	strb r0, [r1]
	ldrh r0, [r7]
	bl sub_08052714
	strb r0, [r6]
	bl calculate_camera_scroll_from_npc
	movs r2, #1
_08052ED6:
	adds r4, #8
	cmp r2, #0
	bne _08052EE2
	ldrb r0, [r4]
	cmp r0, #0xff
	bne _08052E70
_08052EE2:
	bl update_cursor_tile_position
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052EF4: .4byte 0x030057E0
_08052EF8: .4byte 0x000007FE
_08052EFC: .4byte 0x08413114
_08052F00: .4byte 0x00000C56
_08052F04: .4byte 0x00000C52
_08052F08: .4byte 0x00000C54
_08052F0C: .4byte 0x00000C57
_08052F10: .4byte 0x00000C48
_08052F14: .4byte 0x00000C4A
	.syntax divided
