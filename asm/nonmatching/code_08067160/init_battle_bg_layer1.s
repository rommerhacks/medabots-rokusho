	.syntax unified

	thumb_func_start init_battle_bg_layer1
init_battle_bg_layer1: @ 0x08069514
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	add r1, sp, #4
	movs r0, #0
	strh r0, [r1]
	ldr r4, _080695E4 @ =0x040000D4
	str r1, [r4]
	ldr r0, _080695E8 @ =0x0600E800
	str r0, [r4, #4]
	ldr r0, _080695EC @ =0x81000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080695F0 @ =0x087C52C8
	ldr r1, _080695F4 @ =0x0600CD00
	bl LZ77UnCompVram
	ldr r0, _080695F8 @ =0x087C5518
	ldr r1, _080695FC @ =0x0600D0A0
	bl LZ77UnCompVram
	ldr r0, _08069600 @ =0x087C55D0
	str r0, [r4]
	ldr r0, _08069604 @ =0x05000180
	str r0, [r4, #4]
	ldr r1, _08069608 @ =0x84000008
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806960C @ =0x087C55F0
	str r0, [r4]
	ldr r0, _08069610 @ =0x050001A0
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #4
	movs r1, #1
	movs r2, #0xe
	bl write_tilemap_tiles_dma
	movs r0, #4
	movs r1, #0xb
	movs r2, #0xe
	bl write_tilemap_tiles_dma
	movs r0, #4
	movs r1, #0x15
	movs r2, #0xe
	bl write_tilemap_tiles_dma
	ldr r1, _08069614 @ =0x0400000A
	ldr r2, _08069618 @ =0x00001D0D
	adds r0, r2, #0
	strh r0, [r1]
	movs r6, #0xc4
	lsls r6, r6, #8
	movs r5, #1
	str r5, [sp]
	movs r0, #1
	adds r1, r6, #0
	movs r2, #0x6f
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	ldr r7, _0806961C @ =0x03002C30
	adds r1, r7, #0
	adds r1, #0x42
	movs r0, #0xf
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	movs r4, #0x7f
	strh r4, [r0]
	str r5, [sp]
	movs r0, #2
	adds r1, r6, #0
	movs r2, #0x7b
	movs r3, #9
	bl init_battle_sprite_entry_08048818
	adds r1, r7, #0
	adds r1, #0x82
	movs r0, #0x5f
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x84
	strh r4, [r0]
	str r5, [sp]
	movs r0, #3
	adds r1, r6, #0
	movs r2, #0x87
	movs r3, #0xa
	bl init_battle_sprite_entry_08048818
	adds r1, r7, #0
	adds r1, #0xc2
	movs r0, #0xaf
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc4
	strh r4, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080695E4: .4byte 0x040000D4
_080695E8: .4byte 0x0600E800
_080695EC: .4byte 0x81000400
_080695F0: .4byte 0x087C52C8
_080695F4: .4byte 0x0600CD00
_080695F8: .4byte 0x087C5518
_080695FC: .4byte 0x0600D0A0
_08069600: .4byte 0x087C55D0
_08069604: .4byte 0x05000180
_08069608: .4byte 0x84000008
_0806960C: .4byte 0x087C55F0
_08069610: .4byte 0x050001A0
_08069614: .4byte 0x0400000A
_08069618: .4byte 0x00001D0D
_0806961C: .4byte 0x03002C30
	.syntax divided
