	.syntax unified

	thumb_func_start init_scene_with_palette_and_song_5
init_scene_with_palette_and_song_5: @ 0x08067440
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	mov r4, sp
	mov r0, sp
	movs r1, #0
	movs r2, #0x80
	bl custom_memset
	movs r5, #0
	ldr r0, _08067648 @ =0x00006B40
	strh r0, [r4, #2]
	ldr r0, _0806764C @ =0x00005EE0
	strh r0, [r4, #0x22]
	mov r1, sp
	adds r1, #0x42
	movs r0, #0xa5
	lsls r0, r0, #7
	strh r0, [r1]
	adds r1, #0x20
	ldr r0, _08067650 @ =0x00004A40
	strh r0, [r1]
	movs r0, #5
	bl play_song
	add r0, sp, #0x80
	str r5, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _08067654 @ =0x01006000
	bl CpuFastSet
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_080415BC
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, _08067658 @ =0x00006060
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, _0806765C @ =0x04000008
	ldr r3, _08067660 @ =0x00001B04
	adds r0, r3, #0
	strh r0, [r4]
	ldr r0, _08067664 @ =0x087A3CFC
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r5, _08067668 @ =0x00001F04
	adds r0, r5, #0
	strh r0, [r4]
	ldr r1, _0806766C @ =0x0400000A
	ldr r2, _08067670 @ =0x00001E05
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08067674 @ =0x00003D06
	adds r0, r3, #0
	strh r0, [r1]
	adds r4, #6
	ldr r5, _08067678 @ =0x00001C07
	adds r0, r5, #0
	strh r0, [r4]
	ldr r0, _0806767C @ =0x087A3E64
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _08067680 @ =0x087A40A0
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _08067684 @ =0x087A1410
	ldr r4, _08067688 @ =0x02030000
	adds r1, r4, #0
	bl dma3_copy_or_decompress
	adds r2, r0, #0
	ldr r1, _0806768C @ =0x06004000
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuFastSet
	ldr r0, _08067690 @ =0x087A13B0
	ldr r1, _08067694 @ =0x0202FA00
	movs r2, #0x18
	bl CpuFastSet
	ldr r1, _08067698 @ =0x0202F800
	mov r0, sp
	movs r2, #0x20
	bl CpuFastSet
	ldr r0, _0806769C @ =0x08785F34
	ldr r1, _080676A0 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _080676A4 @ =0x0850DEB8
	ldr r1, _080676A8 @ =0x05000200
	movs r2, #8
	bl CpuFastSet
	movs r3, #0
	ldr r1, _080676AC @ =0x03006F74
	movs r4, #0x78
	movs r2, #0x50
	adds r7, r1, #0
_0806751A:
	ldr r0, [r1]
	adds r0, #0xa2
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r1]
	adds r0, #0xa7
	adds r0, r0, r3
	strb r2, [r0]
	adds r3, #1
	cmp r3, #4
	bls _0806751A
	movs r3, #0
	ldr r6, _080676B0 @ =0x03002C30
	ldr r5, _080676AC @ =0x03006F74
	movs r4, #0
_08067538:
	ldr r1, [r5]
	lsls r2, r3, #1
	adds r0, r1, #0
	adds r0, #0x8a
	adds r0, r0, r2
	strh r4, [r0]
	adds r0, r1, #0
	adds r0, #0x92
	adds r0, r0, r2
	strh r4, [r0]
	adds r1, #0x9a
	adds r1, r1, r2
	strh r4, [r1]
	adds r3, #1
	cmp r3, #3
	bls _08067538
	ldr r1, [r7]
	movs r0, #0
	strh r0, [r1, #0x3c]
	movs r3, #0
	adds r5, r6, #0
	adds r5, #0x40
_08067564:
	adds r4, r3, #1
	movs r0, #0xc8
	lsls r0, r0, #8
	strh r0, [r5]
	movs r0, #2
	strb r0, [r5, #0x1c]
	adds r0, r3, #0
	movs r1, #0x12
	bl sub_0807CBBC
	strb r0, [r5, #0xa]
	movs r0, #0x8b
	lsls r0, r0, #1
	strh r0, [r5, #6]
	adds r5, #0x40
	adds r3, r4, #0
	cmp r3, #0x47
	ble _08067564
	movs r4, #0
	bl init_fade_color_blend_params
	movs r0, #0x32
	bl battle_ui_setup_partial
	ldr r0, _080676B4 @ =0x04000042
	movs r2, #0xf0
	strh r2, [r0]
	ldr r1, _080676B8 @ =0x04000046
	ldr r3, _080676BC @ =0x00001888
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _080676C0 @ =0x04000040
	strh r2, [r0]
	subs r1, #2
	movs r5, #0xa2
	lsls r5, r5, #6
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, #4
	ldr r2, _080676C4 @ =0x00003D3F
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080676C8 @ =0x0400004A
	movs r3, #0
	strh r4, [r0]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #3
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #4
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080676CC @ =0x04000050
	ldr r2, _080676D0 @ =0x00000844
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r5, #4
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #8
	strh r0, [r1]
	ldr r1, _080676AC @ =0x03006F74
	ldr r0, [r1]
	strh r4, [r0, #0x3a]
	adds r0, #0x48
	strb r3, [r0]
	ldr r0, [r1]
	adds r0, #0x49
	strb r3, [r0]
	ldr r0, [r1]
	adds r0, #0x4a
	strb r3, [r0]
	ldr r0, [r1]
	adds r0, #0x4b
	strb r3, [r0]
	ldr r0, _080676D4 @ =0x03000440
	adds r0, #0x84
	strb r3, [r0]
	ldr r1, _080676D8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x84
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067648: .4byte 0x00006B40
_0806764C: .4byte 0x00005EE0
_08067650: .4byte 0x00004A40
_08067654: .4byte 0x01006000
_08067658: .4byte 0x00006060
_0806765C: .4byte 0x04000008
_08067660: .4byte 0x00001B04
_08067664: .4byte 0x087A3CFC
_08067668: .4byte 0x00001F04
_0806766C: .4byte 0x0400000A
_08067670: .4byte 0x00001E05
_08067674: .4byte 0x00003D06
_08067678: .4byte 0x00001C07
_0806767C: .4byte 0x087A3E64
_08067680: .4byte 0x087A40A0
_08067684: .4byte 0x087A1410
_08067688: .4byte 0x02030000
_0806768C: .4byte 0x06004000
_08067690: .4byte 0x087A13B0
_08067694: .4byte 0x0202FA00
_08067698: .4byte 0x0202F800
_0806769C: .4byte 0x08785F34
_080676A0: .4byte 0x06010000
_080676A4: .4byte 0x0850DEB8
_080676A8: .4byte 0x05000200
_080676AC: .4byte 0x03006F74
_080676B0: .4byte 0x03002C30
_080676B4: .4byte 0x04000042
_080676B8: .4byte 0x04000046
_080676BC: .4byte 0x00001888
_080676C0: .4byte 0x04000040
_080676C4: .4byte 0x00003D3F
_080676C8: .4byte 0x0400004A
_080676CC: .4byte 0x04000050
_080676D0: .4byte 0x00000844
_080676D4: .4byte 0x03000440
_080676D8: .4byte 0x0300137C
	.syntax divided
