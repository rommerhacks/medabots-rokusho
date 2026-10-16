	.syntax unified

	thumb_func_start sub_0800406C
sub_0800406C: @ 0x0800406C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	ldr r7, _08004194 @ =0x03000440
	movs r0, #0x56
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08004088
	bl setup_overworld_scene_from_position
_08004088:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _08004198 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r2]
	ldr r4, _0800419C @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r5, _080041A0 @ =0x0400000A
	ldr r3, _080041A4 @ =0x00001801
	adds r0, r3, #0
	strh r0, [r5]
	ldr r6, _080041A8 @ =0x0400000C
	ldr r1, _080041AC @ =0x00001902
	adds r0, r1, #0
	strh r0, [r6]
	ldr r3, _080041B0 @ =0x0400000E
	mov r8, r3
	ldr r1, _080041B4 @ =0x00001A03
	adds r0, r1, #0
	strh r0, [r3]
	ldr r0, _080041B8 @ =0x084E61CC
	ldr r1, _080041BC @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _080041C0 @ =0x084C48B4
	ldr r1, _080041C4 @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _080041C8 @ =0x084C4A34
	ldr r1, _080041CC @ =0x06006200
	bl lz_decompress_dispatch
	ldr r0, _080041D0 @ =0x084C3208
	ldr r1, _080041D4 @ =0x06007480
	bl lz_decompress_dispatch
	ldr r0, _080041D8 @ =0x084C33DC
	ldr r1, _080041DC @ =0x06006800
	bl lz_decompress_dispatch
	ldr r0, _080041E0 @ =0x084C4DB0
	ldr r1, _080041E4 @ =0x06006E00
	bl lz_decompress_dispatch
	ldr r0, _080041E8 @ =0x084C7318
	ldr r1, _080041EC @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r0, _080041F0 @ =0x084C6A98
	ldr r1, _080041F4 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r2, _080041F8 @ =0x084EF310
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080041FC @ =0x084EF9C8
	ldrh r3, [r5]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08004200 @ =0x084F03EC
	ldrh r3, [r6]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08004204 @ =0x084F13C0
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	mov r1, sb
	ldrb r5, [r1]
	cmp r5, #0
	bne _08004230
	ldr r0, _08004208 @ =0x084F2820
	ldr r1, _0800420C @ =0x0202FA00
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _08004210 @ =0x0850DEF8
	ldr r1, _08004214 @ =0x0202F800
	movs r2, #0x40
	bl CpuFastSet
	ldr r4, _08004218 @ =0x0850DD58
	ldr r1, _0800421C @ =0x0202F980
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	adds r0, #0x40
	ldr r1, _08004220 @ =0x0202F9A0
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x40
	ldr r1, _08004224 @ =0x0202F9E0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08004228 @ =0x084E2E58
	ldr r1, _0800422C @ =0x0202F9C0
	movs r2, #8
	bl CpuFastSet
	adds r0, r7, #0
	adds r0, #0x5a
	strb r5, [r0]
	bl sub_080059D0
	adds r0, r7, #0
	adds r0, #0x84
	strb r5, [r0]
	b _0800427E
	.align 2, 0
