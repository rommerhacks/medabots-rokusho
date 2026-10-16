	.syntax unified

	thumb_func_start sub_080075AC
sub_080075AC: @ 0x080075AC
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x10
	movs r6, #0x80
	lsls r6, r6, #0x13
	ldrh r1, [r6]
	ldr r0, _08007784 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r6]
	ldr r4, _08007788 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r2, _0800778C @ =0x0400000A
	mov r8, r2
	ldr r1, _08007790 @ =0x00001801
	adds r0, r1, #0
	strh r0, [r2]
	adds r2, #2
	mov sb, r2
	ldr r1, _08007794 @ =0x00001902
	adds r0, r1, #0
	strh r0, [r2]
	adds r2, #2
	mov sl, r2
	ldr r1, _08007798 @ =0x00001A03
	adds r0, r1, #0
	strh r0, [r2]
	ldr r0, _0800779C @ =0x084E7264
	ldr r1, _080077A0 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _080077A4 @ =0x084C32DC
	ldr r1, _080077A8 @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _080077AC @ =0x084C3208
	ldr r1, _080077B0 @ =0x06006280
	bl lz_decompress_dispatch
	ldr r0, _080077B4 @ =0x084C48B4
	ldr r1, _080077B8 @ =0x06007400
	bl lz_decompress_dispatch
	ldr r0, _080077BC @ =0x084C4A34
	ldr r1, _080077C0 @ =0x06007600
	bl lz_decompress_dispatch
	ldr r0, _080077C4 @ =0x084C6A98
	ldr r1, _080077C8 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r0, _080077CC @ =0x084C7318
	ldr r1, _080077D0 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r0, _080077D4 @ =0x0848833C
	ldr r1, _080077D8 @ =0x06006A00
	bl lz_decompress_dispatch
	ldr r2, _080077DC @ =0x084EF348
	ldrh r3, [r4]
	movs r5, #0x80
	lsls r5, r5, #2
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080077E0 @ =0x084EFB5C
	mov r0, r8
	ldrh r3, [r0]
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080077E4 @ =0x084F04F0
	mov r1, sb
	ldrh r3, [r1]
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080077E8 @ =0x084F1554
	mov r0, sl
	ldrh r3, [r0]
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _080077EC @ =0x084F2BA0
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _080077F0 @ =0x08488B44
	ldr r1, _080077F4 @ =0x05000160
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080077F8 @ =0x0850DEF8
	ldr r1, _080077FC @ =0x05000200
	movs r2, #0x40
	bl CpuFastSet
	ldr r4, _08007800 @ =0x0850DD58
	ldr r1, _08007804 @ =0x05000300
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	subs r0, #0x40
	ldr r1, _08007808 @ =0x05000320
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0800780C @ =0x084E2E98
	ldr r1, _08007810 @ =0x050003A0
	movs r2, #8
	bl CpuFastSet
	adds r4, #0xc0
	ldr r1, _08007814 @ =0x05000340
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08007818 @ =0x084E2E58
	ldr r1, _0800781C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _08007820 @ =0x03002C30
	ldr r2, _08007824 @ =0x01000800
	add r0, sp, #0xc
	bl CpuFastSet
	ldrh r0, [r6]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6]
	bl sub_0800941C
	ldr r1, _08007828 @ =0x083B4AE0
	ldr r4, _0800782C @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	adds r0, #0x4b
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0xa
	movs r1, #2
	movs r2, #5
	movs r3, #2
	bl write_tilemap_rect
	bl render_medal_sprite_tile
	bl render_medal_list_entries
	bl render_medal_slots_in_menu
	bl render_medal_name_display
	bl load_medal_sprite
	bl render_medal_level_display
	bl sub_0800988C
	bl sub_08009900
	bl sub_0800944C
	bl decompress_active_medal_sprite
	bl init_active_medal_battle_sprites
	bl draw_medal_position_tile
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #4
	bne _08007764
	adds r1, r4, #0
	adds r1, #0x4b
	ldrb r0, [r1]
	cmp r0, #0
	bne _08007764
	movs r0, #1
	strb r0, [r1]
	movs r0, #7
	bl play_song
_08007764:
	ldr r0, _0800782C @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08007830 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007784: .4byte 0x0000F0FF
_08007788: .4byte 0x04000008
_0800778C: .4byte 0x0400000A
_08007790: .4byte 0x00001801
_08007794: .4byte 0x00001902
_08007798: .4byte 0x00001A03
_0800779C: .4byte 0x084E7264
_080077A0: .4byte 0x06004000
_080077A4: .4byte 0x084C32DC
_080077A8: .4byte 0x06006000
_080077AC: .4byte 0x084C3208
_080077B0: .4byte 0x06006280
_080077B4: .4byte 0x084C48B4
_080077B8: .4byte 0x06007400
_080077BC: .4byte 0x084C4A34
_080077C0: .4byte 0x06007600
_080077C4: .4byte 0x084C6A98
_080077C8: .4byte 0x06017400
_080077CC: .4byte 0x084C7318
_080077D0: .4byte 0x06017E00
_080077D4: .4byte 0x0848833C
_080077D8: .4byte 0x06006A00
_080077DC: .4byte 0x084EF348
_080077E0: .4byte 0x084EFB5C
_080077E4: .4byte 0x084F04F0
_080077E8: .4byte 0x084F1554
_080077EC: .4byte 0x084F2BA0
_080077F0: .4byte 0x08488B44
_080077F4: .4byte 0x05000160
_080077F8: .4byte 0x0850DEF8
_080077FC: .4byte 0x05000200
_08007800: .4byte 0x0850DD58
_08007804: .4byte 0x05000300
_08007808: .4byte 0x05000320
_0800780C: .4byte 0x084E2E98
_08007810: .4byte 0x050003A0
_08007814: .4byte 0x05000340
_08007818: .4byte 0x084E2E58
_0800781C: .4byte 0x050003C0
_08007820: .4byte 0x03002C30
_08007824: .4byte 0x01000800
_08007828: .4byte 0x083B4AE0
_0800782C: .4byte 0x03000440
_08007830: .4byte 0x0300137C
	.syntax divided
