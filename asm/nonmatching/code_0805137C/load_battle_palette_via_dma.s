	.syntax unified

	thumb_func_start load_battle_palette_via_dma
	.global load_battle_palette_via_dma
load_battle_palette_via_dma: @ 0x08051DEC
	push {r4, r5, lr}
	adds r4, r0, #0
	bl decompress_battle_tile_graphics
	cmp r4, #0
	bne _08051E30
	ldr r1, _08051E18 @ =0x040000D4
	ldr r3, _08051E1C @ =0x083F8634
	ldr r2, _08051E20 @ =0x083D29A6
	ldr r4, _08051E24 @ =0x030057E0
	ldr r5, _08051E28 @ =0x00000C5C
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08051E2C @ =0x05000200
	b _08051E4C
	.align 2, 0
_08051E18: .4byte 0x040000D4
_08051E1C: .4byte 0x083F8634
_08051E20: .4byte 0x083D29A6
_08051E24: .4byte 0x030057E0
_08051E28: .4byte 0x00000C5C
_08051E2C: .4byte 0x05000200
_08051E30:
	ldr r1, _08051E6C @ =0x040000D4
	ldr r3, _08051E70 @ =0x083F8634
	ldr r2, _08051E74 @ =0x083D29A6
	ldr r4, _08051E78 @ =0x030057E0
	ldr r5, _08051E7C @ =0x00000C5C
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08051E80 @ =0x0202F800
_08051E4C:
	str r0, [r1, #4]
	ldr r0, _08051E84 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _08051E7C @ =0x00000C5C
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _08051E88 @ =0x00000C28
	adds r0, r4, r2
	strb r1, [r0]
	bl load_battle_terrain_data
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08051E6C: .4byte 0x040000D4
_08051E70: .4byte 0x083F8634
_08051E74: .4byte 0x083D29A6
_08051E78: .4byte 0x030057E0
_08051E7C: .4byte 0x00000C5C
_08051E80: .4byte 0x0202F800
_08051E84: .4byte 0x84000008
_08051E88: .4byte 0x00000C28
	.syntax divided