_08004194: .4byte 0x03000440
_08004198: .4byte 0x0000F0FF
_0800419C: .4byte 0x04000008
_080041A0: .4byte 0x0400000A
_080041A4: .4byte 0x00001801
_080041A8: .4byte 0x0400000C
_080041AC: .4byte 0x00001902
_080041B0: .4byte 0x0400000E
_080041B4: .4byte 0x00001A03
_080041B8: .4byte 0x084E61CC
_080041BC: .4byte 0x06004000
_080041C0: .4byte 0x084C48B4
_080041C4: .4byte 0x06006000
_080041C8: .4byte 0x084C4A34
_080041CC: .4byte 0x06006200
_080041D0: .4byte 0x084C3208
_080041D4: .4byte 0x06007480
_080041D8: .4byte 0x084C33DC
_080041DC: .4byte 0x06006800
_080041E0: .4byte 0x084C4DB0
_080041E4: .4byte 0x06006E00
_080041E8: .4byte 0x084C7318
_080041EC: .4byte 0x06017E00
_080041F0: .4byte 0x084C6A98
_080041F4: .4byte 0x06017400
_080041F8: .4byte 0x084EF310
_080041FC: .4byte 0x084EF9C8
_08004200: .4byte 0x084F03EC
_08004204: .4byte 0x084F13C0
_08004208: .4byte 0x084F2820
_0800420C: .4byte 0x0202FA00
_08004210: .4byte 0x0850DEF8
_08004214: .4byte 0x0202F800
_08004218: .4byte 0x0850DD58
_0800421C: .4byte 0x0202F980
_08004220: .4byte 0x0202F9A0
_08004224: .4byte 0x0202F9E0
_08004228: .4byte 0x084E2E58
_0800422C: .4byte 0x0202F9C0
_08004230:
	ldr r0, _08004370 @ =0x084F2820
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _08004374 @ =0x0850DEF8
	ldr r1, _08004378 @ =0x05000200
	movs r2, #0x40
	bl CpuFastSet
	ldr r4, _0800437C @ =0x0850DD58
	ldr r1, _08004380 @ =0x05000380
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	adds r0, #0x40
	ldr r1, _08004384 @ =0x050003A0
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x40
	ldr r1, _08004388 @ =0x050003E0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0800438C @ =0x084E2E58
	ldr r1, _08004390 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
_0800427E:
	movs r7, #0
	str r7, [sp, #0x1c]
	ldr r1, _08004394 @ =0x03002C30
	ldr r2, _08004398 @ =0x01000800
	add r0, sp, #0x1c
	bl CpuFastSet
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xfa
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r1, [r2]
	ldr r0, _0800439C @ =0x0000FFDF
	ands r0, r1
	strh r0, [r2]
	ldr r6, _080043A0 @ =0x03000440
	adds r0, r6, #0
	adds r0, #0x53
	strb r7, [r0]
	adds r0, #0x43
	movs r5, #1
	strb r5, [r0]
	movs r0, #0
	bl sub_08006238
	movs r0, #0
	bl sub_08006284
	movs r0, #0
	bl sub_080062D0
	movs r0, #0
	bl sub_0800631C
	movs r0, #0
	bl sub_08006368
	bl sub_08005AD0
	bl sub_08005B44
	bl sub_08005C10
	bl sub_08005BB4
	bl render_script_text_window
	bl render_medal_skill_row_0
	bl render_medal_name_text
	bl render_medal_skill_row_1
	bl render_medal_desc_text
	bl render_medal_skill_row_2
	bl render_script_text_line
	bl render_medal_skill_row_3
	bl draw_battle_stat_value
	bl decompress_sprite_from_game_state
	adds r0, r6, #0
	adds r0, #0x98
	ldrb r0, [r0]
	adds r1, r6, #0
	adds r1, #0x99
	ldrb r1, [r1]
	adds r2, r6, #0
	adds r2, #0x9a
	ldrb r2, [r2]
	adds r3, r6, #0
	adds r3, #0x9b
	ldrb r3, [r3]
	str r7, [sp]
	movs r4, #6
	str r4, [sp, #4]
	movs r4, #0xa8
	str r4, [sp, #8]
	movs r4, #0x20
	str r4, [sp, #0xc]
	adds r4, r6, #0
	adds r4, #0x5e
	ldrb r4, [r4]
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	bl init_battle_medabot_sprites
	bl setup_battle_cursor_sprites
	adds r0, r6, #0
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #0
	beq _08004352
	bl init_scene_state
_08004352:
	adds r0, r6, #0
	adds r0, #0x84
	strb r7, [r0]
	ldr r1, _080043A4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004370: .4byte 0x084F2820
_08004374: .4byte 0x0850DEF8
_08004378: .4byte 0x05000200
_0800437C: .4byte 0x0850DD58
_08004380: .4byte 0x05000380
_08004384: .4byte 0x050003A0
_08004388: .4byte 0x050003E0
_0800438C: .4byte 0x084E2E58
_08004390: .4byte 0x050003C0
_08004394: .4byte 0x03002C30
_08004398: .4byte 0x01000800
_0800439C: .4byte 0x0000FFDF
_080043A0: .4byte 0x03000440
_080043A4: .4byte 0x0300137C
	.syntax divided
