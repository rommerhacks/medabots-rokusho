	.syntax unified

	thumb_func_start sub_08013B8C
sub_08013B8C: @ 0x08013B8C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0xc
	bl sub_08043CA8
	movs r5, #0x80
	lsls r5, r5, #0x13
	ldrh r1, [r5]
	ldr r0, _08013D40 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r5]
	ldr r4, _08013D44 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r2, _08013D48 @ =0x0400000A
	mov r8, r2
	ldr r1, _08013D4C @ =0x00001901
	adds r0, r1, #0
	strh r0, [r2]
	ldr r6, _08013D50 @ =0x0400000C
	ldr r2, _08013D54 @ =0x00001A02
	adds r0, r2, #0
	strh r0, [r6]
	ldr r0, _08013D58 @ =0x0400000E
	mov sb, r0
	ldr r1, _08013D5C @ =0x00001B03
	adds r0, r1, #0
	mov r2, sb
	strh r0, [r2]
	ldr r0, _08013D60 @ =0x084ED4C4
	ldr r1, _08013D64 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _08013D68 @ =0x084C50D8
	ldr r1, _08013D6C @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _08013D70 @ =0x084C33DC
	ldr r1, _08013D74 @ =0x06006800
	bl lz_decompress_dispatch
	ldr r0, _08013D78 @ =0x084C4DB0
	ldr r1, _08013D7C @ =0x06006E00
	bl lz_decompress_dispatch
	ldr r0, _08013D80 @ =0x084C36F0
	ldr r1, _08013D84 @ =0x06007200
	bl lz_decompress_dispatch
	ldr r0, _08013D88 @ =0x084C50BC
	ldr r1, _08013D8C @ =0x06007480
	bl lz_decompress_dispatch
	ldr r0, _08013D90 @ =0x084C7318
	ldr r1, _08013D94 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r2, _08013D98 @ =0x084EF5DC
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08013D9C @ =0x084F0128
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08013DA0 @ =0x084F0D24
	ldrh r3, [r6]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08013DA4 @ =0x084F205C
	mov r1, sb
	ldrh r3, [r1]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _08013DA8 @ =0x084F37E0
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _08013DAC @ =0x0850DEF8
	ldr r1, _08013DB0 @ =0x05000200
	movs r2, #0x40
	bl CpuFastSet
	ldr r4, _08013DB4 @ =0x0850DD58
	ldr r1, _08013DB8 @ =0x05000380
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	adds r0, #0x40
	ldr r1, _08013DBC @ =0x050003A0
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x40
	ldr r1, _08013DC0 @ =0x050003E0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08013DC4 @ =0x084E2E58
	ldr r1, _08013DC8 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0
	str r0, [sp, #8]
	ldr r1, _08013DCC @ =0x03002C30
	ldr r2, _08013DD0 @ =0x01000800
	add r0, sp, #8
	bl CpuFastSet
	ldrh r0, [r5]
	movs r2, #0xfa
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r4, _08013DD4 @ =0x0300047C
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r0, #1
	strb r0, [r4, #0xa]
	movs r0, #0
	movs r1, #0
	bl position_battle_team_cursors
	bl init_battle_cursor_sprite_08017B24
	bl render_battle_bot_label
	bl sub_08017D14
	bl load_bot_sprite_tiles_to_vram
	bl copy_battle_bot_data_to_state
	bl battle_load_script_to_buffer
	bl battle_setup_bot_font_tile
	bl render_battle_bot_status_row
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r4, [r4, #1]
	adds r0, r0, r4
	ldr r4, _08013DD8 @ =0x03001864
	adds r1, r4, #0
	bl get_bot_part_effective_values
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	bl set_game_state_params
	bl init_ewram_buffers_and_state
	bl setup_battle_bot_display
	movs r0, #0
	movs r1, #8
	bl battle_sprite_set_palette_index
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp]
	ldr r0, _08013DDC @ =0x000063C0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xb
	movs r3, #2
	bl fill_tilemap_rect_08042698
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _08013DE0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013D40: .4byte 0x0000F0FF
_08013D44: .4byte 0x04000008
_08013D48: .4byte 0x0400000A
_08013D4C: .4byte 0x00001901
_08013D50: .4byte 0x0400000C
_08013D54: .4byte 0x00001A02
_08013D58: .4byte 0x0400000E
_08013D5C: .4byte 0x00001B03
_08013D60: .4byte 0x084ED4C4
_08013D64: .4byte 0x06004000
_08013D68: .4byte 0x084C50D8
_08013D6C: .4byte 0x06006000
_08013D70: .4byte 0x084C33DC
_08013D74: .4byte 0x06006800
_08013D78: .4byte 0x084C4DB0
_08013D7C: .4byte 0x06006E00
_08013D80: .4byte 0x084C36F0
_08013D84: .4byte 0x06007200
_08013D88: .4byte 0x084C50BC
_08013D8C: .4byte 0x06007480
_08013D90: .4byte 0x084C7318
_08013D94: .4byte 0x06017E00
_08013D98: .4byte 0x084EF5DC
_08013D9C: .4byte 0x084F0128
_08013DA0: .4byte 0x084F0D24
_08013DA4: .4byte 0x084F205C
_08013DA8: .4byte 0x084F37E0
_08013DAC: .4byte 0x0850DEF8
_08013DB0: .4byte 0x05000200
_08013DB4: .4byte 0x0850DD58
_08013DB8: .4byte 0x05000380
_08013DBC: .4byte 0x050003A0
_08013DC0: .4byte 0x050003E0
_08013DC4: .4byte 0x084E2E58
_08013DC8: .4byte 0x050003C0
_08013DCC: .4byte 0x03002C30
_08013DD0: .4byte 0x01000800
_08013DD4: .4byte 0x0300047C
_08013DD8: .4byte 0x03001864
_08013DDC: .4byte 0x000063C0
_08013DE0: .4byte 0x0300137C
	.syntax divided
