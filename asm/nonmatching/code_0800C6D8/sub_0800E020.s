	.syntax unified

	thumb_func_start sub_0800E020
sub_0800E020: @ 0x0800E020
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	bl sub_08043CA8
	ldr r0, _0800E13C @ =0x03000440
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800E03A
	cmp r0, #4
	bne _0800E03E
_0800E03A:
	bl load_medapart_sprite_by_slot
_0800E03E:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0800E140 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r2]
	ldr r4, _0800E144 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r5, _0800E148 @ =0x0400000A
	ldr r3, _0800E14C @ =0x00001801
	adds r0, r3, #0
	strh r0, [r5]
	ldr r6, _0800E150 @ =0x0400000C
	ldr r1, _0800E154 @ =0x00001902
	adds r0, r1, #0
	strh r0, [r6]
	ldr r3, _0800E158 @ =0x0400000E
	mov r8, r3
	ldr r1, _0800E15C @ =0x00001A03
	adds r0, r1, #0
	strh r0, [r3]
	ldr r0, _0800E160 @ =0x084ECB3C
	ldr r1, _0800E164 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _0800E168 @ =0x084C43C0
	ldr r1, _0800E16C @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _0800E170 @ =0x084C47A0
	ldr r1, _0800E174 @ =0x06007080
	bl lz_decompress_dispatch
	ldr r0, _0800E178 @ =0x084C4330
	ldr r1, _0800E17C @ =0x06007100
	bl lz_decompress_dispatch
	ldr r0, _0800E180 @ =0x084C47E0
	ldr r1, _0800E184 @ =0x06007200
	bl lz_decompress_dispatch
	ldr r0, _0800E188 @ =0x084C4BAC
	ldr r1, _0800E18C @ =0x06007300
	bl lz_decompress_dispatch
	ldr r0, _0800E190 @ =0x084C3648
	ldr r1, _0800E194 @ =0x06007880
	bl lz_decompress_dispatch
	ldr r0, _0800E198 @ =0x084C7318
	ldr r1, _0800E19C @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r2, _0800E1A0 @ =0x084EF5A4
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0800E1A4 @ =0x084F0068
	ldrh r3, [r5]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0800E1A8 @ =0x084F0CA4
	ldrh r3, [r6]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0800E1AC @ =0x084F1EC8
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r5, _0800E13C @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800E0FC
	cmp r0, #4
	bne _0800E1D4
_0800E0FC:
	ldr r0, _0800E1B0 @ =0x084F3620
	ldr r1, _0800E1B4 @ =0x0202FA00
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _0800E1B8 @ =0x05000200
	ldr r1, _0800E1BC @ =0x0202F800
	movs r2, #0x80
	bl CpuFastSet
	ldr r4, _0800E1C0 @ =0x0850DDD8
	ldr r1, _0800E1C4 @ =0x0202F980
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x60
	ldr r1, _0800E1C8 @ =0x0202F9A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0800E1CC @ =0x084E2E58
	ldr r1, _0800E1D0 @ =0x0202F9C0
	movs r2, #8
	bl CpuFastSet
	adds r1, r5, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	b _0800E214
	.align 2, 0
_0800E13C: .4byte 0x03000440
_0800E140: .4byte 0x0000F0FF
_0800E144: .4byte 0x04000008
_0800E148: .4byte 0x0400000A
_0800E14C: .4byte 0x00001801
_0800E150: .4byte 0x0400000C
_0800E154: .4byte 0x00001902
_0800E158: .4byte 0x0400000E
_0800E15C: .4byte 0x00001A03
_0800E160: .4byte 0x084ECB3C
_0800E164: .4byte 0x06004000
_0800E168: .4byte 0x084C43C0
_0800E16C: .4byte 0x06006000
_0800E170: .4byte 0x084C47A0
_0800E174: .4byte 0x06007080
_0800E178: .4byte 0x084C4330
_0800E17C: .4byte 0x06007100
_0800E180: .4byte 0x084C47E0
_0800E184: .4byte 0x06007200
_0800E188: .4byte 0x084C4BAC
_0800E18C: .4byte 0x06007300
_0800E190: .4byte 0x084C3648
_0800E194: .4byte 0x06007880
_0800E198: .4byte 0x084C7318
_0800E19C: .4byte 0x06017E00
_0800E1A0: .4byte 0x084EF5A4
_0800E1A4: .4byte 0x084F0068
_0800E1A8: .4byte 0x084F0CA4
_0800E1AC: .4byte 0x084F1EC8
_0800E1B0: .4byte 0x084F3620
_0800E1B4: .4byte 0x0202FA00
_0800E1B8: .4byte 0x05000200
_0800E1BC: .4byte 0x0202F800
_0800E1C0: .4byte 0x0850DDD8
_0800E1C4: .4byte 0x0202F980
_0800E1C8: .4byte 0x0202F9A0
_0800E1CC: .4byte 0x084E2E58
_0800E1D0: .4byte 0x0202F9C0
_0800E1D4:
	ldr r0, _0800E288 @ =0x084F3620
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r4, _0800E28C @ =0x0850DDD8
	ldr r1, _0800E290 @ =0x05000380
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x60
	ldr r1, _0800E294 @ =0x050003A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0800E298 @ =0x084E2E58
	ldr r1, _0800E29C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	bl init_scene_buffers_0800F60C
	bl load_overworld_sprite_by_direction
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
_0800E214:
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, _0800E2A0 @ =0x03002C30
	ldr r2, _0800E2A4 @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xfb
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _0800E2A8 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x3e
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0xee
	bl load_part_data
	bl load_npc_sprite_data
	bl load_scene_sprite_data
	bl render_menu_tilemap_section
	bl load_script_data_to_buffer
	bl fill_bg1_tilemap_from_state
	bl setup_menu_tilemap_by_state
	bl render_shop_price_display
	bl count_compatible_medaparts
	bl setup_battle_bot_count_sprites
	adds r1, r4, #0
	adds r1, #0x42
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0800E2AC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800E288: .4byte 0x084F3620
_0800E28C: .4byte 0x0850DDD8
_0800E290: .4byte 0x05000380
_0800E294: .4byte 0x050003A0
_0800E298: .4byte 0x084E2E58
_0800E29C: .4byte 0x050003C0
_0800E2A0: .4byte 0x03002C30
_0800E2A4: .4byte 0x01000800
_0800E2A8: .4byte 0x03000440
_0800E2AC: .4byte 0x0300137C
	.syntax divided
