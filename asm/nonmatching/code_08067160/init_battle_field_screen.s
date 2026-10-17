	.syntax unified

	thumb_func_start init_battle_field_screen
init_battle_field_screen: @ 0x0806939C
	push {r4, r5, lr}
	ldr r1, _080694A0 @ =0x03006F90
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080694A4 @ =0x0400000C
	ldr r2, _080694A8 @ =0x00001E0A
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _080694AC @ =0x00001F0B
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, _080694B0 @ =0x03001800
	ldr r0, _080694B4 @ =0x03006F84
	ldrb r0, [r0]
	adds r4, #0x38
	movs r5, #0
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, #0
	bl decompress_sprite_to_vram_08043C08
	bl load_battle_script_entry_b
	bl apply_battle_blend_effect_b
	ldr r2, _080694B8 @ =0x083B24A8
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl decompress_to_ewram_27000
	ldr r0, _080694BC @ =0x087C4EBC
	ldr r1, _080694C0 @ =0x0600C800
	bl LZ77UnCompVram
	ldr r0, _080694C4 @ =0x087C4F48
	ldr r1, _080694C8 @ =0x0600C880
	bl LZ77UnCompVram
	ldr r0, _080694CC @ =0x087C4FDC
	ldr r1, _080694D0 @ =0x0600C9C0
	bl LZ77UnCompVram
	ldr r0, _080694D4 @ =0x087C51C0
	ldr r1, _080694D8 @ =0x0600CC40
	bl LZ77UnCompVram
	ldr r0, _080694DC @ =0x040000D4
	ldr r1, _080694E0 @ =0x087C5248
	str r1, [r0]
	ldr r1, _080694E4 @ =0x05000100
	str r1, [r0, #4]
	ldr r2, _080694E8 @ =0x84000008
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080694EC @ =0x087C5268
	str r1, [r0]
	ldr r1, _080694F0 @ =0x05000120
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080694F4 @ =0x087C5288
	str r1, [r0]
	ldr r1, _080694F8 @ =0x05000140
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080694FC @ =0x087C52A8
	str r1, [r0]
	ldr r1, _08069500 @ =0x05000160
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	movs r0, #0
	movs r1, #2
	movs r2, #4
	bl write_tilemap_tiles_dma
	movs r0, #0
	movs r1, #2
	movs r2, #7
	bl write_tilemap_tiles_dma
	movs r0, #0
	movs r1, #2
	movs r2, #0xa
	bl write_tilemap_tiles_dma
	movs r0, #1
	movs r1, #6
	movs r2, #3
	bl write_tilemap_tiles_dma
	movs r0, #2
	movs r1, #0xe
	movs r2, #3
	bl write_tilemap_tiles_dma
	movs r0, #3
	movs r1, #0x1a
	movs r2, #4
	bl write_tilemap_tiles_dma
	movs r0, #3
	movs r1, #0x1a
	movs r2, #7
	bl write_tilemap_tiles_dma
	movs r0, #3
	movs r1, #0x1a
	movs r2, #0xa
	bl write_tilemap_tiles_dma
	ldr r0, _08069504 @ =0x0300057C
	strh r5, [r0]
	strh r5, [r0, #2]
	ldr r0, _08069508 @ =0x03001C04
	strh r5, [r0]
	strh r5, [r0, #2]
	ldr r1, _0806950C @ =0x030017F0
	ldr r0, _08069510 @ =battle_vblank_update_bg
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080694A0: .4byte 0x03006F90
_080694A4: .4byte 0x0400000C
_080694A8: .4byte 0x00001E0A
_080694AC: .4byte 0x00001F0B
_080694B0: .4byte 0x03001800
_080694B4: .4byte 0x03006F84
_080694B8: .4byte 0x083B24A8
_080694BC: .4byte 0x087C4EBC
_080694C0: .4byte 0x0600C800
_080694C4: .4byte 0x087C4F48
_080694C8: .4byte 0x0600C880
_080694CC: .4byte 0x087C4FDC
_080694D0: .4byte 0x0600C9C0
_080694D4: .4byte 0x087C51C0
_080694D8: .4byte 0x0600CC40
_080694DC: .4byte 0x040000D4
_080694E0: .4byte 0x087C5248
_080694E4: .4byte 0x05000100
_080694E8: .4byte 0x84000008
_080694EC: .4byte 0x087C5268
_080694F0: .4byte 0x05000120
_080694F4: .4byte 0x087C5288
_080694F8: .4byte 0x05000140
_080694FC: .4byte 0x087C52A8
_08069500: .4byte 0x05000160
_08069504: .4byte 0x0300057C
_08069508: .4byte 0x03001C04
_0806950C: .4byte 0x030017F0
_08069510: .4byte battle_vblank_update_bg
	.syntax divided
