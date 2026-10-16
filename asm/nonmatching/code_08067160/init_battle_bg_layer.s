	.syntax unified

	thumb_func_start init_battle_bg_layer
init_battle_bg_layer: @ 0x080692FC
	push {r4, r5, r6, lr}
	ldr r1, _0806936C @ =0x03006F90
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08069370 @ =0x0400000C
	ldr r2, _08069374 @ =0x00001E0A
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08069378 @ =0x00001F0B
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, _0806937C @ =0x03001800
	ldr r0, _08069380 @ =0x03006F84
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x38
	movs r6, #0
	strb r0, [r5]
	ldrb r0, [r5]
	movs r1, #0
	bl decompress_tileset_to_vram
	ldrb r0, [r5]
	lsls r0, r0, #3
	ldr r1, _08069384 @ =0x083C3B04
	adds r0, r0, r1
	adds r4, #0x39
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	bl apply_battle_blend_effect_a
	ldr r2, _08069388 @ =0x083B23F8
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl decompress_to_ewram_27000
	ldr r0, _0806938C @ =0x0300057C
	strh r6, [r0]
	strh r6, [r0, #2]
	ldr r0, _08069390 @ =0x03001C04
	strh r6, [r0]
	strh r6, [r0, #2]
	ldr r1, _08069394 @ =0x030017F0
	ldr r0, _08069398 @ =sub_08043E48
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806936C: .4byte 0x03006F90
_08069370: .4byte 0x0400000C
_08069374: .4byte 0x00001E0A
_08069378: .4byte 0x00001F0B
_0806937C: .4byte 0x03001800
_08069380: .4byte 0x03006F84
_08069384: .4byte 0x083C3B04
_08069388: .4byte 0x083B23F8
_0806938C: .4byte 0x0300057C
_08069390: .4byte 0x03001C04
_08069394: .4byte 0x030017F0
_08069398: .4byte sub_08043E48
	.syntax divided
